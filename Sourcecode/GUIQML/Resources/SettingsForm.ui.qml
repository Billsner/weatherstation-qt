import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1

    GridLayout {
        x: 124
        y: 82
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 2
        columns: 2

        signal signalswitch3(int count)


        GroupBox {
            id: groupBox2
            GridLayout {
                x: -5
                y: 0
                RadioButton {
                    id: radioButton3
                    text: qsTr("Smoke Detector")
                }

                Button {
                    id: button3
                    text: qsTr("Test")
                }

                RadioButton {
                    id: radioButton4
                    text: qsTr("Movement Detector")
                }

                Button {
                    id: button4
                    text: qsTr("Test")
                }

                Switch {
                    id: switch3
                    text: qsTr("Window 01")

                }

                Label {
                    id: label3
                    text: switch3.checked ? "Open" : "Closed"
                }

                Switch {
                    id: switch4
                    text: qsTr("Window 02")
                }

                Label {
                    id: label4
                    text: switch4.checked ? "Open" : "Closed"
                }
                columns: 2
                rows: 4
            }
            title: qsTr("Bathroom")
        }
    }

    Connections {
        target: switch3
        onClicked: pageBackground1.signalswitch3(switch3.checked)
    }
}
