import QtQuick 1.1

Rectangle {
    id: container

    property string text: "Button"
    property string action: ""
	property alias textWidth: buttonLabel.width
	property alias textHeight: buttonLabel.height
	property alias fontSize: buttonLabel.font.pointSize

	Text {
		id: buttonLabel
		color: "#ffffff"
		anchors.centerIn: container
		text: container.text
		font.pointSize: 25
	}

    border { width: 1; color: Qt.darker(activePalette.button) }
    smooth: true
    radius: 8
	color: theme.color

    MouseArea {
        id: mouseArea
        anchors.fill: parent
		onClicked: loadMenu(container.action)
    }
}
