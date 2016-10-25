//
//  sdmNodeControl.h
//  QtProject-Template
//
//  Created by Peter JC Spencer on 16/01/2016.
//
//

#ifndef sdmNodeControl_h
#define sdmNodeControl_h

/// \file sdmNodeControl.h
///
/// \brief Contains the definition of the NodeControl class.
///

#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>
#include <QIcon>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QButtonGroup>
#include <QPushButton>
#include <QDrag>

#include "sdmConstants.h"
#include "sdmBezierScroller.h"
#include "sdmSimpleImageItem.h"
#include "sdmCustomTextItem.h"
#include "sdmSimpleMatrixItem.h"
#include "sdmPainterPathUtility.h"
#include "sdmStyles.h"

#include <memory>

using std::unique_ptr;
using std::make_unique;

// Supported enum(s).
enum class NodeControlType
{
    Unkown      = 0,
    Default,
    Label,
    Image,
    ImageMasked
};


namespace spencers
{
    ///
    /// \brief NodeControl class.
    ///
    class NodeControl : public QGraphicsObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] type        Scene managing this Node.
        /// \param [in] parent      Parent item of this NodeControl.
        ///
        NodeControl(const NodeControlType type, QGraphicsItem *parent = 0);
        
        ///
        /// \brief Destructor.
        ///
        virtual ~NodeControl();
        
        ///
        /// \brief The NodeControlType of this NodeControl.
        ///
        /// A NodeControl can support a number of different type(s)
        ///
        /// \return Type for this NodeControl.
        ///
        auto nodeType() -> NodeControlType
        {
            return _type;
        };
        
        ///
        /// \brief The label text for this NodeControl.
        ///
        /// \return                 A new QString object.
        ///
        auto labelText() const -> QString;
        
        ///
        /// \brief Sets the label text for this NodeControl.
        ///
        /// \param [in] text        New QString object.
        ///
        void setLabelText(const QString& text);
        
        ///
        /// \brief The label text item for this NodeControl.
        ///
        /// \return CustomeTextItem for this NodeControl.
        ///
        auto labelTextItem() -> const CustomTextItem*;
        
        ///
        /// \brief Sets the icon for this NodeControl.
        ///
        /// \param [in] icon        New QIcon object.
        ///
        void setIcon(QIcon& icon);
        
        ///
        /// \brief Sets the background brush for this NodeControl.
        ///
        /// \param [in] brush        New QBrush object.
        ///
        void setBackgroundBrush(const QBrush& brush);
        
        ///
        /// \brief Sets the background pen for this NodeControl.
        ///
        /// \param [in] text        New QPen object.
        ///
        void setBackgroundPen(const QPen& pen);
        
        ///
        /// \brief The input items for this NodeControl.
        ///
        /// \return                 A list of BezierScrollerItem(s).
        ///
        auto inputItems() const -> QList<BezierScrollerItem*>;
        
        ///
        /// \brief Sets the input items for this NodeControl.
        ///
        /// \param [in] items        A new collection of BezierScrollerItem(s).
        ///
        void setInputItems(QList<BezierScrollerItem*>& items);
        
        ///
        /// \brief The input items for this NodeControl.
        ///
        /// \return                 A list of BezierScrollerItem(s).
        ///
        auto outputItems() const -> QList<BezierScrollerItem*>;
        
        ///
        /// \brief Sets the output items for this NodeControl.
        ///
        /// \param [in] items        A new collection of BezierScrollerItem(s).
        ///
        void setOutputItems(QList<BezierScrollerItem*>& items);
        
        ///
        /// \brief The flag tracking matrix which belongs to this NodeControl.
        ///
        /// \return                 The SimpleMatrixItem for this NodeControl.
        ///
        auto flagTrackingMatrix() -> const SimpleMatrixItem*;
        
        ///
        /// \brief Adds an item to the SimpleMatrixItem for this NodeControl.
        ///
        /// \param [in] colour      The color object for the new item.
        /// \param [in] selected    Defines if this item is selected.
        ///
        void addFlagTrackingItem(const QColor& colour, const bool selected = false);
        
        ///
        /// \brief Removes all tracking flag items for this NodeControl.
        ///
        void removeFlagTrackingItems();
        
    public: // Reimplemented.
        
        ///
        /// \brief Reimplemented from QGraphicsItem.
        ///
        /// \return                 A new QPainterPath object.
        ///
        QPainterPath shape() const;
        
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
        
        ///
        /// \brief Sets the selected state for this item.
        ///
        /// \param [in] selected     Flag used to set new selected state.
        ///
        void setSelected(bool selected);
        
    public slots:
        
        ///
        /// \brief Called when label text is modified.
        ///
        /// \param [in] text     New label text.
        ///
        void updateLayout(const QString& text);
        
    public: // Static members.
        
        ///
        /// \brief Size utility.
        ///
        /// \return The size for a NodeControlType.
        ///
        static auto sizeForType(const NodeControlType type) -> const QSize;
        
        ///
        /// \brief Border utility.
        ///
        /// \return The border size for a NodeControlType.
        ///
        static auto marginsForType(const NodeControlType type) -> const QMargins;
        
        ///
        /// \brief Padding utility.
        ///
        /// \return The padding size for a NodeControlType.
        ///
        static auto paddingSizeForType(const NodeControlType type) -> const QSize;
        
    protected:
        
        ///
        /// \brief Creates a new background path for this NodeControl.
        ///
        /// \param [in] size     Size for the path.
        /// \return A new QPainterPath object.
        ///
        auto createBackgroundPath(const QSizeF size) -> QPainterPath;
        
        ///
        /// \brief Updates the layout for this NodeControl.
        ///
        void layout();
        
        ///
        /// \brief The visible size for this NodeControl.
        ///
        /// \return A new QSizeF.
        ///
        auto visibleSize() -> const QSizeF;
        
        ///
        /// \brief The minimum content size for this NodeControl.
        ///
        /// \return A new QSizeF.
        ///
        auto minimumContentSize() -> const QSizeF;
        
        ///
        /// \brief Scales the visible size of this NodeControl.
        ///
        /// \param [in] scale     Scale for size.
        /// \return A new QSizeF.
        ///
        auto scaledVisibleSize(const QSizeF scale) -> const QSizeF;
        
        ///
        /// \brief The offset size for this NodeControl.
        ///
        /// \return A new QSizeF.
        ///
        auto offsetSize() -> const QSizeF;
        
        ///
        /// \brief The shape position for this NodeControl.
        ///
        /// \param [in] expanded        Flag for expanded.
        /// \return                     A new QPointF.
        ///
        auto shapePos(bool expanded) -> const QPointF;
        
        ///
        /// \brief The shape size for this NodeCOntrol.
        ///
        /// \param [in] expanded        Flag for expanded.
        /// \return                     A new QSizeF.
        ///
        auto shapeSize(bool expanded) -> const QSizeF;
        
        ///
        /// \brief Configures the scroll for this NodeControl.
        ///
        /// \param [in] scroller     The BezierScoller object to modify.
        ///
        void configureScroller(BezierScroller& scroller);
        
        ///
        /// \brief Mouse event filter.
        ///
        /// \param [in] obj     The obj recieving the event.
        /// \param [in] event   The Qt event delivered.
        ///
        bool eventFilter(QObject *obj, QEvent *event);
        
    protected: // Reimplemented.
        
        ///
        /// \brief Called when the mouse enteres the shape of the item.
        ///
        /// \param [in] event   Qt event object.
        ///
        void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::hoverMoveEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
        
        ///
        /// \brief Called when the mouse leaves the shape of the item.
        ///
        /// \param [in] event   Qt event object
        ///
        void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::mouseReleaseEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        
        ///
        /// \brief Reimplemented from QGraphicsItem::mouseDoubleClickEvent().
        ///
        /// \param [in] event       Qt event object.
        ///
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        
        ///
        /// \brief Called to notify custom items that some part of the item's state changes.
        ///
        /// \param [in] change  Is the parameter of the item that is changing.
        /// \param [in] value   The new value; the type of the value depends on change.
        ///
        QVariant itemChange(GraphicsItemChange change, const QVariant &value);
        
    private: // Static members.
        
        ///
        /// \brief QSize for label NodeControl.
        ///
        static QSize _labelMatrixSize;
        
        ///
        /// \brief QSize for image NodeControl.
        ///
        static QSize _imageDefaultSize;
        
        ///
        /// \brief QSize for masked NodeControl.
        ///
        static QSize _imageMaskedSize;
        
        ///
        /// \brief An offset for scroller path.
        ///
        static qreal _scrollerPathOffset;
        
        ///
        /// \brief Scroller cap.
        ///
        static qreal _scrollerPathCap;
        
    private: // Members.
        
        ///
        /// \brief Identifiers the type for this NodeControl.
        ///
        NodeControlType _type;
        
        ///
        /// \brief Border margins for this NodeControl.
        ///
        QMargins _borderMargins;
        
        ///
        /// \brief Padding size for this NodeControl.
        ///
        QSizeF _paddingSize;
        
        ///
        /// \brief Content rect for this NodeControl.
        ///
        QRectF _contentRect;
        
        ///
        /// \brief The background path displayed by this NodeControl.
        ///
        QGraphicsPathItem _backgroundPathItem;
        
        ///
        /// \brief The shape path for this NodeControl.
        ///
        QPainterPath _shapePath;
        
        ///
        /// \brief The background brush applied.
        ///
        QBrush _backgroundBrush;
        
        ///
        /// \brief The background pen applied.
        ///
        QPen _backgroundPen;
        
        ///
        /// \brief The image item supported by this NodeControl.
        ///
        unique_ptr<SimpleImageItem> _simpleImageItem;
        
        ///
        /// \brief The text item supported by this NodeControl.
        ///
        unique_ptr<CustomTextItem> _customTextItem;
        
        ///
        /// \brief The control matrix supported by this NodeControl.
        ///
        unique_ptr<SimpleMatrixItem> _controlMatrix;
        
        ///
        /// \brief The BezierScroller connections for this NodeControl.
        ///
        QHash<QString, BezierScroller*> _connections;
        
        ///
        /// \brief Expanded state for this NodeControl.
        ///
        bool _isExpanded;
    };
}


#endif


