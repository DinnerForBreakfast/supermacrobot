import Qt 4.7
import "../assets"
import com.autoplay 1.0

Item {
    function menuClick(action){
		screenLoader.source = action + "/Main.qml"
    }

    Menu{
        mdl:DirModel{}
        btns:MenuButton{
            text:fileName
            action:filePath
        }

        id: menu1
        x: 0
        y: 0
    }
}
