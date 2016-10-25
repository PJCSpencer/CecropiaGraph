//
//  sdmPlugConnection.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 23/05/2016.
//
//

#include "sdmPlugConnection.h"

#include <QtMath>

#include "sdmPlug.h"
#include "sdmPlugGroup.h"
#include "sdmStyles.h"
#include "sdmPainterPathUtility.h"


namespace spencers
{
    int PlugConnection::_minimumPathLengthForVisiblity = 30;
    
    
    PlugConnection::PlugConnection(QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _path(QPainterPath())
    , _directionPathItem(this)
    , _sourcePlug(make_unique<Plug>(*this))
    , _destinationPlug(make_unique<Plug>(*this))
    {
        _directionPathItem.setPen(Qt::NoPen);
        _directionPathItem.setBrush(Styles::downtownColor);
        _directionPathItem.setPath(PainterPathUtility::createTrianglePath(3, 0, QSize(11, 11), 1));
    }
    
    
    PlugConnection::~PlugConnection()
    {
        _sourcePlug->detach();
        _destinationPlug->detach();
    }
    
    
    auto PlugConnection::otherPlug(const Plug& plug) -> Plug&
    {
        if (&plug == _destinationPlug.get())
        {
            return *_sourcePlug.get();
        }
        return *_destinationPlug.get();
    }
    
    
    auto PlugConnection::detachedPlug() -> Plug&
    {
        if (_sourcePlug->group() == nullptr)
        {
            return *_sourcePlug.get();
        }
        return *_destinationPlug.get();
    }
    
    
    void PlugConnection::updatePath()
    {
        if (_sourcePlug->group() && _destinationPlug->group())
        {
            QGraphicsObject::prepareGeometryChange();
        
            QPainterPath path;
            path.moveTo(_sourcePlug->centre());
            path.lineTo(_destinationPlug->centre());
            _path.swap(path);
        }
        
        updateDirection();
    }
    
    
    void PlugConnection::updatePath(const QPointF& startPoint, const QPointF& endPoint)
    {
        QGraphicsObject::prepareGeometryChange();
        
        QPainterPath path;
        path.moveTo(startPoint);
        path.lineTo(endPoint);
        _path.swap(path);
        
        updateDirection();
    }
    
    
    void PlugConnection::updateDirection() // TODO:Resolve ...
    {
        auto plugGroup = _sourcePlug->group() ? _sourcePlug->group() : _destinationPlug->group();
        
        auto pt = mapToItem(plugGroup, _path.currentPosition());
        auto rotation = atan2 (pt.y(), pt.x());
        rotation += qDegreesToRadians(plugGroup->parentItem()->rotation());
        
        _directionPathItem.setVisible(pt.manhattanLength() > _minimumPathLengthForVisiblity ? true : false);
        _directionPathItem.setPos(_path.pointAtPercent(0.5f));
        _directionPathItem.setRotation(qRadiansToDegrees(rotation));
    }
    
    
    QRectF PlugConnection::boundingRect() const
    {
        return _path.boundingRect().marginsAdded(QMargins(1, 1, 1, 1));
    }
    
    
    void PlugConnection::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
    {
        Q_UNUSED(widget);
        Q_UNUSED(option);
        
        /*QPen pen = Styles::downtownDashedPen;
        
        auto gutter = 3;
        auto space = gutter * pen.width();
        auto length = (_path.length() - (2 * gutter)) * pen.width();
        
        QVector<qreal> pattern;
        pattern << 1 << space << length - (space * 2) << 0 << 1 << space;
        
        pen.setDashPattern(pattern);*/
        
        painter->setPen(Styles::downtownDashedPen);
        painter->setClipRect(option->exposedRect);
        painter->drawPath(_path);
    }
}


