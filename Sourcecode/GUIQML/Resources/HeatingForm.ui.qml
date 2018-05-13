import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1

    GridLayout {
        x: 53
        y: 94
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 2
        columns: 2

        GroupBox {
            id: groupBox1
            Layout.preferredHeight: 314
            Layout.preferredWidth: 324
            title: qsTr("Living Room")

            Label {
                id: label2
                x: 221
                y: 16
                text: qsTr("Actual")
                font.pointSize: 18
            }

            Label {
                id: label1
                x: 15
                y: 15
                text: qsTr("Target")
                font.pointSize: 18
            }

            ProgressBar {
                id: progressBar2
                x: 156
                y: 162
                rotation: -90
                value: 0.5
            }

            ProgressBar {
                id: progressBar1
                x: -50
                y: 161
                value: dial.position
                rotation: -90
            }

            Dial {
                id: dial
                x: 107
                y: 114
            }




        }

        GroupBox {
            id: groupBox4
            Layout.preferredHeight: 314
            Layout.preferredWidth: 324
            Label {
                id: label7
                x: 221
                y: 16
                text: qsTr("Actual")
                font.pointSize: 18
            }

            Label {
                id: label8
                x: 15
                y: 15
                text: qsTr("Target")
                font.pointSize: 18
            }

            ProgressBar {
                id: progressBar7
                x: 156
                y: 162
                rotation: -90
                value: 0.5
            }

            ProgressBar {
                id: progressBar8
                x: -50
                y: 161
                rotation: -90
                value: dial3.position
            }

            Dial {
                id: dial3
                x: 107
                y: 114
            }
            title: qsTr("Living Room")
        }

        GroupBox {
            id: groupBox2
            Layout.preferredHeight: 314
            Layout.preferredWidth: 324
            Label {
                id: label3
                x: 221
                y: 16
                text: qsTr("Actual")
                font.pointSize: 18
            }

            Label {
                id: label4
                x: 15
                y: 15
                text: qsTr("Target")
                font.pointSize: 18
            }

            ProgressBar {
                id: progressBar3
                x: 156
                y: 162
                rotation: -90
                value: 0.5
            }

            ProgressBar {
                id: progressBar4
                x: -50
                y: 161
                rotation: -90
                value: dial1.position
            }

            Dial {
                id: dial1
                x: 107
                y: 114
            }
            title: qsTr("Living Room")
        }

        GroupBox {
            id: groupBox3
            Layout.preferredHeight: 314
            Layout.preferredWidth: 324
            Label {
                id: label5
                x: 221
                y: 16
                text: qsTr("Actual")
                font.pointSize: 18
            }

            Label {
                id: label6
                x: 15
                y: 15
                text: qsTr("Target")
                font.pointSize: 18
            }

            ProgressBar {
                id: progressBar5
                x: 156
                y: 162
                rotation: -90
                value: 0.5
            }

            ProgressBar {
                id: progressBar6
                x: -50
                y: 161
                rotation: -90
                value: dial2.position
            }

            Dial {
                id: dial2
                x: 107
                y: 114
            }
            title: qsTr("Living Room")
        }
    }

}
