//
//  sdmFilterListStyleDelegate.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 31/03/2016.
//
//

#include "sdmFilterListStyleDelegate.h"

#include <iostream>

#include "sdmStyles.h"


namespace spencers
{
    QSizeF FilterListStyleDelegate::_borderSize = QSizeF(8.0f, 0.0f);
    QSizeF FilterListStyleDelegate::_paddingSize = QSizeF(12.0f, 0.0f);
    QSize FilterListStyleDelegate::_pixmapSize = QSize(9, 9);
    
    
    FilterListStyleDelegate::FilterListStyleDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
    , _positiveIcon(":icons/DisclosurePositive.svg") /* TODO:Resolve icon path(s) ... */
    , _negativeIcon(":icons/DisclosureNegative.svg")
    {
    }
    
    
    void FilterListStyleDelegate::paint(QPainter *painter,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
    {
        auto dx = _paddingSize.width();
        auto top = option.rect.top();
        auto width = option.rect.width();
        auto height = option.rect.height();
        
        QRectF textRect(dx, top, width - (dx * 2.0f), height);
        QRect pixmapRect(width - (_pixmapSize.width() + _borderSize.width()),
                         top + (height * 0.5f) - (_pixmapSize.height() * 0.5f),
                         _pixmapSize.width(),
                         _pixmapSize.height());
        
        bool selected = option.state & QStyle::State_Selected;
        
        if (selected)
        {
            painter->fillRect(option.rect, Styles::highlightColor());
            painter->setPen(option.palette.highlightedText().color());
        }
        else
            painter->setPen(option.palette.text().color());
        
        painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, index.data().toString());
        painter->drawPixmap(pixmapRect, selected
                            ? _positiveIcon.pixmap(_pixmapSize)
                            : _negativeIcon.pixmap(_pixmapSize));
    }
}


