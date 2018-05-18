import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1

    GridLayout {
        x: 53
        y: 68
        width: 313
        height: 285
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 2
        columns: 2

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
