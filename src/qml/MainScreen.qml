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
            Rectangle {
                id: playerOne
                height: 100
                width: 100
                x: ballPosition.p1PosX
                y: ballPosition.p1PosY
                radius: 180
                Image {
                    source: "qrc:/images/ball1"
                    anchors.fill: parent
                    rotation: ballPosition.p1Rot
                    transformOrigin: Item.Center
                }
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
            Rectangle {
                id: playerTwo
                height: 100
                width: 100
                x: ballPosition.p1PosX
                y: ballPosition.p1PosY
                radius: 180
                Image {
                    source: "qrc:/images/ball2"
                    anchors.fill: parent
                    rotation: ballPosition.p1Rot
                    transformOrigin: Item.Center
                }
            }
        }
    }
}
