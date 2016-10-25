//
//  sdmStyles.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 28/04/2016.
//
//

#ifndef sdmStyles_h
#define sdmStyles_h

/// \file sdmStyles.h
///
/// \brief Contains the definition of the Styles class.
///

#include <QObject>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QFont>

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;


namespace spencers
{
    ///
    /// \brief Styles class.
    ///
    class Styles : public QObject // TODO:Support library ...
    {
    public: // Colour.
        
        ///
        /// \brief Creates a NodeControl gradient brush.
        ///
        /// \param [in] white           The level of white to apply.
        ///
        /// \return                     A new QColor object.
        ///
        static auto whiteColor(const int white, const int alpha = 255) -> const QColor;
        
        ///
        /// \brief Highlight QColor object.
        ///
        static auto highlightColor() -> const QColor;
        
        ///
        /// \brief Electric blue QColor object.
        ///
        static const QColor electricBlueColor;
        
        ///
        /// \brief Vibrant green QColor object.
        ///
        static const QColor vibrantGreenColor;
        
        ///
        /// \brief Lush pink QColor object.
        ///
        static const QColor lushPinkColor;
        
        ///
        /// \brief Downtown QColor object.
        ///
        static const QColor downtownColor;
        
        ///
        /// \brief SilverStreak QColor object.
        ///
        static const QColor silverStreakColor;
        
    public: // Pen.
        
        ///
        /// \brief NodeControl background QPen.
        ///
        static const QPen nodeBackgroundPen;
        
        ///
        /// \brief NodeControl selected QPen.
        ///
        static const QPen nodeSelectedPen;
        
        ///
        /// \brief NodeControl highlighted text QPen.
        ///
        static const QPen highlightedTextPen;
        
        ///
        /// \brief Downtown solid QPen.
        ///
        static const QPen downtownSolidPen;
        
        ///
        /// \brief Downtown dashed QPen.
        ///
        static const QPen downtownDashedPen;
        
    public: // Brush.
        
        ///
        /// \brief Creates a NodeControl gradient brush.
        ///
        /// \param [in] height          The height for gradient.
        ///
        /// \return                     A new QBrush object.
        ///
        static auto silverStreakBrush(const qreal height) -> const QBrush;
        
    public: // Font.
        
        ///
        /// \brief Creates a font.
        ///
        /// \param [in] white           The weight for font.
        /// \param [in] pointSize       The point size for font.
        ///
        /// \return                     A new QFont object.
        ///
        static auto defaultFont(int weight = QFont::Medium, int pointSize = 13) -> const QFont*;
    };
}

#endif


