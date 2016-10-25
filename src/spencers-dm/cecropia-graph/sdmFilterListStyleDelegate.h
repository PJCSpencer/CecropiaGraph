//
//  sdmFilterListStyleDelegate.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 31/03/2016.
//
//

#ifndef sdmFilterListStyleDelegate_h
#define sdmFilterListStyleDelegate_h

/// \file sdmFilterListStyleDelegate.h
///
/// \brief Contains the definition of the FilterListStyleDelegate class.
///

#include <QStyledItemDelegate>
#include <QPainter>
#include <QIcon>
#include <QPixmap>


namespace spencers
{
    ///
    /// \brief FilterListStyleDelegate
    ///
    class FilterListStyleDelegate : public QStyledItemDelegate
    {
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent of this object.
        ///
        explicit FilterListStyleDelegate(QObject *parent = 0);
        
        ///
        /// \brief Paints this item.
        ///
        /// \param [in] painter     Painter used to draw this item.
        /// \param [in] option      Style options for this item.
        /// \param [in] widget      Optional containing widget.
        ///
        void paint(QPainter *painter,
                   const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;
        
    private:
        
        ///
        /// \brief Positive QIcon for this FilterListStyleDelegate.
        ///
        QIcon _positiveIcon;
        
        ///
        /// \brief Negative QIcon for this FilterListStyleDelegate.
        ///
        QIcon _negativeIcon;
        
    private: // Static private members.
        
        ///
        /// \brief Border size.
        ///
        static QSizeF _borderSize;
        
        ///
        /// \brief Padding size.
        ///
        static QSizeF _paddingSize;
        
        ///
        /// \brief Pixmap size.
        ///
        static QSize _pixmapSize;
    };
}

#endif


