//
//  sdmPlugGroup.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 02/05/2016.
//
//

#ifndef sdmPlugGroup_h
#define sdmPlugGroup_h

/// \file sdmPlugGroup.h
///
/// \brief Contains the definition of the PlugGroup class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>
#include <QList>

#include <iostream>


namespace spencers
{
    class Plug;
    
    
    ///
    /// \brief PlugGroup class.
    ///
    class PlugGroup : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent          Parent widget of this View.
        ///
        explicit PlugGroup(QGraphicsItem *parent = 0);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~PlugGroup();
        
        ///
        /// \brief All the Plug(s0 for this PlugGroup.
        ///
        /// \return                     A QList object.
        ///
        auto plugs() -> const QList<Plug*>;
        
        ///
        /// \brief Adds a Plug to this PlugGroup.
        ///
        /// \param [in] plugItem        A Plug object.
        ///
        void addPlug(Plug* plugItem);
        
        ///
        /// \brief Removes a Plug from this PlugGroup.
        ///
        /// \param [in] item            A Plug object.
        ///
        void removePlug(Plug* item);
        
        ///
        /// \brief Removes all Plug(s) from this PlugGroup.
        ///
        void removeAllPlugs();
        
        ///
        /// \brief Utility target for this PlugGroup.
        ///
        /// \return                     A QString object.
        ///
        auto target() -> const QString&
        {
            return _target;
        };
        
        ///
        /// \brief Sets the target for this PlugGroup.
        ///
        /// \param [in] target         A QString reference.
        ///
        void setTarget(const QString& target);
        
        ///
        /// \brief Stes the pen color for this PlugGroup.
        ///
        /// \param [in] painter         A QColor reference.
        ///
        void setPenColour(const QColor& color);
        
        ///
        /// \brief Sets the brush for this PlugGroup.
        ///
        /// \param [in] color         A QBrush reference.
        ///
        void setBrushColour(const QColor& color);
        
    public: // Reimplemented.
        
        ///
        /// \brief Reimplemented from QGraphicsItem.
        ///
        /// \return                 A new QPainterPath object.
        ///
        QPainterPath shape() const;
        
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
        
    signals:
        
        ///
        /// \brief Emitted when this PlugGroup changes.
        ///
        /// \param [in] plugGroup   A PlugGroup object.
        ///
        void plugGroupChanged(PlugGroup& plugGroup);
        
        ///
        /// \brief Emitted when a Plug is detached from this PlugGroup.
        ///
        /// \param [in] plugGroup   A PlugGroup object.
        /// \param [in] plug        A Plug object.
        ///
        void plugGroupDetached(PlugGroup& plugGroup, Plug* plug);
        
    protected: // Reimplemented.
        
        ///
        /// \brief Called when the mouse enteres the shape of the item.
        ///
        /// \param [in] event   Qt event object
        ///
        void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
        
        ///
        /// \brief Called when the mouse leaves the shape of the item.
        ///
        /// \param [in] event   Qt event object
        ///
        void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
        
        ///
        /// \brief Called if the mouse is released after a click on this item.
        ///
        /// Is always called after \ref zodiac::Node::mousePressEvent "mousePressEvent" and possibly
        /// \ref zodiac::Node::mouseMoveEvent "mouseMoveEvent".
        ///
        /// \param [in] event   Qt event object.
        ///
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    
    private: // Static private members.
        
        ///
        /// \brief The pen width.
        ///
        static qreal _penWidth;
        
        ///
        /// \brief The padding.
        ///
        static qreal _padding;
        
        ///
        /// \brief The border margins.
        ///
        static QMargins _borderMargins;
        
    private:
        
        ///
        /// \brief The plugs owned by this PlugGroup.
        ///
        QList<Plug*> _plugs;
        
        ///
        /// \brief A unique id.
        ///
        int _uid;
        
        ///
        /// \brief Utility target.
        ///
        QString _target;
        
        ///
        /// \brief Expanded state.
        ///
        bool _isExpanded;
        
        ///
        /// \brief The pen.
        ///
        QPen _pen;
        
        ///
        /// \brief The brush.
        ///
        QBrush _brush;
    };
}

#endif


