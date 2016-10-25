//
//  sdmNodeView.cpp
//  QtProject-Template
//
//  Created by Peter JC Spencer on 06/01/2016.
//
//

#include "sdmNodeView.h"

#include <QtWidgets>

#include "sdmNodeScene.h"


namespace spencers
{
    qreal NodeView::_scaleSpeed = 0.001f;
    qreal NodeView::_minScaleFactor = 0.1f;
    qreal NodeView::_maxScaleFactor = 3.0f;
    
    
    NodeView::NodeView(QWidget *parent)
    : QGraphicsView(parent)
    , _primaryPopUp(true)
    , _secondaryPopUp(false)
    , _scaleFactor(1.0f)
    {
        setRenderHint(QPainter::Antialiasing);
        setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        setDragMode(QGraphicsView::RubberBandDrag);
        setAttribute(Qt::WA_AcceptTouchEvents);
        
        setBackgroundBrush(Styles::whiteColor(245));
        
        connect(&_primaryPopUp, SIGNAL(selectedIndex(const QModelIndex&)),
                this, SLOT(primaryPopUpSelectedIndex(const QModelIndex&)));
        
        connect(&_secondaryPopUp, SIGNAL(selectedIndex(const QModelIndex&)),
                this, SLOT(secondaryPopUpSelectedIndex(const QModelIndex&)));
    }
    
    
    void NodeView::setScene(QGraphicsScene *scene)
    {
        if (scene != QGraphicsView::scene())
        {
            _nodeControlWidget.release();
            _nodeControlWidget = make_unique<NodeControlWidget>(*scene);
            
            _plugConnectionWidget.release();
            _plugConnectionWidget = make_unique<PlugConnectionWidget>(*scene);
            
            // Connect widgets.
            connect(_nodeControlWidget.get(),
                    SIGNAL(sceneAddChange(NodeControl&)),
                    _plugConnectionWidget.get(),
                    SLOT(sceneAdded(NodeControl&)));
            
            connect(_nodeControlWidget.get(),
                    SIGNAL(sceneRemoveChange(NodeControl&)),
                    _plugConnectionWidget.get(),
                    SLOT(sceneRemoved(NodeControl&)));
        }
        
        QGraphicsView::setScene(scene);
    }
    
    
    void NodeView::keyReleaseEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Escape)
        {
            if (_nodeControlWidget->hasFocus())
            {
                _nodeControlWidget->hide();
            }
            else if (_plugConnectionWidget->hasFocus())
            {
                _plugConnectionWidget->cancelSession();
            }
        }
        else if (event->key() == Qt::Key_Backspace)
        {
            _nodeControlWidget->removeSelected();
        }
        else if (event->key() == Qt::Key_Tab
            && QApplication::widgetAt(QCursor::pos()))
        {
            _primaryPopUp.show(NodeLibrary::fileSystemModel());
        }
        else
        {
            event->ignore();
        }
    }
    
    
    bool NodeView::event(QEvent *event)
    {
        switch (event->type())
        {
            case QEvent::Gesture:
                return gestureEvent(static_cast<QGestureEvent*>(event));
                break;
                
            default:
                break;
        }
        return QGraphicsView::event(event);
    }
    
    
    bool NodeView::viewportEvent(QEvent *event)
    {
        if ((event->type() == QEvent::Leave) && (QGuiApplication::mouseButtons() != Qt::NoButton))
            return true;
        
        return QGraphicsView::viewportEvent(event);
    }
    
    
    bool NodeView::gestureEvent(QGestureEvent *event)
    {
        if (QGesture *pinchEvent = event->gesture(Qt::PinchGesture))
        {
            QPinchGesture* pinch = static_cast<QPinchGesture*>(pinchEvent);
            
            if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged)
            {
                // TODO:Suppport scaling gesture ...
            }
        }
        return true;
    }
    
    
    void NodeView::primaryPopUpSelectedIndex(const QModelIndex& index)
    {
        auto pt = _primaryPopUp.cliffhangerPoint(index.row());
        
        _secondaryPopUp.move(pt.x(), pt.y());
        _secondaryPopUp.show(NodeLibrary::contentsModel(index.data().toString()));
    }
    
    
    void NodeView::secondaryPopUpSelectedIndex(const QModelIndex& index)
    {
        // Dismiss popup(s).
        _primaryPopUp.hide();
        _secondaryPopUp.hide();
        
        if (auto variant = _primaryPopUp.selectedIndexData()) 
        {
            QString dirString = variant->toString();
            QString fileString = index.data().toString();

            auto type = NodeLibrary::typeFromModel(fileString);
            auto size = NodeControl::sizeForType(type);
            
            auto origin = mapFromGlobal(QCursor::pos());
            auto scale = 0.5f;
            auto viewportWidth = maximumViewportSize().width() * scale;
            auto viewportHeight = maximumViewportSize().height() * scale;
            auto bounds = QRectF(-viewportWidth, -viewportHeight, viewportWidth * 2, viewportHeight * 2);
            
            _nodeControlWidget->setData(DataKeys::Path, QVariant(fileString));
            _nodeControlWidget->setHoverPath(PainterPathUtility::createRoundedRectPath(size, size.height() * 0.5f));
            _nodeControlWidget->setHoverPosition(mapToScene(origin).toPoint());
            _nodeControlWidget->setHoverBounds(bounds);
            _nodeControlWidget->show();
        }
    }
}


