//
//  sdmMainWindow.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 21/02/2016.
//
//

#ifndef sdmMainWindow_h
#define sdmMainWindow_h

/// \file sdmMainWindow.h
///
/// \brief Contains the definition of the MainWindow class.
///

#include <QMainWindow>
#include <QApplication>
#include <QSettings>

#include <memory>

using std::unique_ptr;
using std::make_unique;

///
/// \brief Styles class.
///
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    
    ///
    /// \brief Constructor.
    ///
    /// \param parent       Qt parent.
    ///
    MainWindow(QWidget *parent=0);
};

#endif


