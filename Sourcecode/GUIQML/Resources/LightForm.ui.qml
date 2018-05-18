import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1
    property alias groupBox1: groupBox1

    GridLayout {
        x: 148
        y: 159
        anchors.horizontalCenterOffset: 94
        anchors.horizontalCenter: parent.horizontalCenter
        columnSpacing: 20
        rowSpacing: 20
        rows: 2
        columns: 2

        GroupBox {
            id: groupBox1
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            title: qsTr("Living Room")

            GridLayout {
                rows: 3
                columns: 2

                Switch {
                    id: switch1
                    text: qsTr("All")
                }

                Slider {
                    id: slider1
                    Layout.preferredHeight: 25
                    Layout.preferredWidth: 180
                    value: 0.5
                }

                Switch {
                    id: switch2
                    text: qsTr("Central")
                }

                Slider {
                    id: slider2
                    Layout.preferredHeight: 25
                    Layout.preferredWidth: 180
                    value: 0.5
                }

                Switch {
                    id: switch3
                    text: qsTr("Corner")
                }

                Slider {
                    id: slider3
                    Layout.preferredHeight: 25
                    Layout.preferredWidth: 180
                    value: 0.5
                }
            }
        }
    }

}
