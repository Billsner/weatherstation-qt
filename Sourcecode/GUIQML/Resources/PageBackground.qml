import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

Rectangle {
    Material.theme: Material.Dark
    Material.accent: Material.DeepOrange
    width: 800
    height: 420
    color: "#191919"
    clip: true
    property alias title: label.text

    Label {
        id: label
        x: 8
        y: 18
        text: qsTr("")
        font.pixelSize: 22
    }


}
