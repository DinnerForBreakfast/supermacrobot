import QtQuick 1.1

Item {
	id: recordbutton
	x: btn.x
	y: btn.y
	//width: btn.width
	//height: btn.height
	property alias text: btn.text
	property alias fontSize: btn.fontSize

	MenuButton {
		id: btn
		//x: recordButton.x
		//y: recordButton.y
		width: recordButton.width
		height: recordButton.height
	}

	MouseArea {
		id: mouseArea
		anchors.fill: btn
		onClicked: {
				superMacroBot.toggleRecordState();
		}
	}

	states: [
		State {
			name: "on"
			PropertyChanges {
				target: btn
				color:"#bb0000"
			}
		}
	]
	transitions: [
		Transition {
			from: ""; to: "on"
			PropertyAnimation {
				target: btn
				properties: "color"
				duration: 75
			}
		}
	]
}
