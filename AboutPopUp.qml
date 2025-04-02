import QtQuick
import QtQuick.Controls

Popup {
    id: aboutPopup
    modal: true
    focus: true
    width: parent.width
    height:parent.height
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    background: Rectangle {
        color: "white"
        radius: 18
    }

    contentItem: Flickable {
        topMargin: 75
        clip: true
        anchors.fill: parent
        contentWidth: parent.width
        contentHeight: columnLayout.height
        flickableDirection: Flickable.Vertical

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOff
        }

        Column {
            id: columnLayout
            width: parent.width - 20
            spacing: 35
            anchors.centerIn: parent
            Text {
                text: qsTr("Shutdown Scheduler")
                font.bold: true
                font.pointSize: 14
                color: "black"
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                wrapMode: Text.WrapAnywhere
            }

            Text {
                text: qsTr("Shutdown Scheduler is a lightweight and efficient application designed to help users ") +
                      qsTr("schedule system shutdown, restart, hibernate, or sleep operations with ease. Built using ") +
                      qsTr("C++ and Qt6, this application ensures a smooth and responsive user experience while ") +
                      qsTr("maintaining low system resource usage.\n\n") +

                      qsTr("With a simple and intuitive interface, Shutdown Scheduler allows users to set automatic shutdown ") +
                      qsTr("times, helping save power, automate tasks, and manage system uptime effectively. Whether you need ") +
                      qsTr("to turn off your computer after a long download, restart after an update, or hibernate at a ") +
                      qsTr("specific time, this tool provides a seamless solution.")
                font.pointSize: 12
                color: "#252422"
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                wrapMode: Text.WordWrap
            }
            CustomButton{
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Close"
                onClicked: {
                    close()
                }
            }
        }
    }
}
