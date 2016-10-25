//
//  sdmFilterListWidget.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 21/03/2016.
//
//

#include "sdmFilterListWidget.h"

#include <QtWidgets>


namespace spencers
{
    FilterListWidget::FilterListWidget(const bool useFilter, QWidget *parent)
    : QWidget(parent)
    , _listView(this)
    {
        setWindowFlags(Qt::Popup); // TODO:Override to ensure this will be a popup ...
        
        if (useFilter)
        {
            _lineEdit = make_unique<QLineEdit>(this); // TODO:Support QCompleter ...
            _lineEdit->setStyleSheet("QLineEdit { border:1px solid lightgray; padding:0 4px; border-radius:4px; }");
            _lineEdit->setPlaceholderText(Placeholder::Filter);
            _lineEdit->setFocusPolicy(Qt::NoFocus); // TODO:Resolve ...
        }
        
        _listView.setStyleSheet("QListView { background:transparent; } QListView::item { padding:4px 0; }");
        _listView.setFocusPolicy(Qt::NoFocus);
        
        // Connect.
        connect(&_listView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicked(const QModelIndex&)));
    }
    
    
    void FilterListWidget::setModel(QAbstractItemModel* model)
    {
        _listView.setModel(model);
        _listView.clearSelection();
    }
    
    
    void FilterListWidget::show(QAbstractItemModel* model)
    {
        _listView.setModel(model);
        _listView.clearSelection();
        
        QFileSystemModel* castModel = dynamic_cast<QFileSystemModel*>(model);
        if (castModel != nullptr)
        {
            _listView.setItemDelegate(make_unique<FilterListStyleDelegate>().release());
            _listView.setRootIndex(castModel->index(castModel->rootPath()));
            
            connect(castModel, SIGNAL(directoryLoaded(const QString)), this, SLOT(showLoaded()));
        }
        else
        {
            _listView.setItemDelegate(make_unique<CustomListStyleDelegate>().release());
            
            layout();
            QWidget::show();
        }
    }
    
    
    auto FilterListWidget::selectedIndexData() -> unique_ptr<QVariant>
    {
        QItemSelectionModel* selectionModel = _listView.selectionModel();
        
        if (!selectionModel->hasSelection())
            return nullptr;
        
        return make_unique<QVariant>(selectionModel->selectedIndexes().at(0).data());
    }
    
    
    auto FilterListWidget::borderSize() -> const QSize
    {
        return QSize(8, 6);
    }
    
    
    auto FilterListWidget::paddingSize() -> const QSize
    {
        return QSize(0, 6);
    }
    
    
    auto FilterListWidget::lineEdit() -> const QLineEdit*
    {
        if (_lineEdit != nullptr)
            return _lineEdit.get();
        
        return nullptr;
    }
    
    
    auto FilterListWidget::lineEditSize() -> const QSize
    {
        return QSize(minimumSize().width() - (borderSize().width() * 2.0f), 25);
    }
    
    
    auto FilterListWidget::listViewSize() -> const QSize
    {
        int count = _listView.model()->rowCount();
        auto width = minimumSize().width();
        auto height = 0;
        
        QFileSystemModel* castModel = dynamic_cast<QFileSystemModel*>(_listView.model());
        if (castModel != 0)
            count = castModel->rowCount(castModel->index(castModel->rootPath()));
        
        height = (minimumSize().height() + 1) * count;
        
        return QSize(width, height);
    }
    
    
    auto FilterListWidget::minimumSize() -> const QSize
    {
        auto height = _listView.sizeHintForRow(0);
        
        QFileSystemModel* castModel = dynamic_cast<QFileSystemModel*>(_listView.model());
        if (castModel != 0)
            return QSize(160, height); // TODO:Resolve ...
            
        return QSize(_listView.sizeHintForColumn(0) + 2, height); // TODO:Support constant ...
    }
    
    
    auto FilterListWidget::cliffhangerPoint(const int row) -> const QPoint
    {
        auto inset = 8;
        auto offset = 4;
        auto dy = (borderSize().height()
                   + lineEditSize().height()
                   + paddingSize().height()
                   + (minimumSize().height() * row)
                   + offset);
        
        return QPoint(geometry().right() - inset, geometry().top() + dy);
    }
    
    
    void FilterListWidget::layout()
    {
        auto dy = 0;
        auto width = minimumSize().width();
        auto height = listViewSize().height();
        auto widgetHeight = 0;
        
        if (_lineEdit != nullptr)
        {
            _lineEdit->setGeometry(borderSize().width(),
                                   borderSize().height(),
                                   lineEditSize().width(),
                                   lineEditSize().height());
            
            dy = borderSize().height() + lineEditSize().height() + paddingSize().height();
            widgetHeight = (borderSize().height()
                            + lineEditSize().height()
                            + paddingSize().height()
                            + height
                            + borderSize().height());
            
            // Position over the line edit for convienience.
            move(cursor().pos().x() - round(minimumSize().width() * 0.75f),
                 cursor().pos().y() - ((borderSize().height() + (lineEditSize().height() * 0.5f))));
        }
        else
            widgetHeight = height;
        
        _listView.setGeometry(0, dy, width, height);
        resize(width, widgetHeight);
    }
    
    
    void FilterListWidget::clicked(const QModelIndex& index)
    {
        emit selectedIndex(index);
    }
    
    
    void FilterListWidget::showLoaded()
    {
        layout();
        QWidget::show();
    }
}


