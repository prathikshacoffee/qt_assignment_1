import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import interact_time 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("question 4")

    property double current_time_qml: 0
    property int iter_n: 10000

    InteractProperties {
        id: interact_properties_instance
    }

    InteractMethods {
        id: interact_methods_instance
    }
    InteractSignals {
        id: interact_signals_instance
    }

    Button {
        id: compute_time_property_button
        text: "Property"
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -240
        anchors.verticalCenterOffset: -180
        onClicked: {
            current_time_qml = new Date().getTime()
            for (var i = 0; i < iter_n-1; ++i) {
                        interact_properties_instance.set_property_time(current_time_qml)
                    }
            interact_properties_instance.set_emit_flag(1);
            interact_properties_instance.set_property_time(current_time_qml)
        }
    }

    TextField{
        id: property_textfield
        text: interact_properties_instance.read_property
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -180

    }

    Button {
        id: compute_time_invoke_button
        text: "Q_Invoke"
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -240
        anchors.verticalCenterOffset: -60
        onClicked: {
            current_time_qml = new Date().getTime()
            for (var i = 0; i < iter_n-1; ++i) {
                        interact_methods_instance.slot_q_invokable_time(current_time_qml,0)
                    }
            interact_methods_instance.slot_q_invokable_time(current_time_qml,1)
        }
    }

    TextField{
        id: invoke_textfield
        text: interact_methods_instance.get_time_var()
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -60

    }

    Button {
        id: compute_time_slot_button
        text: "Public Slot"
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -240
        anchors.verticalCenterOffset: 60
        onClicked: {
            current_time_qml = new Date().getTime()
            for (var i = 0; i < iter_n-1; ++i) {
                        interact_methods_instance.slot_time(current_time_qml,0)
                    }
            interact_methods_instance.slot_time(current_time_qml,1)
        }
    }

    TextField{
        id: public_slot
        text: interact_methods_instance.get_time_var()
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 60

    }


    Button {
        id: compute_time_signal_button
        text: "Signal"
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -240
        anchors.verticalCenterOffset:180
        onClicked: {
            current_time_qml = new Date().getTime()
            for (var i = 0; i < iter_n; ++i) {
                        interact_signals_instance.emit_signal(current_time_qml)
                    }
        }
    }

    TextField{
        id: slot_signal
        text: "0"
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 180

    }

    Connections{
        target: interact_methods_instance
        onTimeQiVarChanged: invoke_textfield.text = interact_methods_instance.get_time_var()
        onTimeSlotVarChanged: public_slot.text = interact_methods_instance.get_time_var()
    }

    Connections{
        target: interact_signals_instance
        onSignalTime: slot_signal.text = interact_signals_instance.get_time_var()
    }

}
