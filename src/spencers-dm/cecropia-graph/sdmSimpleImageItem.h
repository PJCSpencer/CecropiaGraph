//
//  sdmSimpleImageItem.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 20/02/2016.
//
//

#ifndef sdmGraphicsImageItem_h
#define sdmGraphicsImageItem_h

/// \file sdmSimpleImageItem.h
///
/// \brief Contains the definition of the SimpleImageItem class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QMargins>

#include "sdmConstants.h"
#include "sdmStyles.h"


namespace spencers
{
    ///
    /// \brief SimpleImageItem
    ///
    class SimpleImageItem : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] icon
        /// \param [in] size
        /// \param [in] parent  Parent widget of this item.
        ///
        SimpleImageItem(const QSizeF size, QGraphicsItem *parent = 0);
        
        ///
        /// \brief Sets the icon for this SimpleImageItem.
        ///
        /// \param [in] icon        A new QIcon object.
        ///
        void setIcon(QIcon& icon);
        
        ///
        /// \brief Sets the icon size for this SimpleImageItem.
        ///
        /// \param [in] size        The new icon QSize.
        ///
        void setIconSize(const QSize& size);
        
        ///
        /// \brief Sets the background shape for this SimpleImageItem.
        ///
        /// \param [in] shape       A SimpleShape flag.
        ///
        void setBackgroundShape(const SimpleShape shape);
        
        ///
        /// \brief Sets the background shape border for this SimpleImageItem.
        ///
        /// \param [in] margins     The QSize to apply.
        ///
        void setBackgroundShapeBorder(const QSizeF size);
        
        ///
        /// \brief Sets the background shape color for this SimpleImageItem.
        ///
        /// \param [in] color       A new QColor.
        ///
        void setBackgroundShapeColor(const QColor& color);
        
        ///
        /// \brief Sets the background shape color for this SimpleImageItem.
        ///
        /// \param [in] enabled     A boolean for clipping.
        ///
        void setBackgroundClipping(bool enabled);
        
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
    private:
        
        ///
        /// \brief The QIcon for this SimpleImageItem.
        ///
        QIcon _icon;
        
        ///
        /// \brief The icon QSize.
        ///
        QSizeF _iconSize;
        
        ///
        /// \brief The background shape.
        ///
        SimpleShape _backgroundShape;
        
        ///
        /// \brief The background shape border.
        ///
        QSizeF _backgroundShapeBorder;
        
        ///
        /// \brief The background shape color.
        ///
        QColor _backgroundShapeColor;
        
        ///
        /// \brief
        ///
        bool _backgroundClipping;
    };
}

#endif


