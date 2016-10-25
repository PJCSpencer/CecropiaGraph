//
//  sdmNodeControlWidget.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 22/08/2016.
//
//

#include "sdmNodeControlWidget.h"

#include <QtWidgets>

#include "sdmNodeLibrary.h"
#include "sdmNodeControl.h"
#include "sdmNodeScene.h"
#include "sdmStyles.h"


namespace spencers
{
    NodeControlWidget::NodeControlWidget(QGraphicsScene& graphicsScene, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _scene(&graphicsScene)
    , _cache(QList<NodeControl*>())
    , _pathItem(this)
    {
        setFlag(QGraphicsItem::ItemIsFocusable);
        setAcceptHoverEvents(true);
        setFlag(QGraphicsItem::ItemIsSelectable);
    }
    
    
    NodeControlWidget::~NodeControlWidget()
    {
        _cache.clear();
    }
    
    
    void NodeControlWidget::setHoverPath(const QPainterPath& path)
    {
        _pathItem.setPath(path);
        _pathItem.setPen(QPen(Styles::whiteColor(0, 255 * 0.35f), 1, Qt::DashLine));
        _pathItem.setBrush(Qt::NoBrush);
    }
    
    
    void NodeControlWidget::setHoverPosition(const QPointF point)
    {
        _pathItem.setPos(QPointF(point.x() - (_pathItem.boundingRect().width() * 0.5f),
                                 point.y() - (_pathItem.boundingRect().height() * 0.5f)));
    }
    
    
    void NodeControlWidget::setHoverBounds(const QRectF rect)
    {
        _bounds = QRectF(rect);
    }
    
    
    void NodeControlWidget::show()
    {
        // Change cursor.
        QApplication::setOverrideCursor(Qt::SizeAllCursor);
        
        _scene->addItem(this);
        _scene->setFocusItem(this);
    }
    
    
    void NodeControlWidget::hide()
    {
        // Restor cursor.
        QApplication::restoreOverrideCursor();
        
        // Remove this.
        _scene->removeItem(this);
    }
    
    
    void NodeControlWidget::removeSelected()
    {
        auto selectedItems = _scene->selectedItems();
        
        foreach(QGraphicsItem* item, selectedItems)
        {
            if (auto focusItem = item->focusItem())
            {
                // A CustomTextItem can also use Qt::Key_Backspace to remove text.
                auto castFocusItem = dynamic_cast<CustomTextItem*>(focusItem);
                if (castFocusItem)
                    return;
            }
        }
        
        foreach(QGraphicsItem* item, selectedItems)
        {
            auto castItem = dynamic_cast<NodeControl*>(item);
            if (castItem != nullptr && _cache.contains(castItem))
            {
                emit sceneRemoveChange(*castItem);
                
                _cache.removeOne(castItem);
                _scene->removeItem(item);
                
                delete item;
            }
        }
    }
    
    
    QRectF NodeControlWidget::boundingRect() const
    {
        return _bounds;
    }
    
    
    void NodeControlWidget::paint(QPainter *painter,
                              const QStyleOptionGraphicsItem *option,
                              QWidget *widget)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    
    
    void NodeControlWidget::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
    {
        setHoverPosition(event->scenePos());
    }
    
    
    void NodeControlWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        NodeScene *castScene = static_cast<NodeScene*>(scene()); // NB:A little extreme maybe.
        if (!castScene)
        {
            return;
        }
        
        // Create a new node instance.
        if (auto node = NodeLibrary::createNode(data(DataKeys::Path).toString()))
        {
            // Configure.
            node->setLabelText(*castScene->itemTitle(node->nodeType()));
            node->setPos(QPointF(event->scenePos().x() - (node->boundingRect().width() * 0.5f),
                                 event->scenePos().y() - (node->boundingRect().height() * 0.5f)));
            
            // Cache, add to scene.
            _cache.append(node.get());
            scene()->addItem(node.get());
            
            // Dispatch signal.
            emit sceneAddChange(*node.release());
        }
        
        hide();
    }
    
    
    void NodeControlWidget::keyReleaseEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Escape)
        {
            hide();
        }
    }
}


