import QtQuick 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.0

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 800
    height: 480
    title: qsTr("Smart Home")
    Material.theme: Material.Dark
    Material.accent: Material.DeepOrange

    StackLayout {
        id: swipeView
        width: 800
        height: 430
        anchors.bottomMargin: -10
        anchors.bottom: parent.bottom
        anchors.top: SideBar.top
        currentIndex: tabBar.currentIndex

        Wetter {

        }

        Smarthome {

        }

        Settings {

        }


    }

    SideBar {
        id: sideBar
    }

    TabBar {
        id: tabBar
        x: 252
        y: -420
        width: 300
        height: 30
        position: TabBar.Header
        anchors.horizontalCenter: parent.horizontalCenter
        visible: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        z: 2
        contentHeight: 30
        currentIndex: swipeView.currentIndex
        TabButton {
            width: 100
            height: 25
            text: qsTr("Wetter")
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }
        TabButton {
            x: 350
            width: 100
            height: 25
            text: qsTr("Smarthome")
            anchors.top: parent.top
            anchors.topMargin: 0
        }
        TabButton {
            x: 700
            width: 100
            height: 25
            text: qsTr("Einstellung")
            anchors.top: parent.top
            anchors.topMargin: 0
        }
    }
}
