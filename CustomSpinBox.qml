import QtQuick
import QtQuick.Controls

SpinBox {
    id: spinBox
    from: 0
    to:1000000000
    stepSize: 2

    background: Rectangle {
        color: "#E3F2FD"  // Dark background
        radius: 8
        border.color: "#E3F2FD"
        width: parent.width+1
        height:parent.height+1
    }

    contentItem: Text {
        text: spinBox.textFromValue(spinBox.value, spinBox.locale)
        font.pixelSize: 18
        color: "#686963"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
