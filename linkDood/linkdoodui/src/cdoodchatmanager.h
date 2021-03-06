#ifndef CDOODCHATMANAGER_H
#define CDOODCHATMANAGER_H

#include <QObject>
#include <QMimeData>
#include <QDebug>
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QTextBlock>
#include <QTextFormat>
#include <QQuickTextDocument>

#include "cdoodlistmodel.h"
#include "linkdoodclient.h"
#include "cdoodchatmanagermodel.h"
#include "linkdoodui_workspace.h"

class CDoodChatItem;

class CDoodChatManager : public CDoodListModel
{
    Q_OBJECT
    Q_PROPERTY(int selectImageCount READ selectImageCount WRITE setSelectImageCount NOTIFY selectImageCountChanged)
    Q_PROPERTY(int selectFileCount READ selectFileCount WRITE setSelectFileCount NOTIFY selectFileCountChanged)
public:
    explicit CDoodChatManager(LinkDoodClient *client = 0, QObject *parent = 0);
    ~CDoodChatManager();

    Q_INVOKABLE  void switchToChatPage(QString targetId, QString name,QString chatType,QString lastMsgId="",int unReadCount=0,QString icon="");
    Q_INVOKABLE  void showUiFinished();
    Q_INVOKABLE  void groupChatTipMember(QString membername);
    Q_INVOKABLE  void clearList();
    Q_INVOKABLE  void getMoreHistoryMessage();
    Q_INVOKABLE  void getGroupMemsList(QString groupId);
    Q_INVOKABLE  CDoodChatManagerModel* chatModel ()const;
    Q_INVOKABLE  void isTextOnClipboard();
    Q_INVOKABLE  bool isTextOnly(QString text);
    Q_INVOKABLE  bool isMySentFile(QString filePath);
    void updateMsgToListView(Msg msg,bool isFromPC=false);

    void startPushChatPage();

    //选择图片
    int selectImageCount();
    void setSelectImageCount(int count);
    Q_INVOKABLE void setSelectImageCount(int oper,QString url);
    Q_INVOKABLE bool imageExisted(QString url);
    Q_INVOKABLE void startSendPicture();
    Q_INVOKABLE QString cameraFilePath();
    Q_INVOKABLE void sendPictrue(QString path,bool isRotate=false);

    //选择文件
    int selectFileCount();
    void setSelectFileCount(int count);
    Q_INVOKABLE void setSelectFileCount(int oper,QString url);
    Q_INVOKABLE bool fileExisted(QString url);
    Q_INVOKABLE void startSendFile();
    void sendFile(QString path);
    Q_INVOKABLE void setDraft(QString targetId,QQuickTextDocument* item);
    //发送消息
    Q_INVOKABLE void sendText(QQuickTextDocument* item,QString oriText,QList<QString> list);
    Q_INVOKABLE void resendMessage(QString localId);
    Q_INVOKABLE QString handleEmojiText(QQuickTextDocument* item);

    void sendText(QString text,QString oriText,QList<QString> list);
    void sendMessage(Msg msg);
    //发送动态表情
    Q_INVOKABLE void sendDyEmojiMsg(QString path);

    //获取消息
    Q_INVOKABLE void getMessages(QString targetid, int count,QString lastMsgid,int flag=0);

    //移除会话
    Q_INVOKABLE void removeChat(QString targetid);
    //设置消息已读
    Q_INVOKABLE void setMessageRead(QString targetid,QString msgid);
    //获取未读消息列表
    Q_INVOKABLE void getUnReadMessages(void);
    //删除消息
    Q_INVOKABLE void deleteMessage(QString targetid, QString localId);
    Q_INVOKABLE void revokeMessage(QString targetId,QString localId);

    Q_INVOKABLE void transforMessage(QString targetid,QString targetName,QString avatar, QString msgId);
    Q_INVOKABLE void entryChat(const QString &targetid);
    Q_INVOKABLE void exitChat();
    Q_INVOKABLE QString chatPageId();
    Q_INVOKABLE void downloadFile(QString localId, QString targetId);
    Q_INVOKABLE QString judgeFileFromat(QString filePath);
    Q_INVOKABLE void getUserInfo(QString userid);
    Q_INVOKABLE void downloadMainImage(QString main_url,QString encryptkey,QString targetId);

    //上传图片
    void uploadAndSendImageMsg(Msg);
    //上传文件
    void uploadAndSendFileMsg(Msg msg);

    //下载文件
    void downloadFile(QString path, QString url, QString json,QString localId,QString targetId);

    //下载图片
    void downloadImage(QString url, QString property);
    void downloadHistoryImage(QString url, QString property, QString targetid, QString localid);
    //解密文件
    bool decryptFile(QString encryptkey, QString srcpath, QString destpath);
    //获取文件列表
    void getFileList(int64 targetid, int64 fileid, int count, int flag);

    void groupMemsChanged(QString groupid,int size);
signals:
    void removeCurrentChat();
    //会话列表头像更新
    void chatAvatarChanged(QString id,QString avatar);
    //监听离线消息通知
    void offlineMsgNotice(IMOfflineMsgList msgList);
    //监听新消息通知
    void newMessageNotice();
    //发送消息返回
    void sendMessageResult(bool code,QString sendTime,QString msgId);
    //获取消息结果返回
    void getMessagesResult(bool code,QString sessionId,MsgList msgList);
    //移除会话结果返回
    void groupChatTipMemberResult(QString membername);
    void removeChatResult(bool);
    void getUserInfoResult(int code, Contact contact);
    void transforMessageBack(int code);
    void downloadMainImageResult(QString main_url,QString localpath);
    void updateSessionPageMsgReaded(QString targetId);

    void idChanged();
    void revokeMessageOutTime();
    void nameChanged();
    void chatTypeChanged();
    void chatPageChanged();
    void draftChanged(QString id, QString avater,QString name,QString chatType,QString draft);
    void selectImageCountChanged();
    void selectFileCountChanged();
    void sendShowChatPage(QString chatName,
                          QString targetid,
                          QString chatType);
private slots:
    void onDraftChanged(QString draft);
    void onDeleteMessage(QString targetId,QStringList msgs);
    void onGetOrgUserInfoResult(int code,OrgUser orguser);
    void onUploadImageProgess(QString targetId,QString localId,int progress);
    void onGetGroupMemberListReslut(int code, QString id, MemberList list);
    void onGroupMemberListChanged(QString operType,QString GroupId,MemberList memberlist);
    void onAccountInfoChanged(Contact user);
    void onAnthAvatarChanged(QString avatar);
    void onContactInfoChanged(int oper,Contact user);
    void onDownloadImage(QString targetId,QString localId,QString url,QString enkey);
    //会话列表头像更新
    void onDownloadMainImageResult(QString main_url,QString localpath);
    void onChatAvatarChanged(QString id,QString avatar);
    //监听离线消息通知
    void onChatOfflineMsgNotice(IMOfflineMsgList msgList);
    //监听新消息通知
    void onChatMessageNotice(Msg msg);
    //发送消息返回
    void onChatSendMessageResult(bool code,QString sendTime,QString msgId);
    //获取消息结果返回
    void onChatGetMessagesResult(bool code,QString sessionId,MsgList msgList);
    //移除会话结果返回
    void onChatRemoveChatResult(bool code);
    //移除消息结果返回
    void onChatDeleteMessagesResult(int code);

    //上传头像返回
    void onChatUploadAvatar(QString orgijson, QString thumbjson, int code);
    //上传文件返回
    void onChatUploadFile(QString tagetid, QString jasoninfo, int code);
    //文件进度
    void onChatFileProgress(int extra_req, int process, QString info,QString localId,QString targetId);

    //下载文件返回
    void onChatDownloadFile(int code, QString localpath, QString tagetid);
    //上传图片返回
    void onChatupLoadImage(QString tagetid, QString orgijson, QString thumbjson, int code);
    //下载图片返回
    void onChatDownloadImage(int code, QString localpath, QString tagetid);
    void onDownloadHistoryImage(int code, QString localpath, QString targetid, QString localid);
    void onTransMessageFinishBack(int code,QString info);
    void onUploadFileBackUrl(QString targetId,QString localId,QString fileUrl,QString enkey);
    void onUploadImgeBackUrl(QString targetId,QString localId,QString thumbUrl,QString mainUrl,QString enkey);
    //获取文件列表返回
    void onChatGetFileList(int code, FileInfoList files);
    void onGetUserInfo(int code, Contact contact);
    void onReqestUserInfo(QString userId);
    void onGroupInfoChanged(QString type,Group gp);
private:
    void initConnect();
private:
    linkdoodui_Workspace* m_pUiManager;
    LinkDoodClient *m_pClient;
    QList<QString>  mSelcetSendImagesList;
    QList<QString>  mSelcetSendFilesList;
    QString mActId;
    QString mActName;
    QString mActAvatar;
    QString m_sTargetid;

    QString mCurentChatId,mCurentChatType,mCurentChatName;
    //缓存聊天列表
    QMap<QString,CDoodChatManagerModel*> mMsgListModel;
    CDoodChatManagerModel*               mChatModel;
    QMap<QString, QString> mFileFormat;

    //图片缩放
    void scaledImage(QString sourceImagePath, float scaledWidth, float scaledHeight, QString &outImagePath,bool isRotate=false);
    void setFileFormat();
    void initModelConnects(CDoodChatManagerModel* model);
};

#endif // CDOODCHATMANAGER_H
