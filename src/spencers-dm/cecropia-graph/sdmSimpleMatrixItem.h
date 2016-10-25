//
//  sdmSimpleMatrixItem.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 21/02/2016.
//
//

#ifndef sdmGraphicsMatrix_h
#define sdmGraphicsMatrix_h

/// \file sdmSimpleMatrixItem.h
///
/// \brief Contains the definition of the SimpleMatrixItem class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>

#include "sdmStyles.h"
#include "sdmPainterPathUtility.h"

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    ///
    /// \brief SimpleMatrixItem class.
    ///
    class SimpleMatrixItem : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent          Parent widget of this item.
        ///
        explicit SimpleMatrixItem(QGraphicsItem *parent = 0);
         
        ///
        /// \brief Adds a new cell to this SimpleMatrixItem.
        ///
        /// \param [in] color           Sets thehe color for cell.
        /// \param [in] selected        Sets the selected state for cell
        /// \param [in] path            Sets the path for cell.
        ///
        void addCell(const QColor color,
                     const bool selected = false,
                     const QPainterPath& path = QPainterPath()); // TODO:Implement 'tag' support ...
        
        ///
        /// \brief Removes all cels from this SimpleMatrixItem.
        ///
        void removeAllCells();
        
        ///
        /// \brief The padding size for this SimpleMatrixItem.
        ///
        /// \return                     A new QSizeF.
        ///
        auto paddingSize() -> const QSizeF { return _paddingSize; }
        
        ///
        /// \brief Sets the padding size for this SimpleMatrixItem.
        ///
        /// \param [in] size            A new QSizeF for padding size.
        ///
        void setPaddingSize(const QSizeF size);
        
        ///
        /// \brief The cell size for this SimpleMatrixItem.
        ///
        /// \return                     A new QSizeF.
        ///
        auto cellSize() -> const QSizeF { return _cellSize; }
        
        ///
        /// \brief Sets the cell size for this SimpleMatrixItem.
        ///
        /// \param [in] size            A new QSizeF for cell size.
        ///
        void setCellSize(const QSizeF size);
        
    public: // Reimplemented.
        
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
    
        void cellDidChange(int cellIndex); // TODO:Support 'on/off' or 'selected/enabled/highlighted' flag ...
        
    protected: // Reimplemented.
        
        ///
        /// \brief Reimplemented from QGraphicsItem::mouseReleaseEvent().
        ///
        /// \param [in] event           Qt event object.
        ///
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
        
    private:
        
        ///
        /// \brief Padding size.
        ///
        QSizeF _paddingSize;
        
        ///
        /// \brief Cell size.
        ///
        QSizeF _cellSize;
    };
}

#endif


