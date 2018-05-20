import QtQuick 2.4
import QtQuick.Controls 2.0

PageBackground {
    width: 800
    height: 60
    property alias visibleDate: visibleDate
    property alias visibleDayName: visibleDayName
    property alias visibleTime: visibleTime


    CustomLabel {
        id: visibleTime
        x: 18
        y: 22
        text: "--:--:--"
        font.pixelSize: 15
    }

    CustomLabel {
        id: visibleDayName
        x: 206
        y: 22
        text: qsTr("---")
        font.pixelSize: 15
    }

    CustomLabel {
        id: visibleDate
        x: 90
        y: 22
        text: "-- -- ----"
        font.pixelSize: 15
    }
}
