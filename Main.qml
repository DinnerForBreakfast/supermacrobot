import QtQuick 1.0
import "base/assets"

Rectangle {
    id: main

    width: 800; height: 480
    color: "#000000"

    SystemPalette { id: activePalette }

    Loader{
        id:screenLoader
        y: 50
        width: 800
        height: 430
        source:"qrc:base/menu/MainMenu.qml"
    }

    NavButton {
        id: mainMenuButton
        x: 1
        y: 1
        width: 140
        height: 40
        text: "Main Menu"
        action: "qrc:base/menu/MainMenu.qml"
    }

    NavButton {
        id: backButton
        x: 153
        y: 1
        height: 40
        text: "Back"
    }

    NavButton {
        id: upButton
        x: 221
        y: 1
        height: 40
        text: "Up"
    }
}
