import Qt 4.7
import "../assets"
import SuperMacroBot 1.0

Item {
    function menuClick(action){
		screenLoader.source = action + "/Main.qml"
    }

    Menu{
        mdl:DirModel{}
        btns:MenuButton{
            text:fileName
            action:filePath
			width: parent.width - 8
			height: textHeight + 40
        }

        id: menu1
        x: 0
        y: 0
    }
}
