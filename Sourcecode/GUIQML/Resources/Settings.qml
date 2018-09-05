import QtQuick 2.4

SettingsForm {

    dateformat.model: ["dd.MM.yyyy", "yyyy.MM.dd", "yyyy.dd.MM"]

    buttonExit.onClicked: Qt.quit();


    function setDateFormat(FormatIndex) {
        dateformat.currentIndex = FormatIndex;
        dateformat.forceActiveFocus();
        print("setDateFormat")

    }
}
