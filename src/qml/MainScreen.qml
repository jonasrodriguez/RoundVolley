import QtQuick 2.12

Item {
    id: playArea
    width: parent.width
    height: 600
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    Row {
        anchors.fill: parent
        Rectangle {
            height: playArea.height
            width: 630
            color: "light yellow"
            Image {
                source: "qrc:/images/ball1"
                fillMode: Image.PreserveAspectFit
                height: 100
                width: 100
                x: ballPosition.posX
                y: ballPosition.posY
                rotation: ballPosition.rotation
                transformOrigin: Item.Center
            }
        }
        Rectangle {
            height: playArea.height / 2
            width: 20
            color: "black"
            anchors.bottom: parent.bottom
        }
        Rectangle {
            height: playArea.height
            width: 630
            color: "light green"
            Image {
                source: "qrc:/images/ball2"
                fillMode: Image.PreserveAspectFit
                height: 100
                width: 100
                x: 300
                y: 430
                rotation: ballPosition.rotation
                transformOrigin: Item.Center
            }
        }
    }
}
