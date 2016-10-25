//
//  sdmConstants.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 17/05/2016.
//
//

#include "sdmConstants.h"


namespace spencers
{
    // Key.
    const QString Keys::Path = "path";
    
    const QString Keys::Input = "input";
    const QString Keys::Output = "output";
    const QString Keys::Target = "target";
    
    const QString Keys::Index = "index";
    
    const QString Keys::UId = "uid";
    const QString Keys::Name = "name";
    const QString Keys::Title = "title";
    
    const QString Keys::Icon = "icon";
    const QString Keys::Image = "image";
    const QString Keys::Colour = "colour";
    
    const QString Keys::Blueprint = "blueprint";
    const QString Keys::Type = "type";
    const QString Keys::DataType = "dataType";
    const QString Keys::Connections = "connections";
    const QString Keys::Ports = "ports";

    
    // DataType Key(s).
    const QString DataTypeKeys::Unkown = "com.spencers-dm.port.data-type.unkown";
    const QString DataTypeKeys::Boolean = "com.spencers-dm.port.data-type.boolean";
    const QString DataTypeKeys::Integer = "com.spencers-dm.port.data-type.int";
    const QString DataTypeKeys::Qreal = "com.spencers-dm.port.data-type.qreal";
    const QString DataTypeKeys::String = "com.spencers-dm.port.data-type.string";
    
    
    // DataKey.
    const int DataKeys::Path        = 1001;
    
    
    // Placeholder.
    const QString Placeholder::Filter = "Filter";
}


