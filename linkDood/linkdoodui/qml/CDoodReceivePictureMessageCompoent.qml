import QtQuick 2.0
import com.syberos.basewidgets 2.0

Component {
    id: receivePictrueMessage

    Item {
        id: receivePictrueMessageRoot

        x: 0

        width: parent.width
        height: pictrueMessageBg.height

        property var myChatPage
        Loader {
            id: textNameRootLoader
            anchors.top: parent.top
            anchors.left: pictrueMessageBg.left
            asynchronous: false
            sourceComponent: null
        }

        Component {
            id: textNameRootComponent

            Item {
                id: textNameRoot
                height: textNameText.implicitHeight + 6
                width: chatDelegateRoot.maxMessageLength
                z: 100
                clip:  true

                Text {
                    id: textNameText
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5

                    color:"#999999"
                    font.pixelSize: 20
                    elide: Text.ElideRight;
                    text: model.modelData.name
                }
            }
        }

        Loader {
            id: receiveTextMsgHeadImageViewLoader
            anchors.top: textNameRootLoader.bottom

            anchors.left: parent.left
            anchors.leftMargin: 20
            asynchronous: false
            sourceComponent: receiveTextMsgHeadImageViewComponent
        }

        Component {
            id: receiveTextMsgHeadImageViewComponent

            CDoodHeaderImage {
                id: receiveTextMsgHeadImageView
                width: 90
                height: 90
                radius: 6
                name:""
                headerColor: sessionListManager.getHeaderColor(model.modelData.id)
                iconSource: setIcon("1", model.modelData.contactThumbAvatar)
//                    "qrc:/res/headerDefault.png"/*"file://"+ model.modelData.thumbAvatar*/

                MouseArea {
                    anchors.fill: parent
                    onPressAndHold: {
                        console.log("todo @ !!!")
                    }
                }
            }
        }

        BorderImage {
            id: pictrueMessageBg
            anchors.left: receiveTextMsgHeadImageViewLoader.right
            anchors.leftMargin: 10
            anchors.top: receiveTextMsgHeadImageViewLoader.top

            property var pictrueMessageWidth: pictrueMessage.width + 55
            property var pictrueMessageHeight: pictrueMessage.height + 40

            width: pictrueMessageWidth
            height: pictrueMessageHeight
            asynchronous : true

            border { left: 15; top: 50; right: 15; bottom: 15 }

            horizontalTileMode: BorderImage.Repeat
            verticalTileMode: BorderImage.Repeat

            source: "qrc:/res/receive/message.png"

            MouseArea {
                anchors.fill: parent

                onPressAndHold: {

                }

                onPressed: {
                    pictrueMessageBg.source = "qrc:/res/receive/messageActive.png"
                }

                onReleased: {
                    pictrueMessageBg.source = "qrc:/res/receive/message.png"
                }

                onCanceled: {
                    pictrueMessageBg.source = "qrc:/res/receive/message.png"
                }
                onClicked: {
                    console.log("sseeeeeeeeeeeeeeeeeeeeeeeeeeeeee")
                    myChatPage = pageStack.getCachedPage(Qt.resolvedUrl("CDoodViewImage.qml"),"CDoodViewImage");
                    myChatPage.imageSource = model.modelData.body;
                    console.log("xxxx1224:"+model.modelData.body)
                    pageStack.push(myChatPage);
                    if (chatListView.editing)
                        return;
                }
            }

            Image{
                id: pictrueMessage
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.top: parent.top
                anchors.topMargin: 25
                source: model.modelData.body

                visible: true
                Component.onCompleted: {
                    if(pictrueMessage.implicitWidth > chatDelegateRoot.maxMessageLength)
                        pictrueMessage.width = chatDelegateRoot.maxMessageLength
                }
            }
        }

        Loader {
            id: reciveFailedImageLoader
            anchors.left: pictrueMessageBg.right
            anchors.leftMargin: 20
            anchors.verticalCenter: pictrueMessageBg.verticalCenter
            asynchronous: true
            sourceComponent: null
        }

        Component {
            id: reciveFailedImageComponent

            Image {
                id: reciveFailedImage
                sourceSize: Qt.size(50, 50)
                visible: false
                source: "qrc:/res/sendfailed.png"
            }
        }

        Loader {
            id:  receivePictrueMessageLoadingLoader

            anchors.left: pictrueMessageBg.right
            anchors.leftMargin: 15
            anchors.verticalCenter: pictrueMessageBg.verticalCenter

            asynchronous: false
            sourceComponent: null
        }

        Component {
            id: receivePictrueMessageLoadingComponent

            CIndicator {
                direction: Qt.Horizontal
                textColor:"#ffffff"
                text:""
                spacing:28
                fontSize:26
            }
        }

        Behavior on x {
            NumberAnimation { duration: 100 }
        }
    }
}
