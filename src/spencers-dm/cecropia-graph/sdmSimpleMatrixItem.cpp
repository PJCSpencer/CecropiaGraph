//
//  sdmSimpleMatrixItem.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 21/02/2016.
//
//

#include "sdmSimpleMatrixItem.h"

#include <QtWidgets>


namespace spencers
{
    SimpleMatrixItem::SimpleMatrixItem(QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _paddingSize(4.0f, 0.0f)
    , _cellSize(18.0f, 9.0f)
    {
        setFlag(ItemIsSelectable);
    }

    
    void SimpleMatrixItem::addCell(const QColor color,
                                 const bool selected,
                                 const QPainterPath& path)
    {
        auto lineWidth = 1.25f;
        QColor duplicate(color);
        
        unique_ptr<QGraphicsItemGroup> group;
        unique_ptr<QGraphicsPathItem> pathItem;
        
        group = make_unique<QGraphicsItemGroup>(this);
        group->setPos((_paddingSize.width() + _cellSize.width()) * (childItems().size() - 1), 0);
        
        pathItem = make_unique<QGraphicsPathItem>(path, group.get());
        pathItem->setVisible(selected ? true : false);
        pathItem->setPen(Qt::NoPen);
        pathItem->setBrush(duplicate);
        pathItem.release();
        
        duplicate.setAlpha(127);
        
        pathItem = make_unique<QGraphicsPathItem>(path, group.get());
        pathItem->setVisible(selected ? false : true);
        pathItem->setPen(QPen(QColor(duplicate), lineWidth));
        pathItem->setBrush(Styles::whiteColor(245));
        pathItem.release();
        
        group.release();
    }
    
    
    void SimpleMatrixItem::removeAllCells()
    {
        for (QGraphicsItem* object : childItems())
        {
            object->setParentItem(nullptr);
            scene()->removeItem(object);
            
            delete object;
        }
    }
    
    
    void SimpleMatrixItem::setPaddingSize(const QSizeF size)
    {
        _paddingSize = size;
    }
    
    
    void SimpleMatrixItem::setCellSize(const QSizeF size)
    {
        _cellSize = size;
    }
    
    
    QRectF SimpleMatrixItem::boundingRect() const
    {
        auto count = childItems().size();
        
        return QRectF(0.0f,
                      0.0f,
                      (_cellSize.width() * count) + (_paddingSize.width() * (count - 1)),
                      _cellSize.height());
    }
    
    
    void SimpleMatrixItem::paint(QPainter *painter,
                              const QStyleOptionGraphicsItem *option,
                              QWidget *widget)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    
    
    void SimpleMatrixItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
    {
        std::cout << "SimpleMatrixItem::mouseReleaseEvent" << std::endl;
        
        // Find nearest column.
        auto area = event->pos().x() / (_cellSize.width() + _paddingSize.width());
        auto region = ceil(area) - 1;
        auto dx = (_cellSize.width() + _paddingSize.width()) * region;
        auto rect = QRectF(QPointF(dx, 0.0f), _cellSize);
        
        // Test.
        if (rect.contains(event->pos().toPoint()))
        {
            // Modify cell state.
            QGraphicsItemGroup *group = dynamic_cast<QGraphicsItemGroup*>(childItems()[region]);
            
            if (group != 0)
            {
                bool stateIsOn = !(group->childItems()[0]->isVisible());
            
                group->childItems()[0]->setVisible(stateIsOn);
                group->childItems()[1]->setVisible(!stateIsOn);
                
                emit cellDidChange(region); // TODO:Support stateIsOn flag ..?
            }
        }
        
        QGraphicsObject::mouseReleaseEvent(event);
    }
}


