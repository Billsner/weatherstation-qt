import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1
    objectName: "Settings"


    signal signaldateformat(string format)
    property alias dateformat: dateformat


    GridLayout {
        x: 124
        y: 93
        width: 210
        height: 106
        anchors.horizontalCenterOffset: -233
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 2
        columns: 2

        GroupBox {
            id: groupBox2
            width: 210
            GridLayout {
                x: -5
                y: 0
                width: 181
                height: 48


                ComboBox {
                    id: dateformat
                    x: 294
                    y: 9
                    width: 180
                    height: 43
                    Layout.minimumHeight: 50
                    Layout.minimumWidth: 180
                }
                columns: 2
                rows: 4
            }
            title: qsTr("Dateformat")
        }
    }

    Connections {
        target: dateformat
        onAccepted: signaldateformat(dateformat.currentText)
    }
}
