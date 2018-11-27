import QtQuick 2.4

WetterForm {

    function setToday(picspource) {
        today.source = picspource;
        today.update();
        print("setToday")

    }
}
