#-------------------------------------------------
#
# Project generated by QtCreator for SyberOS.
#
#-------------------------------------------------

# This is needed for using syberos-application module
include(../syberos.pri)

QT += qml quick dbus multimedia gui-private  gui
QT       += sensors
TARGET = linkdoodui
TEMPLATE = app

CONFIG += link_pkgconfig qml_debug
PKGCONFIG += syberos-application syberos-application-cache

INCLUDEPATH += ../linkdoodclient
LIBS += -L../linkdoodclient
LIBS += -llinkdoodclient
QMAKE_LFLAGS += -Wl,-rpath=$$LIB_DIR -Wl,-Bsymbolic

RESOURCES += qml.qrc images.qrc \
    smilies.qrc

HEADERS += src/linkdoodui_workspace.h \
    src/cdoodlistmodel.h \
    src/cdoodloginmanager.h \
    src/cdoodsessionlistmanager.h \
    src/cdoodsessionlistitem.h \
    src/cdoodcontactitem.h \
    src/cdoodcontactmanager.h \
    src/cdoodenterprisemanager.h\
    src/cdoodchatmanager.h\
    src/cdooduserdatamanage.h \
    src/cdoodchatitem.h \
    src/cdoodorgitem.h \
    src/cdoodorguseritem.h \
    src/cdoodorgmanager.h \
    src/cdooduserprofilemanager.h \
    src/cdoodemojimanager.h \
    src/cdoodemojiitem.h \
    src/cdoodaddcontactmanager.h \
    src/cdoodgroupmanager.h \
    src/cdoodgroupitem.h \
    src/cdoodfriendverificationmanager.h \
    src/cdoodsysmsgmanager.h \
    src/cdoodsysmsgitem.h\
    src/cdoodmembermanager.h \
    src/cdoodmemberitem.h \
    src/cdoodlocalsearchmanager.h \
    src/cdoodchatmanagermodel.h \
    src/cdoodfileviewmanager.h \
    src/cdoodenterpriseitem.h

SOURCES += src/main.cpp \
    src/linkdoodui_workspace.cpp \
    src/cdoodlistmodel.cpp \
    src/cdoodloginmanager.cpp \
    src/cdoodsessionlistmanager.cpp \
    src/cdoodsessionlistitem.cpp \
    src/cdoodcontactitem.cpp \
    src/cdoodcontactmanager.cpp \
    src/cdoodenterprisemanager.cpp\
    src/cdoodchatmanager.cpp\
    src/cdooduserdatamanage.cpp \
    src/cdoodchatitem.cpp \
    src/cdoodorgitem.cpp \
    src/cdoodorguseritem.cpp \
    src/cdoodorgmanager.cpp \
    src/cdooduserprofilemanager.cpp \
    src/cdoodemojimanager.cpp \
    src/cdoodemojiitem.cpp \
    src/cdoodaddcontactmanager.cpp \
    src/cdoodgroupmanager.cpp \
    src/cdoodgroupitem.cpp \
    src/cdoodfriendverificationmanager.cpp \
    src/cdoodsysmsgmanager.cpp \
    src/cdoodsysmsgitem.cpp\
    src/cdoodmembermanager.cpp \
    src/cdoodmemberitem.cpp \
    src/cdoodlocalsearchmanager.cpp \
    src/cdoodchatmanagermodel.cpp \
    src/cdoodfileviewmanager.cpp \
    src/cdoodenterpriseitem.cpp

OTHER_FILES += qml/*.qml

target.path = $$INSTALL_DIR/bin

res.files = res
res.path = $$INSTALL_DIR/

INSTALLS += target res

DISTFILES += \
    qml/CDoodLoginPage.qml \
    qml/CDoodTabViewStyle.qml \
    qml/CDoodSessionListPage.qml \
    qml/CDoodContactRootPage.qml \
    qml/CDoodRootTabView.qml \
    qml/CDoodHeaderImage.qml \
    qml/CDoodUserDataPage.qml \
    qml/CDoodChatDelegate.qml \
    qml/CDoodSendTextMessageCompoent.qml \
    qml/CDoodReceiveTextMessageCompoent.qml \
    qml/CDoodContactMainPage.qml \
    qml/CDoodEnterprise.qml \
    qml/CDoodTabViewEnterStyle.qml \
    qml/CDoodProfileDataPage.qml \
    qml/CDoodMailLoginPage.qml \
    qml/CDoodActivateAccountPage.qml \
    qml/CDoodChangePasswordPage.qml \
    qml/CDoodAddContactPage.qml \
    qml/CDoodSearchContactPage.qml\
    qml/CDoodVerifyImgPage.qml \
    qml/CDoodGroupListPage.qml \
    qml/CDoodFriendVerificationPage.qml \
    qml/cdoodMemberListPage.qml \
    qml/CDoodGroupAddMemberPage.qml \
    qml/CDoodGroupSetPage.qml \
    qml/CDoodAddGroupPage.qml \
    qml/CDoodChatMessageOption.qml \
    qml/CDoodGroupViewImagePage.qml \
    qml/CDoodGroupAddMainPage.qml \
    qml/CDoodGroupAddOrgPage.qml
