//
//  sdmCustomTextItem.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 09/05/2016.
//
//

#include "sdmCustomTextItem.h"

#include <iostream>
#include <QtWidgets>


namespace spencers
{
    const int CustomTextItem::defaultMaxTextLength = 24;
    const qreal CustomTextItem::editingCornerRadius = 2.0f;
    
    
    CustomTextItem::CustomTextItem(const QFont& font, const int maxTextLength, QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
    , _editing(false)
    , _maxTextLength(maxTextLength)
    {
        setTextInteractionFlags(Qt::NoTextInteraction);
        
        setFont(font);
    }
    
    
    void CustomTextItem::setMaximumTextLength(const int length)
    {
        _maxTextLength = length;
    }
    
    
    void CustomTextItem::setTextInteractionFlags(Qt::TextInteractionFlags flags)
    {
        _editing = (flags == Qt::TextEditorInteraction ? true : false);

        if (!_editing)
        {
            flags &= !Qt::TextEditable;
            flags &= !Qt::TextSelectableByMouse;
            flags &= !Qt::TextEditorInteraction;
        }
        
        QGraphicsTextItem::setTextInteractionFlags(flags);
    }
    
    
    void CustomTextItem::keyPressEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Return
            || event->key() == Qt::Key_Enter
            || event->key() == Qt::Key_Escape)
        {
            setTextInteractionFlags(Qt::NoTextInteraction);
            
            emit returnPressed();
        }
        else if (event->key() == Qt::Key_Backspace)
        {
            QGraphicsTextItem::keyPressEvent(event);
            
            emit textChanged(toPlainText());
        }
        else if (toPlainText().length() < _maxTextLength)
        {
            QGraphicsTextItem::keyPressEvent(event);
            
            emit textChanged(toPlainText());
        }
    }
    
    
    bool CustomTextItem::sceneEvent(QEvent *event)
    {
        if (event->type() == QEvent::FocusOut)
        {
            setTextInteractionFlags(Qt::NoTextInteraction);
            
            QTextCursor cursor = textCursor();
            cursor.clearSelection();
            setTextCursor(cursor);
            
            emit editingFinished();
        }
        
        return QGraphicsTextItem::sceneEvent(event);
    }
    
    
    QRectF CustomTextItem::boundingRect() const
    {
        auto rect = QGraphicsTextItem::boundingRect();
        
        return QRectF(rect.left(), rect.top(), rect.width(), rect.height() - 1);
    }
    
    
    void CustomTextItem::paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget)
    {
        Q_UNUSED(widget);
        
        // Could have used 'option->state' here but this would result in a delayed re-draw.
        if (_editing)
        {
            painter->setPen(Styles::highlightedTextPen);
            painter->setBrush(Qt::white);
            painter->drawRoundedRect(boundingRect(),
                                     editingCornerRadius,
                                     editingCornerRadius);
        }
        
        // Ref:http://www.qtcentre.org/threads/15089-QGraphicsView-change-selected-rectangle-style
        QStyleOptionGraphicsItem duplicate = (*option);
        duplicate.state &= !QStyle::State_Selected;
        
        QGraphicsTextItem::paint(painter, &duplicate, widget);
    }
}


