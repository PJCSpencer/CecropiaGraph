//
//  sdmBezierScrollerAnimation.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 25/04/2016.
//
//

#ifndef sdmBezierScrollerAnimation_h
#define sdmBezierScrollerAnimation_h

/// \file sdmBezierScrollerAnimation.h
///
/// \brief Contains the definition of the BezierScrollerAnimation class.
///

#include <QObject>
#include <QTimeLine>

#include <math.h>
#include <iostream>


namespace spencers
{
    ///
    /// \brief BezierScrollerAnimation class.
    ///
    class BezierScrollerAnimation : public QObject
    {
        Q_OBJECT
        
    public:
        
        ///
        /// \brief Constructor.
        ///
        /// \param [in] parent  Parent of this object.
        ///
        explicit BezierScrollerAnimation(int itemIndex, int utilityIndex, int duration);
        
        ///
        /// \brief The item index for this BezierScrollerAnimation.
        ///
        /// \return                     An int.
        ///
        auto itemIndex() -> int { return _itemIndex; };
        
        ///
        /// \brief The utility index for this BezierScrollerAnimation.
        ///
        /// \return                     An int.
        ///
        auto utilityIndex() -> int { return _utilityIndex; };
        
        ///
        /// \brief The value for this BezierScrollerAnimation.
        ///
        /// \return                     An qreal.
        ///
        auto value() -> qreal { return _value; };
        
        ///
        /// \brief Sets the from value for this BezierScrollerAnimation.
        ///
        /// \param [in] value           The qreal.
        ///
        void setFromValue(const qreal value);
        
        ///
        /// \brief Sets the to value for this BezierScrollerAnimation.
        ///
        /// \param [in] value           The qreal.
        ///
        void setToValue(const qreal value);
        
        ///
        /// \brief Starts the animation.
        ///
        void start();
        
    public slots:
        
        ///
        /// \brief Called when the animation updates.
        ///
        /// \param [out] value          A qreal representing the current value.
        ///
        void update(qreal value);
        
    signals:
        
        ///
        /// \brief Emitted when the animation changes.
        ///
        /// \param [out] animation      The object which has changed, this.
        ///
        void valueChanged(BezierScrollerAnimation* animation);
        
    private:
        
        ///
        /// \brief Item index
        ///
        int _itemIndex;
        
        ///
        /// \brief Item index
        ///
        int _utilityIndex;
        
        ///
        /// \brief The QTimeLine used to drive this BezierScrollerAnimation.
        ///
        QTimeLine _timeline;
        
        ///
        /// \brief The current value.
        ///
        qreal _value;
        
        ///
        /// \brief The from value.
        ///
        qreal _fromValue;
        
        ///
        /// \brief The to value.
        ///
        qreal _toValue;
    };
}

#endif


