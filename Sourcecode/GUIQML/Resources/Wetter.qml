import QtQuick 2.4

WetterForm {

    function setToday(picspource) {
        todayImage.source = picspource;
        todayImage.update();
        print("setToday")

    }

    function setWarning(picspource) {
        warningImage.source = picspource;
        warningImage.update();
        print("setwarning")

    }
}
