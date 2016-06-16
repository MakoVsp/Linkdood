#ifndef LINKDOODSERVICE_H
#define LINKDOODSERVICE_H

#include <QObject>
#include "authcontroler.h"

class CSystemPackageManager;
class ChatControler;
class ContactControler;

class LinkDoodService : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.vrv.linkDood")

public:
    void static createService();

    static LinkDoodService* instance();

signals:
    void loginSucceeded();
    void loginFailed(int64 errCode);

public slots:

    QString installPath();

    QString dataPath();

    // 功能		:	登录
    // 返回		:	NULL
    // 返回值    :	void
    // 参数		:
    // 		1.  server	服务器地址
    // 		2.  userId	登录ID
    // 		3.  password	登录密码
    void login(const QString &server,
               const QString &userId,
               const QString &password);

    /*****************start chat**************************/
    void getChatList(void);//获取会话列表
    void getUnReadMessages(void);//获取未读消息列表
    /*****************end chat****************************/

public:
    static LinkDoodService* m_pInstance;

private:
    LinkDoodService(QObject *parent = 0);

    ~LinkDoodService();

    // 初始化SDK
    void initSdk();
    void initObserver();//初始监听接口

    // 初始化Dbus连接
    void initDBusConnection();

    void onLoginResult(service::ErrorInfo& info,int64 userId);

private:
    CSystemPackageManager *m_pPackageManager;
    QString m_sInstallPath;

    std::shared_ptr<AuthControler>  m_pAuth;
    std::shared_ptr<ChatControler>  m_pChatObserver;
    std::shared_ptr<ContactControler>  m_pContactObserver;

    std::shared_ptr<service::IMClient> m_pIMClient;
};

#endif // LINKDOODSERVICE_H
