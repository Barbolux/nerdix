import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Controls 2.1


Window{
    id:janela
    visible: true
    width: 500
    height: 500


    Rectangle {
    id:rec00
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 10
    y: 10

    MouseArea {
        id: areaDoMouse
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';


          }
        }
}
    Rectangle {
    id:rec01
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 115
    y: 10
    MouseArea {
        id:areaDoMouse01
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';
             dialogo.conversa();
        }
        }
}
    Rectangle {
    id:rec02
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 220
    y: 10
    MouseArea {
        id:areaDoMouse02
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';
             dialogo.conversa();
          }
        }
}

    Rectangle {
    id:rec03
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 10
    y: 115
    MouseArea {
        id:areaDoMouse03
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';
             dialogo.conversa();
          }
        }
}

    Rectangle {
    id:rec04
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 115
    y: 115
    MouseArea {
        id:areaDoMouse04
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';
             dialogo.conversa();
          }
        }
}
    Rectangle {
    id:rec05
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 220
    y: 115
    MouseArea {
        id:areaDoMouse05
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                   parent.color = 'yellow';
             dialogo.conversa();
          }
        }
}



    Rectangle {
    id:rec06
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x:10
    y:220

    MouseArea {
        id:areaDoMouse06
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';
             dialogo.conversa();
          }
        }

 }

    Rectangle {
    id:rec07
    width: 100; height: 100
    color: "green"
    radius: 100/30 //arredonda a borda
    border.color: "black"
    x: 115
    y: 220
    MouseArea {
        id:areaDoMouse07
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (mouse.button == Qt.LeftButton)
                parent.color = 'yellow';
             dialogo.conversa();
        }
    }
    }

    Rectangle {
        id:rec08
        width: 100; height: 100
        color: "green"
        radius: 100/30 //arredonda a borda
        border.color: "black"
        x:220
        y:220
        MouseArea {
            id:areaDoMouse08
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked: {
                if (mouse.button == Qt.LeftButton)
                    parent.color = 'yellow';
             dialogo.conversa();
            }
        }
    }
}
