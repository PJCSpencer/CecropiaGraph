/*
 *  sdmNodeScene.h
 *  QtProject-Template
 *
 *  Created by Peter JC Spencer on 06/01/2016.
 *
 */

#ifndef sdmNodeScene_h
#define sdmNodeScene_h

/// \file sdmNodeScene.h
///
/// \brief Contains the definition of the NodeScene class.
///

#include <QGraphicsScene>

#include "sdmConstants.h"
#include "sdmNodeLibrary.h"
#include "sdmPainterPathUtility.h"
#include "sdmNodeControl.h"
#include "sdmBezierScroller.h"
#include "sdmBezierScrollerItem.h"
#include "sdmCustomTextItem.h"

#include <memory>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    ///
    /// \brief NodeScene class.
    ///
    class NodeScene : public QGraphicsScene
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent          Qt parent object owning this Scene.
        ///
        explicit NodeScene(QObject *parent);
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] path            QString object representing an absolute json path.
        /// \param [in] parent          Qt parent object owning this Scene.
        ///
        NodeScene(const QString& path, QObject *parent);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~NodeScene();
        
    public:
        
        ///
        /// \brief TODO:
        ///
        auto items(const NodeControlType type) const -> QList<QGraphicsItem *>;
        
        ///
        /// \brief Utility which provides a new unique title.
        ///
        /// \return A new QString object.
        ///
        auto itemTitle(const NodeControlType type) -> const QString*;
        
    protected: // Reimplemented.
        
        ///
        /// \brief Called when the mouse pressed.
        ///
        /// \param [in] event   Qt event object
        ///
        void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    };
}

#endif


