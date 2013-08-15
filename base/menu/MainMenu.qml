import QtQuick 1.0
import "../assets"

Item {

    ListModel{

		id:menulist

        ListElement{
			label:"Apps"
			file:"Apps.qml"
        }
		ListElement{
			label:"Triggers"
			file:"Triggers.qml"
		}
        ListElement{
			label:"Scripts"
			file:"Scripts.qml"
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
		mdl:menulist
        x: 0
        y: 0
    }
}
