# ----------------------------------------------------
# WLDEV.RU WLMill
# ------------------------------------------------------

TEMPLATE = app
TARGET = wlmill
QT += core widgets serialport gui network opengl script


QMAKE_LFLAGS = -no-pie

#DEFINES += QT_NO_DEBUG_OUTPUT\
#           QT_NO_INFO_OUTPUT\
#           QT_NO_WARNING_OUTPUT\


DEFINES += DEF_HMAP

VERSION = 1.0.0

QMAKE_TARGET_COMPANY = WLDEV
QMAKE_TARGET_PRODUCT = WLMill
#QMAKE_TARGET_DESCRIPTION = Long thoughtful description
QMAKE_TARGET_COPYRIGHT = (c) WLDEV.RU

#CONFIG += debug release
CONFIG += c++11

#LIBS += -lOpengl32 -lglu32 -lcomdlg32

INCLUDEPATH +=\
           src\
           script\
           widget\
           shader\
           model


TRANSLATIONS += wlmill_ru.ts

HEADERS += \
    widget/wldevicewidget.h \
    widget/wldrivewidget.h \
    widget/wleditiowidget.h \
    widget/wledittext.h \
    widget/wlenternum.h \
    widget/wlenterstring.h \
    widget/wlgprogramwidget.h \
    widget/wliowidget.h \
    widget/wlmessmanager.h \
    widget/wlpamlistwidget.h \
    widget/wlpamwidget.h \
    widget/wlgmodelwidget.h \
    widget/wlaxiswidget.h \
    widget/wlmpgwidget.h \
    widget/wleditmpgwidget.h \
    widget/wlconsolemodbus.h \
    widget/wlpidwidget.h \
    widget/wlcodeeditor.h \
    widget/wlheightmapwidget.h \
    widget/wleditmillwidget.h \
    widget/wlpositionwidget.h \
    widget/wlvisualwidget.h \
    widget/wltoolswidget.h \
    widget/wltoolswidget.h \
    widget/wlgaxislabel.h \
    widget/wleditpoint.h \
    widget/wlgdrivewidget.h \
    src/wl3dpoint.h \
    src/wlcalc.h \
    src/wldrive.h \
    src/wlelementtraj.h \
    src/wlflags.h \
    src/wlframe.h \
    src/wlgcode.h \
    src/wlgcodesh.h \
    src/wlgmodel.h \
    src/wlgprogram.h \
    src/wllabel.h \
    src/wllog.h \
    src/wlmcodesh.h \
    src/wlopengl.h \
    src/wlpad.h \
    src/wlgtool.h \
    src/wlgpoint.h \
    src/wlmachine.h \
    src/wleditgcode.h \
    src/wldoublespinbox.h \
    src/wljoysticks.h \
    src/wlheightmap.h \
    src/wlgmachine.h \
    src/wlmill.h \
    src/wlgdrive.h \
    model/wlheightmaptablemodel.h \
    model/wlgtoolstablemodel.h

 SOURCES += \
    widget/wldevicewidget.cpp \
    widget/wldrivewidget.cpp \
    widget/wleditiowidget.cpp \
    widget/wledittext.cpp \
    widget/wlenternum.cpp \
    widget/wlenterstring.cpp \
    widget/wlgprogramwidget.cpp \
    widget/wliowidget.cpp \
    widget/wlmessmanager.cpp \
    widget/wlpamlistwidget.cpp \
    widget/wlpamwidget.cpp \
    widget/wlgmodelwidget.cpp \
    widget/wlaxiswidget.cpp \
    widget/wlmpgwidget.cpp \
    widget/wleditmpgwidget.cpp \
    widget/wlconsolemodbus.cpp \
    widget/wlpidwidget.cpp \
    widget/wlcodeeditor.cpp \
    widget/wlheightmapwidget.cpp \
    widget/wlvisualwidget.cpp \
    widget/wlgaxislabel.cpp \
    widget/wltoolswidget.cpp \
    widget/wleditmillwidget.cpp \
    widget/wleditpoint.cpp \
    widget/wlpositionwidget.cpp \
    widget/wlgdrivewidget.cpp \
    src/wl3dpoint.cpp \
    src/wlcalc.cpp \
    src/wldrive.cpp \
    src/wlflags.cpp \
    src/wlgcode.cpp \
    src/wlgcodesh.cpp \
    src/wlgmodel.cpp \
    src/wlgprogram.cpp \
    src/wllabel.cpp \
    src/wllog.cpp \
    src/wlmcodesh.cpp \
    src/wlopengl.cpp \
    src/wlpad.cpp \
    src/wlmachine.cpp \
    src/wleditgcode.cpp \
    src/wldoublespinbox.cpp \
    src/wlelementtraj.cpp \
    src/wljoysticks.cpp \
    src/wlheightmap.cpp \
    src/wlgtool.cpp \
    src/wlgpoint.cpp \
    src/wlgmachine.cpp \
    src/wlmill.cpp \
    src/wlgdrive.cpp \
    model/wlheightmaptablemodel.cpp \
    model/wlgtoolstablemodel.cpp \
    main.cpp


FORMS += \
    widget/wldevicewidget.ui \
    widget/wldrivewidget.ui \
    widget/wleditiowidget.ui \
    widget/wledittext.ui \
    widget/wlenternum.ui \
    widget/wlenterstring.ui \
    widget/wlgprogramwidget.ui \
    widget/wliowidget.ui \
    widget/wlmessmanager.ui \
    widget/wlpamlistwidget.ui \
    widget/wlpamwidget.ui \
    widget/wlframewidget.ui \
    widget/wlgmodelwidget.ui \
    widget/wlaxiswidget.ui \
    widget/wlmpgwidget.ui \
    widget/wleditmpgwidget.ui \
    widget/wlconsolemodbus.ui \
    widget/wlpidwidget.ui \
    widget/wleditgcode.ui \
    widget/wleditmillwidget.ui \
    widget/wlheightmapwidget.ui\    
    widget/wlpositionwidget.ui \
    widget/wleditpoint.ui \
    widget/wltoolswidget.ui \
    widget/wlgdrivewidget.ui


RESOURCES += \
    image.qrc \
    shaders.qrc \
    config.qrc \
    qml.qrc

win32:RC_ICONS +=wlmill.ico

include (QJoysticks/QJoysticks.pri)
include (wlmotion/WLMotion.pri)
include (wlscript/WLScript.pri)

DISTFILES += \
    data/icons/play-red.png \
    data/icons/cancel.png \
    data/icons/wl.png \
    data/icons/wl.png
