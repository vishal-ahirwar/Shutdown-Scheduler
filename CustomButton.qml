import QtQuick
import QtQuick.Controls

Button{
    implicitWidth: 160
    implicitHeight:55
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
