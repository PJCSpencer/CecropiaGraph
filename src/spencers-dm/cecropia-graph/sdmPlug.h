//
//  sdmPlug.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 10/05/2016.
//
//

#ifndef sdmPlugItem_h
#define sdmPlugItem_h

/// \file sdmPlug.h
///
/// \brief Contains the definition of the Plug class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsEllipseItem>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;


namespace spencers
{
    class PlugGroup;
    class PlugConnection;
    
    
    ///
    /// \brief Plug class.
    ///
    class Plug : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] owner           The owner for this Plug.
        /// \param [in] parent          Parent widget of this View.
        ///
        explicit Plug(PlugConnection& owner, QGraphicsItem *parent = Q_NULLPTR);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~Plug();
        
    public:
        
        ///
        /// \brief Sets the color for this Plug.
        ///
        /// \param [in] color           A QColor object.
        ///
        void setColour(const QColor& color);
        
        ///
        /// \brief Detaches this Plug.
        ///
        void detach();
        
        ///
        /// \brief The centre for this Plug.
        ///
        /// \return                     A QPointF.
        ///
        auto centre() -> const QPointF;
        
        ///
        /// \brief The owning plug group for this Plug.
        ///
        /// \return                     A PlugGroup object.
        ///
        auto group() const -> PlugGroup*;
        
        ///
        /// \brief The owning plug connection for this Plug
        ///
        /// \return                     A PlugCOnnection object.
        ///
        auto connection() const -> PlugConnection&;
        
        ///
        /// \brief Utility animation support.
        ///
        /// \param [in] visible         The visibility flag.
        /// \param [in] animated        A boolean to apply animation.
        /// \param [in] delay           The delay to apply for animation.
        /// \param [in] duration        Animation duration.
        ///
        void setVisible(bool visible,
                        bool animated,
                        const int delay = 0,
                        const int duration = 100);
        
    public: // Static members.
        
        ///
        /// \brief The pin radius.
        ///
        static qreal pinRadius;
        
        ///
        /// \brief The padding radius.
        ///
        static qreal paddingRadius;
        
        ///
        /// \brief The shape radius,
        ///
        static auto shapeRadius() -> qreal;
        
    public: // Reimplemented.
        
        ///
        /// \brief Reimplemented from QGraphicsItem.
        ///
        /// \return                     A QPainterPath object.
        ///
        QPainterPath shape() const;
        
        ///
        /// \brief Defines the outer bounds of the item as a rectangle.
        ///
        /// \return                     The bounding rectangle for this item.
        ///
        QRectF boundingRect() const;
        
        ///
        /// \brief Paints this item.
        ///
        /// \param [in] painter         Painter used to draw this item.
        /// \param [in] option          Style options for this item.
        /// \param [in] widget          Optional containing widget.
        ///
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget = 0);
        
    signals:
        
        ///
        /// \brief Emitted when a mouse event initiates the selected drop position.
        ///
        /// \param [out]
        ///
        void plugItemChanged(Plug* Plug);
        
    private:
        
        ///
        /// \brief The owning PlugCOnnection.
        ///
        PlugConnection& _owner;
        
        ///
        /// \brief Index for this Plug.
        ///
        int _index { -1 };
        
        ///
        /// \brief Target for this Plug.
        ///
        QString _target;
        
        ///
        /// \brief The shape for this Plug.
        ///
        QGraphicsEllipseItem _shapeItem;
        
        ///
        /// \brief The graphics effect.
        ///
        unique_ptr<QGraphicsOpacityEffect> _effect;
        
        ///
        /// \brief Animation support for this Plug.
        ///
        unique_ptr<QPropertyAnimation> _animation;
        
    };
}

#endif


