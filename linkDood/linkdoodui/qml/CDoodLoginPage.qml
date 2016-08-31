import QtQuick 2.0
import com.syberos.basewidgets 2.0
CPage {
    id: loginPage

    property string  server
    property string  name
    property string  password


    onStatusChanged: {
        if (status === CPageStatus.WillShow) {
            loginPage.statusBarHoldEnabled = true
            gScreenInfo.setStatusBar(loginPage.statusBarHoldEnabled)
            loginPage.statusBarHoldItemColor = "#edf0f0"
            gScreenInfo.setStatusBarStyle("black")
        }
    }

    Connections {
        target: loginManager

        //        onInputRootTabView: {
        //            console.log("onInputRootTabView !!!!")
        //            pageStack.replace(Qt.resolvedUrl("CDoodRootTabView.qml"), "", true);
        //        }

        onLoginSucceeded: {
            console.log("onLoginSuccess !!!!")
            loadingDialog.hide();
            sessionListManager.getChatList();
            enterpriseManager.setFarOrg();
            orgManager.resetOrgList();
            pageStack.replace(Qt.resolvedUrl("CDoodRootTabView.qml"), "", true);

            //            var component = pageStack.getCachedPage(Qt.resolvedUrl("CDoodChatPage.qml"),"CDoodChatPage");
        }
        onLoginResultObserver:{
            console.log("onLoginResultObserver !!!!");
            loginManager.setLoginInfo(2,userID,userLineEdit.text,"");
        }


        onLoginFailed: {console.log("onLoginFailed !!!!")
            loadingDialog.hide();

            if(err === "帐号已经登录"){
                sessionListManager.getChatList();
                contactManager.getContactList();
                userProfileManager.getAccountInfo();
                groupManager.getGroupList();
                enterpriseManager.setFarOrg();
                orgManager.resetOrgList();
                chatManager.clearList();
                pageStack.replace(Qt.resolvedUrl("CDoodRootTabView.qml"), "", true);
                return;
            }
            gToast.requestToast(err,"","");
            if(err==="首次登录，请激活帐号")
            {
                pageStack.replace(Qt.resolvedUrl("CDoodActivateAccountPage.qml"), "", true);
            }
            if(err==="输入错误次数过多,请输入验证码")
            {
                pageStack.replace(Qt.resolvedUrl("CDoodVerifyImgPage.qml"), "", true);
            }
        }
    }

    contentAreaItem: Item {
        anchors.fill :parent
        Rectangle {
            id: loginBackground
            anchors.fill: parent
            color: "#f2f2f2"
        }
        Flickable{
            id: filckableInput
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            contentHeight: parent.height

            Connections {
                target: gInputContext
                onSoftwareInputPanelVisibleChanged: {
                    if(gInputContext.softwareInputPanelVisible) {
                        filckableInput.contentHeight = filckableInput.parent.height + 200
                    } else {
                        filckableInput.contentHeight = filckableInput.parent.height
                    }
                }
            }

            Rectangle{
                id:titleBackground

                anchors.top: parent.top
                anchors.left: parent.left

                width:parent.width
                height: 86
                color:"#003658"
                Text{
                    id:titleText

                    anchors.centerIn: parent

                    text:qsTr("手机用户登录")
                    color:"white"
                    font.pixelSize: 36
                }
            }

            Rectangle {
                id: inputBackGround

                anchors.top: titleBackground.bottom
                height: 404
                anchors.topMargin: 16
                anchors.left: parent.left
                anchors.right:parent.right
                anchors.leftMargin: 16
                anchors.rightMargin:16
                border.color: "#777777"
                border.width: 1
                radius:10
                color: "#ffffff"
            }

            Text{
                id:conTip

                anchors{
                    left:inputBackGround.left
                    leftMargin: 25
                    verticalCenter: conLineEdit.verticalCenter
                }
                width:100
                text:qsTr("国家和地区")
                font.pixelSize: 30
            }

            CLineEdit {
                id: conLineEdit
                anchors.top: inputBackGround.top
                anchors.left: conTip.right
                anchors.right:inputBackGround.right
                anchors.leftMargin: 50/*srvLineEdit.text ==="" ? 50 : 0*/

                height: 101
                passwordLabelEnabled: false
                textLeftMargin: 50
                clip: true

                //              horizontalAlignment: srvLineEdit.text ==="" ? TextInput.AlignLeft: TextInput.AlignHCenter
                textColor:"#787777"
                font.pixelSize: 30
                placeholderText:os.i18n.ctr(qsTr("请输入国家"))

                inputMethodHints: Qt.ImhHiddenText/*|Qt.ImhPreferNumbers*/
                text: "中国"

                onTextChanged: {
                    passWordEdit.text = ""

                    if(loginPage.state !== "hidden") {
                        loginPage.state = "hidden"
                    }
                }
            }
            CLine {
                width: inputBackGround.width
                anchors.top: conLineEdit.bottom
                anchors.left:inputBackGround.left
                z: parent.z+2
            }
            Text{
                id:srvTip

                anchors{
                    left:inputBackGround.left
                    leftMargin: 25
                    verticalCenter: srvLineEdit.verticalCenter
                }
                width:100
                text:qsTr("服务器")
                font.pixelSize: 30
            }

            CLineEdit {
                id: srvLineEdit
                anchors.top: conLineEdit.bottom
                anchors.left: srvTip.right
                anchors.right:inputBackGround.right
                anchors.leftMargin: 50/*srvLineEdit.text ==="" ? 50 : 0*/

                height: 101
                passwordLabelEnabled: false
                textLeftMargin: 50
                clip: true

                //              horizontalAlignment: srvLineEdit.text ==="" ? TextInput.AlignLeft: TextInput.AlignHCenter
                textColor:"#787777"
                font.pixelSize: 30
                placeholderText:os.i18n.ctr(qsTr("请输入服务器"))
                validator:RegExpValidator{regExp:/^[a-zA-Z0-9.][a-zA-Z0-9.]*$/}
                inputMethodHints: Qt.ImhHiddenText/*|Qt.ImhPreferNumbers*/
                text: loginManager.getLoginService();

                onTextChanged: {
                    passWordEdit.text = ""

                    if(loginPage.state !== "hidden") {
                        loginPage.state = "hidden"
                    }
                }
            }
            CLine {
                width: inputBackGround.width
                anchors.top: srvLineEdit.bottom
                anchors.left:inputBackGround.left
                z: parent.z+2
            }
            Text{
                id:userTip

                anchors{
                    left:inputBackGround.left
                    leftMargin: 25
                    verticalCenter: userLineEdit.verticalCenter
                }
                width:100
                text:qsTr("+86")
                font.pixelSize: 30
            }

            CLineEdit {
                id: userLineEdit
                anchors.top: srvLineEdit.bottom
                anchors.left: userTip.right
                anchors.right:inputBackGround.right
                anchors.leftMargin: 50/*srvLineEdit.text ==="" ? 50 : 0*/

                height: 101
                passwordLabelEnabled: false
                textLeftMargin: 50
                clip: true

                //              horizontalAlignment: srvLineEdit.text ==="" ? TextInput.AlignLeft: TextInput.AlignHCenter
                textColor:"#787777"
                font.pixelSize: 30
                placeholderText:os.i18n.ctr(qsTr("请输入手机号"))
                validator:RegExpValidator{regExp:/^[0-9]*$/}
                inputMethodHints: Qt.ImhHiddenText/*|Qt.ImhPreferNumbers*/
                text: loginManager.getLoginPhone();

                onTextChanged: {
                    passWordEdit.text = "";

                    if(loginPage.state !== "hidden") {
                        loginPage.state = "hidden"
                    }
                }
            }
            CLine {
                width: inputBackGround.width
                anchors.top: userLineEdit.bottom
                anchors.left:inputBackGround.left
                z: parent.z+2
            }
            //            Rectangle{
            //                anchors.top: userLineEdit.bottom
            //                anchors.left: inputBackGround.left
            //                height: passWordEdit.height
            //                width: inputBackGround.width
            //                MouseArea {
            //                    anchors.fill: parent
            //                    onClicked: {
            //                        passWordEdit.focus = true;
            //                    }
            //                }
            //            }

            Text{
                id:srvPwd

                anchors{
                    left:inputBackGround.left
                    leftMargin: 25
                    verticalCenter: passWordEdit.verticalCenter
                }
                width: 100
                text:qsTr("密码")
                font.pixelSize: 30
            }

            CLineEdit {
                id: passWordEdit
                anchors.top: userLineEdit.bottom
                anchors.left: srvPwd.right
                anchors.right:inputBackGround.right
                anchors.leftMargin: 50
                anchors.rightMargin: 20

                clearLabelRightMargin:40
                height: 101
                passwordLabelEnabled: false
                echoMode: TextInput.Password
                textLeftMargin: 50
                clip: true
                textColor:"#787777"
                font.pixelSize: 30
                validator:RegExpValidator{regExp:/^[a-zA-Z0-9][a-zA-Z0-9]*$/}
                placeholderText:os.i18n.ctr(qsTr("请输入密码"))
                inputMethodHints:Qt.ImhHiddenText
                CButton{
                    id: seePassword;
                    anchors.right: parent.right
                    iconSource: passWordEdit.echoMode === TextInput.Normal ? "qrc:/res/control/echo_normal.png" : "qrc:/res/control/echo_pwd.png"
                    backgroundEnabled: false
                    width: 40
                    height: parent.height
                    onReleased: {
                        if(containsMouse){
                            passWordEdit.echoMode = passWordEdit.echoMode === TextInput.Normal ? TextInput.Password : TextInput.Normal;
                        }
                    }
                }
            }

            CButton {
                id: loginButton

                anchors.top: passWordEdit.bottom
                anchors.topMargin: 19
                anchors.horizontalCenter: parent.horizontalCenter
                height:121
                width:680

                opacity : pressed ? 1: (userLineEdit.text .trim()==="" || passWordEdit.text.trim() ==="" ? 0.5 : 1)
                text:os.i18n.ctr(qsTr("登 录")) // "登 录"
                textColor:  "#ffffff"

                backgroundComponent: Rectangle {
                    anchors.fill: parent
                    color:"#32c2fe"
                    radius: 10
                }

                onClicked: {
                    console.log("login onClicked !!!")
                    if(srvLineEdit.text ===""){
                        gToast.requestToast("服务器不能为空","","");
                        return;
                    }
                    if(userLineEdit.text ===""){
                        gToast.requestToast("用户名不能为空","","");
                        return;
                    }
                    if(passWordEdit.text ===""){
                        gToast.requestToast("密码不能为空","","");
                        return;
                    }
                    if(loginManager.checkFirstWordIsSpace(userLineEdit.text)) {
                        userLineEdit.text = ""
                        userLineEdit.focus = true
                        if(immanager.windowFocus)
                            gToast.requestToast("账号格式不正确","","");
                        return
                    }
                    if(userLineEdit.text === "") {
                        userLineEdit.focus = true
                        gToast.requestToast("帐号不能为空","","");
                    } else if(passWordEdit.text === "") {
                        passWordEdit.focus = true
                        gToast.requestToast("密码不能为空","","");
                    } else {
                        loadingDialog.show();
                        loginManager.setLoginPhone(userLineEdit.text);
                        loginManager.setLoginService(srvLineEdit.text);
                        loginManager.login(srvLineEdit.text, "0086"+userLineEdit.text+":1", passWordEdit.text);
                    }
                }

                Behavior on opacity {
                    PropertyAnimation { duration: 200 }
                }
            }
            CButton{
                id:forgetpsw
                anchors.top: loginButton.bottom
                anchors.topMargin: 50
                anchors.rightMargin: 20
                anchors.right: parent.right
                height:50
                width:200
                visible: false
                text:os.i18n.ctr(qsTr("忘记密码"))
                textColor:  "#32c2fe"
                backgroundComponent: Rectangle {
                    anchors.fill: parent
                    color:"#f2f2f2"
                    radius: 10
                }
                onClicked: {
                    var tll = Qt.openUrlExternally("http://www.baidu.com");
                    console.log("sssss",tll);
                    //loginManager.openUrl("http://www.baidu.com");
                    //webview.goForward();
                }
            }
            CButton{
                id:maillogin
                anchors.top: loginButton.bottom
                anchors.topMargin: 50
                anchors.leftMargin: 20
                anchors.left: parent.left
                height:50
                width:200
                text:os.i18n.ctr(qsTr("身份证登录"))
                textColor:  "#32c2fe"
                backgroundComponent: Rectangle {
                    anchors.fill: parent
                    color:"#f2f2f2"
                    radius: 10
                }
                onClicked: {
                    pageStack.replace(Qt.resolvedUrl("CDoodMailLoginPage.qml"), "", true);
                }
            }

            CIndicatorDialog {
                id:loadingDialog
                //            indicatorDirection: Qt.Horizontal
                messageText: os.i18n.ctr(qsTr("正在登录中...")) // qsTr("正在登录中...")
            }

        }
    }
}
