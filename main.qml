import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import Qt.labs.platform 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal fileSelected(string filePath)

    MenuBar {
        Menu {
            title: "File"
            MenuItem {
                id: menuOpen
                text: "Open"
                shortcut: "Ctrl+o"

                onTriggered: {
                    fileDialog.open()
                }
            }

        }
    }

    FileDialog {
        id: fileDialog
        nameFilters: [ "Apk file (*.apk)", "All files (*)" ]
        onAccepted: {
            fileSelected(file)
        }
        onRejected: {
            console.log("Canceled")
        }
    }
}

