//
//  sdmPlugConnection.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 23/05/2016.
//
//

#ifndef sdmPlugConnection_h
#define sdmPlugConnection_h

/// \file sdmPlugConnection.h
///
/// \brief Contains the definition of the PlugConnection class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QStyleOptionGraphicsItem>

#include <math.h>
#include <memory>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    class Plug;
    
    
    ///
    /// \brief PlugConnection class.
    ///
    class PlugConnection : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent      Parent widget of this item.
        ///
        explicit PlugConnection(QGraphicsItem *parent = 0);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~PlugConnection();
        
        ///
        /// \brief The source Plug for this PlugConnection.
        ///
        /// \return                 A Plug object.
        ///
        auto source() const -> Plug*
        {
            return _sourcePlug.get();
        };
        
        ///
        /// \brief The destination Plug for this PlugConnection.
        ///
        /// \return                 A Pliug object.
        ///
        auto destination() const -> Plug*
        {
            return _destinationPlug.get();
        };
        
        ///
        /// \brief Utility which identifiers the Plug which is not argument.
        ///
        /// \return                 A Plug reference.
        ///
        auto otherPlug(const Plug& plug) -> Plug&;
        
        ///
        /// \brief Utility, identifies the Plug not connected.
        ///
        /// \return                 A Plug object.
        ///
        auto detachedPlug() -> Plug&;
        
        
        ///
        /// \brief Updates the path for this PlugConnection.
        ///
        void updatePath();
        
        ///
        /// \brief Updates the path for this PlugConnection.
        ///
        /// \param [in] startPoint  A QPoint.
        /// \param [in] endPoint    A QPoint.
        ///
        void updatePath(const QPointF& startPoint, const QPointF& endPoint);
        
    public: // Reimplemented.
        
        ///
        /// \brief Defines the outer bounds of the item as a rectangle.
        ///
        /// \return                 The bounding rectangle for this item.
        ///
        QRectF boundingRect() const;
        
        ///
        /// \brief Paints this item.
        ///
        /// \param [in] painter     Painter used to draw this item.
        /// \param [in] option      Style options for this item.
        /// \param [in] widget      Optional containing widget.
        ///
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget = 0);
        
    private: // Private member function(s).
        
        ///
        /// \brief Updates the direction for this PlugConnection.
        ///
        void updateDirection();
        
    private: // Private static memebers.
        
        ///
        /// \brief Minimum length for path to make direction visible.
        /// 
        static int _minimumPathLengthForVisiblity;
        
    private:
        
        ///
        /// \brief The path.
        ///
        QPainterPath _path;
        
        ///
        /// \brief The direction for path.
        ///
        QGraphicsPathItem _directionPathItem;
        
        ///
        /// \brief Start point.
        ///
        QPointF _startPoint;
        
        ///
        /// \brief First control point.
        ///
        QPointF _cp1Point;
        
        ///
        /// \brief Second control point.
        ///
        QPointF _cp2Point;
        
        ///
        /// \brief End point.
        ///
        QPointF _endPoint;
        
        ///
        /// \brief Source Plug.
        ///
        unique_ptr<Plug> _sourcePlug;
        
        ///
        /// \brief Destination Plug.
        ///
        unique_ptr<Plug> _destinationPlug;
    };
    
    
    // Unused.
    struct PlugConnectionDeleter
    {
        void operator()(PlugConnection* ptr) const
        {
            printf("Deleting PlugConnection.\n");
            delete ptr;
        }
    };
}

#endif


