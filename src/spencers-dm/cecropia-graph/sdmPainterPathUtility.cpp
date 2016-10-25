//
//  sdmPainterPathUtility.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 31/03/2016.
//
//

#include "sdmPainterPathUtility.h"

#include <QtMath>
#include <QTransform>
#include <QVector2D>

#include <iostream>
#include <math.h>


namespace spencers
{
    auto PainterPathUtility::createRoundedRectPath(const QSize size,
                                                   const qreal cornerRadius) -> QPainterPath
    {
        QPainterPath path = QPainterPath();
        path.addRoundedRect(QRectF(0, 0, size.width(), size.height()),
                            cornerRadius,
                            cornerRadius);
        
        return path;
    }
    
    
    auto PainterPathUtility::createTrianglePath(const int numPoints,
                                                const qreal rotation,
                                                const QSize size,
                                                const qreal cornerRadius) -> QPainterPath
    {
        auto scale = 0.5f;
        auto scaledCornerRadius = cornerRadius * scale;
        auto scaledSizeWidth = size.width() * scale;
        auto scaledSizeHeight = size.height() * scale;
        
        QList<QPointF> pts;
        auto startAngle = qDegreesToRadians(rotation);
        auto incrementAngle = qDegreesToRadians(360.0f / numPoints);
        qreal dx, dy;
        
        for (auto i = 0; i < numPoints; i ++)
        {
            dx = cos(startAngle) * scaledSizeWidth;
            dy = sin(startAngle) * scaledSizeHeight;
            
            pts << QPointF(dx, dy);
            
            startAngle += incrementAngle;
        }
        
        auto count = pts.count();
        QPointF pt0, pt1, pt2;
        qreal ab, ac;
        QPointF startPt, ctrlPt1, ctrlPt2, endPt;
        
        QPainterPath path = QPainterPath();
        
        for (auto i = 0; i < count; i ++)
        {
            pt0 = pts[i];
            pt1 = i >= count-1 ? pts[0] : pts[i+1];
            pt2 = i == 0 ? pts[count-1] : pts[i-1];
            
            ab = atan2(pt1.y() - pt0.y(), pt1.x() - pt0.x());
            ac = atan2(pt2.y() - pt0.y(), pt2.x() - pt0.x());
            
            startPt = QPointF(cos(ac) * cornerRadius + pt0.x(), sin(ac) * cornerRadius + pt0.y());
            ctrlPt1 = QPointF(cos(ac) * scaledCornerRadius + pt0.x(), sin(ac) * scaledCornerRadius + pt0.y());
            ctrlPt2 = QPointF(cos(ab) * scaledCornerRadius + pt0.x(), sin(ab) * scaledCornerRadius + pt0.y());
            endPt = QPointF(cos(ab) * cornerRadius + pt0.x(), sin(ab) * cornerRadius + pt0.y());
            
            if (i <= 0)
            {
                path.moveTo(startPt);
            }
            else
            {
                path.lineTo(startPt);
            }
            
            path.cubicTo(ctrlPt1, ctrlPt2, endPt);
        }
        
        path.closeSubpath();
        
        return path;
    }
    
    
    auto PainterPathUtility::createTorpedoPath(const QSize size,
                                               const qreal cornerRadius) -> QPainterPath
    {
        qreal dxy = size.height() + (cornerRadius * 2);
        QPainterPath head = PainterPathUtility::createTrianglePath(3,
                                                                   180,
                                                                   QSize(dxy, dxy),
                                                                   cornerRadius);
        QTransform transform;
        transform.translate((size.height() * 0.5f), size.height() * 0.5f);
        
        QPainterPath body = QPainterPath();
        body.addRect(QRectF(head.boundingRect().width() - cornerRadius,
                            0.0f,
                            size.width() - (head.boundingRect().width() + (size.height() * 0.5f)),
                            size.height()));
        
        QPainterPath tail = QPainterPath();
        tail.addEllipse(QRectF(size.width() - size.height(),
                               0.0f,
                               size.height(),
                               size.height()));
        
        QPainterPath path = QPainterPath();
        path.addPath(transform.map(head));
        path = path.united(body);
        path = path.united(tail);
        
        return path;
    }
}


