//
//  sdmFilterListWidget.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 21/03/2016.
//
//

#ifndef sdmFilterListWidget_h
#define sdmFilterListWidget_h

/// \file sdmFilterListWidget.h
///
/// \brief Contains the definition of the FilterListWidget class.
///

#include <QWidget>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QModelIndexList>
#include <QString>
#include <QFontMetrics>

#include "sdmConstants.h"
#include "sdmFilterListStyleDelegate.h"
#include "sdmCustomListStyleDelegate.h"
#include "sdmStyles.h"

#include <math.h>
#include <iostream>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    ///
    /// \brief FilterListWidget class.
    ///
    class FilterListWidget : public QWidget
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent widget of this widget.
        ///
        FilterListWidget(const bool useFilter, QWidget *parent = 0);
        
        ///
        /// \brief The border size for this FilterListWidget.
        ///
        /// \return                 A new QSize.
        ///
        auto borderSize() -> const QSize;
        
        ///
        /// \brief The padding size for this FilterListWidget.
        ///
        /// \return                 A new QSize.
        ///
        auto paddingSize() -> const QSize;
        
        ///
        /// \brief The line edit for this FilterListWidget.
        ///
        /// \return                 A QLineEdit object.
        ///
        auto lineEdit() -> const QLineEdit*;
        
        ///
        /// \brief The line edit size for this FilterListWidget.
        ///
        /// \return                 A new QSize.
        ///
        auto lineEditSize() -> const QSize;
        
        ///
        /// \brief The list view size for this FilterListWidget.
        ///
        /// \return                 A new QSize.
        ///
        auto listViewSize() -> const QSize;
        
        ///
        /// \brief Minimum size for this FilterListWidget.
        ///
        /// \return                 A new QSize.
        ///
        auto minimumSize() -> const QSize;
        
        ///
        /// \brief The offset point for the active popup.
        ///
        /// \param [in] row         The row to calculate point.
        /// \return                 A new QPoint.
        ///
        auto cliffhangerPoint(const int row) -> const QPoint;
        
        ///
        /// \brief Sets the active model for this FilterListWidget.
        ///
        /// \param [in]             A QAbstractItemModel object.
        ///
        void setModel(QAbstractItemModel* model);
        
        ///
        /// \brief Displays a model for this QAbstractItemModel.
        ///
        /// \param [in]             A QAbstractItemModel object.
        ///
        void show(QAbstractItemModel* model);
        
        ///
        /// \brief The data object for the selected index model.
        ///
        /// Ref:https://herbsutter.com/2013/05/30/gotw-90-solution-factories
        ///
        /// \return                 A pointer to a QVariant object.
        ///
        auto selectedIndexData() -> unique_ptr<QVariant>;
        
    public slots:
        
        ///
        /// \brief Called when a odel index is selected.
        ///
        /// \param [out]             A QModelIndex object.
        ///
        void clicked(const QModelIndex& index);
        
        ///
        /// \brief Called as a result of a model loading.
        ///
        void showLoaded();
        
    signals:
        
        ///
        /// \brief Emitted when a new model index is selected.
        ///
        /// \param [out]             A QModelIndex object.
        ///
        void selectedIndex(const QModelIndex& index);
        
    protected:
        
        ///
        /// \brief Updates the layout for this FilterListWidget.
        ///
        void layout();
        
    private:
        
        ///
        /// \brief The optional QLineEdit for this FilterListWidget.
        ///
        unique_ptr<QLineEdit> _lineEdit;
        
        ///
        /// \brief The QListView for this FilterListWidget.
        ///
        QListView _listView;
    };
}

#endif


