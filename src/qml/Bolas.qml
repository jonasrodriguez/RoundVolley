import QtQuick 2.12

Rectangle {

    color: "black"
    width: parent.width * 0.9
    height: parent.height / 4
    anchors.bottom: parent.bottom
    anchors.bottomMargin: height / 3
    anchors.horizontalCenter: parent.horizontalCenter
    Image {
        source: "qrc:/images/ball1"
        fillMode: Image.PreserveAspectFit
        height: parent.height
        x: ballPosition.posX
        y: ballPosition.posY
        rotation: ballPosition.rotation
        transformOrigin: Item.Center
    }
}
