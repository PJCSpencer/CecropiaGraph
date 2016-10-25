#############################################################################
# Makefile for building: Generated-Files/Debug/CecropiaGraph.app/Contents/MacOS/CecropiaGraph
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  CecropiaGraph.pro
# Template: app
# Command: /Users/Home/Documents/Qt/5.5/clang_64/bin/qmake -spec macx-xcode -o CecropiaGraph.xcodeproj/project.pbxproj CecropiaGraph.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/Home/Documents/Qt/5.5/clang_64/bin/moc
UIC       = /Users/Home/Documents/Qt/5.5/clang_64/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_USE_QSTRINGBUILDER -DQT_NO_DEBUG -DQT_SVG_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I. -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -IGenerated-Files/Debug/moc -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/System/Library/Frameworks/AGL.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -F/Users/Home/Documents/Qt/5.5/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compilers: Generated-Files/Debug/qrc/qrc_icons.cpp Generated-Files/Debug/moc/moc_sdmMainwindow.cpp Generated-Files/Debug/moc/moc_sdmNodeView.cpp Generated-Files/Debug/moc/moc_sdmNodeScene.cpp\
	 Generated-Files/Debug/moc/moc_sdmNodeControl.cpp Generated-Files/Debug/moc/moc_sdmNodeControlWidget.cpp Generated-Files/Debug/moc/moc_sdmBezierScroller.cpp\
	 Generated-Files/Debug/moc/moc_sdmBezierScrollerItem.cpp Generated-Files/Debug/moc/moc_sdmBezierScrollerAnimation.cpp Generated-Files/Debug/moc/moc_sdmPlug.cpp\
	 Generated-Files/Debug/moc/moc_sdmPlugGroup.cpp Generated-Files/Debug/moc/moc_sdmPlugConnection.cpp Generated-Files/Debug/moc/moc_sdmPlugConnectionWidget.cpp\
	 Generated-Files/Debug/moc/moc_sdmSimpleImageItem.cpp Generated-Files/Debug/moc/moc_sdmCustomTextItem.cpp Generated-Files/Debug/moc/moc_sdmSimpleMatrixItem.cpp\
	 Generated-Files/Debug/moc/moc_sdmFilterListWidget.cpp
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all: Generated-Files/Debug/qrc/qrc_icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) Generated-Files/Debug/qrc/qrc_icons.cpp
Generated-Files/Debug/qrc/qrc_icons.cpp: res/svg/icons.qrc \
		res/svg/DisclosureNegative.svg \
		res/svg/DisclosurePositive.svg
	/Users/Home/Documents/Qt/5.5/clang_64/bin/rcc -name icons res/svg/icons.qrc -o Generated-Files/Debug/qrc/qrc_icons.cpp

compiler_moc_header_make_all: Generated-Files/Debug/moc/moc_sdmMainwindow.cpp Generated-Files/Debug/moc/moc_sdmNodeView.cpp Generated-Files/Debug/moc/moc_sdmNodeScene.cpp Generated-Files/Debug/moc/moc_sdmNodeControl.cpp Generated-Files/Debug/moc/moc_sdmNodeControlWidget.cpp Generated-Files/Debug/moc/moc_sdmBezierScroller.cpp Generated-Files/Debug/moc/moc_sdmBezierScrollerItem.cpp Generated-Files/Debug/moc/moc_sdmBezierScrollerAnimation.cpp Generated-Files/Debug/moc/moc_sdmPlug.cpp Generated-Files/Debug/moc/moc_sdmPlugGroup.cpp Generated-Files/Debug/moc/moc_sdmPlugConnection.cpp Generated-Files/Debug/moc/moc_sdmPlugConnectionWidget.cpp Generated-Files/Debug/moc/moc_sdmSimpleImageItem.cpp Generated-Files/Debug/moc/moc_sdmCustomTextItem.cpp Generated-Files/Debug/moc/moc_sdmSimpleMatrixItem.cpp Generated-Files/Debug/moc/moc_sdmFilterListWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) Generated-Files/Debug/moc/moc_sdmMainwindow.cpp Generated-Files/Debug/moc/moc_sdmNodeView.cpp Generated-Files/Debug/moc/moc_sdmNodeScene.cpp Generated-Files/Debug/moc/moc_sdmNodeControl.cpp Generated-Files/Debug/moc/moc_sdmNodeControlWidget.cpp Generated-Files/Debug/moc/moc_sdmBezierScroller.cpp Generated-Files/Debug/moc/moc_sdmBezierScrollerItem.cpp Generated-Files/Debug/moc/moc_sdmBezierScrollerAnimation.cpp Generated-Files/Debug/moc/moc_sdmPlug.cpp Generated-Files/Debug/moc/moc_sdmPlugGroup.cpp Generated-Files/Debug/moc/moc_sdmPlugConnection.cpp Generated-Files/Debug/moc/moc_sdmPlugConnectionWidget.cpp Generated-Files/Debug/moc/moc_sdmSimpleImageItem.cpp Generated-Files/Debug/moc/moc_sdmCustomTextItem.cpp Generated-Files/Debug/moc/moc_sdmSimpleMatrixItem.cpp Generated-Files/Debug/moc/moc_sdmFilterListWidget.cpp
Generated-Files/Debug/moc/moc_sdmMainwindow.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QApplication \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QSettings \
		src/sdmMainwindow.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/sdmMainwindow.h -o Generated-Files/Debug/moc/moc_sdmMainwindow.cpp

Generated-Files/Debug/moc/moc_sdmNodeView.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsView \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGestureEvent \
		src/spencers-dm/cecropia-graph/sdmFilterListWidget.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QLineEdit \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QListView \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QStandardItemModel \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QFileSystemModel \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QModelIndexList \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QString \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFontMetrics \
		src/spencers-dm/cecropia-graph/sdmConstants.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		src/spencers-dm/cecropia-graph/sdmFilterListStyleDelegate.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QStyledItemDelegate \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QIcon \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPixmap \
		src/spencers-dm/cecropia-graph/sdmCustomListStyleDelegate.h \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmNodeControlWidget.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QVariant \
		src/spencers-dm/cecropia-graph/sdmPlugConnectionWidget.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		src/spencers-dm/cecropia-graph/sdmNodeView.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmNodeView.h -o Generated-Files/Debug/moc/moc_sdmNodeView.cpp

Generated-Files/Debug/moc/moc_sdmNodeScene.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsScene \
		src/spencers-dm/cecropia-graph/sdmConstants.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QString \
		src/spencers-dm/cecropia-graph/sdmNodeLibrary.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QStandardPaths \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QDir \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QStandardItemModel \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QFileSystemModel \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QJsonParseError \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QJsonDocument \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QJsonObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QJsonValue \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QJsonArray \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QHash \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QList \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QVariant \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		src/spencers-dm/cecropia-graph/sdmNodeControl.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QIcon \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsRectItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsEllipseItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QButtonGroup \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QPushButton \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QDrag \
		src/spencers-dm/cecropia-graph/sdmBezierScroller.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QtMath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QTimeLine \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QLineF \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsItemGroup \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsSimpleTextItem \
		src/spencers-dm/cecropia-graph/sdmPlugGroup.h \
		src/spencers-dm/cecropia-graph/sdmPainterPathUtility.h \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.h \
		src/spencers-dm/cecropia-graph/sdmSimpleImageItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPixmap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMargins \
		src/spencers-dm/cecropia-graph/sdmCustomTextItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsTextItem \
		src/spencers-dm/cecropia-graph/sdmNodeScene.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmNodeScene.h -o Generated-Files/Debug/moc/moc_sdmNodeScene.cpp

Generated-Files/Debug/moc/moc_sdmNodeControl.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QIcon \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsRectItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsEllipseItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QButtonGroup \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QPushButton \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QDrag \
		src/spencers-dm/cecropia-graph/sdmConstants.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QString \
		src/spencers-dm/cecropia-graph/sdmBezierScroller.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QList \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QtMath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QTimeLine \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QLineF \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsItemGroup \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsSimpleTextItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		src/spencers-dm/cecropia-graph/sdmPlugGroup.h \
		src/spencers-dm/cecropia-graph/sdmPainterPathUtility.h \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.h \
		src/spencers-dm/cecropia-graph/sdmSimpleImageItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPixmap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMargins \
		src/spencers-dm/cecropia-graph/sdmCustomTextItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsTextItem \
		src/spencers-dm/cecropia-graph/sdmNodeControl.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmNodeControl.h -o Generated-Files/Debug/moc/moc_sdmNodeControl.cpp

Generated-Files/Debug/moc/moc_sdmNodeControlWidget.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QVariant \
		src/spencers-dm/cecropia-graph/sdmNodeControlWidget.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmNodeControlWidget.h -o Generated-Files/Debug/moc/moc_sdmNodeControlWidget.cpp

Generated-Files/Debug/moc/moc_sdmBezierScroller.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QList \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QtMath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QTimeLine \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QLineF \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsItemGroup \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsSimpleTextItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		src/spencers-dm/cecropia-graph/sdmPlugGroup.h \
		src/spencers-dm/cecropia-graph/sdmPainterPathUtility.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.h \
		src/spencers-dm/cecropia-graph/sdmBezierScroller.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmBezierScroller.h -o Generated-Files/Debug/moc/moc_sdmBezierScroller.cpp

Generated-Files/Debug/moc/moc_sdmBezierScrollerItem.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsItemGroup \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsSimpleTextItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QtMath \
		src/spencers-dm/cecropia-graph/sdmPlugGroup.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QList \
		src/spencers-dm/cecropia-graph/sdmPainterPathUtility.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmBezierScrollerItem.h -o Generated-Files/Debug/moc/moc_sdmBezierScrollerItem.cpp

Generated-Files/Debug/moc/moc_sdmBezierScrollerAnimation.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QTimeLine \
		src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmBezierScrollerAnimation.h -o Generated-Files/Debug/moc/moc_sdmBezierScrollerAnimation.cpp

Generated-Files/Debug/moc/moc_sdmPlug.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsEllipseItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsOpacityEffect \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QPropertyAnimation \
		src/spencers-dm/cecropia-graph/sdmPlug.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmPlug.h -o Generated-Files/Debug/moc/moc_sdmPlug.cpp

Generated-Files/Debug/moc/moc_sdmPlugGroup.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QList \
		src/spencers-dm/cecropia-graph/sdmPlugGroup.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmPlugGroup.h -o Generated-Files/Debug/moc/moc_sdmPlugGroup.cpp

Generated-Files/Debug/moc/moc_sdmPlugConnection.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QStyleOptionGraphicsItem \
		src/spencers-dm/cecropia-graph/sdmPlugConnection.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmPlugConnection.h -o Generated-Files/Debug/moc/moc_sdmPlugConnection.cpp

Generated-Files/Debug/moc/moc_sdmPlugConnectionWidget.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		src/spencers-dm/cecropia-graph/sdmPlugConnectionWidget.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmPlugConnectionWidget.h -o Generated-Files/Debug/moc/moc_sdmPlugConnectionWidget.cpp

Generated-Files/Debug/moc/moc_sdmSimpleImageItem.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPixmap \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QIcon \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QMargins \
		src/spencers-dm/cecropia-graph/sdmConstants.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QString \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmSimpleImageItem.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmSimpleImageItem.h -o Generated-Files/Debug/moc/moc_sdmSimpleImageItem.cpp

Generated-Files/Debug/moc/moc_sdmCustomTextItem.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsTextItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		src/spencers-dm/cecropia-graph/sdmCustomTextItem.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmCustomTextItem.h -o Generated-Files/Debug/moc/moc_sdmCustomTextItem.cpp

Generated-Files/Debug/moc/moc_sdmSimpleMatrixItem.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainterPath \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsEllipseItem \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QGraphicsPathItem \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmPainterPathUtility.h \
		src/spencers-dm/cecropia-graph/sdmSimpleMatrixItem.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmSimpleMatrixItem.h -o Generated-Files/Debug/moc/moc_sdmSimpleMatrixItem.cpp

Generated-Files/Debug/moc/moc_sdmFilterListWidget.cpp: /Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QLineEdit \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QListView \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QStandardItemModel \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QFileSystemModel \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QModelIndexList \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QString \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFontMetrics \
		src/spencers-dm/cecropia-graph/sdmConstants.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers/QObject \
		src/spencers-dm/cecropia-graph/sdmFilterListStyleDelegate.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers/QStyledItemDelegate \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPainter \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QIcon \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPixmap \
		src/spencers-dm/cecropia-graph/sdmCustomListStyleDelegate.h \
		src/spencers-dm/cecropia-graph/sdmStyles.h \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QPen \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QBrush \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QColor \
		/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers/QFont \
		src/spencers-dm/cecropia-graph/sdmFilterListWidget.h
	/Users/Home/Documents/Qt/5.5/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Home/Documents/Qt/5.5/clang_64/mkspecs/macx-clang -I/Users/Home/Documents/Work/Projects/Qt/QtProject-Template/Xcode -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtSvg.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtWidgets.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtGui.framework/Headers -I/Users/Home/Documents/Qt/5.5/clang_64/lib/QtCore.framework/Headers -F/Users/Home/Documents/Qt/5.5/clang_64/lib src/spencers-dm/cecropia-graph/sdmFilterListWidget.h -o Generated-Files/Debug/moc/moc_sdmFilterListWidget.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_header_clean 
