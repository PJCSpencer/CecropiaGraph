//
//  sdmSimpleImageItem.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 20/02/2016.
//
//

#include "sdmSimpleImageItem.h"

#include <iostream>


namespace spencers
{
    SimpleImageItem::SimpleImageItem(const QSizeF size, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _icon()
    , _iconSize(size)
    , _backgroundShape(SimpleShape::NoShape)
    , _backgroundShapeBorder(QSizeF())
    , _backgroundShapeColor(Qt::transparent)
    , _backgroundClipping(false)
    {
    }
    
    
    void SimpleImageItem::setIcon(QIcon& icon)
    {
        _icon.swap(icon);
        
        QGraphicsObject::update();
    }
    
    
    void SimpleImageItem::setIconSize(const QSize& size)
    {
        _iconSize = QSize(size);
        
        QGraphicsObject::update();
    }
    
    
    void SimpleImageItem::setBackgroundShape(const SimpleShape shape)
    {
        _backgroundShape = shape;
        
        QGraphicsObject::update();
    }
    
    
    void SimpleImageItem::setBackgroundShapeBorder(const QSizeF size)
    {
        _backgroundShapeBorder = QSizeF(size);
        
        QGraphicsObject::update();
    }
    
    
    void SimpleImageItem::setBackgroundShapeColor(const QColor& color)
    {
        _backgroundShapeColor = QColor(color);
        
        QGraphicsObject::update();
    }
    
    
    void SimpleImageItem::setBackgroundClipping(bool enabled)
    {
        _backgroundClipping = enabled;
        
        QGraphicsObject::update();
    }
    
    
    QRectF SimpleImageItem::boundingRect() const
    {
        return QRectF(QPointF(0, 0), _iconSize + _backgroundShapeBorder);
    }
    
    
    void SimpleImageItem::paint(QPainter *painter,
                                const QStyleOptionGraphicsItem *option,
                                QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        
        if (_backgroundShape != SimpleShape::NoShape)
        {
            painter->setPen(Qt::NoPen);
            painter->setBrush(_backgroundShapeColor);
            QPainterPath path = QPainterPath();
            
            switch (_backgroundShape)
            {
                case SimpleShape::Circle:
                    path.addEllipse(boundingRect());
                    break;
                
                case SimpleShape::Square:
                    path.addRect(boundingRect());
                    break;
                    
                default:
                    break;
            }
            
            painter->drawPath(path);
            
            if (_backgroundClipping)
            {
                painter->setClipPath(path);
            }
        }
        
        auto scale = 0.5f;
        auto rect = QRect(boundingRect().left() + (_backgroundShapeBorder.width() * scale),
                          boundingRect().top() + (_backgroundShapeBorder.height() * scale),
                          _iconSize.width(),
                          _iconSize.height());
        
        auto scaled = QSize(_iconSize.width() * painter->transform().m11(),
                            _iconSize.height() * painter->transform().m22());
        
        QPixmap pixmap = _icon.pixmap(scaled);
        painter->drawPixmap(rect, pixmap);
    }
}


