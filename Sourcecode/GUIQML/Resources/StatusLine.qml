import QtQuick 2.4
import QtQuick.Dialogs 1.2

StatusLineForm
{
    objectName: "statusbar"

    function setclock(cpptime)
    {
        visibleTime.text = cpptime;
        //print("setclock")
    }


    function setdateday(cppdate, cppday)
    {
        visibleDate.text = cppdate;
        visibleDayName.text = cppday;
        print("setdateday")
    }

    function setTemp(tempIn, tempOut)
    {
        visibleValueTempIn.text = tempIn;
        visibleValueTempOut.text = tempOut;
        print("setTemp")
    }
}
