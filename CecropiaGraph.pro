
QT          += core gui widgets
CONFIG      += c++11 static
DEFINES     *= QT_USE_QSTRINGBUILDER

static {
    QT  += svg
}

unix {
    QMAKE_CXX =  g++
}

TARGET = CecropiaGraph
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = Generated-Files/Release
}
CONFIG(release, debug|release) {
    DESTDIR = Generated-Files/Debug
}

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
RCC_DIR = $$DESTDIR/qrc
UI_DIR = $$DESTDIR/u

SOURCES += \
    src/main.cpp \
    src/sdmMainWindow.cpp \
    src/spencers-dm/cecropia-graph/sdmConstants.cpp \
    src/spencers-dm/cecropia-graph/sdmNodeLibrary.cpp \
    src/spencers-dm/cecropia-graph/sdmNodeView.cpp \
    src/spencers-dm/cecropia-graph/sdmNodeScene.cpp \
    src/spencers-dm/cecropia-graph/sdmNodeControl.cpp \
    src/spencers-dm/cecropia-graph/sdmNodeControlWidget.cpp \
    src/spencers-dm/cecropia-graph/sdmBezierScroller.cpp \
    src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.cpp \
    src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.cpp \
    src/spencers-dm/cecropia-graph/sdmPlug.cpp \
    src/spencers-dm/cecropia-graph/sdmPlugGroup.cpp \
    src/spencers-dm/cecropia-graph/sdmPlugConnection.cpp \
    src/spencers-dm/cecropia-graph/sdmPlugConnectionWidget.cpp \
    src/spencers-dm/cecropia-graph/sdmSimpleImageItem.cpp \
    src/spencers-dm/cecropia-graph/sdmCustomTextItem.cpp \
    src/spencers-dm/cecropia-graph/sdmSimpleMatrixItem.cpp \
    src/spencers-dm/cecropia-graph/sdmFilterListWidget.cpp \
    src/spencers-dm/cecropia-graph/sdmFilterListStyleDelegate.cpp \
    src/spencers-dm/cecropia-graph/sdmCustomListStyleDelegate.cpp \
    src/spencers-dm/cecropia-graph/sdmPainterPathUtility.cpp \
    src/spencers-dm/cecropia-graph/sdmStyles.cpp

HEADERS += \
    src/sdmMainwindow.h \
    src/spencers-dm/cecropia-graph/sdmConstants.h \
    src/spencers-dm/cecropia-graph/sdmNodeLibrary.h \
    src/spencers-dm/cecropia-graph/sdmNodeView.h \
    src/spencers-dm/cecropia-graph/sdmNodeScene.h \
    src/spencers-dm/cecropia-graph/sdmNodeControl.h \
    src/spencers-dm/cecropia-graph/sdmNodeControlWidget.h \
    src/spencers-dm/cecropia-graph/sdmBezierScroller.h \
    src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.h \
    src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.h \
    src/spencers-dm/cecropia-graph/sdmPlug.h \
    src/spencers-dm/cecropia-graph/sdmPlugGroup.h \
    src/spencers-dm/cecropia-graph/sdmPlugConnection.h \
    src/spencers-dm/cecropia-graph/sdmPlugConnectionWidget.h \
    src/spencers-dm/cecropia-graph/sdmSimpleImageItem.h \
    src/spencers-dm/cecropia-graph/sdmCustomTextItem.h \
    src/spencers-dm/cecropia-graph/sdmSimpleMatrixItem.h \
    src/spencers-dm/cecropia-graph/sdmFilterListWidget.h \
    src/spencers-dm/cecropia-graph/sdmFilterListStyleDelegate.h \
    src/spencers-dm/cecropia-graph/sdmCustomListStyleDelegate.h \
    src/spencers-dm/cecropia-graph/sdmPainterPathUtility.h \
    src/spencers-dm/cecropia-graph/sdmStyles.h

RESOURCES += \
    res/svg/icons.qrc
