//
//  sdmBezierScroller.h
//  QtProject-Template
//
//  Created by Peter JC Spencer on 17/01/2016.
//
//

#ifndef sdmBezierScroller_h
#define sdmBezierScroller_h

/// \file sdmBezierScroller.h
///
/// \brief Contains the definition of the BezierScroller class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>
#include <QList>
#include <QMap>
#include <QtMath>
#include <QTimeLine>
#include <QLineF>
#include <QPropertyAnimation>

#include "sdmBezierScrollerItem.h"
#include "sdmBezierScrollerAnimation.h"
#include "sdmPainterPathUtility.h"

#include <math.h>
#include <memory>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    ///
    /// \brief BezierScroller class.
    ///
    class BezierScroller : public QGraphicsObject
    {
        Q_OBJECT
        
    public:

        ///
        /// \brief Constructor.
        ///
        /// \param [in] origin          Start position for scroll.
        /// \param [in] length          Length of scroll.
        /// \param [in] parent          Parent widget of this item.
        ///
        BezierScroller(const qreal origin, const qreal length, QGraphicsItem *parent = 0);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~BezierScroller();
        
        ///
        /// \brief The item for this BezierScroller.
        ///
        /// \return                 A QList object.
        ///
        auto items() -> const QList<BezierScrollerItem*>
        {
            return _items;
        }
        
        ///
        /// \brief Adds a single item to this BezierScroller.
        ///
        /// \param [in]             A BezierScrollerItem object.
        ///
        void addItem(BezierScrollerItem* scrollerItem);
        
        ///
        /// \brief Adds multiple items to this BezierScroller.
        ///
        /// \param [in]             A QList of item(s).
        ///
        void addItems(QList<BezierScrollerItem*>& scrollerItems);
        
        ///
        /// \brief Removes all item(s) from this BezierScroller.
        ///
        void removeAllItems();
        
        ///
        /// \brief Sets the visibility for item(s) of this BezierScroller.
        ///
        /// \param [in] visible     A boolean defining visibility.
        /// \param [in] animate     A boolean to support animation.
        ///
        void setItemsVisible(const bool visible, const bool animate);
        
        ///
        /// \brief Sets the scroll path for this BezierScroller.
        ///
        /// \param [in] path        A new QPainterPath object.
        ///
        void setScrollPath(const QPainterPath& path);
        
        ///
        /// \brief Sets the scroll handle color.
        ///
        /// \param [in] color       A new QColor object.
        ///
        void setScrollControlColour(const QColor& color);
        
        ///
        /// \brief Positions the scroll origin for this BezierScroller.
        ///
        /// \param [in] unit       A qreal for unit.
        ///
        void position(const qreal unit);
        
        ///
        /// \brief Translates the scroll position for this BezierScroller.
        ///
        /// \param [in] shift       A qreal for shift.
        ///
        void translate(const qreal shift);
        
        ///
        /// \brief Scrolls this BezierScrollerItem.
        ///
        /// \param [in] shift       A qreal.
        ///
        void scroll(const qreal shift);
        
        ///
        /// \brief The scroll origin for this BezierScroller.
        ///
        /// \return                 A qreal value.
        ///
        auto scrollOrigin() const -> qreal
        {
            return _scrollOrigin;
        }
        
        ///
        /// \brief The content inset for this BezierScroller.
        ///
        /// \return                 A qreal.
        ///
        auto contentInset() -> qreal;
        
        ///
        /// \brief Calculates the base content size for this BezierScroller.
        ///
        /// \return                 A qreal.
        ///
        auto contentLength() -> qreal;
        
        ///
        /// \brief The content size for this BezierScroller.
        ///
        /// \return                 A new QSize.
        ///
        auto contentSize() -> QSize;
        
        ///
        /// \brief Calculates the absolute content size for this BezierScroller.
        ///
        /// \return                 A new QSize.
        ///
        auto absoluteContentSize() -> QSize;
        
        ///
        /// \brief The flipped flag for this BezierScroller.
        ///
        /// \return                 A boolean.
        ///
        auto isFlipped() -> bool { return _flipped; };
        
        ///
        /// \brief Sets the flipped flag for this BezierScroller.
        ///
        /// \param [in] shift       A boolean.
        ///
        void setFlipped(const bool flipped) { _flipped = flipped; };
        
        ///
        /// \brief Sets the padding scale between scroller items for this BezierScroller.
        ///
        /// \param [in] scale       A qreal for padding scale.
        ///
        void setPaddingScale(const qreal scale);
        
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
        
    public: // Static members.
        
        ///
        /// \brief Radius for the scroll handle.
        ///
        static qreal scrollBarControlRadius;
        
        ///
        /// \brief Gutter between scroll handle and first item.
        ///
        static qreal scrollBarGutterRadius;
        
        ///
        /// \brief The amount of scroll interpolation to apply.
        ///
        static qreal scrollInterpolation;
        
        ///
        /// \brief The amount of padding between item(s).
        ///
        static qreal scrollItemPadding;
        
        ///
        /// \brief The amount of drag interpolation to apply.
        ///
        static qreal dragInterpolation;
        
        ///
        /// \brief The duration for a drag animation.
        ///
        static int dragAnimationDuration;
        
    public slots:
        
        ///
        /// \brief Utility, called when a animation changes.
        ///
        /// \param [in] animation   A BezierScrollerAnimation object.
        ///
        void animationChanged(BezierScrollerAnimation* animation);
        
    protected:
        
        ///
        /// \brief Aligns all the items for this BezierScroller.
        ///
        /// \param [in] path                The QPainterPath object used for alignment.
        /// \param [in] scrollOrigin        A qreal for origin.
        /// \param [in] scrollOriginOffset  A qreal for offset.
        /// \param [in] items               A QList of BezierScrollerItem(s).
        /// \param [in] linearStep          The linear step.
        /// \param [in] cubicStep           The cubic step.
        /// \param [in] size                A QSize to capture.
        ///
        void align(const QPainterPath& scrollPath,
                   const qreal scrollOrigin,
                   const qreal scrollLength,
                   const QList<BezierScrollerItem*> items,
                   const qreal linearStep,
                   const qreal cubicStep,
                   QSizeF& size);
        
        ///
        /// \brief Starts a drag session.
        ///
        /// \param [in] event       Qt event object.
        ///
        void beginDrag(const QGraphicsSceneMouseEvent* event);
        
        ///
        /// \brief Updates a drag session.
        ///
        /// \param [in] event       Qt event object.
        ///
        void updateDrag(const QGraphicsSceneMouseEvent* event);
        
    public: // Reimplemented.
        
        ///
        /// \brief Reimplemented from QGraphicsItem::mouseReleaseEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::mouseReleaseEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::mouseReleaseEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
        
        ///
        /// \brief Mouse event filter.
        ///
        /// \param [in] obj         The obj recieving the event.
        /// \param [in] event       The Qt event delivered.
        ///
        bool eventFilter(QObject *obj, QEvent *event);
        
    private:
        
        ///
        /// \brief Content size.
        ///
        QSizeF _contentSize;
        
        ///
        /// \brief Flipped state.
        ///
        bool _flipped;
        
        ///
        /// \brief Scroll control handle.
        ///
        QGraphicsPathItem _scrollControlItem;
        
        ///
        /// \brief Scroll enabled state.
        ///
        bool _scrollEnabled;
        
        ///
        /// \brief Scroll origin.
        ///
        qreal _scrollOrigin;
        
        ///
        /// \brief Scroll position.
        ///
        qreal _scrollPosition;
        
        ///
        /// \brief Scroll length.
        ///
        qreal _scrollLength;
        
        ///
        /// \brief Padding scale.
        ///
        qreal _paddingScale;
        
        ///
        /// \brief Linear scroll step.
        ///
        qreal _linearScrollStep;
        
        ///
        /// \brief Cubic scroll step.
        ///
        qreal _cubicScrollStep;
        
        ///
        /// \brief Scroll path.
        ///
        QPainterPath _scrollPath;
        
        ///
        /// \brief Utility path used for dragging.
        ///
        QPainterPath _utilityPath;
        
        ///
        /// \brief Utility path segements used for dragging.
        ///
        QList<QPainterPath> _utilityPathSegments;
        
        ///
        /// \brief Drag enabled state.
        ///
        bool _dragEnabled;
        
        ///
        /// \brief Drag location.
        ///
        QPointF _dragLocation;
        
        ///
        /// \brief Drag location offset.
        ///
        qreal _dragLocationOffset;
        
        ///
        /// \brief Dragging item index.
        ///
        int _dragItemIndex;
        
        ///
        /// \brief Drag tracking item index.
        ///
        int _dragTrackingIndex;
        
        ///
        /// \brief Drag animations buffer.
        ///
        QMap<int, BezierScrollerAnimation*> _dragAnimations;
        
        ///
        /// \brief The BezierScrollerItem(s) cache.
        ///
        QList<BezierScrollerItem*> _items;
    };
}

#endif


