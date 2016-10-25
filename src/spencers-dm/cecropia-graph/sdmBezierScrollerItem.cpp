//
//  sdmBezierScrollerItem.cpp
//  QtProject-Template
//
//  Created by Peter JC Spencer on 25/01/2016.
//
//

#include "sdmBezierScrollerItem.h"

#include <QtWidgets>

#include "sdmPlug.h"
#include "sdmPlugConnection.h" // Hmmm.


namespace spencers
{
    qreal BezierScrollerItem::plugGroupOffset = 3.0f;
    qreal BezierScrollerItem::dragInProgressAlpha = 0.4f;
    QMargins BezierScrollerItem::contentMargins = QMargins(6, 2.5f, 6, 2.5f);
    
    
    BezierScrollerItem::BezierScrollerItem(QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _backgroundPathItem(this)
    , _simpleTextItem(this)
    , _plugGroup(make_unique<PlugGroup>(this))
    {
        _backgroundPathItem.setPen(Qt::NoPen);
        _backgroundPathItem.setBrush(Styles::lushPinkColor);
        _backgroundPathItem.setPos(0, 0);
        
        _simpleTextItem.setFont(*Styles::defaultFont(QFont::DemiBold));
        _simpleTextItem.setBrush(Styles::whiteColor(240));
        _simpleTextItem.setPos(0, 0);
    }
    
    
    auto BezierScrollerItem::title() -> const QString
    {
        return _simpleTextItem.text();
    }
    
    
    void BezierScrollerItem::setTitle(const QString& string)
    {
        _simpleTextItem.setText(string);
        
        setTitleInset(0);
    }
    
    
    void BezierScrollerItem::setTitleInset(const qreal inset)
    {
        auto scale = 0.5f;
        auto width = _simpleTextItem.boundingRect().width();
        auto height = _simpleTextItem.boundingRect().height();
        
        _simpleTextItem.setTransformOriginPoint(width * scale, height * scale);
        _simpleTextItem.setPos(inset, -(height * scale));
    }
    
    
    void BezierScrollerItem::setTitleColour(const QColor& color)
    {
        _simpleTextItem.setBrush(color);
    }
    
    
    auto BezierScrollerItem::plugGroup() const -> PlugGroup*
    {
        return _plugGroup.get();
    }
    
    
    void BezierScrollerItem::setPlugGroupTarget(const QString& target)
    {
        _plugGroup->setTarget(target);
    }
    
    
    auto BezierScrollerItem::sizeForString(const QString& string) -> QSize
    {
        QFontMetrics fontMetrics (*Styles::defaultFont(QFont::DemiBold));
        
        return QSize(fontMetrics.boundingRect(string).width(),
                     fontMetrics.tightBoundingRect("qtypdfghjklb").height()); // Uniform.
    }
    
    
    auto BezierScrollerItem::sizeHeight(/* TODO:const QMargins margins = QMargins() ... */) -> qreal
    {
        return BezierScrollerItem::sizeForString("qtypdfghjklb").height();
    }
    
    
    void BezierScrollerItem::setBackgroundPath(const QPainterPath& path)
    {
        _backgroundPathItem.setPath(path);
        _backgroundPathItem.setPos(0.0f, -(path.boundingRect().height() * 0.5f));
        
        _plugGroup->setPos(_backgroundPathItem.boundingRect().width() + plugGroupOffset,
                           -(_plugGroup->boundingRect().height() * 0.5f));
    }
    
    
    void BezierScrollerItem::setBackgroundBrush(const QBrush& brush)
    {
        _backgroundPathItem.setBrush(brush);
    }
    
    
    void BezierScrollerItem::setBackgroundPen(const QPen& pen)
    {
        _backgroundPathItem.setPen(pen);
    }
    
    
    void BezierScrollerItem::update(const QPointF pos, const qreal rotation)
    {
        setPos(pos);
        setRotation(rotation);
        
        foreach (Plug* plug, _plugGroup->plugs())
        {
            plug->connection().updatePath();
        }
    }
    
    
    void BezierScrollerItem::setRotation(qreal angle)
    {
        auto fangle = fabs(angle);
        
        // Item(s) text should always read left to right.
        if (fangle > 90 && fangle <= 270)
            _simpleTextItem.setRotation(180);
        
        else if (fangle >= 90)
            _simpleTextItem.setRotation(0);
        
        QGraphicsItem::setRotation(angle);
    }
    
    
    auto BezierScrollerItem::boundingSize() -> const QSizeF
    {
        return _backgroundPathItem.boundingRect().size();
    }
    
    
    QRectF BezierScrollerItem::boundingRect() const
    {
        auto size = _backgroundPathItem.boundingRect().size();
        
        return QRectF(0.0f,
                      -(size.height() * 0.5f),
                      size.width(),
                      size.height());
    }
    
    
    void BezierScrollerItem::paint(QPainter *painter,
                                   const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    
    
    void BezierScrollerItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        if (QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            event->accept();
            setOpacity(dragInProgressAlpha);
        }
        else
            QGraphicsObject::mousePressEvent(event);
    }
    
    
    void BezierScrollerItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
    {
        setOpacity(1.0f);
        QGraphicsObject::mousePressEvent(event);
    }
}


