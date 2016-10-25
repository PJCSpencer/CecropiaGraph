//
//  sdmNodeLibrary.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 31/03/2016.
//
//

#include "sdmNodeLibrary.h"

#include <QApplication>
#include <QDebug>


namespace spencers
{
    QHash<QString, QStandardItemModel*> NodeLibrary::_contentModels;
    QHash<QString, QString*> NodeLibrary::_contentModelsPaths;
    QHash<QString, QIcon*> NodeLibrary::_icons;
    QHash<QString, QMap<QString, QVariant>*> NodeLibrary::_ports;
    
    
    auto NodeLibrary::rootDirectory() -> const QDir
    {
        static QDir dir(QDir::toNativeSeparators("/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode/res/json/nodelib"));
        
        return dir;
    }
    
    
    auto NodeLibrary::fileSystemModel() -> QFileSystemModel*
    {
        unique_ptr<QFileSystemModel> model = nullptr;
        model = make_unique<QFileSystemModel>();
        
        model->setRootPath(NodeLibrary::rootDirectory().path());
        model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
        
        return model.release();
    }
    
    
    auto NodeLibrary::contentsModel(const QString& string) -> QStandardItemModel*
    {
        if (!_contentModels.contains(string))
        {
            unique_ptr<QStandardItemModel> model = nullptr;
            QList<QStandardItem*> list;
            QString path = NodeLibrary::rootDirectory().path() + "/" + string;
            QString fileInfoPath;
            QString name;
            QString iconName;
            QString iconPath;
            
            QDir sub(QDir::toNativeSeparators(path));
            sub.setNameFilters(QStringList("*.json"));
            sub.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
            
            foreach (QString file, sub.entryList())
            {
                fileInfoPath = QFileInfo(sub, file).filePath(); // TODO:Check for duplicate ...
                
                if (auto jsonObject = NodeLibrary::openJson(fileInfoPath))
                {
                    name = jsonObject->value(Keys::Name).toString();
                    _contentModelsPaths[name] = make_unique<QString>(fileInfoPath).release();
                    
                    if (NodeLibrary::validateJson(*jsonObject))
                    {
                        iconName = jsonObject->value(Keys::Icon).toString();
                        iconPath = path + "/" + iconName;
                        iconPath = QDir::toNativeSeparators(iconPath);

                        QFile file(iconPath);
                        if (file.open(QIODevice::ReadOnly))
                        {
                            _icons[iconName] = make_unique<QIcon>(iconPath).release();
                            list << make_unique<QStandardItem>(*_icons[iconName], name).release();
                        }
                        else
                        {
                            list << make_unique<QStandardItem>(name).release();
                        }
                    }
                    else
                        qDebug() << "Failed to validate json file:" << fileInfoPath;
                }
            }

            model = make_unique<QStandardItemModel>();
            model->appendColumn(list);
            
            _contentModels[string] = model.release();
        }
        
        return _contentModels[string];
    }
    
    
    auto NodeLibrary::createNode(const QString& key) -> unique_ptr<NodeControl>
    {
        if (!_contentModelsPaths.contains(key))
        {
            return nullptr;
        }
        
        if (auto jsonObject = NodeLibrary::openJson(*_contentModelsPaths[key]))
        {
            NodeControlType type = NodeLibrary::typeFromString(jsonObject->value(Keys::Type).toString());
            
            if (type == NodeControlType::Unkown)
            {
                return nullptr;
            }
            
            // Create a new NodeControl instance.
            auto node = make_unique<NodeControl>(type);
            
            if (type == NodeControlType::Default || type == NodeControlType::Image)
            {
                if (jsonObject->contains(Keys::Icon)) // TODO:Organise resource(s) ~ icons/large/*.svg ...
                {
                    auto iconName = jsonObject->value(Keys::Icon).toString();
                    
                    if (!_icons.contains(iconName)) // TODO:Support image type(s) ...
                    {
                        return nullptr;
                    }
                    
                    auto icon = QIcon(*_icons[iconName]);
                    node->setIcon(icon);
                }
            }
            
            // TODO:Support Keys::FlagTracking ...
            
            
            // Parse port(s).
            cachePortsInfo(jsonObject->value(Keys::Ports).toArray());
                
            // Parse inputs and outputs.
            auto inputs = createScrollerItems(jsonObject->value(Keys::Input).toArray());
            auto outputs = createScrollerItems(jsonObject->value(Keys::Output).toArray());
            
            // Apply.
            node->setInputItems(inputs);
            node->setOutputItems(outputs);
            
            // Return object;
            return node;
        }
        
        return nullptr;
    }
    
    
    auto NodeLibrary::createNodeWithFile(const QString& path) -> unique_ptr<NodeControl>
    {
        Q_UNUSED(path);
        
        return nullptr;
    }
    
    
    auto NodeLibrary::port(const QString& key) -> const QMap<QString, QVariant>*
    {
        if (_ports.contains(key))
        {
            return _ports[key];
        }
        return nullptr;
    }
            
    
    void NodeLibrary::cachePortsInfo(const QJsonArray& jsonArray)
    {
        QJsonObject jsonObject;
        QString key;
        
        for (auto i = 0; i < jsonArray.size(); i ++)
        {
            jsonObject = jsonArray[i].toObject();
            key = jsonObject[Keys::UId].toString();
            
            if (!_ports.contains(key))
            {
                auto port = make_unique<QMap<QString, QVariant>>();
                port->insert(Keys::Title, QVariant(jsonObject[Keys::Title].toString()));
                port->insert(Keys::Target, QVariant(jsonObject[Keys::Target].toString()));
                port->insert(Keys::DataType, QVariant(jsonObject[Keys::DataType].toString()));
                             
                _ports[key] = port.release();
            }
        }
    }
    
            
    auto NodeLibrary::createScrollerItems(const QJsonArray& jsonArray) -> const QList<BezierScrollerItem*>
    {
        QList<BezierScrollerItem*> result;
        QString key;
        unique_ptr<BezierScrollerItem> scrollerItem = nullptr;
        
        foreach(const QJsonValue& value, jsonArray)
        {
            key = value.toString();
            
            scrollerItem = make_unique<BezierScrollerItem>();
            
            scrollerItem->setTitle(_ports[key]->value(Keys::Title).toString());
            scrollerItem->setPlugGroupTarget(_ports[key]->value(Keys::Target).toString());
            scrollerItem->setBackgroundBrush(QBrush(*dataTypeColor(_ports[key]->value(Keys::DataType).toString())));
            
            result.append(scrollerItem.release());
        }
        
        return result;
    }
    
    
    auto NodeLibrary::openJson(const QString& filePath) -> unique_ptr<QJsonObject>
    {
        unique_ptr<QJsonObject> jsonObject = nullptr;
        
        QFile file(filePath);
        if (file.open(QFile::ReadOnly | QIODevice::Text))
        {
            if (file.error() != QFile::NoError)
            {
                qDebug() << QString("Failed to read from file %1, error:%2").arg(file.fileName()).arg(file.errorString());
            }
            else
            {
                QJsonParseError error;
                QJsonDocument document = QJsonDocument::fromJson(file.readAll(), &error);
                
                if (error.error != QJsonParseError::NoError)
                {
                    qDebug() << "Error passing json document:" << error.errorString();
                }
                else if (document.isEmpty())
                {
                    qDebug() << "Json document empty:" << file.fileName();
                }
                else
                {
                    jsonObject = make_unique<QJsonObject>(document.object());
                }
            }
            
            // Close the file.
            file.close();
        }
        else
        {
            qDebug() << "Could not open the file" << file.fileName() << "for reading:" << file.errorString();
        }
        return jsonObject;
    }
    
    
    auto NodeLibrary::validateJson(const QJsonObject& jsonObject) -> bool
    {
        static QStringList requiredKeys;
        if (requiredKeys.isEmpty())
        {
            requiredKeys << Keys::Name << Keys::Type << Keys::Icon << Keys::Blueprint
            << Keys::Input << Keys::Output << Keys::Ports;
        }
            
        foreach (QString key, requiredKeys)
        {
            if (!jsonObject.keys().contains(key))
            {
                return false;
            }
        }
        
        return true;
    }
            
    
    auto NodeLibrary::typeFromModel(const QString& key) -> NodeControlType
    {
        NodeControlType returnType = NodeControlType::Unkown;
                    
        if (auto jsonObject = NodeLibrary::openJson(*_contentModelsPaths[key]))
        {
            returnType = NodeLibrary::typeFromString(jsonObject->value(Keys::Type).toString());
        }
                    
        return returnType;
    }
                
                
    auto NodeLibrary::typeFromString(const QString& string) -> NodeControlType
    {
        static QMap<NodeControlType, QString> map;
        if (map.isEmpty())
        {
            map[NodeControlType::Default] = "com.spencers-dm.node.type.default";
            map[NodeControlType::Label] = "com.spencers-dm.node.type.label";
            map[NodeControlType::Image] = "com.spencers-dm.node.type.image";
        }
        
        if (!map.values().contains(string))
        {
            return NodeControlType::Unkown;
        }
        
        return map.key(string);
    }
                
    
    auto NodeLibrary::prefixForType(const NodeControlType type) -> QString
    {
        static QString postfix = "object"; // TODO:Extent ...
        static QMap<NodeControlType, QString> map;
        if (map.isEmpty())
        {
            map[NodeControlType::Default] = "default_";
            map[NodeControlType::Label] = "label_";
            map[NodeControlType::Image] = "image_";
        }
        
        if (!map.keys().contains(type))
        {
            return "unkown_" + postfix;
        }
        
        return map.value(type) + postfix;
    }
            
            
    auto NodeLibrary::dataTypeColor(const QString& key) -> const QColor*
    {
        static QMap<QString, QColor*> map;
        if (map.isEmpty())
        {
            map[DataTypeKeys::Unkown] = make_unique<QColor>(127, 127, 127).release();
            map[DataTypeKeys::Boolean] = make_unique<QColor>(30, 30, 30).release();
            map[DataTypeKeys::Integer] = make_unique<QColor>(22, 89, 222).release();
            map[DataTypeKeys::Qreal] = make_unique<QColor>(Styles::lushPinkColor).release();
            map[DataTypeKeys::String] = make_unique<QColor>(54, 197, 255).release();
        }
        
        if (!map.keys().contains(key))
        {
            return map[DataTypeKeys::Unkown];
        }
        
        return map[key];
    }
}


