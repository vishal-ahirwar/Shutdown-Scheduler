import QtQuick
import QtQuick.Controls

Button{
    width: 160
    height:55
    background: Rectangle{
        radius: 16
        color: "#E3F2FD"
        width: parent.width
        height:parent.height
    }
    contentItem: Text{
        anchors.fill: parent
        text: parent.text
        font.pixelSize: 22
        color: "#686963"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
