#include "cdoodemojimanager.h"
#include "cdoodemojiitem.h"

#include <QDir>

CDoodEmojiManager::CDoodEmojiManager(LinkDoodClient *client, int type, QObject *parent) :
    CDoodListModel(parent), m_pClient(client), mType(type)
{
    mEmojiExplain["Dynamic_Expression_01"] = BAOBAO_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_02"] = CENGCENG_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_03"] = CHIFAN_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_04"] = DAKU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_05"] = HENG_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_06"] = JIAYOU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_07"] = KOUBI_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_08"] = LIEPI_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_09"] = QINQIN_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_10"] = SHUQIAN_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_11"] = SHUIJIAO_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_12"] = WULIAO_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_13"] = XIEXIE_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_14"] = ZAIJI_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_15"] = ZHUAKUANG_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_16"] = CHOUMEI_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_17"] = DAXIAO_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_18"] = DIANTOU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_19"] = FEIJIALOU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_20"] = GANBEI_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_21"] = JICHENGGOU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_22"] = JIABANLOU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_23"] = KAIHUILA_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_24"] = LAOTIANBAOYOU_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_25"] = QIANDAO_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_26"] = XINGHUI_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_27"] = YALISHANDA_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_28"] = ZAN_DYNAMIC;
    mEmojiExplain["Dynamic_Expression_29"] = GUZHANG_DYNAMIC;

    qRegisterMetaType<CDoodEmojiManager*>();
    if(type == 1)
    {
        loadEmoji(":/res/smilies/dynamic_expression");
    }
    else
    {
        loadEmoji(":/res/smilies/emoji_face/");
        loadEmoji(":/res/smilies/instruct/");
    }
}

void CDoodEmojiManager::onBtnItemClicked(QString index)
{
    emit signalEmojiChanged(mEmojiListMap[index]->path());
}

void CDoodEmojiManager::loadEmoji(QString path)
{
    QDir faceDir;
    faceDir.setPath(path);

    QFileInfoList faceFileInfoList = faceDir.entryInfoList(QDir::Files, QDir::Name);
    QString faceName="";
    QString facePath="";

    qDebug() << Q_FUNC_INFO <<"77777777777:"<< faceFileInfoList.size();
    for (int i = 0; i < faceFileInfoList.size(); i++)
    {
        facePath = "qrc"+faceFileInfoList.at(i).absoluteFilePath();
        faceName = faceFileInfoList.at(i).baseName();

        if (mEmojiListMap.contains(faceName))
        {
            CDoodEmojiItem* item = (CDoodEmojiItem*)mEmojiListMap.value(faceName);
            item->setName(faceName);
            item->setPath(facePath);
            if(mType == 1)
            {
                item->setExplain(mEmojiExplain[faceName]);
            }
        }else{

            CDoodEmojiItem* item = new CDoodEmojiItem(this);
            item->setName(faceName);
            item->setPath(facePath);
            if(mType == 1)
            {
                item->setExplain(mEmojiExplain[faceName]);
            }
            insertItem(itemCount(),item);
            mEmojiListMap[faceName] = item;
        }
        qDebug() << Q_FUNC_INFO << "name" <<faceName <<"path:" <<facePath;
    }
}
