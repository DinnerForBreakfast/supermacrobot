																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										#-------------------------------------------------
#
# Project created by QtCreator 2010-07-29T04:47:56
#
#-------------------------------------------------

QT       += core gui declarative sql

TARGET = SuperMacroBot
TEMPLATE = app

OBJECTS_DIR = tmp
MOC_DIR = tmp

DEFINES += __need_timeval \
		QT_NO_CURSOR

SOURCES += main.cpp \
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
    clickpacket.cpp \
    script.cpp \
    dao.cpp \
    scriptplayer.cpp \
    supermacrobot.cpp \
    mainwindow.cpp \
    device.cpp

HEADERS  += \
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
    clickpacket.h \
    script.h \
    dao.h \
    scriptplayer.h \
    supermacrobot.h \
    singleton.h \
    mainwindow.h \
    device.h

FORMS    += \
    mainscreen.ui

RESOURCES += \
    supermacrobot.qrc

OTHER_FILES += \
    base/assets/ScrollBar.qml \
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
    base/assets/MenuButton.qml \
    base/assets/Menu.qml \
    base/menu/Settings.qml \
    base/menu/Apps.qml \
    base/menu/Scripts.qml \
    base/assets/RecordButton.qml \
    base/assets/Theme.qml

message($$QMAKESPEC)

linux-g++ {
	CONFIG += link_pkgconfig
	PKGCONFIG += libusb-1.0 libudev pcap
}

linux-ti33x-g++ {
	LIBS += -L/angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/usr/lib -ludev -lpcap
	LIBS += -L/angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/lib -lusb-1.0
	INCLUDEPATH += /angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/usr/include
	INCLUDEPATH += /angstrom/setup-scripts/build/tmp-angstrom_v2012_05-eglibc/sysroots/beaglebone/usr/include/libusb-1.0
}

target.path = /opt/supermacrobot
INSTALLS += target
