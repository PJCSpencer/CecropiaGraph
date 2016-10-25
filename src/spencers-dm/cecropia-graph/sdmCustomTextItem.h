//
//  sdmCustomTextItem.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 09/05/2016.
//
//

#ifndef sdmCustomTextItem_h
#define sdmCustomTextItem_h

/// \file sdmCustomTextItem.h
///
/// \brief Contains the definition of the CustomTextItem class.
///

#include <QGraphicsTextItem>
#include <QPainter>
#include <QPainterPath>
#include <QFont>

#include "sdmStyles.h"


namespace spencers
{
    ///
    /// \brief CustomTextItem class.
    ///
    class CustomTextItem : public QGraphicsTextItem // TODO:Support truncated text ...
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent widget of this item.
        ///
        CustomTextItem(const QFont& font,
                       const int maxTextLength = defaultMaxTextLength,
                       QGraphicsItem *parent = Q_NULLPTR);
        
        ///
        /// \brief Sets the maximum text length for this CustomTextItem.
        ///
        /// \param [in] length      The new length.
        ///
        void setMaximumTextLength(const int length);
        
    public: // Static members.
        
        ///
        /// \brief The maximum text length for this CustomTextItem.
        ///
        static const int defaultMaxTextLength;
        
        ///
        /// \brief The corner radius for this CustomTextItem.
        ///
        static const qreal editingCornerRadius;
        
    public: // Reimplemented.
        
        ///
        /// \brief Sets the flags flags to specify how the text item should react to user input.
        ///
        /// \param [in] flags       Enum specifying flags.
        ///
        void setTextInteractionFlags(Qt::TextInteractionFlags flags);
        
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
        
    signals:
        
        ///
        /// \brief Emitted when the return key is pressed.
        ///
        void returnPressed();
        
        ///
        /// \brief Emitted when the text of this CustomTextItem changes.
        ///
        /// \param [out] text       A new QString object.
        ///
        void textChanged(const QString& text);
        
        ///
        /// \brief Emitted when editing this CustomTextItem has finished.
        ///
        void editingFinished();
        
    protected:
        
        ///
        /// \brief Reimplemented from QGraphicsItem::keyPressEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void keyPressEvent(QKeyEvent *event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::sceneEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        bool sceneEvent(QEvent *event);
        
    private:
        
        ///
        /// \brief The state flag for editing.
        ///
        bool _editing;
        
        ///
        /// \brief The maximum text length.
        ///
        int _maxTextLength;
    };
}

#endif


