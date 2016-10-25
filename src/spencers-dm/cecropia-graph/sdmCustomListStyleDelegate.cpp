//
//  sdmCustomListStyleDelegate.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 12/08/2016.
//
//

#include "sdmCustomListStyleDelegate.h"

#include <iostream>

#include "sdmStyles.h"


namespace spencers
{
    CustomListStyleDelegate::CustomListStyleDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
    {
    }
    
    
    void CustomListStyleDelegate::paint(QPainter *painter,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
    {
        bool selected = option.state & QStyle::State_Selected;
        
        if (selected)
        {
            painter->fillRect(option.rect, Styles::highlightColor());
            painter->setPen(option.palette.highlightedText().color());
        }
        else
            painter->setPen(option.palette.text().color());
        
        QVariant value = index.data(Qt::DecorationRole);
        if (value.isValid() && value.type() == QVariant::Icon)
        {
            auto icon = qvariant_cast<QIcon>(value);
            auto pixmap = icon.pixmap(option.decorationSize);
            
            auto inset = option.rect.height() - option.decorationSize.height();
            auto scaledInset = inset * 0.5f;
            auto pixmapRect = QRect(QPoint(option.rect.left() + scaledInset, option.rect.top() + scaledInset),
                                    option.decorationSize);
            
            auto textRect = QRect(option.rect.left() + pixmapRect.width() + inset,
                                  option.rect.top(),
                                  option.rect.width() - pixmapRect.width() - inset,
                                  option.rect.height());
            
            painter->drawPixmap(pixmapRect, pixmap);
            painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, index.data().toString());
        }
        else
        {
            painter->drawText(option.rect, Qt::AlignHCenter | Qt::AlignVCenter, index.data().toString());
        }
    }
}


