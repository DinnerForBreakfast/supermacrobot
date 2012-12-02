import Qt 4.7

Rectangle {
    id: container

    property string text: "Button"
    property string action: ""

    width: parent.width - 8; height: buttonLabel.height + 40
    border { width: 1; color: Qt.darker(activePalette.button) }
    smooth: true
    radius: 8
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
        onClicked: buttonClick(container.action)
    }

    Text {
        id: buttonLabel
        color: "#ffffff"
        anchors.centerIn: container
        text: container.text
		font.pointSize: 25
    }
}
