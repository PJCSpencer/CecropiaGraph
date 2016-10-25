//
//  sdmPlugConnectionWidget.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 11/07/2016.
//
//

#ifndef sdmPlugConnectionWidget_h
#define sdmPlugConnectionWidget_h

/// \file sdmPlugConnectionWidget.h
///
/// \brief Contains the definition of the PlugConnectionWidget class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>

#include <memory>

using std::make_unique;

// Supported enum(s).
enum class PlugConnectionTask
{
    Unkown      = 0,
    Start,
    Change
};


namespace spencers
{
    class NodeControl;
    class Plug;
    class PlugGroup;
    class PlugConnection;
    
    
    ///
    /// \brief PlugConnectionWidget class
    ///
    class PlugConnectionWidget : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent widget of this object.
        ///
        PlugConnectionWidget(QGraphicsScene& graphicsScene, bool isVisible = false);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~PlugConnectionWidget();
        
        ///
        /// \brief Cancels a connection session.
        ///
        void cancelSession();
        
        ///
        /// \brief Called when a plug group changes.
        ///
        /// \param [in] plugGroup       A PlugGroup object.
        ///
        void endSession(PlugGroup* plugGroup);
        
        ///
        /// \brief Remove any connection to incoming NodeControl.
        ///
        /// \param [in] nodeControl     A NodeControl object.
        ///
        void removeConnected(const NodeControl& nodeControl);
        
    public: // Reimplemented.
        
        ///
        /// \brief Defines the outer bounds of the item as a rectangle.
        ///
        /// \return                 The bounding rectangle for this item.
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
        
    public slots:
        
        ///
        /// \brief Called when a plug initiates.
        ///
        /// \param [in] plugGroup       A PlugGroup object.
        ///
        void startSession(PlugGroup& plugGroup);
        
        ///
        /// \brief Called when a plug group changes.
        ///
        /// \param [in] plugGroup       A PlugGroup reference.
        /// \param [in] plug            A Plug pointer.
        ///
        void changeSession(PlugGroup& plugGroup, Plug* plug);
        
        ///
        /// \brief Called when added to a scene.
        ///
        /// \param [in] nodeControl       A NodeControl object.
        ///
        void sceneAdded(NodeControl& nodeControl);
        
        ///
        /// \brief Called when removed from a scene.
        ///
        /// \param [in] nodeControl       A NodeControl object.
        ///
        void sceneRemoved(NodeControl& nodeControl);
        
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
        
    private:
        
        ///
        /// \brief Scene object.
        ///
        QGraphicsScene* _scene;
        
        ///
        /// \brief All connection instances in the graph.
        ///
        QList<PlugConnection*> _cache;
        
        ///
        /// \brief The active connection.
        ///
        PlugConnection* _liveConnection;

        ///
        /// \brief The anchor position.
        ///
        QPointF _anchorPos;
        
        ///
        /// \brief Bounds.
        ///
        QRectF _bounds;
    };
}

#endif


