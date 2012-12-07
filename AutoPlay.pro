#-------------------------------------------------
#
# Project created by QtCreator 2010-07-29T04:47:56
#
#-------------------------------------------------

QT       += core gui declarative

TARGET = AutoPlay
TEMPLATE = app

OBJECTS_DIR = tmp
MOC_DIR = tmp

SOURCES += main.cpp \
        autoplay.cpp \
#    DeclarativeDragArea.cpp \
#    DeclarativeMimeData.cpp \
#    DeclarativeDropArea.cpp \
#    DeclarativeDragDropEvent.cpp \
    directorymodel.cpp \
    cpcap.cpp \
    cusbprotocol.cpp \
    cmouse.cpp \
    ckeyboard.cpp \
    cudevenum.cpp \
    ceventmanager.cpp \
    triggers.cpp \
    gpio.cpp \
    omnibus.cpp \
    serializable.cpp \
    busprotocol.cpp \
    mousepacket.cpp \
    keypacket.cpp \
    buspacket.cpp \
    clickpacket.cpp

HEADERS  += autoplay.h \
#    DeclarativeMimeData.h \
#    DeclarativeDropArea.h \
#    DeclarativeDragDropEvent.h \
#    DeclarativeDragArea.h \
    directorymodel.h \
    ckeyboard.h \
    cmouse.h \
    cpcap.h \
    cudevenum.h \
    cusbprotocol.h \
    ceventmanager.h \
    inputmeta.h \
    triggers.h \
    gpio.h \
    omnibus.h \
    serializable.h \
    busprotocol.h \
    mousepacket.h \
    keypacket.h \
    buspacket.h \
    clickpacket.h

FORMS    += autoplay.ui

RESOURCES += \
    autoplay.qrc

OTHER_FILES += \
    base/menu/Networking.qml \
    base/assets/ScrollBar.qml \
    base/assets/NavButton.qml \
    base/assets/MenuButton.qml \
    base/assets/Menu.qml \
    base/menu/MainMenu.qml \
    Main.qml \
    assets/ScrollBar.qml \
    assets/NavButton.qml \
    assets/MenuButton.qml \
    assets/Menu.qml \
    menu/RecordMode.qml \
    menu/PlayMode.qml \
    menu/Networking.qml \
    menu/MainMenu.qml \
    menu/GeneralSettings.qml \
    menu/ButtonAssignments.qml \
    base/assets/ScrollBar.qml \
    base/assets/NavButton.qml \
    base/assets/MenuButton.qml \
    base/assets/Menu.qml \
    base/menu/Buttons.qml \
    base/menu/Settings.qml \
    base/menu/Record.qml \
    base/menu/Apps.qml

#CONFIG  += link_pkgconfig
#PKGCONFIG += libusb-1.0

unix:!macx:!symbian: LIBS += -L/angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/usr/lib -ludev -lpcap
unix:!macx:!symbian: LIBS += -L/angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/lib -lusb-1.0
unix:!macx:!symbian: INCLUDEPATH += /angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/usr/include
unix:!macx:!symbian: INCLUDEPATH += /angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/usr/include/libusb-1.0

target.path = /opt/autoplay
INSTALLS += target
