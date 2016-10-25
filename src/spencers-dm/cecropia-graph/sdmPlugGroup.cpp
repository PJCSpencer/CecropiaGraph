//
//  sdmPlugGroup.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 02/05/2016.
//
//

#include "sdmPlugGroup.h"

#include <QtWidgets>

#include "sdmNodeScene.h"
#include "sdmPlug.h"
#include "sdmStyles.h"


namespace spencers
{
    qreal PlugGroup::_padding = 5.0f;
    QMargins PlugGroup::_borderMargins = QMargins(24, 20, 30, 20);
    qreal PlugGroup::_penWidth = 1.75f;
    
    
    PlugGroup::PlugGroup(QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _plugs(QList<Plug*>())
    , _uid(-1)
    , _target("Undefined")
    , _isExpanded(false)
    , _pen(QPen(Styles::downtownColor, _penWidth, Qt::SolidLine, Qt::FlatCap))
    , _brush(Styles::downtownColor)
    {
        setAcceptHoverEvents(true);
        setFlag(QGraphicsItem::ItemIsSelectable);
    }
    
    
    PlugGroup::~PlugGroup()
    {
        removeAllPlugs();
    }
    
    
    auto PlugGroup::plugs() -> const QList<Plug*>
    {
        return _plugs;
    }
    
    
    void PlugGroup::addPlug(Plug* plug)
    {
        if (plug == nullptr)
            return;

        // Configure and buffer.
        plug->setParentItem(this);
        plug->setPos(0, 0);
        plug->setVisible(false, false);
        
        _plugs.append(plug);
    }
    
    
    void PlugGroup::removePlug(Plug* plug)
    {
        if (plug == nullptr)
            return;

        _plugs.removeOne(plug);
        
        plug->setParentItem(nullptr);
        scene()->removeItem(plug);
        
        QGraphicsItem::update();
    }
    
    
    void PlugGroup::removeAllPlugs()
    {
        foreach (Plug* plug, _plugs)
        {
            removePlug(plug);
        }
    }
    
    
    void PlugGroup::setTarget(const QString& target)
    {
        _target = QString(target);
    }
    
    
    QPainterPath PlugGroup::shape() const
    {
        QPainterPath path;
        path.addEllipse(boundingRect());
        
        return path;
    }
    
    
    QRectF PlugGroup::boundingRect() const
    {
        auto count = _isExpanded ? childItems().count() : 1;
        auto radius = Plug::shapeRadius();
        auto margins = _isExpanded ? _borderMargins : QMargins();
        
        return QRectF(0.0f, 0.0f, radius * count, radius).marginsAdded(margins);
    }
    
    
    void PlugGroup::paint(QPainter *painter,
                                   const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        auto sRadius = Plug::shapeRadius();
            
        painter->setPen(_pen);
        painter->setBrush(Qt::NoBrush);
        painter->drawEllipse(QRectF(QPointF(), QSizeF(sRadius, sRadius)));
        
        if (_plugs.count() >= 1)
        {
            sRadius = Plug::shapeRadius() * 0.5f;
            auto pRadius = Plug::pinRadius * 0.5f;
            auto dxy = sRadius - pRadius;
            auto rect = QRectF(dxy, dxy, Plug::pinRadius, Plug::pinRadius);
            
            painter->setPen(Qt::NoPen);
            painter->setBrush(_brush);
            painter->drawEllipse(rect);
        }
    }
    
    
    void PlugGroup::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
    {
        if (QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            _isExpanded = true;
            QGraphicsItem::update();
            
            auto dx = 0.0f;
            auto delay = 0;
            
            for (Plug* object : _plugs)
            {
                object->setPos(dx, 0.0f);
                object->setVisible(true, true, delay);
                
                // sequence->addPause(250);
                
                dx += Plug::shapeRadius();
                dx += _padding;
                
                delay += 100;
            }
        }
        
        QGraphicsItem::hoverEnterEvent(event);
    }
    
    
    void PlugGroup::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
    {
        if (_isExpanded)
        {
            _isExpanded = false;
            QGraphicsItem::update();
            
            for (Plug* object : _plugs)
            {
                object->setPos(0.0f, 0.0f);
                object->setVisible(false, true);
            }
        }
        
        QGraphicsItem::hoverLeaveEvent(event);
    }
    
    
    void PlugGroup::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
    {
        if (_isExpanded)
        {
            // Find nearest legit column.
            auto area = event->pos().x() / (Plug::shapeRadius() + _padding);
            auto region = ceil(area) - 1;
            
            if (region < _plugs.count())
            {
                emit plugGroupDetached(*this, _plugs[region]);
            }
        }
        else
        {
            emit plugGroupChanged(*this);
        }
    }
}


