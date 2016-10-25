//
//  sdmConstants.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 17/05/2016.
//
//

#ifndef sdmConstants_h
#define sdmConstants_h

#include <QString>


namespace spencers
{
    class Keys
    {
    public:
        
        static const QString Path;
        
        static const QString Input;
        static const QString Output;
        static const QString Target;
        
        static const QString Index;
        
        static const QString UId;
        static const QString Name;
        static const QString Title;
        
        static const QString Icon;
        static const QString Image;
        static const QString Colour;
        
        static const QString Blueprint;
        static const QString Type;
        static const QString DataType;
        static const QString Connections;
        static const QString Ports;
    };
    
    
    class DataTypeKeys
    {
    public:
        static const QString Unkown;
        static const QString Boolean;
        static const QString Integer;
        static const QString Qreal;
        static const QString String;
    };
    
    
    class DataKeys
    {
    public:
        static const int Path;
    };
    
    
    class Placeholder
    {
    public:
        
        static const QString Filter;
    };
    
    
    enum class SimpleShape
    {
        NoShape = 1001,
        Circle,
        Square,
        Custom,
    };
    
    
    enum class ImagePosition
    {
        NoPosition = 1001,
        Left,
        Right,
        Middle,
    };
}

#endif


