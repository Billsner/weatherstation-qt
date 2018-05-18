import QtQuick 2.4
import QtQuick.Controls 2.0

PageBackground {
    width: 800
    height: 60
    property alias button1: button1
    property alias comboBox: comboBox
    property alias customLabel1: customLabel1
    property alias customLabel2: customLabel2


    CustomLabel {
        id: customLabel1
        x: 18
        y: 22
        text: "--:--:--"
        font.pixelSize: 15
    }

    Label {
        id: label1
        x: 206
        y: 22
        text: qsTr("Sunday")
        font.pixelSize: 15
    }

    CustomLabel {
        id: customLabel2
        x: 90
        y: 22
        text: "-- -- ----"
        font.pixelSize: 15
    }

    ComboBox {
        id: comboBox
        x: 294
        y: 9
        width: 212
        height: 43
    }

    Button {
        id: button1
        x: 549
        y: 8
        width: 212
        text: qsTr("Configure")
    }   
}
