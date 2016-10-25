//
//  sdmBezierScrollerAnimation.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 25/04/2016.
//
//

#include "sdmBezierScrollerAnimation.h"



namespace spencers
{
    BezierScrollerAnimation::BezierScrollerAnimation(int itemIndex, int utilityIndex, int duration)
    : _itemIndex(itemIndex)
    , _utilityIndex(utilityIndex)
    , _timeline(duration)
    {
        // Configure.
        _timeline.setCurveShape(QTimeLine::EaseInOutCurve);
        
        // Bind.
        connect(&_timeline,
                SIGNAL(valueChanged(qreal)),
                this,
                SLOT(update(qreal)));
    }
    
    
    void BezierScrollerAnimation::setFromValue(const qreal value)
    {
        _fromValue = value;
    }
    

    void BezierScrollerAnimation::setToValue(const qreal value)
    {
        _toValue = value;
    }
    
    
    void BezierScrollerAnimation::start()
    {
        _value = _fromValue;
        
        if (_timeline.state() == QTimeLine::NotRunning)
        {
            _timeline.start();
        }
    }
    
    
    void BezierScrollerAnimation::update(qreal value)
    {
        _value = (_fromValue + value * (_toValue - _fromValue));
        
        emit valueChanged(this);
        
        if (_timeline.currentValue() >= 1.0f)
        {
            _timeline.stop();
        }
    }
}


