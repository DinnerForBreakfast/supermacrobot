import Qt 4.7

Item {

    property variant mdl
    property Component btns : MenuButton{
        text: label
        action: file
    }

    function buttonClick(action){menuClick(action)}

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
