import QtQuick 2.0
import com.syberos.basewidgets 2.0
import QtDocGallery 5.0
import com.syberos.multimedia.photos 2.0

CPage {
    id: selectLocalImgePage

    property int maxSelectCount: 5
    onStatusChanged: {
        if (status === CPageStatus.WillShow) {
            selectLocalImgePage.statusBarHoldEnabled = true
            gScreenInfo.setStatusBar(selectLocalImgePage.statusBarHoldEnabled)
            selectLocalImgePage.statusBarHoldItemColor = "#edf0f0"
            gScreenInfo.setStatusBarStyle("black")
        }
        if(CPageStatus.WillHide === status){
            chatManager.setSelectImageCount(0,"");
        }
    }
    contentAreaItem:Item {
        anchors.fill :parent
        Rectangle {
            id: selectLocalImgeBackground
            anchors.fill: parent
            color: "#f2f2f2"
        }
        Rectangle{
            id: titleBackground

            color:"#003953"
            width:parent.width
            height:86
            anchors{
                top:parent.top
                left:parent.left
            }
            IconButton{
                id:btnBack
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    chatManager.setSelectImageCount(0,"");
                    pageStack.pop();
                }
            }
            Text{
                text:qsTr("选择图片")
                color:"white"
                font.pixelSize: 36
                anchors.centerIn: parent
            }
            Rectangle{
                id:btnSelectImg
                width:120
                height: 60
                color:"green"
                radius: 10
                visible: /*chatManager.selectImageCount>0*/false

                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
                Text{
                    text:qsTr("发送")+chatManager.selectImageCount+"/"+selectLocalImgePage.maxSelectCount
                    font.pixelSize: 28
                    color:"white"
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        chatManager.startSendPicture();
                        pageStack.pop();
                    }
                }
            }
        }
        ListView {
            id: imageList

            anchors.top: titleBackground.bottom
            anchors.bottom: parent.bottom

            width: parent.width
            clip:true
            model: gallery

            DocumentGalleryModel {
                id: gallery

                autoUpdate: true
                rootType: DocumentGalleryModel.Image
                sortProperties: ["-lastModified"]
                properties: ["fileExtension", "fileName", "filePath", "fileSize", "lastModified", "lastAccessed", "mimeType", "path", "url"]

                onProgressChanged:  {
                    if(gallery.progress === 1) {
                        //                filePageOverlay.visible = false
                    }
                }
            }

            delegate: Rectangle {
                id: imageDelegate
                height: 160
                width: parent.width
                color: "#ffffff"
                //visible: !chatManager.isMySentFile(filePath)
                property bool imageSelectState :chatManager.imageExisted(filePath)
                MouseArea {
                    anchors.fill: parent

                    onPressed: {
                        imageDelegate.color = "#cdcdcd"
                    }


                    onReleased: {
                        imageDelegate.color = "#ffffff"
                        chatManager.setSelectImageCount(1,filePath);
                        chatManager.startSendPicture();
                        pageStack.pop();
//                        if(imageDelegate.imageSelectState) {
//                            imageSelectImage.source = "qrc:/res/picture_unselected.png"
//                            imageDelegate.imageSelectState = false
//                            chatManager.setSelectImageCount(-1,filePath);
//                        } else {

//                            if(chatManager.selectImageCount>=selectLocalImgePage.maxSelectCount){
//                                gToast.requestToast("最多选择"+selectLocalImgePage.maxSelectCount+"张图片","","");
//                                return;
//                            }
//                            imageSelectImage.source = "qrc:/res/pictures_selected.png"
//                            imageDelegate.imageSelectState = true;
//                            chatManager.setSelectImageCount(1,filePath);
//                        }
                    }

                    onCanceled: {
                        imageDelegate.color = "#ffffff"
                    }
                }

                PImage {
                    id: imageImage
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.verticalCenter: parent.verticalCenter
                    width: 85
                    height: 85
                    sourceUrl: url
                    animated: false
                    thumbnailOnly: true

                    Connections {
                        target: imageImage.item
                        onStatusChanged: {
                            if (imageImage.status === Image.Error || imageImage.status === Image.Null) {
                                //imageImage.sourceUrl = "qrc:/images/defultPicture.png"
                            }
                        }
                    }
                }
                Text {
                    id: imageTitleText
                    anchors.left: imageImage.right
                    anchors.leftMargin: 30
                    anchors.right: imageSelectImageRoot.left
                    anchors.rightMargin: 30
                    anchors.top: parent.top
                    anchors.topMargin: 44
                    font.pixelSize: 30
                    color: "#333333"
                    elide: Text.ElideRight;
                    text: fileName
                }

                Text {
                    id: imageFileSizeText
                    anchors.left: imageTitleText.left
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 44
                    font.pixelSize: 26
                    color: "#8d8d8d"
                    elide: Text.ElideRight;
                    text:  getSizeStr(fileSize)
                }

                Text {
                    id: imageLastModifiedText
                    anchors.left: imageFileSizeText.right
                    anchors.leftMargin: 30
                    anchors.right: imageSelectImageRoot.left
                    anchors.rightMargin: 30
                    anchors.top: imageFileSizeText.top
                    font.pixelSize: 26
                    color: "#8d8d8d"
                    elide: Text.ElideRight;
                    text: Qt.formatDateTime(model.lastModified,"yyyy-MM-dd  hh:mm")
                }

                Item {
                    id: imageSelectImageRoot

                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    width: 90

                    Image {
                        id: imageSelectImage
                        anchors.right: parent.right
                        anchors.rightMargin: 40
                        anchors.verticalCenter: parent.verticalCenter
                        source: imageDelegate.imageSelectState ? "qrc:/res/pictures_selected.png" : "qrc:/res/picture_unselected.png"
                        sourceSize: Qt.size(50, 50)
                        asynchronous: true
                        smooth: true
                        visible: false
                    }
                }

                CLine {
                    width: parent.width
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.right: parent.right
                    anchors.rightMargin: 40
                    anchors.bottom: parent.bottom
                    z: parent.z+2
                }
            }
        }
    }

    function getSizeStr(bytes) {
        var unit = ["B", "KB", "MB", "GB", "TB"]
        var i = 0
        var str = bytes + unit[0]
        while(bytes > 1024 && i<unit.length) {
            bytes /= 1024.0
            i++
            str = Number(bytes).toPrecision(3) + unit[i]
        }
        return str
    }
}
