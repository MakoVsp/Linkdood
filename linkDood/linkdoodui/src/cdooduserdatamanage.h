#ifndef CDDODUSERDATAITEM_H
#define CDDODUSERDATAITEM_H
#include <QObject>
class CDoodUserDataManage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString gender READ gender WRITE setGender NOTIFY genderChanged)
    Q_PROPERTY(QString avatar READ avatar WRITE setAvatar NOTIFY avatarChanged)
    Q_PROPERTY(QString thumbAvatar READ thumbAvatar WRITE setThumbAvatar NOTIFY thumbAvatarChanged)
    Q_PROPERTY(bool isFriend READ isFriend WRITE setIsFriend NOTIFY isFriendChanged)

public:
    explicit CDoodUserDataManage(QObject *parent = 0);

    QString id() const;
    Q_INVOKABLE QString setId(const QString &data);

    QString name() const;
    Q_INVOKABLE QString setName(const QString &data);

    QString gender() const;
    Q_INVOKABLE QString setGender(const QString &data);


    QString avatar() const;
    Q_INVOKABLE QString setAvatar(const QString &data);


    QString thumbAvatar() const;
    Q_INVOKABLE QString setThumbAvatar(const QString &data);

    bool isFriend() const;
    Q_INVOKABLE bool setIsFriend(const bool &data);

signals:
    void idChanged();
    void nameChanged();
    void genderChanged();
    void avatarChanged();
    void thumbAvatarChanged();
    void isFriendChanged();

public slots:

private:
    QString mId;
    QString mName;
    QString mThumbAvatar;
    QString mGender;
    QString mAvatar;
    bool mIsFriend;
};
#endif // CDOODCONTACTITEM_H
