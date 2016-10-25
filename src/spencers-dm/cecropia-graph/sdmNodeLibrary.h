//
//  sdmNodeLibrary.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 31/03/2016.
//
//

#ifndef sdmNodeLibrary_h
#define sdmNodeLibrary_h

/// \file sdmNodeLibrary.h
///
/// \brief Contains the definition of the NodeLibrary class.
///

#include <QObject>
#include <QStandardPaths>
#include <QDir>
#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QString>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QMap>
#include <QHash>
#include <QList>
#include <QVariant>
#include <QColor>
#include <QGraphicsScene>

#include "sdmNodeControl.h"

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::move;


namespace spencers
{
    ///
    /// \brief NodeLibrary class.
    ///
    class NodeLibrary : public QObject
    {
    public:
        
        ///
        /// \brief The root directory for the NodeLibrary.
        ///
        /// \return             A new QFileSystemModel object.
        ///
        static auto rootDirectory() -> const QDir;
        
        ///
        /// \brief The file system model for this NodeLibrary.
        ///
        /// \return             A pointer to a new QFileSystemModel object.
        ///
        static auto fileSystemModel() -> QFileSystemModel*;
        
        ///
        /// \brief A conents Model for the NodeLibrary.
        ///
        /// \param [in] string  
        /// \return             A pointer to a new QStandardItemModel object.
        ///
        static auto contentsModel(const QString& string) -> QStandardItemModel*;
        
        ///
        /// \brief Create a new NodeControl object.
        ///
        /// \param [in] string  A string object representing the key.
        /// \return             A pointer to a new NodeControl object.
        ///
        static auto createNode(const QString& key) -> unique_ptr<NodeControl>;
        
        ///
        /// \brief Create a new NodeControl object from file.
        ///
        /// \param [in] string  A string object representing the path to a json file.
        /// \return             A pointer to a new NodeControl object.
        ///
        static auto createNodeWithFile(const QString& path) -> unique_ptr<NodeControl>;
        
        ///
        /// \brief Identifies a port for a specific key
        ///
        /// \param [in] key     A string object representing the key.
        /// \return             A pointer to a new QMap object.
        ///
        static auto port(const QString& key) -> const QMap<QString, QVariant>*;
        
        ///
        /// \brief Utility which returns a node type.
        ///
        /// \param [in]         A QString for key.
        /// \return             A NodeControlType.
        ///
        static auto typeFromModel(const QString& key) -> NodeControlType;
        
        ///
        /// \brief Utility which returns a prefix for specified type.
        ///
        /// \param [in]         A NodeControlType to identify.
        /// \return             A new QString object.
        ///
        static auto prefixForType(const NodeControlType type) -> QString;
        
    private: // Function(s).
        
        ///
        /// \brief Utility for caching port information.
        ///
        /// \param [in] jsonArray   The QJsonArray object to examine.
        ///
        static void cachePortsInfo(const QJsonArray& jsonArray);
        
        ///
        /// \brief Utility used to create new BezierScrollerItem object(s).
        ///
        /// \param [in] jsonArray   The QJsonArray object to examine.
        /// \return                 A new QList object.
        ///
        static auto createScrollerItems(const QJsonArray& jsonArray) -> const QList<BezierScrollerItem*>;
        
        ///
        /// \brief Utility, the color identifying a datatype.
        ///
        /// \param [in] key         The QString key to query.
        /// \return                 A cached QColor object.
        ///
        static auto dataTypeColor(const QString& key) -> const QColor*;
        
        ///
        /// \brief Opens a json object for filePath.
        ///
        /// \param [in] filePath    A QString representing the path.
        /// \return                 A new QJsonObject object.
        ///
        static auto openJson(const QString& filePath) -> unique_ptr<QJsonObject>;
        
        ///
        /// \brief Utility json validation.
        ///
        /// \param [in] jsonObject  The QJsonObject object to validate.
        /// \return                 A boolean describing success/fail.
        ///
        static auto validateJson(const QJsonObject& jsonObject) -> bool;
        
        ///
        /// \brief Utility NodeControlType identification.
        ///
        /// \param [in] string      A QString object describing type.
        /// \return                 A type enum.
        ///
        static auto typeFromString(const QString& string) -> NodeControlType;
        
    private:
        
        ///
        /// \brief A cache of QStandardItemModel object(s).
        ///
        static QHash<QString, QStandardItemModel*> _contentModels;
        
        ///
        /// \brief A cache of path(s) to content model object(s).
        ///
        static QHash<QString, QString*> _contentModelsPaths;
        
        ///
        /// \brief Utility cache of icon(s).
        ///
        static QHash<QString, QIcon*> _icons;
        
        ///
        /// \brief A cache of port info.
        ///
        static QHash<QString, QMap<QString, QVariant>*> _ports;
    };
}

#endif 


