//
//  sdmPlugConnectionWidget.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 11/07/2016.
//
//

#include "sdmPlugConnectionWidget.h"

#include <QtWidgets>

#include "sdmNodeControl.h"
#include "sdmPlugGroup.h"
#include "sdmPlug.h"
#include "sdmPlugConnection.h"


namespace spencers
{
    PlugConnectionWidget::PlugConnectionWidget(QGraphicsScene& graphicsScene, bool isVisible)
    : QGraphicsObject(nullptr)
    , _scene(&graphicsScene)
    , _cache(QList<PlugConnection*>())
    , _liveConnection(nullptr)
    {
        setFlag(QGraphicsItem::ItemIsFocusable);
        setAcceptHoverEvents(true);
        
        if (isVisible)
            _scene->addItem(this);
    }
    
    
    PlugConnectionWidget::~PlugConnectionWidget()
    {
        _cache.clear();
    }
    
    
    QRectF PlugConnectionWidget::boundingRect() const
    {
        return _bounds;
    }
    
    
    void PlugConnectionWidget::paint(QPainter *painter,
                               const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    
    
    void PlugConnectionWidget::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
    {
        if (_liveConnection != 0)
        {
            _liveConnection->updatePath(_anchorPos, event->scenePos()); // TODO: _anchorPlug->centre(); ...
        }
    }
    
    
    void PlugConnectionWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        // Remove this first or items(s) are screened from selection.
        _scene->removeItem(this);
        
        // Temporarily remove plug connection.
        _scene->removeItem(_liveConnection);
        
        // Did the user select something of interest?
        PlugGroup* selectedItem = nullptr;
        QList<QGraphicsItem *> items = _scene->items(event->scenePos());
        
        for (QGraphicsItem* item : items)
        {
            if (auto castItem = dynamic_cast<PlugGroup*>(item))
            {
                selectedItem = castItem;
                break;
            }
        }
        
        // Put the plug connection back.
        _scene->addItem(_liveConnection);
        
        // End session appropriatly.
        if (selectedItem != nullptr)
            endSession(selectedItem);
        else
            endSession(nullptr);
    }
    
    
    void PlugConnectionWidget::startSession(PlugGroup& plugGroup)
    {
        // Create a new plug connection instance, transfer ownership.
        auto tmp = make_unique<PlugConnection>();
        _liveConnection = tmp.release();
        
        // Cache.
        plugGroup.addPlug(_liveConnection->source());
        _cache.append(_liveConnection);
        _scene->addItem(_liveConnection);
        
        // Update geometry.
        _anchorPos = QPointF(_liveConnection->source()->centre());
        _bounds = QRectF(_scene->sceneRect());
        
        // Add to the scene.
        _scene->setFocusItem(this);
        _scene->addItem(this);
    }
    
    
    void PlugConnectionWidget::changeSession(PlugGroup& plugGroup, Plug* plug)
    {
        Q_UNUSED(plugGroup);
        
        _liveConnection = &plug->connection();
        
        _anchorPos = QPointF(_liveConnection->otherPlug(*plug).centre());
        _bounds = QRectF(_scene->sceneRect());
        
        // Lets go for a ride.
        plug->detach();
        
        _scene->setFocusItem(this);
        _scene->addItem(this);
    }
    
    
    void PlugConnectionWidget::cancelSession()
    {
        _scene->removeItem(this);
        endSession(nullptr);
    }
    
    
    void PlugConnectionWidget::endSession(PlugGroup* plugGroup)
    {
        if (plugGroup != nullptr && (_liveConnection->source() != _liveConnection->destination()))
        {
            // Buffer.
            plugGroup->addPlug(&_liveConnection->detachedPlug());
            
            // Clean up.
            _liveConnection = 0;
        }
        else
        {
            _cache.removeOne(_liveConnection);
            _scene->removeItem(_liveConnection);
            
            _liveConnection->deleteLater();
            _liveConnection = 0;
        }
    }
    
    
    void PlugConnectionWidget::sceneAdded(NodeControl& nodeControl)
    {
        QList<BezierScrollerItem*> items;
        items.append(nodeControl.inputItems());
        items.append(nodeControl.outputItems());
        
        for (BezierScrollerItem* scrollerItem : items)
        {
            connect(scrollerItem->plugGroup(),
                    SIGNAL(plugGroupChanged(PlugGroup&)),
                    this,
                    SLOT(startSession(PlugGroup&)));
            
            connect(scrollerItem->plugGroup(),
                    SIGNAL(plugGroupDetached(PlugGroup&, Plug*)),
                    this,
                    SLOT(changeSession(PlugGroup&, Plug*)));
        }
    }
    
    
    void PlugConnectionWidget::sceneRemoved(NodeControl& nodeControl)
    {
        removeConnected(nodeControl);
    }
    
    
    void PlugConnectionWidget::removeConnected(const NodeControl& nodeControl)
    {
        QList<BezierScrollerItem*> items;
        items.append(nodeControl.inputItems());
        items.append(nodeControl.outputItems());
        
        for (BezierScrollerItem* scrollItem : items)
        {
            for (Plug* plug : scrollItem->plugGroup()->plugs())
            {
                auto connection = &plug->connection();
                
                if (_cache.contains(connection))
                {
                    _cache.removeOne(connection);
                    _scene->removeItem(connection);
                    
                    delete connection;
                }
            }
        }
    }
}


