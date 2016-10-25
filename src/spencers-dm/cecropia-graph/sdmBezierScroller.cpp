//
//  sdmBezierScroller.cpp
//  QtProject-Template
//
//  Created by Peter JC Spencer on 17/01/2016.
//
//

#include "sdmBezierScroller.h"

#include <QtWidgets>


namespace spencers
{
    qreal BezierScroller::scrollBarControlRadius = 8.0f;
    qreal BezierScroller::scrollBarGutterRadius = 4.0f;
    qreal BezierScroller::scrollInterpolation = 0.0016f; // 0.001
    qreal BezierScroller::scrollItemPadding = 2.0f;
    qreal BezierScroller::dragInterpolation = 0.0115;
    int BezierScroller::dragAnimationDuration = 300;
    
    
    BezierScroller::BezierScroller(const qreal origin, const qreal length, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _flipped(true)
    , _scrollControlItem(this)
    , _scrollEnabled(false)
    , _scrollOrigin(origin)
    , _scrollPosition(0.0f)
    , _scrollLength(length)
    , _paddingScale(1.0)
    , _dragEnabled(false)
    , _dragAnimations()
    , _items(QList<BezierScrollerItem*>())
    {
        setAcceptedMouseButtons(Qt::LeftButton);
        
        // Configure scroll bar control.
        auto radius = BezierScroller::scrollBarControlRadius;
        auto scaledRadius = radius * 0.5f;
        
        QPainterPath path = QPainterPath();
        path.addEllipse(QRect(-scaledRadius, -scaledRadius, radius, radius));
        
        _scrollControlItem.setPath(path);
        _scrollControlItem.setPen(Qt::NoPen);
        _scrollControlItem.setBrush(Styles::silverStreakColor);
    }
    
    
    BezierScroller::~BezierScroller()
    {
        _dragAnimations.clear();
        removeAllItems();
    }
    
    
    void BezierScroller::setScrollPath(const QPainterPath& path)
    {
        auto shift = scrollBarControlRadius * 0.5f;
        
        _scrollPath = QPainterPath(path);
        _scrollPath.translate(shift, shift);
        
        // updateContentSize();
        scroll(0);
    }
    
    
    void BezierScroller::setScrollControlColour(const QColor& color)
    {
        _scrollControlItem.setBrush(color);
    }
    
    
    void BezierScroller::setPaddingScale(const qreal scale)
    {
        _paddingScale = scale;
        
        // updateContentSize();
        scroll(0);
    }
    
    
    void BezierScroller::position(const qreal unit)
    {
        _scrollOrigin = unit;
        _scrollOrigin = _scrollOrigin < 0.0f ? 1.0f : _scrollOrigin;
        _scrollOrigin = _scrollOrigin  > 1.0 ? 0.0f : _scrollOrigin;
        
        scroll(0);
    }
    
    
    void BezierScroller::translate(const qreal shift) // TODO:Support 'wrapping' ...
    {
        _scrollOrigin += shift;
        _scrollOrigin = _scrollOrigin < 0.0f ? 1.0f : _scrollOrigin;
        _scrollOrigin = _scrollOrigin  > 1.0 ? 0.0f : _scrollOrigin;
        
        scroll(0);
    }
    
    
    void BezierScroller::scroll(const qreal shift) // TODO:Resolve oversampling, support 'wrapping' ...
    {
        if (_items.isEmpty())
        {
            return;
        }
        
        auto length = _scrollPath.length();
        auto start = 0.0f;
        auto end = (length * _scrollLength);
        auto frame = _scrollPosition + shift > 1.0f ? 1.0f : _scrollPosition + shift;
        frame = frame < 0.0f ? 0.0f : frame;
        
        // Linear interpolation.
        auto result = start + frame * (end - start);
        
        // Wrap scroll position if scrollWrapEnabled when translating.
        if (result > (end - contentSize().height()))
        {
            result = start + _scrollPosition * (end - start);
        }
        else
        {
            _scrollPosition = frame;
        }
        
        // Add scroll origin.
        result += (_scrollPath.length() * _scrollOrigin);
        if (result > length)
        {
            result = (result - length);
        }
        
        // Interpolate control.
        auto percent = _scrollPath.percentAtLength(result);
        _scrollControlItem.setPos(_scrollPath.pointAtPercent(percent));
        
        // Interpolate all item(s).
        align(_scrollPath,
              result,
              contentInset(),
              _items,
              _linearScrollStep,
              _cubicScrollStep,
              _contentSize);
    }
    
    
    void BezierScroller::align(const QPainterPath& scrollPath,
                               const qreal scrollOrigin,
                               const qreal scrollLength,
                               const QList<BezierScrollerItem*> scrollItems,
                               const qreal linearStep,
                               const qreal cubicStep,
                               QSizeF& size) // TODO:Resolve curve interpolation ...
    {
        if (scrollPath.isEmpty() || scrollItems.isEmpty())
        {
            return;
        }

        qreal percent;
        qreal slope;
        qreal angle;
        auto t = scrollOrigin;
        auto step = scrollLength;
        auto interpolatedStep = (linearStep - cubicStep);
        BezierScrollerItem* scrollerItem = nullptr;
        qreal scrollerItemWidth;
        
        size = QSizeF(0.0f, 0.0f);
        
        for (auto i = 0; i < scrollItems.count(); i ++)
        {
            scrollerItem = scrollItems[i];

            if (i > 0)
            {
                // Make a temporary move along the path.
                percent = scrollPath.percentAtLength(t + (step * 0.5f));
                
                // Interpolate between line and curve.
                slope = scrollPath.slopeAtPercent(percent);
                slope = slope < -1.0 ? -1.0 : slope;
                slope = slope > 1.0 ? 1.0 : slope;
                
                // Evaluate actual step.
                step = (linearStep - (interpolatedStep * fabs(slope)));
            }
            
            // Over-sampling.
            if ((t + step) > scrollPath.length())
            {
                t = (t + step) - scrollPath.length();
            }
            else
            {
                t += step;
            }
            
            // Cache size, item(s) are stacked top-to-bottom like so (.!!!).
            scrollerItemWidth = scrollerItem->boundingSize().width();
            size.setWidth(scrollerItemWidth > size.width() ? scrollerItemWidth : size.width());
            size.setHeight(size.height() + step);
            
            // Apply.
            percent = scrollPath.percentAtLength(t);
            
            // TODO:Support 'rotation offset' memeber variable ..?
            angle = scrollPath.angleAtPercent(percent);
            angle += _flipped ? 90.0f : 270.0f;
            
            // Transform scroller item.
            scrollerItem->setLengthToPos(t);
            scrollerItem->update(scrollPath.pointAtPercent(percent),
                                 -angle);
        }
    }
    
    
    auto BezierScroller::contentInset() -> qreal
    {
        if (_items.isEmpty())
        {
            return 0.0f;
        }
        return (scrollBarControlRadius * 0.5f) + (_items[0]->boundingRect().height() * 0.5f);
    }
    
    
    auto BezierScroller::contentLength() -> qreal
    {
        auto size = contentSize();
        
        return QLineF(QPointF(), QPointF(size.width(), size.height())).length();
    }
    
    
    auto BezierScroller::contentSize() -> QSize
    {
        return QSize(_contentSize.toSize());
    }
    
    
    auto BezierScroller::absoluteContentSize() -> QSize
    {
        return contentSize() + QSize(0, contentInset());
    }
    
    
    void BezierScroller::addItem(BezierScrollerItem* scrollerItem)
    {
        // Configured item.
        scrollerItem->setParentItem(this);
        scrollerItem->installEventFilter(this);
        
        // Cache linear and cubic interpolation steps.
        if (_items.count() == 0)
        {
            _linearScrollStep = scrollerItem->boundingSize().height() + BezierScroller::scrollItemPadding;
            _cubicScrollStep = _linearScrollStep * _paddingScale; // TODO:Resolve dynamically ...
        }
        _items.append(scrollerItem);
        
        // Distribute along scroll path.
        scroll(0);
    }
    
    
    void BezierScroller::addItems(QList<BezierScrollerItem*>& scrollerItems)
    {
        foreach (BezierScrollerItem* object, scrollerItems)
        {
            addItem(object);
        }
    }
    
    
    void BezierScroller::removeAllItems()
    {
        _items.clear();
        
        scroll(0);
    }
    
    
    void BezierScroller::setItemsVisible(const bool visible, const bool animate)
    {
        Q_UNUSED(visible);
        Q_UNUSED(animate);
    }
    
    
    QRectF BezierScroller::boundingRect() const
    {
        return QRectF(0.0f,
                      0.0f,
                      _scrollPath.boundingRect().width() + BezierScroller::scrollBarControlRadius,
                      _scrollPath.boundingRect().height() + BezierScroller::scrollBarControlRadius);
    }
    
    
    void BezierScroller::paint(QPainter *painter,
                                   const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    
    
    void BezierScroller::mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        auto radius = BezierScroller::scrollBarControlRadius * 0.5f;
        QPointF edge = QPointF(_scrollControlItem.pos().x() + radius,
                               _scrollControlItem.pos().y() + radius);
        QLineF mLine(_scrollControlItem.pos(), event->pos().toPoint());
        QLineF rLine(_scrollControlItem.pos(), edge);
        
        _scrollEnabled = (mLine.length() <= rLine.length() ? true : false);
        
        if (!_scrollEnabled)
        {
            QGraphicsObject::mousePressEvent(event);
        }
    }
    
    
    void BezierScroller::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
    {
        if (_scrollEnabled)
        {
            // TODO:Multi-directional support ...
            
            
            scroll((event->pos().x() - event->lastPos().x()) * BezierScroller::scrollInterpolation);
        }
        else
        {
            QGraphicsObject::mouseMoveEvent(event);
        }
    }
    
    
    void BezierScroller::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
    {
        if (_dragEnabled || _scrollEnabled)
        {
            _dragEnabled = false;
            _scrollEnabled = false;
        }
        else
        {
            QGraphicsObject::mouseReleaseEvent(event);
        }
    }
    
    
    bool BezierScroller::eventFilter(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::GraphicsSceneMousePress
            && QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            // TODO:Scale scroll path ...
            
            int count = _items.count() - 1;
            if (count <= 0)
            {
                return false;
            }
            
            QGraphicsSceneMouseEvent *cEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
            if (cEvent && obj)
            {
                BezierScrollerItem* cScrollerItem = qobject_cast<BezierScrollerItem*>(obj);
                cScrollerItem->setZValue(count);
            
                _dragEnabled = true;
                _dragItemIndex = _items.indexOf(cScrollerItem);
                _dragTrackingIndex = _dragItemIndex;
            
                /* TODO:Introduce _path.angleAtPercent() for a more comfortable UX, line would
                 then be perpendicular to item. Also the reason why points are part supported ..? */
                
                // Use local coordinates to help calculate offset.
                auto dy = cEvent->pos().y();
                auto column = cScrollerItem->boundingSize().height();
                auto chunk = column * _dragItemIndex;
                
                _dragLocationOffset = (dy >= 0 ? chunk + dy : chunk - fabs(dy));
                _dragLocation = QPointF(QCursor::pos().x() - _dragLocationOffset, 0.0f);
                
                beginDrag(nullptr);
            }
        }
        else if (event->type() == QEvent::GraphicsSceneMouseMove
            && _dragEnabled)
        {
            updateDrag(nullptr);
        }
        else if (event->type() == QEvent::GraphicsSceneMouseRelease
                 && _dragEnabled)
        {
            _dragEnabled = false;
            
            // Modify indexes.
            _items.move(_dragItemIndex, _dragTrackingIndex);
            
            scroll(0);
        }
        
        return QObject::eventFilter(obj, event);
    }
    
    
    void BezierScroller::beginDrag(const QGraphicsSceneMouseEvent* event)
    {
        Q_UNUSED(event);
        
        qreal l0, l1;
        qreal p0, p1;
        qreal step;
        QPointF startPoint, endPoint, ctrlPt;
        
        // Clear the cache.
        _utilityPath = QPainterPath();
        _utilityPathSegments.clear();
        
        for (auto i = 0; i < _items.count() - 1; i ++)
        {
            l0 = _items[i]->lengthToPos();
            p0 = _scrollPath.percentAtLength(l0);
            startPoint = _scrollPath.pointAtPercent(p0);
            
            l1 = _items[i+1]->lengthToPos();
            p1 = _scrollPath.percentAtLength(l1);
            endPoint = _scrollPath.pointAtPercent(p1);
            
            _utilityPathSegments.append(QPainterPath());
            _utilityPathSegments[i].moveTo(startPoint);
            
            if (_utilityPath.isEmpty())
            {
                _utilityPath.moveTo(startPoint);
            }
            
            if (_scrollPath.slopeAtPercent(p0) || _scrollPath.slopeAtPercent(p1))
            {
                step = ((l0 < l1) ? (l1 - l0) : (_scrollPath.length() - l0) + l1) * 0.5f;
                p0 = _scrollPath.percentAtLength(l0 + step);
                ctrlPt = _scrollPath.pointAtPercent(p0);
                
                _utilityPathSegments[i].cubicTo(ctrlPt, ctrlPt, endPoint);
                _utilityPath.cubicTo(ctrlPt, ctrlPt, endPoint);
            }
            else
            {
                _utilityPathSegments[i].lineTo(endPoint);
                _utilityPath.lineTo(endPoint);
            }
        }
    }
    
    
    void BezierScroller::updateDrag(const QGraphicsSceneMouseEvent* event)
    {
        Q_UNUSED(event);
        
        // Because item(s) are rotated global coordinates are used to evaluate ramp/slope.
        auto dx = QCursor::pos().x();
        auto column = _items[0]->boundingSize().height();
        auto length = contentSize().height() - column;
        
        auto distance = QLineF(_dragLocation, QPointF(dx, 0.0f)).length();
        distance = distance > length ? length : distance;
        distance = dx < _dragLocation.x() ? 0.0f : distance;
        
        // Interpolate.
        auto shift = 1.0f / length * distance;
        
        // Update drag position.
        length = _utilityPath.length() * shift;
        auto size = QSizeF();
        
        // Distribute.
        align(_utilityPath,
              length,
              0,
              _items.mid(_dragItemIndex, 1),
              _linearScrollStep,
              _cubicScrollStep,
              size);
        
        auto count = _items.count() - 1;
        auto index = round(count * shift);
        
        if (_dragTrackingIndex == index)
        {
            return;
        }
        
        // Query indexes.
        auto shiftIndexes = _dragTrackingIndex > _dragItemIndex ? true : false;
        auto dragIsLeft = _dragTrackingIndex > index ? true : false;
        
        auto itemIndex = 0;
        auto toIndex = 0;
        
        // Configure animation indexes.
        if (dragIsLeft)
        {
            itemIndex = shiftIndexes ? index + 1 : index;
            toIndex = index;
        }
        else
        {
            itemIndex = index;
            toIndex = index < _dragTrackingIndex ? index + 1 : index - 1;
        }
        
        // int itemIndex = (shiftIndexes && dragIsLeft) ? index + 1 : index;
        // int toIndex = dragIsLeft ? index : index - 1; // index < _dragTrackingIndex ? index + 1 : index - 1;
        int pathIndex = itemIndex > toIndex ? toIndex : itemIndex;
        
        // Update tracking index.
        _dragTrackingIndex = index;
        
        // Configure animation value(s).
        auto fromValue = dragIsLeft ? 0.0f : 1.0f;
        auto toValue = fromValue >= 1.0f ? 0.0f : 1.0f;
        
        /*std::cout
        << "shiftIndexes:" << shiftIndexes
        << ", dragIsLeft:" << dragIsLeft
        << ", _dragItemIndex:" << _dragItemIndex
        << ", _dragTrackingIndex:" << _dragTrackingIndex
        << ", itemIndex:" << itemIndex
        << ", toIndex:" << toIndex
        << ", pathIndex:" << pathIndex
        << ", fromValue:" << fromValue
        << ", toValue:" << toValue
        << "\n"
        << std::endl;*/
        
        // Create an animation.
        unique_ptr<BezierScrollerAnimation> animation = nullptr;
        animation = make_unique<BezierScrollerAnimation>(itemIndex,
                                                         pathIndex,
                                                         BezierScroller::dragAnimationDuration);
        
        connect(animation.get(),
                SIGNAL(valueChanged(BezierScrollerAnimation*)),
                this,
                SLOT(animationChanged(BezierScrollerAnimation*)));
        
        animation->setFromValue(fromValue);
        animation->setToValue(toValue);
        animation->start();
        animation.release();
    }
    
    
    void BezierScroller::animationChanged(BezierScrollerAnimation* animation)
    {
        auto path = _utilityPathSegments[animation->utilityIndex()];
        auto length = path.length() * animation->value();
        auto size = QSizeF();
        
         align(path,
              length,
              0,
              _items.mid(animation->itemIndex(), 1),
              _linearScrollStep,
              _cubicScrollStep,
              size);
    }
}


