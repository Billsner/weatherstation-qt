import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

PageBackground {
    id: pageBackground1
    objectName: "WeatherWindow"

    //signal signaldateformatid(int formatid)
    property alias todayImage: todayImage
    property alias warningImage: warningImage

    GroupBox {
        id: todayGB
        x: 22
        y: 20
        width: 132
        height: 186
        title: qsTr("Heute")

        Text {
            id: todayMin
            x: 12
            y: -9
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Min:"
            font.pixelSize: 12
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: todayMax
            x: 12
            y: 14
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Max:"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }

        GridLayout {
            x: 352
            y: 75
            anchors.horizontalCenterOffset: 94
            anchors.horizontalCenter: parent.horizontalCenter
            columnSpacing: 20
            rowSpacing: 20
            rows: 2
            columns: 2
        }


        Image {
            id: todayImage
            x: 4
            y: 41
            width: 100
            height: 90
            source: "Data-Pic-Images/Pictures/WetterIcons/no_info.png"
        }
    }

    GroupBox {
        id: warningGB
        x: 608
        y: 20
        width: 132
        height: 186
        title: qsTr("Warning")
        Text {
            id: warningVon
            x: 12
            y: -9
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Von:"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
        }

        Text {
            id: warningBis
            x: 12
            y: 14
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Bis: "
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }

        GridLayout {
            x: 352
            y: 75
            anchors.horizontalCenterOffset: 94
            rowSpacing: 20
            columnSpacing: 20
            columns: 2
            anchors.horizontalCenter: parent.horizontalCenter
            rows: 2
        }

        Image {
            id: warningImage
            x: 4
            y: 41
            width: 100
            height: 90
            source: "Data-Pic-Images/Pictures/WarningIcons_Big/warn_no_warning.png"
        }
    }

    GroupBox {
        id: todayGB1
        x: 189
        y: 20
        width: 132
        height: 186
        Text {
            id: todayMin1
            x: 12
            y: -9
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Min:"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }

        Text {
            id: todayMax1
            x: 12
            y: 14
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Max:"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }

        GridLayout {
            x: 352
            y: 75
            rows: 2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: 94
            columnSpacing: 20
            columns: 2
            rowSpacing: 20
        }

        Image {
            id: todayImage1
            x: 4
            y: 41
            width: 100
            height: 90
            source: "Data-Pic-Images/Pictures/WetterIcons/no_info.png"
        }
        title: qsTr("Morgen")
    }

    GroupBox {
        id: todayGB2
        x: 362
        y: 20
        width: 132
        height: 186
        Text {
            id: todayMin2
            x: 12
            y: -9
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Min:"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }

        Text {
            id: todayMax2
            x: 12
            y: 14
            width: 88
            height: 17
            color: "#f9f8f8"
            text: "Max:"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }

        GridLayout {
            x: 352
            y: 75
            rows: 2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: 94
            columns: 2
            columnSpacing: 20
            rowSpacing: 20
        }

        Image {
            id: todayImage2
            x: 4
            y: 41
            width: 100
            height: 90
            source: "Data-Pic-Images/Pictures/WetterIcons/no_info.png"
        }
        title: qsTr("Übermorgen")
    }
}
