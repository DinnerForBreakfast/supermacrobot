import QtQuick 1.0
import "base/assets"

Rectangle {
    id: main

    width: 800; height: 480
    color: "#000000"

	Theme{
		id:theme
	}

    SystemPalette { id: activePalette }

	function notifyRecordStateChanged(state){
		console.log("firing notify");
		if(state) recordButton.state = "on";
		else recordButton.state = "";
	}

	function loadMenu(action){
		screenLoader.source = "qrc:base/menu/"+action
	}

    Loader{
        id:screenLoader
		y: 80
        width: 800
		height: 400
        source:"qrc:base/menu/MainMenu.qml"
    }

	MenuButton {
        id: mainMenuButton
        x: 1
        y: 1
		width: 152
		height: 79
		fontSize: 20
        text: "Main Menu"
		action: "MainMenu.qml"
    }

	MenuButton {
        id: backButton
        x: 153
        y: 1
		width: 92
		height: 79
		fontSize: 20
        text: "Back"
    }

	RecordButton {
		id: recordButton
		x: 347
		y: 1
		width: 106
		height: 79
		fontSize: 20
		text: "Record"
	}
}
