import QtQuick
import QtQuick.Controls
Window {
    height: 640
    width: 480
    visible: true
    title: qsTr("Shutdown Scheduler")
    color: "transparent"
    flags: Qt.FramelessWindowHint
    Connections{
        target: controller
        onErrorOccured:function(errorString){
            errorText.text=errorString
        }
        onDurationChanged:function(value){
            spinBoxH.value=value
        }
    }
    Component.onCompleted: {
        spinBoxH.value=controller.duration
    }

    Rectangle
    {
        color: "#FAFAFA"
        width: parent.width
        height:parent.height
        radius: 18
        Rectangle{
            Text{
                id:title
                text:qsTr("Shutdown Scheduler")
                font.pixelSize: 25
                color: "#252422"
                font.bold: true
                anchors{
                    top:parent.top
                    margins: 35
                }
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
            }
            color: "#F7F9F9"
            width: parent.width
            height: parent.height*0.18
            topLeftRadius: parent.radius
            topRightRadius: parent.radius
        }



        Text {
            id: errorText
            text:"Copyright© 2025 Vishal Ahirwar.All rights reserved."
            anchors{
                bottom:parent.bottom
                margins: 55
            }
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
            font.bold: false
            color:"#686963"
            wrapMode: Text.WrapAnywhere
        }
        Column
        {
            anchors.centerIn: parent
            spacing: 15
            CustomSpinBox{
                id:spinBoxH
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 35
                onValueChanged: function (){
                    controller.duration=value
                }
            }

            CustomButton{
                id:btnSetTimer
                text: "Set Timer"
                visible: !controller.can_clear
                enabled: !controller.can_clear
                onClicked: {
                    controller.setTimer()
                }
            }
            CustomButton{
                id:btnCancel
                text:"Clear Timer"
                visible: controller.can_clear
                enabled: controller.can_clear
                onClicked: {
                    controller.clear()
                }
            }
            CustomButton{
                id:btnClose
                text: "Close"
                onClicked: {
                    controller.close();
                }
            }
            CustomButton{
                id:btnAbout
                text:"About"
                onClicked: {
                    aboutPopUp.open()
                }
            }
        }

    }
    AboutPopUp{
        id:aboutPopUp
    }

}
