//
//  sdmNodeScene.cpp
//  QtProject-Template
//
//  Created by Peter JC Spencer on 06/01/2016.
//
//

#include "sdmNodeScene.h"

#include <QtWidgets>


namespace spencers
{
    NodeScene::NodeScene(QObject *parent)
    : QGraphicsScene(parent)
    {
    }
    
    
    NodeScene::NodeScene(const QString& path, QObject *parent)
    : QGraphicsScene(parent)
    {
        Q_UNUSED(path); // TODO:Support 'blueprint' from initialising json ...
    }
    
    
    NodeScene::~NodeScene() {}
    
    
    auto NodeScene::items(const NodeControlType type) const -> QList<QGraphicsItem *>
    {
        QList<QGraphicsItem*> result;

        for (QGraphicsItem* item : QGraphicsScene::items())
        {
            auto castItem = dynamic_cast<NodeControl*>(item);
            if (castItem && (castItem->nodeType() == type))
            {
                result << castItem;
            }
        }
        
        return result;
    }
    
    
    auto NodeScene::itemTitle(const NodeControlType type) -> const QString*
    {
        auto list = items(type);
        auto count = list.count();
        auto prefix = NodeLibrary::prefixForType(type);
        QString title = prefix + QString::number(count++);
        
        foreach(QGraphicsItem* item, QGraphicsScene::items())
        {
            auto castItem = dynamic_cast<NodeControl*>(item);
            if (castItem && (castItem->labelText() == title))
            {
                title = prefix + QString::number(count++);
            }
        }
        
        return make_unique<QString>(title).release();
    }
    
    
    void NodeScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
    {
        QGraphicsScene::mousePressEvent(mouseEvent);
        
        if (mouseEvent->button() == Qt::LeftButton)
        {
            foreach(QGraphicsItem* item, QGraphicsScene::items())
            {
                NodeControl* castItem = dynamic_cast<NodeControl*>(item);
                if (castItem != nullptr)
                    castItem->setSelected(castItem->isSelected());
            }
        }
    }
}


