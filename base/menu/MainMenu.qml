import QtQuick 1.0
import "../assets"

Item {

    function menuClick(action){
        screenLoader.source = "qrc:base/menu/"+action
    }

    ListModel{

        id:buttons

        ListElement{
			label:"Apps"
			file:"Apps.qml"
        }
		ListElement{
			label:"Triggers"
			file:"Triggers.qml"
		}
        ListElement{
			label:"Record"
            file:"RecordMode.qml"
        }
        ListElement{
			label:"Buttons"
			file:"Buttons.qml"
        }
        ListElement{
			label:"Settings"
			file:"Settings.qml"
        }
    }

    Menu {
        id: menu1
        mdl:buttons
        x: 0
        y: 0
    }
}
