//
//  sdmStyles.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 28/04/2016.
//
//

#include "sdmStyles.h"


namespace spencers
{
    auto Styles::whiteColor(const int white, const int alpha) -> const QColor
    {
        return QColor(white, white, white, alpha);
    }
    
    
    auto Styles::highlightColor() -> const QColor // TODO:Platform support ...
    {
        return QColor(57, 131, 254);
    }
    
    
    const QColor Styles::electricBlueColor = QColor(40, 155, 235);
    
    
    const QColor Styles::vibrantGreenColor = QColor(85, 200, 0);
    
    
    const QColor Styles::lushPinkColor = QColor(255, 0, 127);
    
    
    const QColor Styles::downtownColor = Styles::whiteColor(100); // 75
    
    
    const QColor Styles::silverStreakColor = Styles::whiteColor(215);
    
    
    const QPen Styles::nodeBackgroundPen = QPen(Styles::whiteColor(225), 1);

    
    const QPen Styles::nodeSelectedPen = QPen(QColor(250, 210, 0), 2.0f);
    
    
    const QPen Styles::highlightedTextPen = QPen(QColor(128, 180, 240), 3);
    
    
    const QPen Styles::downtownSolidPen = QPen(Styles::downtownColor, 1.75f);
    
    
    const QPen Styles::downtownDashedPen = QPen(Styles::downtownColor, 1.5f, Qt::DashLine);
    
    
    auto Styles::silverStreakBrush(const qreal height) -> const QBrush
    {
        auto sample = 235;
        
        QLinearGradient gradient(0, 0, 0, height);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setColorAt(0, Styles::whiteColor(sample));
        gradient.setColorAt(1, Styles::whiteColor(sample - 25));
        
        return gradient;
    }
    
    
    auto Styles::defaultFont(int weight, int pointSize) -> const QFont*
    {
        auto font = make_unique<QFont>("Menlo", pointSize, weight);
        font->setStyleHint(QFont::SansSerif, QFont::PreferQuality);
        
        return font.release();
    }
}


