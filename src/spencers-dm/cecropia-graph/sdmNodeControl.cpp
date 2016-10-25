//
//  sdmNodeControl.cpp
//  QtProject-Template
//
//  Created by Peter JC Spencer on 16/01/2016.
//
//

#include "sdmNodeControl.h"

#include <QtWidgets>
#include <QtMath>

#include "sdmPlug.h"
#include "sdmPlugConnection.h"


namespace spencers
{
    QSize NodeControl::_labelMatrixSize = QSize(10, 10);
    QSize NodeControl::_imageDefaultSize = QSize(32, 32);
    QSize NodeControl::_imageMaskedSize = QSize(42, 42);
    qreal NodeControl::_scrollerPathOffset = 0.5f;
    qreal NodeControl::_scrollerPathCap = 0.035f;
    
    
    NodeControl::NodeControl(const NodeControlType type, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , _type(type)
    , _borderMargins(NodeControl::marginsForType(type))
    , _paddingSize(NodeControl::paddingSizeForType(type))
    , _backgroundPathItem(this)
    , _shapePath(QPainterPath())
    , _backgroundBrush(Qt::NoBrush)
    , _backgroundPen(Styles::nodeBackgroundPen)
    , _connections(QHash<QString, BezierScroller*>())
    , _isExpanded(true)
    {
        setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
        setAcceptHoverEvents(true);
        
        // Create and configure.
        if (_type == NodeControlType::Default)
        {
            _simpleImageItem = make_unique<SimpleImageItem>(NodeControl::_imageDefaultSize,
                                                            &_backgroundPathItem);
            
            _customTextItem = make_unique<CustomTextItem>(*Styles::defaultFont(QFont::Medium, 12));
            _customTextItem->setParentItem(&_backgroundPathItem);
            _customTextItem->document()->setDocumentMargin(1.0f);
            
            _controlMatrix = make_unique<SimpleMatrixItem>(&_backgroundPathItem);
            
            QList<QColor> colours;
            colours << Styles::electricBlueColor << Styles::vibrantGreenColor;
            
            foreach (const QColor &object, colours)
            {
                addFlagTrackingItem(object, true); // TODO:Extend to support icon ...
            }
        }
        else if (_type == NodeControlType::Image || _type == NodeControlType::ImageMasked)
        {
            _backgroundPen = Qt::NoPen;
            _simpleImageItem = make_unique<SimpleImageItem>(NodeControl::_imageMaskedSize,
                                                            &_backgroundPathItem);
            
            _simpleImageItem->setBackgroundShapeBorder(NodeControl::paddingSizeForType(_type));
        }
        else if (_type == NodeControlType::Label)
        {
            _customTextItem = make_unique<CustomTextItem>(*Styles::defaultFont(QFont::Medium, 12));
            _customTextItem->setParentItem(&_backgroundPathItem);
            
            _controlMatrix = make_unique<SimpleMatrixItem>(&_backgroundPathItem);
            _controlMatrix->setCellSize(_labelMatrixSize);
            
            QList<QColor> colours;
            colours << Styles::electricBlueColor << Styles::vibrantGreenColor;
            
            foreach (const QColor &object, colours)
                addFlagTrackingItem(object, true);
        }
        
        // Bind.
        if (_customTextItem != nullptr)
            connect(_customTextItem.get(),
                    SIGNAL(textChanged(const QString&)),
                    this,
                    SLOT(updateLayout(const QString&)));
        
        // CRITICAL:Create an appropriate brush here because visible height is required.
        _backgroundBrush = Styles::silverStreakBrush(visibleSize().height());
        if (_type == NodeControlType::Image)
        {
            _backgroundBrush = Qt::NoBrush;
        }
        
        // Apply.
        _backgroundPathItem.setBrush(_backgroundBrush);
        _backgroundPathItem.setPen(_backgroundPen);
        
        // Update layout.
        layout();
    }
    
    
    NodeControl::~NodeControl()
    {
        _connections.clear();
    }
    
    
    auto NodeControl::labelTextItem() -> const CustomTextItem*
    {
        if (_type == NodeControlType::Image)
            return nullptr;
        
        return _customTextItem.get();
    }
    
    
    auto NodeControl::labelText() const -> QString
    {
        if (_type == NodeControlType::Default || _type == NodeControlType::Label)
        {
            return QString(_customTextItem->toPlainText());
        }
        
        return QString();
    }
    
    
    void NodeControl::setLabelText(const QString& text)
    {
        if (_type == NodeControlType::Default || _type == NodeControlType::Label)
            _customTextItem->setPlainText(text);
        
        updateLayout(text);
    }
    
    
    void NodeControl::setIcon(QIcon& icon)
    {
        if (_type == NodeControlType::Default || _type == NodeControlType::Image)
            _simpleImageItem->setIcon(icon);
    }
    
    
    auto NodeControl::createBackgroundPath(const QSizeF size) -> QPainterPath
    {
        QPainterPath path;
        path = PainterPathUtility::createRoundedRectPath(size.toSize(), size.height() * 0.5f);
        
        // NB:QPainterPath.addEllipse creates a clockwise path.
        if (_type == NodeControlType::Image) {}
        
        return path;
    }
    
    
    void NodeControl::setBackgroundBrush(const QBrush& brush)
    {
        _backgroundPathItem.setBrush(brush);
    }
    
    
    void NodeControl::setBackgroundPen(const QPen& pen)
    {
        _backgroundPathItem.setPen(pen);
    }

    
    auto NodeControl::inputItems() const -> QList<BezierScrollerItem*>
    {
        if (_connections.contains(Keys::Input))
        {
            return _connections[Keys::Input]->items();
        }
        return QList<BezierScrollerItem*>();
    }
    
    
    void NodeControl::setInputItems(QList<BezierScrollerItem*>& items)
    {
        if (!_connections.contains(Keys::Input))
        {
            auto length = NodeControl::_scrollerPathOffset - NodeControl::_scrollerPathCap;
            
            auto scroller = make_unique<BezierScroller>(0.0f, length, this);
            scroller->setScrollPath(createBackgroundPath(scaledVisibleSize(offsetSize())));
            scroller->installEventFilter(this);
            
            _connections.insert(Keys::Input, scroller.release());
        }
        
        auto scroller = _connections[Keys::Input];
        scroller->removeAllItems();
        
        configureScroller(*scroller);
        
        if (!items.isEmpty())
        {
            QSize titleSize;
            QSize size;
            auto margins = BezierScrollerItem::contentMargins;
            auto cornerRadius = 2.0f;
            
            foreach (BezierScrollerItem* scrollerItem, items)
            {
                if (!scrollerItem->title().isNull() || scrollerItem->title().length() > 0)
                {
                    titleSize = BezierScrollerItem::sizeForString(scrollerItem->title());
                    size = QSize(titleSize.width() + titleSize.height() + margins.right(),
                                 titleSize.height() + margins.top() + margins.bottom());
                    
                    scrollerItem->setTitleInset(titleSize.height() - cornerRadius);
                    scrollerItem->setBackgroundPath(PainterPathUtility::createTorpedoPath(size, cornerRadius));
                }
            }
            
            scroller->addItems(items);
        }
        
        layout();
    }
    
    
    auto NodeControl::outputItems() const -> QList<BezierScrollerItem*>
    {
        if (_connections.contains(Keys::Output))
        {
            return _connections[Keys::Output]->items();
        }
        return QList<BezierScrollerItem*>();
    }
    
    
    void NodeControl::setOutputItems(QList<BezierScrollerItem*>& items)
    {
        if (!_connections.contains(Keys::Output))
        {
            auto offset = NodeControl::_scrollerPathOffset;
            auto length = offset - NodeControl::_scrollerPathCap;
            
            auto scroller = make_unique<BezierScroller>(offset, length, this);
            scroller->setScrollPath(createBackgroundPath(scaledVisibleSize(offsetSize())));
            scroller->installEventFilter(this);
            
            _connections.insert(Keys::Output, scroller.release());
        }
        
        auto scroller = _connections[Keys::Output];
        scroller->removeAllItems();
        
        configureScroller(*scroller);
        
        if (!items.isEmpty())
        {
            QSize titleSize;
            QSize size;
            auto margins = BezierScrollerItem::contentMargins;
            
            foreach (BezierScrollerItem* scrollerItem, items)
            {
                if (!scrollerItem->title().isNull() || scrollerItem->title().length() > 0)
                {
                    titleSize = BezierScrollerItem::sizeForString(scrollerItem->title());
                    size = QSize(titleSize.width() + margins.left() + margins.right(),
                                 titleSize.height() + margins.top() + margins.bottom());
                    
                    scrollerItem->setTitleColour(Styles::downtownColor);
                    scrollerItem->setBackgroundPen(Styles::downtownSolidPen);
                    scrollerItem->setBackgroundBrush(Qt::NoBrush);
                    scrollerItem->setTitleInset(margins.left());
                    scrollerItem->setBackgroundPath(PainterPathUtility::createRoundedRectPath(size,
                                                                                              size.height() * 0.5f));
                }
            }
            
            scroller->addItems(items);
        }
        
        layout();
    }
    
    
    void NodeControl::configureScroller(BezierScroller& scroller) // TODO:Remove ...
    {
        switch (_type)
        {
            case NodeControlType::Default:
                scroller.setPaddingScale(0.65);
                break;
                
            case NodeControlType::Label:
                scroller.setPaddingScale(0.585);
                break;
                
            case NodeControlType::Image:
                scroller.setPaddingScale(0.7);
                break;
                
            default:
                break;
        }
    }
    
    
    auto NodeControl::flagTrackingMatrix() -> const SimpleMatrixItem*
    {
        if (_type != NodeControlType::Default)
            return 0;
        
        return _controlMatrix.get();
    }
    
    
    void NodeControl::addFlagTrackingItem(const QColor& colour, const bool selected)
    {
        if (_type == NodeControlType::Default)
        {
            auto size = _controlMatrix->cellSize().toSize();
            auto path = PainterPathUtility::createRoundedRectPath(size, size.height() * 0.5f);
        
            _controlMatrix->addCell(colour, selected, path);
        }
        else if (_type == NodeControlType::Label)
        {
            auto radius = _controlMatrix->cellSize().toSize().height();
            auto path = QPainterPath();
            path.addEllipse(0, 0, radius, radius);
            
            _controlMatrix->addCell(colour, selected, path);
        }
        
        layout();
    }
    
    
    void NodeControl::removeFlagTrackingItems()
    {
        if (_controlMatrix != nullptr)
            _controlMatrix->removeAllCells();
    }
    
    
    void NodeControl::updateLayout(const QString& text)
    {
        Q_UNUSED(text);
        
        if (_type == NodeControlType::Image) // NB:This will need to support a label. D'oh.
            return;
        
        layout();
        
        for (BezierScroller* scroller : _connections)
        {
            scroller->setScrollPath(createBackgroundPath(scaledVisibleSize(offsetSize())));
        }
    }
    
    
    void NodeControl::layout()
    {
        auto dx = 0.0f;
        auto dy = 0.0f;
        auto size = visibleSize();
        auto scaledWidth = size.width() * 0.5f;
        auto scaledHeight = size.height() * 0.5f;
        auto inset = 0.0f;
        auto radius = (BezierScroller::scrollBarControlRadius
                       + BezierScroller::scrollBarGutterRadius);
        
        BezierScroller* inputScroller = nullptr;
        if (_connections.contains(Keys::Input))
        {
            inputScroller = _connections[Keys::Input];
            inset = inputScroller->contentSize().width();
        }
        
        BezierScroller* outputScroller = nullptr;
        if (_connections.contains(Keys::Output))
        {
            outputScroller = _connections[Keys::Output];
            auto tmp = outputScroller->contentSize().width();
            
            inset = tmp > inset ? tmp : inset;
        }
        
        auto combined = radius + inset + Plug::shapeRadius();
        auto pos = QPointF(inset + Plug::shapeRadius(), inset + Plug::shapeRadius());
        
        _backgroundPathItem.setPos(combined, combined);
        _backgroundPathItem.setPath(createBackgroundPath(size));
        
        _contentRect = QRectF(QPointF(), QSizeF(size.width() + (combined * 2.0f),
                                                size.height() + (combined * 2.0f)));
        
        // CRITICAL:Called after content rect has been calculated.
        auto flag = false;
        _shapePath = createBackgroundPath(shapeSize(flag));
        _shapePath.translate(shapePos(flag));
        
        if (inputScroller)
            inputScroller->setPos(pos);
        
        if (outputScroller)
            outputScroller->setPos(pos);
        
        if (_type == NodeControlType::Image)
        {
            auto penWidth = _backgroundPathItem.pen().width() * 0.5f;
            
            dx = scaledWidth - (_simpleImageItem->boundingRect().width() * 0.5f) + penWidth;
            dy = scaledHeight - (_simpleImageItem->boundingRect().height() * 0.5f) + penWidth;
            _simpleImageItem->setPos(dx, dy);
        }
        else if (_type == NodeControlType::Label)
        {
            dx = _borderMargins.left();
            
            if (_controlMatrix != nullptr)
            {
                _controlMatrix->setPos(dx,
                                       scaledHeight - (_controlMatrix->boundingRect().height() * 0.5f));
                dx = _controlMatrix->pos().x() + _controlMatrix->boundingRect().width() + _paddingSize.width();
                dx -= (_customTextItem->document()->documentMargin() * 0.5f);
            }
            
            _customTextItem->setPos(dx, _borderMargins.top());
        }
        else
        {
            dy = scaledHeight - (_simpleImageItem->boundingRect().height() * 0.5f);
            _simpleImageItem->setPos(_borderMargins.left(), _borderMargins.top());
            
            dx = _simpleImageItem->pos().x() + _simpleImageItem->boundingRect().width() + _paddingSize.width();
            dy = scaledHeight - (_customTextItem->boundingRect().height() - (_customTextItem->document()->documentMargin() * 0.5f));
            _customTextItem->setPos(dx, dy);
            
            _controlMatrix->setPos(dx, scaledHeight + _paddingSize.height());
        }
    }
    
    
    auto NodeControl::sizeForType(const NodeControlType type) -> const QSize
    {
        auto size = QSize(160, 44); // TODO:Resolve all dynamically ...

        switch (type)
        {
            case NodeControlType::Label:
                size = QSize(140, 26);
                break;
                
            case NodeControlType::Image:
                size = QSize(56, 56);
                break;
                
            default:
                break;
        }
        
        return size;
    }
    
    
    auto NodeControl::marginsForType(const NodeControlType type) -> const QMargins
    {
        auto margins = QMargins(16, 4, 16, 4);
        
        switch (type)
        {
            case NodeControlType::Label:
                margins = QMargins(8, 3, 8, 3);
                break;
                
            case NodeControlType::Image:
                margins = QMargins(2, 2, 2, 2);
                break;
                
            default:
                break;
        }
        
        return margins;
    }
    
    
    auto NodeControl::paddingSizeForType(const NodeControlType type) -> const QSize
    {
        auto size = QSize(5, 4);
        
        switch (type)
        {
            case NodeControlType::Label:
                size = QSize(4, 0);
                break;
                
            case NodeControlType::Image:
            case NodeControlType::ImageMasked:
                size = QSize(10, 10);
                break;
                
            default:
                break;
        }
        
        return size;
    }
    
    
    auto NodeControl::visibleSize() -> const QSizeF
    {
        auto width = _borderMargins.left() + minimumContentSize().width() + _borderMargins.right();
        auto height = _borderMargins.top() + minimumContentSize().height() + _borderMargins.bottom();
        
        return QSizeF(width, height);
    }
    
    
    auto NodeControl::scaledVisibleSize(const QSizeF scale) -> const QSizeF
    {
        QSizeF size = visibleSize();
        
        return QSizeF(size.width() + (scale.width() * 2.0f),
                      size.height() + (scale.height() * 2.0f));
    }
    
    
    auto NodeControl::minimumContentSize() -> const QSizeF
    {
        auto width = 0.0f;
        auto xWidth = (_controlMatrix == nullptr) ? 0 : _controlMatrix->boundingRect().width();
        auto height = 0.0f;
        auto xHeight = (_simpleImageItem == nullptr) ? 0 : _simpleImageItem->boundingRect().height();
        
        if (_type == NodeControlType::Image) // TODO:Support clipped scroller content transform ...
        {
            width = _simpleImageItem->boundingRect().width();
            height = _simpleImageItem->boundingRect().height();
        }
        else if (_type == NodeControlType::Label)
        {
            width = xWidth + _controlMatrix->pos().x() + _customTextItem->boundingRect().width();
            width -= _customTextItem->document()->documentMargin();
            
            height = _customTextItem->boundingRect().height();
        }
        else
        {
            width = _simpleImageItem->boundingRect().width() + _paddingSize.width();
            width += (_customTextItem->boundingRect().width() < xWidth
                      ? xWidth
                      : _customTextItem->boundingRect().width());
            
            height = (_customTextItem->boundingRect().height()
                      + _paddingSize.height()
                      + _controlMatrix->boundingRect().height());
            
            height = (height < xHeight ? xHeight : height);
        }
        
        if (_type == NodeControlType::Default || _type == NodeControlType::Label) // TODO:Replace with clipped scroller content transform ...
        {
            auto margins = BezierScrollerItem::contentMargins;
            auto scrollItemHeight = BezierScrollerItem::sizeHeight();
            
            auto numInputs = _connections.contains(Keys::Input) ? _connections[Keys::Input]->items().count() : 0;
            auto numOutputs = _connections.contains(Keys::Output) ? _connections[Keys::Output]->items().count() : 0;
            auto count = numInputs > numOutputs ? numInputs : numOutputs;
            
            // Scroller items are stacked side-by-side on thier heads.
            auto scrollerItemsHeight = (scrollItemHeight + margins.top() + margins.bottom()) * count;
            width = scrollerItemsHeight > width ? scrollerItemsHeight : width;
        }
        
        return QSizeF(width, height);
    }
    
    
    auto NodeControl::offsetSize() -> const QSizeF
    {
        auto controlRadius = (BezierScroller::scrollBarControlRadius * 0.5f);
        auto gutterRadius = BezierScroller::scrollBarGutterRadius;
        QSizeF scaledSize = QSizeF(gutterRadius + controlRadius,
                                   gutterRadius + controlRadius);
        
        return scaledSize;
    }
    
    
    auto NodeControl::shapePos(bool expanded) -> const QPointF
    {
        QPointF result = QPointF();
        
        if (!expanded)
        {
            auto inset = 0;
            auto radius = (BezierScroller::scrollBarControlRadius
                           + BezierScroller::scrollBarGutterRadius);
            
            for (BezierScroller* scroller : _connections)
            {
                auto tmp = scroller->contentSize().width();
                inset = tmp > inset ? tmp : inset;
            }
            
            result = QPointF(inset + radius + Plug::shapeRadius(), inset + radius + Plug::shapeRadius());
        }
        
        return result;
    }
    
    
    auto NodeControl::shapeSize(bool expanded) -> const QSizeF
    {
        QSizeF result;
        
        if (expanded)
        {
            result = QSizeF(_contentRect.size());
        }
        else
        {
            result = QSizeF(_backgroundPathItem.boundingRect().width(),
                          _backgroundPathItem.boundingRect().height());
        }
        
        return result;
    }
    
    
    QPainterPath NodeControl::shape() const
    {
        return _shapePath;
    }
    
    
    QRectF NodeControl::boundingRect() const
    {
        return _contentRect;
    }
    
    
    void NodeControl::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    
    
    void NodeControl::setSelected(bool selected)
    {
        auto stateIsSelected = !hasFocus() && isSelected() ? false : selected;
        
        _backgroundPathItem.setPen(stateIsSelected
                                   ? Styles::nodeSelectedPen
                                   : _backgroundPen);
        
        QGraphicsObject::setSelected(stateIsSelected);
    }
    
    
    QVariant NodeControl::itemChange(GraphicsItemChange change, const QVariant &value)
    {
        if (change == ItemSelectedChange && scene())
            return hasFocus();

        return QGraphicsItem::itemChange(change, value);
    }
    
    
    void NodeControl::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
    {
        // TODO:Support animated collapsing ...
        
        QGraphicsItem::hoverEnterEvent(event);
    }
    
    
    void NodeControl::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
    {
        // TODO:Support animated collapsing ...
        
        QGraphicsItem::hoverMoveEvent(event);
    }
    
    
    void NodeControl::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
    {
        // NB: Dragging outside window bounds cancels hover event.
        
        QGraphicsItem::hoverLeaveEvent(event);
    }
    
    
    void NodeControl::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
    {
        QList<BezierScrollerItem*> items;
        items.append(inputItems());
        items.append(outputItems());
        
        for (BezierScrollerItem* scrollerItem : items) // TODO:Optimise ...
        {
            for (Plug* plug : scrollerItem->plugGroup()->plugs())
            {
                plug->connection().updatePath();
            }
        }
        
        QGraphicsObject::mouseMoveEvent(event);
    }
    
    
    void NodeControl::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
    {
        // Modify expanded state.
        if (QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            _isExpanded = !_isExpanded; // TODO:Support ...
        }
        else if (_type == NodeControlType::Default || _type == NodeControlType::Label)
        {
            auto rect = QRectF(_backgroundPathItem.pos().x() + _customTextItem->pos().x(),
                               _backgroundPathItem.pos().y() + _customTextItem->pos().y(),
                               _customTextItem->boundingRect().width(),
                               _customTextItem->boundingRect().height());
            
            if (rect.contains(event->pos()))
            {
                _customTextItem->setTextInteractionFlags(Qt::TextEditorInteraction);
                _customTextItem->setFocus();
            }
        }
        
        QGraphicsObject::mouseDoubleClickEvent(event);
    }
    
    
    bool NodeControl::eventFilter(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::GraphicsSceneMouseMove
            && QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            QGraphicsSceneMouseEvent *cEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
            
            if (cEvent)
            {
                auto shift = (cEvent->pos().x() - cEvent->lastPos().x()) * BezierScroller::scrollInterpolation;
                
                // Primary will be input or output since its an event interception.
                auto primary = _connections.contains(Keys::Input) ? _connections[Keys::Input] : _connections[Keys::Output];
                auto secondary = (_connections.contains(Keys::Output)
                                  ? _connections[Keys::Output]
                                  : _connections.contains(Keys::Input) ? _connections[Keys::Input] : nullptr);
                
                primary->translate(shift);
                
                if (secondary && primary != secondary)
                {
                    auto vector = primary->scrollOrigin();
                    auto unit = vector + NodeControl::_scrollerPathOffset;
                    unit = (vector >= 0.5f ? (vector - NodeControl::_scrollerPathOffset) : unit);
                    
                    secondary->position(unit);
                }
            }
            
            return true;
        }
        
        return QObject::eventFilter(obj, event);
    }
}


