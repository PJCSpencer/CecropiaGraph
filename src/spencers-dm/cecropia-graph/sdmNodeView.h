/*
 *  sdmNodeView.h
 *  QtProject-Template
 *
 *  Created by Peter JC Spencer on 06/01/2016.
 *
 */

#ifndef sdmNodeView_h
#define sdmNodeView_h

/// \file sdmNodeView.h
///
/// \brief Contains the definition of the NodeView class.
///

#include <QGraphicsView>
#include <QGestureEvent>

#include "sdmFilterListWidget.h"
#include "sdmNodeControlWidget.h"
#include "sdmPlugConnectionWidget.h"
#include "sdmStyles.h"

#include <memory>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    class NodeScene;
    
    
    ///
    /// \brief NodeView class.
    ///
    class NodeView : public QGraphicsView
    {
        Q_OBJECT
        
    public: //
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent widget of this View.
        ///
        explicit NodeView(QWidget *parent);
        
    public: // Reimplemented.
        
        ///
        /// \brief Reimplemented from QGraphicsView.
        ///
        /// \param [in] scene   A QScene object.
        ///
        void setScene(QGraphicsScene *scene);
        
    public slots:
        
        ///
        /// \brief Called when the primary popup selection is made.
        ///
        /// \param [in] index   A new QModelIndex object.
        ///
        void primaryPopUpSelectedIndex(const QModelIndex& index);
        
        ///
        /// \brief Called when the secondary popup selection is made.
        ///
        /// \param [in] index   A new QModelIndex object.
        ///
        void secondaryPopUpSelectedIndex(const QModelIndex& index);
        
    protected:
        
        ///
        /// \brief Reimplemented to receive key release events for the widget.
        ///
        /// \param [in] event   Qt event object.
        ///
        void keyReleaseEvent(QKeyEvent *event);
        
        ///
        /// \brief This is the main event handler; it handles event event.
        ///
        /// \param [in] event   Qt event object.
        ///
        bool event(QEvent *event);
        
        ///
        /// \brief Reimplemented from QAbstractScrollArea::viewportEvent().
        ///
        /// \param [in] event   Qt event object.
        ///
        bool viewportEvent(QEvent *event);
        
        ///
        /// \brief Handles the event handler for gestire events.
        ///
        /// \param [in] event   Qt event object.
        ///
        bool gestureEvent(QGestureEvent *event);
        
    private:
        
        ///
        /// \brief Primary popup widget.
        ///
        FilterListWidget _primaryPopUp;
        
        ///
        /// \brief Secondary popup widget.
        ///
        FilterListWidget _secondaryPopUp;
        
        ///
        /// \brief Helper object, the drop item is used to instanciate a new node item in the graph.
        ///
        unique_ptr<NodeControlWidget> _nodeControlWidget;
        
        ///
        /// \brief
        ///
        unique_ptr<PlugConnectionWidget> _plugConnectionWidget;
        
        ///
        /// \brief Scale factor which supports gesture driven zooming.
        ///
        qreal _scaleFactor;
        
    private:
        
        ///
        /// \brief Scale speed.
        ///
        static qreal _scaleSpeed;
        
        ///
        /// \brief Minimum scale factor.
        ///
        static qreal _minScaleFactor;
        
        ///
        /// \brief Maximum scale factor.
        ///
        static qreal _maxScaleFactor;
    };
    
}

#endif


