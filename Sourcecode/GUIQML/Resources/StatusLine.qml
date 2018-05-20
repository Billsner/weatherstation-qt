import QtQuick 2.4
import QtQuick.Dialogs 1.2

StatusLineForm {
    objectName: "statusbar"

    function setclock(cpptime) {
        visibleTime.text = cpptime;
        print("setclock")

    }


    function setdate(cppdate) {
        visibleDate.text = cppdate;
        print("setdate")

    }

    function setday(cppday) {
        visibleDayName.text = cppday;
        print("setday")

    }

    function setdateday(cppdate, cppday) {
        visibleDate.text = cppdate;
        visibleDayName.text = cppday;
        print("setdate")

    }
}
