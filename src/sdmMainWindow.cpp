//
//  sdmMainWindow.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 06/01/2016.
//
//

#include "sdmMainWindow.h"

#include "spencers-dm/cecropia-graph/sdmNodeScene.h"
#include "spencers-dm/cecropia-graph/sdmNodeView.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Use auto by default: performance, tracks return type, usability.
    auto scene = make_unique<spencers::NodeScene>(this);
    auto view = make_unique<spencers::NodeView>(this);
    
    view->setScene(scene.release());
    setCentralWidget(view.release());
}


