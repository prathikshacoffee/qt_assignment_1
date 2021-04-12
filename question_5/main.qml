import QtQuick 2.12
import QtQuick.Window 2.12

Item {

    function readValues(anArray, anObject, date, color, font) {
        for (var i=0; i<anArray.length; i++)
            console.log("Array item:", anArray[i])

        for (var prop in anObject) {
            console.log("Object item:", prop, "=", anObject[prop])
        }
        console.log("Date day is: ", date.getDay())
        console.log("color is: ", color)
        console.log("font is : ", font.family)
    }

    function readDate() {
//            console.log("The given date is:", dt.toUTCString());
            return new Date();
        }
    function readArray(){

        return [1,2,3,4];
    }
}
