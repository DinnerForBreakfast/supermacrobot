import QtQuick 1.0
import "base/assets"

Rectangle {
    id: main

    width: 800; height: 480
    color: "#000000"

    SystemPalette { id: activePalette }

    Loader{
        id:screenLoader
		y: 80
        width: 800
		height: 400
        source:"qrc:base/menu/MainMenu.qml"
    }

	NavButton {
        id: mainMenuButton
        x: 1
        y: 1
		width: 152
		height: 79
        text: "Main Menu"
        action: "qrc:base/menu/MainMenu.qml"
    }

    NavButton {
        id: backButton
        x: 153
        y: 1
		width: 92
		height: 79
        text: "Back"
    }

    NavButton {
        id: upButton
		x: 245
		y: 1
		width: 77
		height: 79
        text: "Up"
    }

	NavButton {
		id: recordButton
		x: 347
		y: 1
		width: 106
		height: 79
		text: "Record"
	}
}
