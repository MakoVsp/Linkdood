import QtQuick 2.0
import com.syberos.basewidgets 2.0

Item {
    Connections {
        target: enterpriseManager
        onFarOrgResult: {
            console.log("ogr change111111.")
            enterpriseManager.getSonOrgs(id);
            //          orgManager.addOrg(id,name);
//            loadingDialog.show();
        }
        onGetSonOrgsResult:{
            console.log("ogr change.")
            loadingDialog.hide();
            orgTitleListView.positionViewAtEnd();
        }
    }
    id: groupAddOrgPage

    property bool isTransMsg: false

    anchors.fill: parent
    Rectangle {
        anchors.top: parent.top
        anchors.left: parent.left

        width:parent.width
        height: parent.height

        color: "white"
        z:parent.z-1
    }
    Rectangle{
        id:orgTitleListViewbackground
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: 51
        color:"#F2F2F2"
        ListView{
            id: orgTitleListView
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.leftMargin: 47
            //        anchors.topMargin: 21
            width: parent.width
            height: parent.height
            orientation:ListView.Horizontal
            spacing: -25
            model: orgManager
            snapMode: ListView.SnapOneItem
            Rectangle{
                anchors.fill: parent
                color:"#F2F2F2"
                z:parent.z -1
            }

            delegate: Rectangle{
                width: name.contentWidth+80
                height: 50
                anchors.top:parent.top
                color:"#F2F2F2"
                anchors.topMargin: 0
                BorderImage{
                    width: parent.width
                    height: parent.height
                    border.left: 25
                    border.right: 25
                    anchors.top:parent.top
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: -25
                    source: model.modelData.select===""?"qrc:/res/unselected.png":"qrc:/res/selected.png"
                    visible: index !== (orgTitleListView.count)
                    z:parent.z+10
                    Text {
                        id: name
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: model.modelData.name
                        font.pixelSize: 26
                        color:"#333333"
                    }

                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        orgManager.selectOrg(model.modelData.id)
                        enterpriseManager.getSonOrgs(model.modelData.id)
                        loadingDialog.show();
                    }
                }
            }
        }
    }
    Rectangle{
        id:memberRec
        anchors.top: orgTitleListViewbackground.bottom
        height: enterpriseManager.isOrg?0:43
        visible: enterpriseManager.isOrg?false:true
        anchors.left: parent.left
        anchors.right: parent.right
        color:"#EAEEF2"
        Text{
            //            anchors.top: parent.top
//            anchors.left:parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.leftMargin: enterpriseManager.isOrg?45:245
            //            color:"black"
            text:enterpriseManager.tip
            font.pixelSize: 26
        }
    }
    CLine {
        id:line
        width: parent.width
        anchors.top: orgTitleListViewbackground.bottom
        anchors.left:parent.left
        z: parent.z+2
        visible: enterpriseManager.isOrg?true:false
    }
//    Rectangle{
//        id:memberRec
//        anchors.top: orgTitleListViewbackground.bottom
//        height: 43
//        anchors.left: parent.left
//        anchors.right: parent.right
//        color:"#EAEEF2"
//        Text{
//            //            anchors.top: parent.top
//            anchors.left:parent.left
//            anchors.verticalCenter: parent.verticalCenter
//            anchors.leftMargin: enterpriseManager.isOrg?45:245
//            //            color:"black"
//            text:enterpriseManager.isOrg?qsTr("成员"):qsTr("暂未加入任何组织")
//            font.pixelSize: 26
//        }
//    }
    Rectangle{
        anchors.top: enterpriseManager.isOrg? line.bottom:memberRec.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        color:"#F2F2F2"

        ListView {
            id: orgListView
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom



            clip: true
            model: enterpriseManager

            delegate:Item {
                id:contactListDelegate

                width: orgTitleListView.width
                height: 100

                MouseArea {
                    anchors.fill: parent

                    onPressed: {
                        if(mousePressBackgroud.visible){
                            background.color = "#F2F2F2"
                            mousePressBackgroud.visible = false
                        }else{
                            background.color = "#cdcdcd"
                            mousePressBackgroud.visible = true
                        }
                    }

                    onReleased: {
                        //                    userdataManager.setName(model.modelData.name);
                        //                    userdataManager.setGender(model.modelData.gender);
                        //                    userdataManager.setThumbAvatar(model.modelData.thumbAvatar);
                        //                    userdataManager.setId(model.modelData.id);

                        background.color = "white"
                        mousePressBackgroud.visible = false
                        if(model.modelData.gender===""){
                            console.log(" model.modelData.id: ",model.modelData.id)
                            console.log(" model.modelData.name: ",model.modelData.name)
                            orgManager.addOrg(model.modelData.id, model.modelData.name);

                            enterpriseManager.getSonOrgs(model.modelData.id)
                            loadingDialog.show();
                        }
                        else{
                            background.color = "#F2F2F2"
                            if(groupManager.isCreateGroup){
                                var size=groupManager.getSize("1","0",groupManager.memberCount);
                                if(size==="1000"){
                                    gToast.requestToast("群成员数不能超过1000","","");
                                    return;
                                }
                            }
                            else{
                                var size1=groupManager.getSize("1",memberManager.memberSize,groupManager.memberCount);
                                if(size1==="1000"){
                                    gToast.requestToast("群成员数不能超过1000","","");
                                    return;
                                }
                            }

                            if(groupAddOrgPage.isTransMsg){
                                groupManager.selectmember(model.modelData.id);
                                groupManager.selectMemberName(model.modelData.id,model.modelData.name);
                                enterpriseManager.changeMember(groupManager.returnmember());
                                enterpriseManager.selectMember(model.modelData.id);
                                contactManager.selectMember(model.modelData.id);

                            }else{
                                if(groupManager.isCreateGroup){
                                    groupManager.selectmember(model.modelData.id);
                                    enterpriseManager.changeMember(groupManager.returnmember());
                                    contactManager.selectMember(model.modelData.id);
                                    enterpriseManager.selectMember(model.modelData.id);
                                     console.log("000111111");
                                }
                                else{
                                    if(!memberManager.isMember(model.modelData.id)){
                                        groupManager.selectmember(model.modelData.id);
                                        enterpriseManager.changeMember(groupManager.returnmember());
                                        enterpriseManager.selectMember(model.modelData.id);
                                        contactManager.selectMember(model.modelData.id);
                                    }
                                }
                            }
                        }
                    }

                    onCanceled: {
                        background.color = "#F2F2F2"
                        mousePressBackgroud.visible = false
                    }
                }

                Rectangle {
                    width: contactListDelegate.width
                    height: contactListDelegate.height
                    color:"#F2F2F2"


                    Rectangle {
                        id : mousePressBackgroud
                        anchors.fill: parent
                        visible: false
                        color: "#cdcdcd"
                    }

                    Rectangle {
                        id : background
                        anchors.fill: parent
                        //                        anchors.topMargin: 1
                        //                        anchors.bottomMargin: 3
                        //                        anchors.leftMargin: 2
                        //                        anchors.rightMargin:  2
                        color:"#F2F2F2"
                        Image{
                            id:chooseImage1
                            visible:  model.modelData.gender===""?false:true
                            anchors.left: parent.left
                            anchors.leftMargin: 25
                            anchors.topMargin: 16
                            anchors.verticalCenter: parent.verticalCenter
                            source:model.modelData.isChoose==="8888"?"":select1()
                            function select1(){
                                console.log("000");
                                if(groupAddOrgPage.isTransMsg){
                                    if(model.modelData.isChoose===""){
                                        return "qrc:/res/group_select_cbox_normal.png";
                                    }
                                    else{
                                        return "qrc:/res/group_select_cbox_press.png";
                                    }
                                }

                                if(groupManager.isCreateGroup){
                                    console.log("001");
                                    if(model.modelData.isChoose===""){
                                        console.log("111");
                                        return "qrc:/res/group_select_cbox_normal.png";
                                    }
                                    else{
                                        console.log("222");
                                        return "qrc:/res/group_select_cbox_press.png";
                                    }
                                }
                                else{
                                    console.log("002");
                                    if(memberManager.isMember(model.modelData.id)){
                                        return "qrc:/res/group_select_cbox_have.png";
                                    }
                                    if(model.modelData.isChoose===""){
                                        return "qrc:/res/group_select_cbox_normal.png";
                                    }
                                    else{
                                        return "qrc:/res/group_select_cbox_press.png";
                                    }
                                }

                            }
                        }

                        CDoodHeaderImage {
                            id: headPortraitImage
                            anchors.left: parent.left
                            anchors.leftMargin: model.modelData.gender===""?25:100
                            anchors.topMargin: 16
                            anchors.verticalCenter: parent.verticalCenter
                            width: 90
                            height: 90
                            radius: 6
                            name:""
                            iconSource:model.modelData.thumbAvatar;
                        }
                        Text {
                            id: nameText
                            anchors.left: headPortraitImage.right
                            anchors.leftMargin: 30
                            anchors.rightMargin: 20
                            anchors.top: parent.top
                            anchors.topMargin: 20
                            font.pixelSize: 24
                            height: 33
                            clip: true
                            color: "#333333"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                            text: model.modelData.name
                        }
                        CLine {
                            //                            width: parent.width
                            width: 1
                            anchors.left: parent.left
                            color:"#cdcdcd"
                            anchors.leftMargin: 25
                            anchors.right: parent.right
                            anchors.bottom: parent.bottom
                            z: parent.z+2
                        }
                    }
                }
            }
        }
    }
    CIndicatorDialog {
        id:loadingDialog
        //            indicatorDirection: Qt.Horizontal

        messageText: os.i18n.ctr(qsTr("正在获取中...")) // qsTr("正在获取中...")
        onBackKeyReleased: {
            loadingDialog.hide();
        }
    }
}
