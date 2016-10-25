//
//  sdmPlug.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 10/05/2016.
//
//

#include "sdmPlug.h"

#include "sdmPlugGroup.h"
#include "sdmPlugConnection.h"
#include "sdmStyles.h"


namespace spencers
{
    qreal Plug::pinRadius = 4.5f;
    qreal Plug::paddingRadius = 5.5f;
    

    Plug::Plug(PlugConnection& owner, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _owner(owner)
    {
    }
    
    
    Plug::~Plug()
    {
        detach();
    }
    
    
    QPainterPath Plug::shape() const
    {
        QPainterPath path;
        path.addEllipse(boundingRect());
        
        return path;
    }
    
    
    auto Plug::shapeRadius() -> qreal
    {
        return Plug::pinRadius + Plug::paddingRadius;
    }
    
    
    void Plug::setColour(const QColor& color)
    {
        Q_UNUSED(color);
    }
    
    
    void Plug::detach()
    {
        if (auto object = group())
        {
            object->removePlug(this);
        }
    }
    
    
    auto Plug::group() const -> PlugGroup*
    {
        if (auto object = dynamic_cast<PlugGroup*>(parentItem()))
        {
            return object;
        }
        return nullptr;
    }
    
    
    auto Plug::connection() const -> PlugConnection&
    {
        // Ref: http://www.boost.org/doc/libs/1_48_0/libs/smart_ptr/weak_ptr.htm
        return _owner;
    }
    
    
    auto Plug::centre() -> const QPointF
    {
        auto radius = Plug::shapeRadius() * 0.5f;
        return mapToScene(QPointF(radius, radius));
    }
    
    
    void Plug::setVisible(bool visible, bool animated, const int delay, const int duration)
    {
        if (animated)
        {
            auto opacity = visible ? 0.0 : 1.0;
            
            if (_effect != nullptr)
            {
                opacity = _effect->opacity();
                
                _effect.release();
                _animation.release();
            }
            
            _effect = make_unique<QGraphicsOpacityEffect>(this);
            _effect->setOpacity(opacity);
            
            setGraphicsEffect(_effect.get());
            
            _animation = make_unique<QPropertyAnimation>(_effect.get(), "opacity");
            _animation->setEasingCurve(QEasingCurve::InOutElastic);
            _animation->setDuration(duration + delay);
            _animation->setStartValue(visible ? 0.0 : 1.0);
            _animation->setEndValue(visible ? 1.0 : 0.0);
            _animation->start();
        }
        
        QGraphicsItem::setVisible(visible);
        
        _owner.updatePath(); // NB:Just a little hack.
    }
    
    
    QRectF Plug::boundingRect() const
    {
        auto radius = Plug::shapeRadius();
        return QRectF(0.0f, 0.0f, radius, radius);
    }
    
    
    void Plug::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        
        auto sRadius = Plug::shapeRadius() * 0.5f;
        auto pRadius = Plug::pinRadius * 0.5f;
        auto dxy = sRadius - pRadius;
        auto rect = QRectF(dxy, dxy, Plug::pinRadius, Plug::pinRadius);
        
        painter->setPen(Qt::NoPen);
        painter->setBrush(Styles::downtownColor);
        painter->drawEllipse(rect);
        
        painter->setPen(QPen(Styles::downtownColor, 1.75f));
        painter->setBrush(Qt::NoBrush);
        painter->drawEllipse(boundingRect());
    }
}


