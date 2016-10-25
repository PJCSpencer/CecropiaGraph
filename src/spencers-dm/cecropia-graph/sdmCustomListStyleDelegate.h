//
//  sdmCustomListStyleDelegate.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 12/08/2016.
//
//

#ifndef sdmCustomListStyleDelegate_h
#define sdmCustomListStyleDelegate_h

/// \file sdmCustomListStyleDelegate.h
///
/// \brief Contains the definition of the CustomListStyleDelegate class.
///

#include <QStyledItemDelegate>
#include <QPainter>
#include <QIcon>
#include <QPixmap>


namespace spencers
{
    ///
    /// \brief CustomListStyleDelegate class.
    ///
    class CustomListStyleDelegate : public QStyledItemDelegate
    {
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent of this object.
        ///
        explicit CustomListStyleDelegate(QObject *parent = 0);
        
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
    };
}

#endif


