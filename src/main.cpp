//
//  main.cpp
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 06/01/2016.
//
//

#include <QApplication>
#include <QDesktopWidget>

#include "sdmMainwindow.h"


///
/// \brief Main function of this application.
///
/// \param [in] argc    The number of strings pointed to by argv.
/// \param [in] argv    Name of the programm + misc.
///
/// \return             0 if the application ran successfully, otherwise an error code.
///

int main(int argc, char *argv[])
{
    // Create application instance.
    QApplication app(argc, argv);
    app.setOrganizationDomain("www.spencers-digital-media.com");
    app.setApplicationName("CecropiaGraph");
    
    auto scale = 0.8f;
    auto width = 1280 * scale;
    auto height = 720 * scale;

    // Create main window.
    MainWindow window;
    window.resize(width, height);
    window.move((QApplication::desktop()->width() - width) * 0.5f,
                (QApplication::desktop()->height() - height) * 0.5f);
    window.show();
    
    // Begin execution loop.
    int result = app.exec();

    return result;
}


