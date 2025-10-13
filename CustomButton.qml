import QtQuick
import QtQuick.Controls

Button{
    implicitWidth: 160
    implicitHeight:48
    background: Rectangle{
        radius: 18
        color: "#00AEFF"
        width: parent.width
        height:parent.height
    }
    contentItem: Text{
        anchors.fill: parent
        text: parent.text
        font.pixelSize: 22
        color: "#FFFFFF"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
