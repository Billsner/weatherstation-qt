import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1
    title: "Lights"

    GridLayout {
        x: 148
        y: 158
        anchors.horizontalCenter: parent.horizontalCenter
        columnSpacing: 20
        rowSpacing: 20
        rows: 2
        columns: 2

        GroupBox {
            id: groupBox1
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

        GroupBox {
            id: groupBox2
            GridLayout {
                Switch {
                    id: switch4
                    text: qsTr("All")
                }

                Slider {
                    id: slider4
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 25
                    value: 0.5
                }

                Switch {
                    id: switch5
                    text: qsTr("Central")
                }

                Slider {
                    id: slider5
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 25
                    value: 0.5
                }

                Switch {
                    id: switch6
                    text: qsTr("Shower")
                }

                Slider {
                    id: slider6
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 25
                    value: 0.5
                }
                columns: 2
                rows: 3
            }
            title: qsTr("Bathroom")
        }

        GroupBox {
            id: groupBox3
            GridLayout {
                Switch {
                    id: switch7
                    text: qsTr("All")
                }

                Slider {
                    id: slider7
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 25
                    value: 0.5
                }

                Switch {
                    id: switch8
                    text: qsTr("Central")
                }

                Slider {
                    id: slider8
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 25
                    value: 0.5
                }

                Switch {
                    id: switch9
                    text: qsTr("Bed")
                }

                Slider {
                    id: slider9
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 25
                    value: 0.5
                }
                columns: 2
                rows: 3
            }
            title: qsTr("Bedroom 01")
        }

        GroupBox {
            id: groupBox4
            GridLayout {
                Switch {
                    id: switch10
                    text: qsTr("All")
                }

                Slider {
                    id: slider10
                    Layout.preferredHeight: 25
                    Layout.preferredWidth: 180
                    value: 0.5
                }

                Switch {
                    id: switch11
                    text: qsTr("Central")
                }

                Slider {
                    id: slider11
                    Layout.preferredHeight: 25
                    Layout.preferredWidth: 180
                    value: 0.5
                }

                Switch {
                    id: switch12
                    text: qsTr("Bed")
                }

                Slider {
                    id: slider12
                    Layout.preferredHeight: 25
                    Layout.preferredWidth: 180
                    value: 0.5
                }
                columns: 2
                rows: 3
            }
            title: qsTr("Bedroom 02")
        }
    }

}
