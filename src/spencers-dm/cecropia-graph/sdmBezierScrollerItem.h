//
//  sdmBezierScrollerItem.h
//  QtProject-Template
//
//  Created by Peter JC Spencer on 25/01/2016.
//
//

#ifndef sdmBezierScrollerItem_h
#define sdmBezierScrollerItem_h

/// \file sdmBezierScrollerItem.h
///
/// \brief Contains the definition of the BezierScrollerItem class.
///

#include <QGraphicsObject>
#include <QGraphicsItemGroup>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QGraphicsSimpleTextItem>
#include <QColor>
#include <QtMath>

#include "sdmPlugGroup.h"
#include "sdmPainterPathUtility.h"
#include "sdmStyles.h"

#include <iostream>
#include <memory>
#include <math.h>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    ///
    /// \brief BezierScrollerItem class.
    ///
    class BezierScrollerItem : public QGraphicsObject 
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent widget of this item.
        ///
        explicit BezierScrollerItem(QGraphicsItem *parent = 0);
        
        ///
        /// \brief The title for this BezierScrollerItem.
        ///
        /// \return                     A QString object.
        ///
        auto title() -> const QString;
        
        ///
        /// \brief Sets the title for this BezierScrollerItem.
        ///
        /// \param [in] string          A QString object to use for title.
        ///
        void setTitle(const QString& string);
        
        ///
        /// \brief Sets the title inset for this BezierScrollerItem.
        ///
        /// \param [in] inset          A qreal.
        ///
        void setTitleInset(const qreal inset);
        
        ///
        /// \brief Sets the title color for this BezierScrollerItem.
        ///
        /// \param [in] color           A QColor object to use for color.
        ///
        void setTitleColour(const QColor& color);
        
        ///
        /// \brief The plug group for this BezierScrollerItem.
        ///
        /// \return                     A PlugGroup object.
        ///
        auto plugGroup() const -> PlugGroup*;
        
        ///
        /// \brief Sets the plug group target path for this BezierScrollerItem.
        ///
        /// \param [in] target          A new QString object.
        ///
        void setPlugGroupTarget(const QString& target);
        
        ///
        /// \brief Sets the background path for this BezierScrollerItem.
        ///
        /// \param [in] path            A QPainterPath object to use for path.
        ///
        void setBackgroundPath(const QPainterPath& path);
        
        ///
        /// \brief Sets the background color for this BezierScrollerItem.
        ///
        /// \param [in] color           A QColor object to use for color.
        ///
        void setBackgroundBrush(const QBrush& brush);
        
        ///
        /// \brief Sets the background color for this BezierScrollerItem.
        ///
        /// \param [in] color           A QColor object to use for color.
        ///
        void setBackgroundPen(const QPen& pen);
        
        ///
        /// \brief Defines the bounds of the item as a size.
        ///
        /// \return                 The bounds size for this item.
        ///
        auto boundingSize() -> const QSizeF;
        
        ///
        /// \brief Utility, the length to pos.
        ///
        /// \return                     A qreal.
        ///
        auto lengthToPos() -> qreal { return _lengthToPos; };
        
        ///
        /// \brief Utility, sets the length to pos.
        ///
        /// \param [in] length          A qreal.
        ///
        void setLengthToPos(const qreal length) { _lengthToPos = length; };
        
        ///
        /// \brief Updates to geometry for this BezierScrollerItem.
        ///
        /// \param [in] lengthToPos     A qreal to set lengthToPos.
        /// \param [in] pos             A QPointF for setPos.
        /// \param [in] rotation        A qreal for setRotation.
        ///
        void update(const QPointF pos, const qreal rotation);
        
    public:
        
        ///
        /// \brief Reimplemented from QGraphicsItem.
        ///
        void setRotation(qreal angle);
        
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
        
    public: // Static members.
        
        ///
        /// \brief The offset for the plug group owned by this BezierScrollerItem.
        ///
        static qreal plugGroupOffset;
        
        ///
        /// \brief Alpha value used to visualise a drag in progress.
        ///
        static qreal dragInProgressAlpha;
        
        ///
        /// \brief Alpha value used to visualise a drag in progress.
        ///
        static QMargins contentMargins;
        
        ///
        /// \brief Utility, calcualtes the geometry size for a string.
        ///
        /// \param [in] string      The string to measure.
        ///
        /// \return                 A QSize.
        ///
        static auto sizeForString(const QString& string) -> QSize;
        
        ///
        /// \brief Utility, calculates size height.
        ///
        /// \return                 A qreal.
        ///
        static auto sizeHeight() -> qreal;
        
    protected: // Reimplemented.
        
        ///
        /// \brief Called when the mouse i spressed.
        ///
        /// \param [in] event   Qt event object.
        ///
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        
        ///
        /// \brief Called when the mouse is released.
        ///
        /// \param [in] event   Qt event object.
        ///
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        
    private:
        
        ///
        /// \brief Length to pos.
        ///
        qreal _lengthToPos;
        
        ///
        /// \brief Background path.
        ///
        QGraphicsPathItem _backgroundPathItem;
        
        ///
        /// \brief Simple text item.
        ///
        QGraphicsSimpleTextItem _simpleTextItem;
        
        ///
        /// \brief Supported plug group.
        ///
        unique_ptr<PlugGroup> _plugGroup;
    };
}

#endif


