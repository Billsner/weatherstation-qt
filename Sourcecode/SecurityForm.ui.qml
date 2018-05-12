import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1
    title: "Security"

    GridLayout {
        x: 124
        y: 151
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 2
        columns: 2

        signal signalswitch3(int count)


        GroupBox {
            id: groupBox1
            title: qsTr("Living Room")

            GridLayout {
                rows: 4
                columns: 2

                RadioButton {
                    id: radioButton1
                    text: qsTr("Smoke Detector")
                }

                Button {
                    id: button1
                    text: qsTr("Test")
                }

                RadioButton {
                    id: radioButton2
                    text: qsTr("Movement Detector")
                }

                Button {
                    id: button2
                    text: qsTr("Test")
                }

                Switch {
                    id: switch1
                    text: qsTr("Window 01")
                }

                Label {
                    id: label1
                    text: switch1.checked ? "Open" : "Closed"
                }

                Switch {
                    id: switch2
                    text: qsTr("Window 02")
                }

                Label {
                    id: label2
                    text: switch2.checked ? "Open" : "Closed"
                }
            }
        }

        GroupBox {
            id: groupBox2
            GridLayout {
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

        GroupBox {
            id: groupBox3
            GridLayout {
                RadioButton {
                    id: radioButton5
                }

                Button {
                    id: button5
                    text: qsTr("Test")
                }

                RadioButton {
                    id: radioButton6
                    text: qsTr("Movement Detector")
                }

                Button {
                    id: button6
                    text: qsTr("Test")
                }

                Switch {
                    id: switch5
                    text: qsTr("Window 01")
                }

                Label {
                    id: label5
                    text: switch5.checked ? "Open" : "Closed"
                }

                Switch {
                    id: switch6
                    text: qsTr("Window 02")
                }

                Label {
                    id: label6
                    text: switch6.checked ? "Open" : "Closed"
                }
                columns: 2
                rows: 4
            }
            title: qsTr("Bedroom 01")
        }

        GroupBox {
            id: groupBox4
            GridLayout {
                RadioButton {
                    id: radioButton7
                }

                Button {
                    id: button7
                    text: qsTr("Test")
                }

                RadioButton {
                    id: radioButton8
                    text: qsTr("Movement Detector")
                }

                Button {
                    id: button8
                    text: qsTr("Test")
                }

                Switch {
                    id: switch7
                    text: qsTr("Window 01")
                }

                Label {
                    id: label7
                    text: switch7.checked ? "Open" : "Closed"
                }

                Switch {
                    id: switch8
                    text: qsTr("Window 02")
                }

                Label {
                    id: label8
                    text: switch8.checked ? "Open" : "Closed"
                }
                columns: 2
                rows: 4
            }
            title: qsTr("Bedroom 02")
        }
    }

    Connections {
        target: switch3
        onClicked: pageBackground1.signalswitch3(switch3.checked)
    }
}
