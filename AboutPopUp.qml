import QtQuick 2.15
import QtQuick.Controls 2.15

Popup {
    id: aboutPopup
    width: parent.width
    height: parent.height
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    background: Rectangle {
        color: "#FAFAFA"
        radius: 18
    }

    Column {
        anchors.fill: parent
        anchors.margins: 16
        anchors.topMargin: 55
        spacing: 10

        // Title
        Text {
            text: "About Shutdown Scheduler"
            font.bold: true
            font.pointSize: 18
            color: "#BBBBBB"
            horizontalAlignment: Text.AlignHCenter
            width: parent.width
        }
        ScrollView {
            id: info
            width: parent.width
            height: parent.height * 0.75
            clip: true

            contentWidth: parent.width  // Ensures ScrollView content spans full width

            Column {
                width: parent.width * 0.9  // Make it take most of the width
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter  // Centers Column inside ScrollView

                Text {
                    text: "Shutdown Scheduler is a lightweight and efficient tool that allows users to schedule system shutdowns, restarts, or hibernation with ease."
                    wrapMode: Text.WordWrap
                    width: parent.width
                    font.pointSize: 12
                    color: "#CCCCCC"
                }

                Text {
                    text: "Features:\n• Schedule shutdown, restart, hibernate, or log off operations.\n• User-friendly interface.\n• Cross-platform support.\n• Open-source and customizable."
                    wrapMode: Text.WordWrap
                    width: parent.width
                    font.pointSize: 12
                    color: "#AAAAAA"
                }

                Text {
                    text: "License: MIT License"
                    font.italic: true
                    font.pointSize: 12
                    color: "#BBBBBB"
                }

                Text {
                    text: "© 2024 Vishal Ahirwar. All rights reserved."
                    font.pointSize: 10
                    color: "#888888"
                }
            }
        }


        // Buttons
        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            CustomButton {
                width: 220
                text: "GitHub Repository"
                onClicked: Qt.openUrlExternally("https://github.com/vishal-ahirwar/Shutdown-Scheduler")
            }

            CustomButton {
                text: "Close"
                onClicked:close()
            }
        }
    }
}
