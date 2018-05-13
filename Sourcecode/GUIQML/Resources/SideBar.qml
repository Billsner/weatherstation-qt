import QtQuick 2.4
import QtQuick.Dialogs 1.2

SideBarForm {
    objectName: "sidebar"

    comboBox.model: ["Normal", "Vacation", "Party", "Test"]

    button1.onClicked: {
        dialog.open()
    }

    MessageDialog {
        id: dialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            dialog.text = caption;
            dialog.open();
        }
    }

    function setclock(cpptime) {
        customLabel1.text = cpptime;        
        print("setclock")

    }


    function setdate(cppdate) {
        customLabel2.text = cppdate;
        print("setdate")

    }
}
