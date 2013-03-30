import Qt 4.7

Rectangle {
    id: container

    property string text: "Button"
    property string action: ""
    property string img : ""


    width: buttonLabel.width + 20; height: buttonLabel.height + 8
    border { width: 1; color: Qt.darker(activePalette.button) }
    smooth: true
	radius: 16
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#444444"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }

    // color the button with a gradient

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: screenLoader.source = action;
    }

    Image {
        id: buttonIcon
        source: container.img
    }

    Text {
        id: buttonLabel
        color: "#ffffff"
        anchors.centerIn: container
        text: container.text
		font.pointSize: 20
    }
}
