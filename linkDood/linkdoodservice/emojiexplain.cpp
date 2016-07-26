#include "emojiexplain.h"
#include "linkdoodtypedef.h"
#include "common.h"
#include <QDebug>
#include <regex>

using namespace std;

QMap<QString, QString> EmojiExplain::m_EmojiDynamicExplain;
QMap<QString, QString> EmojiExplain::m_EmojiFace;
QMap<QString, QString> EmojiExplain::m_EmojiInstruct;
bool EmojiExplain::isInit = false;
EmojiExplain::EmojiExplain()
{
    init();
}

void EmojiExplain::EmojiParseFrom(string src, string &target)
{
    if(!isInit){
        init();
        isInit = true;
    }
    QString source = QString::fromStdString(src);
    qDebug()<<Q_FUNC_INFO<<"src:"<<source;
    for(auto iter= m_EmojiFace.begin(); iter != m_EmojiFace.end();++iter){
        QString  code = iter.value();
        QString  path = "qrc:/res/smilies/emoji_face/"+iter.key()+".png";
        QString emojiPath = "<img src=\""+path+"\" height=\"36\" width=\"36\""+"/>";
        source.replace(code,emojiPath);
    }

    for(auto iter= m_EmojiInstruct.begin(); iter != m_EmojiInstruct.end();++iter){
        QString  code = iter.key();
        QString  path = "qrc:/res/smilies/instruct/"+iter.value()+".png";
        QString emojiPath = "<img src=\""+path+"\" height=\"36\" width=\"36\""+"/>";
        source.replace(code,emojiPath);
    }
    target = source.toStdString();
    qDebug()<<Q_FUNC_INFO<<"target:"<<source;
}

void EmojiExplain::EmojiParseTo(string src, string &target)
{

    if(!isInit){
        init();
        isInit = true;
    }
    std::string msg = src;
    int len = strlen(EMOJI_IMAGE);
    std::size_t posFirst;
    while((posFirst = msg.find(EMOJI_IMAGE))!= std::string::npos){
        if(std::string::npos != posFirst){
            int nBeg = posFirst+len,nEnd=0;

            std::string tmp = msg.substr(nBeg);
            std::size_t posSec = tmp.find(EMOJI_IMAGE);

            std::string path = msg.substr(nBeg,posSec);
            QString tmpPath= QString::fromStdString(path);
            std::string name= path.substr(path.rfind("/")+1,path.rfind(".")-path.rfind("/")-1);
            if(tmpPath.contains("smilies/emoji_face")){
                name = Common::Hex2Emoji(name);
            }
            if(tmpPath.contains("smilies/instruct")){
                name = m_EmojiInstruct.key(QString::fromStdString(name)).toStdString();
            }
            std::string prev = msg.substr(0,posFirst);
            nEnd=nBeg+posSec+len;
            std::string end = msg.substr(nEnd);
            msg = prev+name+end;
        }
    }
    target = msg;
}

void EmojiExplain::dyEmojiParseFrom(QString src, QString &target, QString &explain)
{
    if(!isInit){
        init();
        isInit = true;
    }
    qDebug()<<Q_FUNC_INFO <<"dyddddd:"<<src;
    src.remove("[");
    src.remove("]");
    src.remove(".gif");

    explain = "["+m_EmojiDynamicExplain[src]+"]";
    target = "qrc:/res/smilies/dynamic_expression/"+src+".gif";
    qDebug()<<Q_FUNC_INFO<<"src:"<<src<<":"<<explain<<":"<<target;
}

void EmojiExplain::dyEmojiParseTo(QString src, QString &target, QString &explain)
{
    if(!isInit){
        init();
        isInit = true;
    }
    QString value = m_EmojiDynamicExplain.value(src,"");
    if(value != ""){
        explain = "["+value+"]";
    }
    target = src+".gif";
        qDebug()<<Q_FUNC_INFO<<"src:"<<src<<":"<<explain<<":"<<target;
}

void EmojiExplain::init()
{
    m_EmojiDynamicExplain["Dynamic_Expression_01"] = BAOBAO_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_02"] = CENGCENG_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_03"] = CHIFAN_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_04"] = DAKU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_05"] = HENG_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_06"] = JIAYOU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_07"] = KOUBI_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_08"] = LIEPI_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_09"] = QINQIN_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_10"] = SHUQIAN_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_11"] = SHUIJIAO_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_12"] = WULIAO_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_13"] = XIEXIE_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_14"] = ZAIJI_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_15"] = ZHUAKUANG_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_16"] = CHOUMEI_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_17"] = DAXIAO_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_18"] = DIANTOU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_19"] = FEIJIALOU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_20"] = GANBEI_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_21"] = JICHENGGOU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_22"] = JIABANLOU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_23"] = KAIHUILA_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_24"] = LAOTIANBAOYOU_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_25"] = QIANDAO_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_26"] = XINGHUI_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_27"] = YALISHANDA_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_28"] = ZAN_DYNAMIC;
    m_EmojiDynamicExplain["Dynamic_Expression_29"] = GUZHANG_DYNAMIC;

    m_EmojiFace["23e283a3"] = "";
    m_EmojiFace["30e283a3"] = "";
    m_EmojiFace["31e283a3"] = "";
    m_EmojiFace["32e283a3"] = "";
    m_EmojiFace["33e283a3"] = "";
    m_EmojiFace["34e283a3"] = "";
    m_EmojiFace["35e283a3"] = "";
    m_EmojiFace["36e283a3"] = "";
    m_EmojiFace["37e283a3"] = "";
    m_EmojiFace["38e283a3"] = "";
    m_EmojiFace["39e283a3"] = "";
    m_EmojiFace["c2a9a9"] = "";
    m_EmojiFace["c2aeae"] = "";
    m_EmojiFace["e284a2"] = "";
    m_EmojiFace["e28696"] = "";
    m_EmojiFace["e28697"] = "";
    m_EmojiFace["e28698"] = "";
    m_EmojiFace["e28699"] = "";
    m_EmojiFace["e28fa9"] = "";
    m_EmojiFace["e28faa"] = "";
    m_EmojiFace["e296b6"] = "";
    m_EmojiFace["e29780"] = "";
    m_EmojiFace["e29880"] = "";
    m_EmojiFace["e29881"] = "";
    m_EmojiFace["e2988e"] = "";
    m_EmojiFace["e29894"] = "";
    m_EmojiFace["e29895"] = "";
    m_EmojiFace["e2989d"] = "";
    m_EmojiFace["e2989defb88f"] = "";
    m_EmojiFace["e298ba"] = "";
    m_EmojiFace["e29988"] = "";
    m_EmojiFace["e29989"] = "";
    m_EmojiFace["e2998a"] = "";
    m_EmojiFace["e2998b"] = "";
    m_EmojiFace["e2998c"] = "";
    m_EmojiFace["e2998d"] = "";
    m_EmojiFace["e2998e"] = "";
    m_EmojiFace["e2998f"] = "";
    m_EmojiFace["e29990"] = "";
    m_EmojiFace["e29991"] = "";
    m_EmojiFace["e29992"] = "";
    m_EmojiFace["e29993"] = "";
    m_EmojiFace["e299a0"] = "";
    m_EmojiFace["e299a3"] = "";
    m_EmojiFace["e299a5"] = "";
    m_EmojiFace["e299a6"] = "";
    m_EmojiFace["e299a8"] = "";
    m_EmojiFace["e299bf"] = "";
    m_EmojiFace["e29aa0"] = "";
    m_EmojiFace["e29aa1"] = "";
    m_EmojiFace["e29abd"] = "";
    m_EmojiFace["e29abe"] = "";
    m_EmojiFace["e29b84"] = "";
    m_EmojiFace["e29b8e"] = "";
    m_EmojiFace["e29baa"] = "";
    m_EmojiFace["e29bb2"] = "";
    m_EmojiFace["e29bb3"] = "";
    m_EmojiFace["e29bb5"] = "";
    m_EmojiFace["e29bba"] = "";
    m_EmojiFace["e29bbd"] = "";
    m_EmojiFace["e29c82"] = "";
    m_EmojiFace["e29c88"] = "";
    m_EmojiFace["e29c8a"] = "";
    m_EmojiFace["e29c8b"] = "";
    m_EmojiFace["e29c8c"] = "";
    m_EmojiFace["e29ca8"] = "";
    m_EmojiFace["e29cb3"] = "";
    m_EmojiFace["e29cb4"] = "";
    m_EmojiFace["e29d8c"] = "";
    m_EmojiFace["e29d94"] = "";
    m_EmojiFace["e29d95"] = "";
    m_EmojiFace["e29da4"] = "";
    m_EmojiFace["e29ea1"] = "";
    m_EmojiFace["e29ebf"] = "";
    m_EmojiFace["e2ac85"] = "";
    m_EmojiFace["e2ac86"] = "";
    m_EmojiFace["e2ac87"] = "";
    m_EmojiFace["e2ad95"] = "";
    m_EmojiFace["e380bd"] = "";
    m_EmojiFace["e38a97"] = "";
    m_EmojiFace["e3ba99"] = "";
    m_EmojiFace["ee8081"] = "";
    m_EmojiFace["ee8082"] = "";
    m_EmojiFace["ee8083"] = "";
    m_EmojiFace["ee8084"] = "";
    m_EmojiFace["ee8085"] = "";
    m_EmojiFace["ee8087"] = "";
    m_EmojiFace["ee8088"] = "";
    m_EmojiFace["ee8089"] = "";
    m_EmojiFace["ee808a"] = "";
    m_EmojiFace["ee808b"] = "";
    m_EmojiFace["ee808c"] = "";
    m_EmojiFace["ee808d"] = "";
    m_EmojiFace["ee808e"] = "";
    m_EmojiFace["ee808f"] = "";
    m_EmojiFace["ee8090"] = "";
    m_EmojiFace["ee8091"] = "";
    m_EmojiFace["ee8092"] = "";
    m_EmojiFace["ee8093"] = "";
    m_EmojiFace["ee8094"] = "";
    m_EmojiFace["ee8095"] = "";
    m_EmojiFace["ee8096"] = "";
    m_EmojiFace["ee8097"] = "";
    m_EmojiFace["ee8098"] = "";
    m_EmojiFace["ee8099"] = "";
    m_EmojiFace["ee809a"] = "";
    m_EmojiFace["ee809b"] = "";
    m_EmojiFace["ee809c"] = "";
    m_EmojiFace["ee809d"] = "";
    m_EmojiFace["ee809e"] = "";
    m_EmojiFace["ee809f"] = "";
    m_EmojiFace["ee80a2"] = "";
    m_EmojiFace["ee80a3"] = "";
    m_EmojiFace["ee80a4"] = "";
    m_EmojiFace["ee80a5"] = "";
    m_EmojiFace["ee80a6"] = "";
    m_EmojiFace["ee80a7"] = "";
    m_EmojiFace["ee80a8"] = "";
    m_EmojiFace["ee80a9"] = "";
    m_EmojiFace["ee80aa"] = "";
    m_EmojiFace["ee80ab"] = "";
    m_EmojiFace["ee80ac"] = "";
    m_EmojiFace["ee80ad"] = "";
    m_EmojiFace["ee80ae"] = "";
    m_EmojiFace["ee80af"] = "";
    m_EmojiFace["ee80b0"] = "";
    m_EmojiFace["ee80b1"] = "";
    m_EmojiFace["ee80b2"] = "";
    m_EmojiFace["ee80b3"] = "";
    m_EmojiFace["ee80b4"] = "";
    m_EmojiFace["ee80b5"] = "";
    m_EmojiFace["ee80b6"] = "";
    m_EmojiFace["ee80b7"] = "";
    m_EmojiFace["ee80b8"] = "";
    m_EmojiFace["ee80b9"] = "";
    m_EmojiFace["ee80ba"] = "";
    m_EmojiFace["ee80bb"] = "";
    m_EmojiFace["ee80bc"] = "";
    m_EmojiFace["ee80bd"] = "";
    m_EmojiFace["ee80be"] = "";
    m_EmojiFace["ee80bf"] = "";
    m_EmojiFace["ee8180"] = "";
    m_EmojiFace["ee8181"] = "";
    m_EmojiFace["ee8182"] = "";
    m_EmojiFace["ee8183"] = "";
    m_EmojiFace["ee8184"] = "";
    m_EmojiFace["ee8185"] = "";
    m_EmojiFace["ee8186"] = "";
    m_EmojiFace["ee8187"] = "";
    m_EmojiFace["ee8188"] = "";
    m_EmojiFace["ee8189"] = "";
    m_EmojiFace["ee818a"] = "";
    m_EmojiFace["ee818b"] = "";
    m_EmojiFace["ee818c"] = "";
    m_EmojiFace["ee818d"] = "";
    m_EmojiFace["ee818e"] = "";
    m_EmojiFace["ee818f"] = "";
    m_EmojiFace["ee8190"] = "";
    m_EmojiFace["ee8191"] = "";
    m_EmojiFace["ee8192"] = "";
    m_EmojiFace["ee8193"] = "";
    m_EmojiFace["ee8194"] = "";
    m_EmojiFace["ee8195"] = "";
    m_EmojiFace["ee8196"] = "";
    m_EmojiFace["ee8197"] = "";
    m_EmojiFace["ee8198"] = "";
    m_EmojiFace["ee8199"] = "";
    m_EmojiFace["ee819a"] = "";
    m_EmojiFace["ee8481"] = "";
    m_EmojiFace["ee8482"] = "";
    m_EmojiFace["ee8483"] = "";
    m_EmojiFace["ee8484"] = "";
    m_EmojiFace["ee8485"] = "";
    m_EmojiFace["ee8486"] = "";
    m_EmojiFace["ee8487"] = "";
    m_EmojiFace["ee8488"] = "";
    m_EmojiFace["ee8489"] = "";
    m_EmojiFace["ee848a"] = "";
    m_EmojiFace["ee848b"] = "";
    m_EmojiFace["ee848c"] = "";
    m_EmojiFace["ee848d"] = "";
    m_EmojiFace["ee848e"] = "";
    m_EmojiFace["ee848f"] = "";
    m_EmojiFace["ee8490"] = "";
    m_EmojiFace["ee8491"] = "";
    m_EmojiFace["ee8492"] = "";
    m_EmojiFace["ee8493"] = "";
    m_EmojiFace["ee8494"] = "";
    m_EmojiFace["ee8495"] = "";
    m_EmojiFace["ee8496"] = "";
    m_EmojiFace["ee8497"] = "";
    m_EmojiFace["ee8498"] = "";
    m_EmojiFace["ee8499"] = "";
    m_EmojiFace["ee849a"] = "";
    m_EmojiFace["ee849b"] = "";
    m_EmojiFace["ee849c"] = "";
    m_EmojiFace["ee849d"] = "";
    m_EmojiFace["ee849e"] = "";
    m_EmojiFace["ee849f"] = "";
    m_EmojiFace["ee84a0"] = "";
    m_EmojiFace["ee84a1"] = "";
    m_EmojiFace["ee84a2"] = "";
    m_EmojiFace["ee84a3"] = "";
    m_EmojiFace["ee84a4"] = "";
    m_EmojiFace["ee84a5"] = "";
    m_EmojiFace["ee84a6"] = "";
    m_EmojiFace["ee84a7"] = "";
    m_EmojiFace["ee84a8"] = "";
    m_EmojiFace["ee84a9"] = "";
    m_EmojiFace["ee84aa"] = "";
    m_EmojiFace["ee84ab"] = "";
    m_EmojiFace["ee84ac"] = "";
    m_EmojiFace["ee84ad"] = "";
    m_EmojiFace["ee84ae"] = "";
    m_EmojiFace["ee84af"] = "";
    m_EmojiFace["ee84b0"] = "";
    m_EmojiFace["ee84b1"] = "";
    m_EmojiFace["ee84b2"] = "";
    m_EmojiFace["ee84b3"] = "";
    m_EmojiFace["ee84b4"] = "";
    m_EmojiFace["ee84b5"] = "";
    m_EmojiFace["ee84b6"] = "";
    m_EmojiFace["ee84b7"] = "";
    m_EmojiFace["ee84b8"] = "";
    m_EmojiFace["ee84b9"] = "";
    m_EmojiFace["ee84ba"] = "";
    m_EmojiFace["ee84bb"] = "";
    m_EmojiFace["ee84bc"] = "";
    m_EmojiFace["ee84bd"] = "";
    m_EmojiFace["ee84be"] = "";
    m_EmojiFace["ee84bf"] = "";
    m_EmojiFace["ee8580"] = "";
    m_EmojiFace["ee8581"] = "";
    m_EmojiFace["ee8582"] = "";
    m_EmojiFace["ee8583"] = "";
    m_EmojiFace["ee8584"] = "";
    m_EmojiFace["ee8585"] = "";
    m_EmojiFace["ee8586"] = "";
    m_EmojiFace["ee8587"] = "";
    m_EmojiFace["ee8588"] = "";
    m_EmojiFace["ee8589"] = "";
    m_EmojiFace["ee858a"] = "";
    m_EmojiFace["ee858b"] = "";
    m_EmojiFace["ee858c"] = "";
    m_EmojiFace["ee858d"] = "";
    m_EmojiFace["ee858e"] = "";
    m_EmojiFace["ee858f"] = "";
    m_EmojiFace["ee8590"] = "";
    m_EmojiFace["ee8591"] = "";
    m_EmojiFace["ee8592"] = "";
    m_EmojiFace["ee8593"] = "";
    m_EmojiFace["ee8594"] = "";
    m_EmojiFace["ee8595"] = "";
    m_EmojiFace["ee8596"] = "";
    m_EmojiFace["ee8597"] = "";
    m_EmojiFace["ee8598"] = "";
    m_EmojiFace["ee8599"] = "";
    m_EmojiFace["ee859a"] = "";
    m_EmojiFace["ee8881"] = "";
    m_EmojiFace["ee8882"] = "";
    m_EmojiFace["ee8883"] = "";
    m_EmojiFace["ee8884"] = "";
    m_EmojiFace["ee8885"] = "";
    m_EmojiFace["ee8886"] = "";
    m_EmojiFace["ee8887"] = "";
    m_EmojiFace["ee8888"] = "";
    m_EmojiFace["ee8889"] = "";
    m_EmojiFace["ee888a"] = "";
    m_EmojiFace["ee888b"] = "";
    m_EmojiFace["ee888c"] = "";
    m_EmojiFace["ee888d"] = "";
    m_EmojiFace["ee888e"] = "";
    m_EmojiFace["ee888f"] = "";
    m_EmojiFace["ee8890"] = "";
    m_EmojiFace["ee8891"] = "";
    m_EmojiFace["ee8892"] = "";
    m_EmojiFace["ee8893"] = "";
    m_EmojiFace["ee8894"] = "";
    m_EmojiFace["ee8895"] = "";
    m_EmojiFace["ee8896"] = "";
    m_EmojiFace["ee8897"] = "";
    m_EmojiFace["ee8898"] = "";
    m_EmojiFace["ee8899"] = "";
    m_EmojiFace["ee889a"] = "";
    m_EmojiFace["ee889b"] = "";
    m_EmojiFace["ee889c"] = "";
    m_EmojiFace["ee889d"] = "";
    m_EmojiFace["ee889e"] = "";
    m_EmojiFace["ee889f"] = "";
    m_EmojiFace["ee88a0"] = "";
    m_EmojiFace["ee88a1"] = "";
    m_EmojiFace["ee88a2"] = "";
    m_EmojiFace["ee88a3"] = "";
    m_EmojiFace["ee88a4"] = "";
    m_EmojiFace["ee88a5"] = "";
    m_EmojiFace["ee88a6"] = "";
    m_EmojiFace["ee88a7"] = "";
    m_EmojiFace["ee88a8"] = "";
    m_EmojiFace["ee88a9"] = "";
    m_EmojiFace["ee88aa"] = "";
    m_EmojiFace["ee88ab"] = "";
    m_EmojiFace["ee88ac"] = "";
    m_EmojiFace["ee88ad"] = "";
    m_EmojiFace["ee88ae"] = "";
    m_EmojiFace["ee88af"] = "";
    m_EmojiFace["ee88b0"] = "";
    m_EmojiFace["ee88b1"] = "";
    m_EmojiFace["ee88b2"] = "";
    m_EmojiFace["ee88b3"] = "";
    m_EmojiFace["ee88b4"] = "";
    m_EmojiFace["ee88b5"] = "";
    m_EmojiFace["ee88b6"] = "";
    m_EmojiFace["ee88b7"] = "";
    m_EmojiFace["ee88b8"] = "";
    m_EmojiFace["ee88b9"] = "";
    m_EmojiFace["ee88ba"] = "";
    m_EmojiFace["ee88bb"] = "";
    m_EmojiFace["ee88bc"] = "";
    m_EmojiFace["ee88bd"] = "";
    m_EmojiFace["ee88be"] = "";
    m_EmojiFace["ee88bf"] = "";
    m_EmojiFace["ee8980"] = "";
    m_EmojiFace["ee8981"] = "";
    m_EmojiFace["ee8982"] = "";
    m_EmojiFace["ee8983"] = "";
    m_EmojiFace["ee8984"] = "";
    m_EmojiFace["ee8985"] = "";
    m_EmojiFace["ee8986"] = "";
    m_EmojiFace["ee8987"] = "";
    m_EmojiFace["ee8988"] = "";
    m_EmojiFace["ee8989"] = "";
    m_EmojiFace["ee898a"] = "";
    m_EmojiFace["ee898b"] = "";
    m_EmojiFace["ee898c"] = "";
    m_EmojiFace["ee898d"] = "";
    m_EmojiFace["ee898e"] = "";
    m_EmojiFace["ee898f"] = "";
    m_EmojiFace["ee8990"] = "";
    m_EmojiFace["ee8991"] = "";
    m_EmojiFace["ee8992"] = "";
    m_EmojiFace["ee8993"] = "";
    m_EmojiFace["ee8c81"] = "";
    m_EmojiFace["ee8c82"] = "";
    m_EmojiFace["ee8c83"] = "";
    m_EmojiFace["ee8c84"] = "";
    m_EmojiFace["ee8c85"] = "";
    m_EmojiFace["ee8c86"] = "";
    m_EmojiFace["ee8c87"] = "";
    m_EmojiFace["ee8c88"] = "";
    m_EmojiFace["ee8c89"] = "";
    m_EmojiFace["ee8c8a"] = "";
    m_EmojiFace["ee8c8b"] = "";
    m_EmojiFace["ee8c8c"] = "";
    m_EmojiFace["ee8c8d"] = "";
    m_EmojiFace["ee8c8e"] = "";
    m_EmojiFace["ee8c8f"] = "";
    m_EmojiFace["ee8c90"] = "";
    m_EmojiFace["ee8c91"] = "";
    m_EmojiFace["ee8c92"] = "";
    m_EmojiFace["ee8c93"] = "";
    m_EmojiFace["ee8c94"] = "";
    m_EmojiFace["ee8c95"] = "";
    m_EmojiFace["ee8c96"] = "";
    m_EmojiFace["ee8c97"] = "";
    m_EmojiFace["ee8c98"] = "";
    m_EmojiFace["ee8c99"] = "";
    m_EmojiFace["ee8c9a"] = "";
    m_EmojiFace["ee8c9b"] = "";
    m_EmojiFace["ee8c9c"] = "";
    m_EmojiFace["ee8c9d"] = "";
    m_EmojiFace["ee8c9e"] = "";
    m_EmojiFace["ee8c9f"] = "";
    m_EmojiFace["ee8ca0"] = "";
    m_EmojiFace["ee8ca1"] = "";
    m_EmojiFace["ee8ca2"] = "";
    m_EmojiFace["ee8ca3"] = "";
    m_EmojiFace["ee8ca4"] = "";
    m_EmojiFace["ee8ca5"] = "";
    m_EmojiFace["ee8ca6"] = "";
    m_EmojiFace["ee8ca7"] = "";
    m_EmojiFace["ee8ca8"] = "";
    m_EmojiFace["ee8ca9"] = "";
    m_EmojiFace["ee8caa"] = "";
    m_EmojiFace["ee8cab"] = "";
    m_EmojiFace["ee8cac"] = "";
    m_EmojiFace["ee8cad"] = "";
    m_EmojiFace["ee8cae"] = "";
    m_EmojiFace["ee8cb0"] = "";
    m_EmojiFace["ee8cb1"] = "";
    m_EmojiFace["ee8cb2"] = "";
    m_EmojiFace["ee8cb3"] = "";
    m_EmojiFace["ee8cb4"] = "";
    m_EmojiFace["ee8cb5"] = "";
    m_EmojiFace["ee8cb6"] = "";
    m_EmojiFace["ee8cb7"] = "";
    m_EmojiFace["ee8cb8"] = "";
    m_EmojiFace["ee8cb9"] = "";
    m_EmojiFace["ee8cba"] = "";
    m_EmojiFace["ee8cbb"] = "";
    m_EmojiFace["ee8cbc"] = "";
    m_EmojiFace["ee8cbd"] = "";
    m_EmojiFace["ee8cbe"] = "";
    m_EmojiFace["ee8cbf"] = "";
    m_EmojiFace["ee8d80"] = "";
    m_EmojiFace["ee8d81"] = "";
    m_EmojiFace["ee8d82"] = "";
    m_EmojiFace["ee8d83"] = "";
    m_EmojiFace["ee8d84"] = "";
    m_EmojiFace["ee8d85"] = "";
    m_EmojiFace["ee8d86"] = "";
    m_EmojiFace["ee8d87"] = "";
    m_EmojiFace["ee8d88"] = "";
    m_EmojiFace["ee8d89"] = "";
    m_EmojiFace["ee8d8a"] = "";
    m_EmojiFace["ee8d8b"] = "";
    m_EmojiFace["ee8d8c"] = "";
    m_EmojiFace["ee8d8d"] = "";
    m_EmojiFace["ee9081"] = "";
    m_EmojiFace["ee9082"] = "";
    m_EmojiFace["ee9083"] = "";
    m_EmojiFace["ee9084"] = "";
    m_EmojiFace["ee9085"] = "";
    m_EmojiFace["ee9086"] = "";
    m_EmojiFace["ee9087"] = "";
    m_EmojiFace["ee9088"] = "";
    m_EmojiFace["ee9089"] = "";
    m_EmojiFace["ee908a"] = "";
    m_EmojiFace["ee908b"] = "";
    m_EmojiFace["ee908c"] = "";
    m_EmojiFace["ee908d"] = "";
    m_EmojiFace["ee908e"] = "";
    m_EmojiFace["ee908f"] = "";
    m_EmojiFace["ee9090"] = "";
    m_EmojiFace["ee9091"] = "";
    m_EmojiFace["ee9092"] = "";
    m_EmojiFace["ee9093"] = "";
    m_EmojiFace["ee9094"] = "";
    m_EmojiFace["ee9095"] = "";
    m_EmojiFace["ee9096"] = "";
    m_EmojiFace["ee9097"] = "";
    m_EmojiFace["ee9098"] = "";
    m_EmojiFace["ee9099"] = "";
    m_EmojiFace["ee909a"] = "";
    m_EmojiFace["ee909b"] = "";
    m_EmojiFace["ee909c"] = "";
    m_EmojiFace["ee909d"] = "";
    m_EmojiFace["ee909e"] = "";
    m_EmojiFace["ee909f"] = "";
    m_EmojiFace["ee90a0"] = "";
    m_EmojiFace["ee90a1"] = "";
    m_EmojiFace["ee90a2"] = "";
    m_EmojiFace["ee90a3"] = "";
    m_EmojiFace["ee90a4"] = "";
    m_EmojiFace["ee90a5"] = "";
    m_EmojiFace["ee90a6"] = "";
    m_EmojiFace["ee90a7"] = "";
    m_EmojiFace["ee90a8"] = "";
    m_EmojiFace["ee90a9"] = "";
    m_EmojiFace["ee90aa"] = "";
    m_EmojiFace["ee90ab"] = "";
    m_EmojiFace["ee90ac"] = "";
    m_EmojiFace["ee90ad"] = "";
    m_EmojiFace["ee90ae"] = "";
    m_EmojiFace["ee90af"] = "";
    m_EmojiFace["ee90b0"] = "";
    m_EmojiFace["ee90b1"] = "";
    m_EmojiFace["ee90b2"] = "";
    m_EmojiFace["ee90b3"] = "";
    m_EmojiFace["ee90b4"] = "";
    m_EmojiFace["ee90b5"] = "";
    m_EmojiFace["ee90b6"] = "";
    m_EmojiFace["ee90b7"] = "";
    m_EmojiFace["ee90b8"] = "";
    m_EmojiFace["ee90b9"] = "";
    m_EmojiFace["ee90ba"] = "";
    m_EmojiFace["ee90bb"] = "";
    m_EmojiFace["ee90bc"] = "";
    m_EmojiFace["ee90bd"] = "";
    m_EmojiFace["ee90be"] = "";
    m_EmojiFace["ee90bf"] = "";
    m_EmojiFace["ee9180"] = "";
    m_EmojiFace["ee9181"] = "";
    m_EmojiFace["ee9182"] = "";
    m_EmojiFace["ee9183"] = "";
    m_EmojiFace["ee9184"] = "";
    m_EmojiFace["ee9185"] = "";
    m_EmojiFace["ee9186"] = "";
    m_EmojiFace["ee9187"] = "";
    m_EmojiFace["ee9188"] = "";
    m_EmojiFace["ee9189"] = "";
    m_EmojiFace["ee918a"] = "";
    m_EmojiFace["ee918b"] = "";
    m_EmojiFace["ee918c"] = "";
    m_EmojiFace["ee9481"] = "";
    m_EmojiFace["ee9482"] = "";
    m_EmojiFace["ee9483"] = "";
    m_EmojiFace["ee9484"] = "";
    m_EmojiFace["ee9485"] = "";
    m_EmojiFace["ee9486"] = "";
    m_EmojiFace["ee9487"] = "";
    m_EmojiFace["ee9488"] = "";
    m_EmojiFace["ee9489"] = "";
    m_EmojiFace["ee948a"] = "";
    m_EmojiFace["ee948b"] = "";
    m_EmojiFace["ee948c"] = "";
    m_EmojiFace["ee948d"] = "";
    m_EmojiFace["ee948e"] = "";
    m_EmojiFace["ee948f"] = "";
    m_EmojiFace["ee9491"] = "";
    m_EmojiFace["ee9492"] = "";
    m_EmojiFace["ee9493"] = "";
    m_EmojiFace["ee9494"] = "";
    m_EmojiFace["ee9495"] = "";
    m_EmojiFace["ee9496"] = "";
    m_EmojiFace["ee9497"] = "";
    m_EmojiFace["ee9498"] = "";
    m_EmojiFace["ee9499"] = "";
    m_EmojiFace["ee949a"] = "";
    m_EmojiFace["ee949b"] = "";
    m_EmojiFace["ee949c"] = "";
    m_EmojiFace["ee949d"] = "";
    m_EmojiFace["ee949e"] = "";
    m_EmojiFace["ee949f"] = "";
    m_EmojiFace["ee94a0"] = "";
    m_EmojiFace["ee94a1"] = "";
    m_EmojiFace["ee94a2"] = "";
    m_EmojiFace["ee94a3"] = "";
    m_EmojiFace["ee94a4"] = "";
    m_EmojiFace["ee94a5"] = "";
    m_EmojiFace["ee94a6"] = "";
    m_EmojiFace["ee94a7"] = "";
    m_EmojiFace["ee94a8"] = "";
    m_EmojiFace["ee94a9"] = "";
    m_EmojiFace["ee94aa"] = "";
    m_EmojiFace["ee94ab"] = "";
    m_EmojiFace["ee94ac"] = "";
    m_EmojiFace["ee94ad"] = "";
    m_EmojiFace["ee94ae"] = "";
    m_EmojiFace["ee94af"] = "";
    m_EmojiFace["ee94b0"] = "";
    m_EmojiFace["ee94b1"] = "";
    m_EmojiFace["ee94b2"] = "";
    m_EmojiFace["ee94b3"] = "";
    m_EmojiFace["ee94b4"] = "";
    m_EmojiFace["ee94b5"] = "";
    m_EmojiFace["ee94b6"] = "";
    m_EmojiFace["ee94b7"] = "";
    m_EmojiFace["f09f8084"] = "";
    m_EmojiFace["f09f85b0"] = "";
    m_EmojiFace["f09f85b1"] = "";
    m_EmojiFace["f09f85be"] = "";
    m_EmojiFace["f09f85bf"] = "";
    m_EmojiFace["f09f868e"] = "";
    m_EmojiFace["f09f8692"] = "";
    m_EmojiFace["f09f8694"] = "";
    m_EmojiFace["f09f8695"] = "";
    m_EmojiFace["f09f8697"] = "";
    m_EmojiFace["f09f8699"] = "";
    m_EmojiFace["f09f869a"] = "";
    m_EmojiFace["f09f87a8f09f87b3"] = "";
    m_EmojiFace["f09f87a9f09f87aa"] = "";
    m_EmojiFace["f09f87aaf09f87b8"] = "";
    m_EmojiFace["f09f87abf09f87b7"] = "";
    m_EmojiFace["f09f87acf09f87a7"] = "";
    m_EmojiFace["f09f87aef09f87b9"] = "";
    m_EmojiFace["f09f87aff09f87b5"] = "";
    m_EmojiFace["f09f87b0f09f87b7"] = "";
    m_EmojiFace["f09f87b7f09f87ba"] = "";
    m_EmojiFace["f09f87baf09f87b8"] = "";
    m_EmojiFace["f09f8881"] = "";
    m_EmojiFace["f09f8882"] = "";
    m_EmojiFace["f09f889a"] = "";
    m_EmojiFace["f09f88af"] = "";
    m_EmojiFace["f09f88b3"] = "";
    m_EmojiFace["f09f88b5"] = "";
    m_EmojiFace["f09f88b6"] = "";
    m_EmojiFace["f09f88b7"] = "";
    m_EmojiFace["f09f88b8"] = "";
    m_EmojiFace["f09f88b9"] = "";
    m_EmojiFace["f09f88ba"] = "";
    m_EmojiFace["f09f8990"] = "";
    m_EmojiFace["f09f8c80"] = "";
    m_EmojiFace["f09f8c82"] = "";
    m_EmojiFace["f09f8c83"] = "";
    m_EmojiFace["f09f8c84"] = "";
    m_EmojiFace["f09f8c85"] = "";
    m_EmojiFace["f09f8c86"] = "";
    m_EmojiFace["f09f8c87"] = "";
    m_EmojiFace["f09f8c88"] = "";
    m_EmojiFace["f09f8c8a"] = "";
    m_EmojiFace["f09f8c99"] = "";
    m_EmojiFace["f09f8c9f"] = "";
    m_EmojiFace["f09f8cb4"] = "";
    m_EmojiFace["f09f8cb5"] = "";
    m_EmojiFace["f09f8cb7"] = "";
    m_EmojiFace["f09f8cb9"] = "";
    m_EmojiFace["f09f8cba"] = "";
    m_EmojiFace["f09f8cbb"] = "";
    m_EmojiFace["f09f8cbe"] = "";
    m_EmojiFace["f09f8d80"] = "";
    m_EmojiFace["f09f8d81"] = "";
    m_EmojiFace["f09f8d82"] = "";
    m_EmojiFace["f09f8d83"] = "";
    m_EmojiFace["f09f8d85"] = "";
    m_EmojiFace["f09f8d86"] = "";
    m_EmojiFace["f09f8d89"] = "";
    m_EmojiFace["f09f8d8a"] = "";
    m_EmojiFace["f09f8d8e"] = "";
    m_EmojiFace["f09f8d93"] = "";
    m_EmojiFace["f09f8d94"] = "";
    m_EmojiFace["f09f8d98"] = "";
    m_EmojiFace["f09f8d99"] = "";
    m_EmojiFace["f09f8d9a"] = "";
    m_EmojiFace["f09f8d9b"] = "";
    m_EmojiFace["f09f8d9c"] = "";
    m_EmojiFace["f09f8d9d"] = "";
    m_EmojiFace["f09f8d9e"] = "";
    m_EmojiFace["f09f8d9f"] = "";
    m_EmojiFace["f09f8da1"] = "";
    m_EmojiFace["f09f8da2"] = "";
    m_EmojiFace["f09f8da3"] = "";
    m_EmojiFace["f09f8da6"] = "";
    m_EmojiFace["f09f8da7"] = "";
    m_EmojiFace["f09f8db0"] = "";
    m_EmojiFace["f09f8db1"] = "";
    m_EmojiFace["f09f8db2"] = "";
    m_EmojiFace["f09f8db3"] = "";
    m_EmojiFace["f09f8db4"] = "";
    m_EmojiFace["f09f8db5"] = "";
    m_EmojiFace["f09f8db6"] = "";
    m_EmojiFace["f09f8db8"] = "";
    m_EmojiFace["f09f8dba"] = "";
    m_EmojiFace["f09f8dbb"] = "";
    m_EmojiFace["f09f8e80"] = "";
    m_EmojiFace["f09f8e81"] = "";
    m_EmojiFace["f09f8e82"] = "";
    m_EmojiFace["f09f8e83"] = "";
    m_EmojiFace["f09f8e84"] = "";
    m_EmojiFace["f09f8e85"] = "";
    m_EmojiFace["f09f8e86"] = "";
    m_EmojiFace["f09f8e87"] = "";
    m_EmojiFace["f09f8e88"] = "";
    m_EmojiFace["f09f8e89"] = "";
    m_EmojiFace["f09f8e8c"] = "";
    m_EmojiFace["f09f8e8d"] = "";
    m_EmojiFace["f09f8e8e"] = "";
    m_EmojiFace["f09f8e8f"] = "";
    m_EmojiFace["f09f8e90"] = "";
    m_EmojiFace["f09f8e91"] = "";
    m_EmojiFace["f09f8e92"] = "";
    m_EmojiFace["f09f8e93"] = "";
    m_EmojiFace["f09f8ea1"] = "";
    m_EmojiFace["f09f8ea2"] = "";
    m_EmojiFace["f09f8ea4"] = "";
    m_EmojiFace["f09f8ea5"] = "";
    m_EmojiFace["f09f8ea6"] = "";
    m_EmojiFace["f09f8ea7"] = "";
    m_EmojiFace["f09f8ea8"] = "";
    m_EmojiFace["f09f8ea9"] = "";
    m_EmojiFace["f09f8eab"] = "";
    m_EmojiFace["f09f8eac"] = "";
    m_EmojiFace["f09f8eaf"] = "";
    m_EmojiFace["f09f8eb0"] = "";
    m_EmojiFace["f09f8eb1"] = "";
    m_EmojiFace["f09f8eb5"] = "";
    m_EmojiFace["f09f8eb7"] = "";
    m_EmojiFace["f09f8eb8"] = "";
    m_EmojiFace["f09f8eb9"] = "";
    m_EmojiFace["f09f8eba"] = "";
    m_EmojiFace["f09f8ebe"] = "";
    m_EmojiFace["f09f8ebf"] = "";
    m_EmojiFace["f09f8f80"] = "";
    m_EmojiFace["f09f8f81"] = "";
    m_EmojiFace["f09f8f83"] = "";
    m_EmojiFace["f09f8f84"] = "";
    m_EmojiFace["f09f8f86"] = "";
    m_EmojiFace["f09f8f88"] = "";
    m_EmojiFace["f09f8f8a"] = "";
    m_EmojiFace["f09f8fa0"] = "";
    m_EmojiFace["f09f8fa2"] = "";
    m_EmojiFace["f09f8fa3"] = "";
    m_EmojiFace["f09f8fa5"] = "";
    m_EmojiFace["f09f8fa6"] = "";
    m_EmojiFace["f09f8fa7"] = "";
    m_EmojiFace["f09f8fa8"] = "";
    m_EmojiFace["f09f8fa9"] = "";
    m_EmojiFace["f09f8faa"] = "";
    m_EmojiFace["f09f8fab"] = "";
    m_EmojiFace["f09f8fac"] = "";
    m_EmojiFace["f09f8fad"] = "";
    m_EmojiFace["f09f8faf"] = "";
    m_EmojiFace["f09f8fb0"] = "";
    m_EmojiFace["f09f908d"] = "";
    m_EmojiFace["f09f908e"] = "";
    m_EmojiFace["f09f9091"] = "";
    m_EmojiFace["f09f9092"] = "";
    m_EmojiFace["f09f9094"] = "";
    m_EmojiFace["f09f9097"] = "";
    m_EmojiFace["f09f9098"] = "";
    m_EmojiFace["f09f9099"] = "";
    m_EmojiFace["f09f909a"] = "";
    m_EmojiFace["f09f909b"] = "";
    m_EmojiFace["f09f909f"] = "";
    m_EmojiFace["f09f90a0"] = "";
    m_EmojiFace["f09f90a4"] = "";
    m_EmojiFace["f09f90a6"] = "";
    m_EmojiFace["f09f90a7"] = "";
    m_EmojiFace["f09f90a8"] = "";
    m_EmojiFace["f09f90ab"] = "";
    m_EmojiFace["f09f90ac"] = "";
    m_EmojiFace["f09f90ad"] = "";
    m_EmojiFace["f09f90ae"] = "";
    m_EmojiFace["f09f90af"] = "";
    m_EmojiFace["f09f90b0"] = "";
    m_EmojiFace["f09f90b1"] = "";
    m_EmojiFace["f09f90b3"] = "";
    m_EmojiFace["f09f90b4"] = "";
    m_EmojiFace["f09f90b5"] = "";
    m_EmojiFace["f09f90b6"] = "";
    m_EmojiFace["f09f90b7"] = "";
    m_EmojiFace["f09f90b8"] = "";
    m_EmojiFace["f09f90b9"] = "";
    m_EmojiFace["f09f90ba"] = "";
    m_EmojiFace["f09f90bb"] = "";
    m_EmojiFace["f09f9180"] = "";
    m_EmojiFace["f09f9182"] = "";
    m_EmojiFace["f09f9183"] = "";
    m_EmojiFace["f09f9184"] = "";
    m_EmojiFace["f09f9186"] = "";
    m_EmojiFace["f09f9187"] = "";
    m_EmojiFace["f09f9188"] = "";
    m_EmojiFace["f09f9189"] = "";
    m_EmojiFace["f09f918a"] = "";
    m_EmojiFace["f09f918b"] = "";
    m_EmojiFace["f09f918c"] = "";
    m_EmojiFace["f09f918d"] = "";
    m_EmojiFace["f09f918e"] = "";
    m_EmojiFace["f09f918f"] = "";
    m_EmojiFace["f09f9190"] = "";
    m_EmojiFace["f09f9191"] = "";
    m_EmojiFace["f09f9192"] = "";
    m_EmojiFace["f09f9194"] = "";
    m_EmojiFace["f09f9195"] = "";
    m_EmojiFace["f09f9197"] = "";
    m_EmojiFace["f09f9198"] = "";
    m_EmojiFace["f09f9199"] = "";
    m_EmojiFace["f09f919c"] = "";
    m_EmojiFace["f09f919f"] = "";
    m_EmojiFace["f09f91a0"] = "";
    m_EmojiFace["f09f91a1"] = "";
    m_EmojiFace["f09f91a2"] = "";
    m_EmojiFace["f09f91a3"] = "";
    m_EmojiFace["f09f91a6"] = "";
    m_EmojiFace["f09f91a7"] = "";
    m_EmojiFace["f09f91a8"] = "";
    m_EmojiFace["f09f91a9"] = "";
    m_EmojiFace["f09f91ab"] = "";
    m_EmojiFace["f09f91ae"] = "";
    m_EmojiFace["f09f91af"] = "";
    m_EmojiFace["f09f91b1"] = "";
    m_EmojiFace["f09f91b2"] = "";
    m_EmojiFace["f09f91b3"] = "";
    m_EmojiFace["f09f91b4"] = "";
    m_EmojiFace["f09f91b5"] = "";
    m_EmojiFace["f09f91b6"] = "";
    m_EmojiFace["f09f91b7"] = "";
    m_EmojiFace["f09f91b8"] = "";
    m_EmojiFace["f09f91bb"] = "";
    m_EmojiFace["f09f91bc"] = "";
    m_EmojiFace["f09f91bd"] = "";
    m_EmojiFace["f09f91be"] = "";
    m_EmojiFace["f09f91bf"] = "";
    m_EmojiFace["f09f9280"] = "";
    m_EmojiFace["f09f9281"] = "";
    m_EmojiFace["f09f9282"] = "";
    m_EmojiFace["f09f9283"] = "";
    m_EmojiFace["f09f9284"] = "";
    m_EmojiFace["f09f9285"] = "";
    m_EmojiFace["f09f9286"] = "";
    m_EmojiFace["f09f9287"] = "";
    m_EmojiFace["f09f9288"] = "";
    m_EmojiFace["f09f9289"] = "";
    m_EmojiFace["f09f928a"] = "";
    m_EmojiFace["f09f928b"] = "";
    m_EmojiFace["f09f928d"] = "";
    m_EmojiFace["f09f928e"] = "";
    m_EmojiFace["f09f928f"] = "";
    m_EmojiFace["f09f9290"] = "";
    m_EmojiFace["f09f9291"] = "";
    m_EmojiFace["f09f9292"] = "";
    m_EmojiFace["f09f9293"] = "";
    m_EmojiFace["f09f9294"] = "";
    m_EmojiFace["f09f9297"] = "";
    m_EmojiFace["f09f9298"] = "";
    m_EmojiFace["f09f9299"] = "";
    m_EmojiFace["f09f929a"] = "";
    m_EmojiFace["f09f929b"] = "";
    m_EmojiFace["f09f929c"] = "";
    m_EmojiFace["f09f929d"] = "";
    m_EmojiFace["f09f929f"] = "";
    m_EmojiFace["f09f92a1"] = "";
    m_EmojiFace["f09f92a2"] = "";
    m_EmojiFace["f09f92a3"] = "";
    m_EmojiFace["f09f92a4"] = "";
    m_EmojiFace["f09f92a6"] = "";
    m_EmojiFace["f09f92a8"] = "";
    m_EmojiFace["f09f92a9"] = "";
    m_EmojiFace["f09f92aa"] = "";
    m_EmojiFace["f09f92b0"] = "";
    m_EmojiFace["f09f92b1"] = "";
    m_EmojiFace["f09f92b9"] = "";
    m_EmojiFace["f09f92ba"] = "";
    m_EmojiFace["f09f92bb"] = "";
    m_EmojiFace["f09f92bc"] = "";
    m_EmojiFace["f09f92bd"] = "";
    m_EmojiFace["f09f92bf"] = "";
    m_EmojiFace["f09f9380"] = "";
    m_EmojiFace["f09f9396"] = "";
    m_EmojiFace["f09f939d"] = "";
    m_EmojiFace["f09f93a0"] = "";
    m_EmojiFace["f09f93a1"] = "";
    m_EmojiFace["f09f93a2"] = "";
    m_EmojiFace["f09f93a3"] = "";
    m_EmojiFace["f09f93a9"] = "";
    m_EmojiFace["f09f93ab"] = "";
    m_EmojiFace["f09f93ae"] = "";
    m_EmojiFace["f09f93b1"] = "";
    m_EmojiFace["f09f93b2"] = "";
    m_EmojiFace["f09f93b3"] = "";
    m_EmojiFace["f09f93b4"] = "";
    m_EmojiFace["f09f93b6"] = "";
    m_EmojiFace["f09f93b7"] = "";
    m_EmojiFace["f09f93ba"] = "";
    m_EmojiFace["f09f93bb"] = "";
    m_EmojiFace["f09f93bc"] = "";
    m_EmojiFace["f09f948a"] = "";
    m_EmojiFace["f09f948d"] = "";
    m_EmojiFace["f09f9491"] = "";
    m_EmojiFace["f09f9492"] = "";
    m_EmojiFace["f09f9493"] = "";
    m_EmojiFace["f09f9494"] = "";
    m_EmojiFace["f09f949d"] = "";
    m_EmojiFace["f09f949e"] = "";
    m_EmojiFace["f09f94a5"] = "";
    m_EmojiFace["f09f94a8"] = "";
    m_EmojiFace["f09f94ab"] = "";
    m_EmojiFace["f09f94af"] = "";
    m_EmojiFace["f09f94b0"] = "";
    m_EmojiFace["f09f94b1"] = "";
    m_EmojiFace["f09f94b2"] = "";
    m_EmojiFace["f09f94b3"] = "";
    m_EmojiFace["f09f94b4"] = "";
    m_EmojiFace["f09f9590"] = "";
    m_EmojiFace["f09f9591"] = "";
    m_EmojiFace["f09f9592"] = "";
    m_EmojiFace["f09f9593"] = "";
    m_EmojiFace["f09f9594"] = "";
    m_EmojiFace["f09f9595"] = "";
    m_EmojiFace["f09f9596"] = "";
    m_EmojiFace["f09f9597"] = "";
    m_EmojiFace["f09f9598"] = "";
    m_EmojiFace["f09f9599"] = "";
    m_EmojiFace["f09f959a"] = "";
    m_EmojiFace["f09f959b"] = "";
    m_EmojiFace["f09f97bb"] = "";
    m_EmojiFace["f09f97bc"] = "";
    m_EmojiFace["f09f97bd"] = "";
    m_EmojiFace["f09f9881"] = "";
    m_EmojiFace["f09f9882"] = "";
    m_EmojiFace["f09f9883"] = "";
    m_EmojiFace["f09f9884"] = "";
    m_EmojiFace["f09f9889"] = "";
    m_EmojiFace["f09f988a"] = "";
    m_EmojiFace["f09f988c"] = "";
    m_EmojiFace["f09f988d"] = "";
    m_EmojiFace["f09f988f"] = "";
    m_EmojiFace["f09f9892"] = "";
    m_EmojiFace["f09f9893"] = "";
    m_EmojiFace["f09f9894"] = "";
    m_EmojiFace["f09f9896"] = "";
    m_EmojiFace["f09f9898"] = "";
    m_EmojiFace["f09f989a"] = "";
    m_EmojiFace["f09f989c"] = "";
    m_EmojiFace["f09f989d"] = "";
    m_EmojiFace["f09f989e"] = "";
    m_EmojiFace["f09f98a0"] = "";
    m_EmojiFace["f09f98a1"] = "";
    m_EmojiFace["f09f98a2"] = "";
    m_EmojiFace["f09f98a3"] = "";
    m_EmojiFace["f09f98a5"] = "";
    m_EmojiFace["f09f98a8"] = "";
    m_EmojiFace["f09f98aa"] = "";
    m_EmojiFace["f09f98ad"] = "";
    m_EmojiFace["f09f98b0"] = "";
    m_EmojiFace["f09f98b1"] = "";
    m_EmojiFace["f09f98b2"] = "";
    m_EmojiFace["f09f98b3"] = "";
    m_EmojiFace["f09f98b7"] = "";
    m_EmojiFace["f09f9985"] = "";
    m_EmojiFace["f09f9986"] = "";
    m_EmojiFace["f09f9987"] = "";
    m_EmojiFace["f09f998c"] = "";
    m_EmojiFace["f09f998f"] = "";
    m_EmojiFace["f09f9a80"] = "";
    m_EmojiFace["f09f9a83"] = "";
    m_EmojiFace["f09f9a84"] = "";
    m_EmojiFace["f09f9a85"] = "";
    m_EmojiFace["f09f9a87"] = "";
    m_EmojiFace["f09f9a89"] = "";
    m_EmojiFace["f09f9a8c"] = "";
    m_EmojiFace["f09f9a8f"] = "";
    m_EmojiFace["f09f9a91"] = "";
    m_EmojiFace["f09f9a92"] = "";
    m_EmojiFace["f09f9a93"] = "";
    m_EmojiFace["f09f9a95"] = "";
    m_EmojiFace["f09f9a97"] = "";
    m_EmojiFace["f09f9a99"] = "";
    m_EmojiFace["f09f9a9a"] = "";
    m_EmojiFace["f09f9aa2"] = "";
    m_EmojiFace["f09f9aa4"] = "";
    m_EmojiFace["f09f9aa5"] = "";
    m_EmojiFace["f09f9aa7"] = "";
    m_EmojiFace["f09f9aac"] = "";
    m_EmojiFace["f09f9aad"] = "";
    m_EmojiFace["f09f9ab2"] = "";
    m_EmojiFace["f09f9ab6"] = "";
    m_EmojiFace["f09f9ab9"] = "";
    m_EmojiFace["f09f9aba"] = "";
    m_EmojiFace["f09f9abb"] = "";
    m_EmojiFace["f09f9abc"] = "";
    m_EmojiFace["f09f9abd"] = "";
    m_EmojiFace["f09f9abe"] = "";
    m_EmojiFace["f09f9b]80"] = "";
    m_EmojiFace["f09f9cb8"] = "";

    m_EmojiInstruct["[微笑]"] = "weixiao";
    m_EmojiInstruct["[色]"] = "se";
    m_EmojiInstruct["[得意]"] = "deyi";
    m_EmojiInstruct["[流泪]"] = "liulei";
    m_EmojiInstruct["[害羞]"] = "haixiu";
    m_EmojiInstruct["[闭嘴]"] = "bizui";
    m_EmojiInstruct["[睡]"] = "shui";
    m_EmojiInstruct["[尴尬]"] = "ganga";
    m_EmojiInstruct["[发怒]"] = "fanu";
    m_EmojiInstruct["[调皮]"] = "tiaopi";
    m_EmojiInstruct["[呲牙]"] = "ciya";
    m_EmojiInstruct["[惊讶]"] = "jingya";
    m_EmojiInstruct["[抓狂]"] = "zhuakuang";
    m_EmojiInstruct["[偷笑]"] = "touxiao";
    m_EmojiInstruct["[白眼]"] = "baiyan";
    m_EmojiInstruct["[傲慢]"] = "aoman";
    m_EmojiInstruct["[流汗]"] = "liuhan";
    m_EmojiInstruct["[疑问]"] = "yiwen";
    m_EmojiInstruct["[嘘]"] = "xu";
    m_EmojiInstruct["[晕]"] = "yun";
    m_EmojiInstruct["[疯了]"] = "fengle";
    m_EmojiInstruct["[敲打]"] = "qiaoda";
    m_EmojiInstruct["[衰]"] = "shuai";
    m_EmojiInstruct["[再见]"] = "zaijian";
    m_EmojiInstruct["[抠鼻]"] = "koubi";
    m_EmojiInstruct["[鼓掌]"] = "guzhang";
    m_EmojiInstruct["[坏笑]"] = "huaixiao";
    m_EmojiInstruct["[鄙视]"] = "bishi";
    m_EmojiInstruct["[委屈]"] = "weiqu";
    m_EmojiInstruct["[阴险]"] = "yinxian";
    m_EmojiInstruct["[亲亲]"] = "qinqin";
    m_EmojiInstruct["[可怜]"] = "kelian";
    m_EmojiInstruct["[左哼哼]"] = "zuohengheng";
    m_EmojiInstruct["[右哼哼]"] = "youhengheng";
    m_EmojiInstruct["[不高兴]"] = "bugaoxing";

    QList<QString>  list = m_EmojiFace.keys();
    for(auto item:list){
        m_EmojiFace[item] = QString::fromStdString(Common::Hex2Emoji(item.toStdString()));
    }
}
