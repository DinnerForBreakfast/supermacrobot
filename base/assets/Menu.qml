import QtQuick 1.1

Item {

    property variant mdl
	property Component btns : MenuButton {
        text: label
        action: file
		width: parent.width - 8
		height: textHeight + 40
    }

    ListView {
        id: menu
        model:mdl
        delegate: btns

        width: 600
        height: 430
        snapMode:"SnapToItem"
        spacing:3
    }

    ScrollBar {
        y:menu.y
        scrollArea: menu
        height: menu.height
        width: 8
        anchors.right:menu.right
    }
}
