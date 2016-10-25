//
//  sdmNodeControlWidget.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 22/08/2016.
//
//

#ifndef sdmNodeControlWidget_hpp
#define sdmNodeControlWidget_hpp

/// \file sdmNodeControlWidget.h
///
/// \brief Contains the definition of the NodeControlWidget class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsPathItem>
#include <QMap>
#include <QVariant>

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::move;
using std::swap;


namespace spencers
{
    class NodeControl;
    
    
    ///
    /// \brief NodeControlWidget class.
    ///
    class NodeControlWidget : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent      Qt parent object owning this SceneItemDrop.
        ///
        explicit NodeControlWidget(QGraphicsScene& graphicsScene, QGraphicsItem *parent = 0);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~NodeControlWidget();
        
        ///
        /// \brief Sets the hover path.
        ///
        /// \param [in] path        A new QPainterPath object.
        ///
        void setHoverPath(const QPainterPath& path);
        
        ///
        /// \brief Sets the hover position.
        ///
        /// \param [in] point       The location as a QPointF.
        ///
        void setHoverPosition(const QPointF point);
        
        ///
        /// \brief Sets the hover drop area.
        ///
        /// \param [in] point       The drop area as a QRectF.
        ///
        void setHoverBounds(const QRectF frame);
        
        ///
        /// \brief Displays this NodeControlWidget.
        ///
        void show();
        
        ///
        /// \brief Displays this NodeControlWidget.
        ///
        void hide();
        
        ///
        /// \brief Removes all selected NodeControl(s) from the scene.
        ///
        void removeSelected();
        
    public: // Reimplemented.
        
        ///
        /// \brief Defines the outer bounds of the item as a rectangle.
        ///
        /// \return The bounding rectangle for this item.
        ///
        QRectF boundingRect() const;
        
        ///
        /// \brief Paints this item.
        ///
        /// \param [in] painter     Painter used to draw this item.
        /// \param [in] option      Style options for this item.
        /// \param [in] widget      Optional containing widget.
        ///
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget = 0);
        
    signals:
        
        ///
        /// \brief Emitted when
        ///
        /// \param [out] nodeControl        The
        ///
        void sceneAddChange(NodeControl& nodeControl);
        
        ///
        /// \brief Emitted when
        ///
        /// \param [out] nodeControl        The
        ///
        void sceneRemoveChange(NodeControl& nodeControl);
        
    protected: // Reimplemented.
        
        ///
        /// \brief Called when the mouse moves within the item.
        ///
        /// \param [in] event   Qt event object.
        ///
        void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
        
        ///
        /// \brief Called when the mouse presses within the item.
        ///
        /// \param [in] event   Qt event object.
        ///
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::keyReleaseEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void keyReleaseEvent(QKeyEvent *event);
        
    private:
        
        ///
        /// \brief Scene object.
        ///
        QGraphicsScene* _scene;
        
        ///
        /// \brief All node instances in the graph.
        ///
        QList<NodeControl*> _cache;
        
        ///
        /// \brief Border size.
        ///
        QRectF _bounds;
        
        ///
        /// \brief Padding size.
        ///
        QGraphicsPathItem _pathItem;
    };
}

#endif 


