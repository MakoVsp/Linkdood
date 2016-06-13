#pragma once
#include "User.h"
#include <vector>
#include <string>
#include <memory>

namespace service{ class Msg; }

struct UserSetting{
	UserSetting() :isonline(0), issearchbybean(0), issearchbyphone(0), issearchbymail(0),
	isshareupdate(0), isnewmsgtip(0), ismultiservmsgtip(0), ismultiservfrdtip(0), ismultiservpersontip(0){}
	int8 isonline;				//����ʾ������Ϣ 0��ʾ 1����ʾ Ĭ��0
	int8 issearchbybean;		//�����Ų���  0���� 1������ Ĭ��0
	int8 issearchbyphone;		//�ֻ��Ų���  0��ʾ 1����ʾ Ĭ��0
	int8 issearchbymail;		//����Ų��� 0��ʾ 1����ʾ Ĭ��0
	int8 isshareupdate;			//�������   0��ʾ���� 1����ʾ���� Ĭ��0
	int8 isnewmsgtip;			//����Ϣ֪ͨ�Ƿ�����0���� 1������ Ĭ��0
	int8 ismultiservmsgtip;		//���������Ϣ֪ͨ�Ƿ�����0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
	int8 ismultiservfrdtip;		//���������V�����ʼ������ 0��ʼ����ʾ 1ʼ����ʾ Ĭ��
	int8 ismultiservpersontip;	//�������������@�����ʼ������0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
};

//������֤��ʽ����
struct ContactVerifyType
{
	ContactVerifyType() :userid(0), type(0){}
	int64 userid;
	int8  type; //��֤����1��Ҫ��֤��Ϣ:2:�������κ������,3:�����κ������
};

struct  OnlineState
{
	OnlineState() :userID(0), connectID(0), deviceType(0), flag(0){}
	int64 userID;   //�û�ID
	int64 connectID;
	int8 deviceType;  //�����豸����
	int8 flag;        //����״̬
};

struct SearchResult {
	std::vector<service::User> users;
	std::vector<service::User> groups;
};

struct  MsgSearchProperty {
	MsgSearchProperty(void) :targetid(0), count(0), msgtype(0),
	start_time(0), end_time(0){}
	int msgtype; //��Ϣ����
	int count;   //��Ϣ����
	int64 targetid;//Ŀ��ID
	int64 start_time;//��ʼʱ��
	int64 end_time;  //����ʱ��
};

struct  MsgSearchResult{
	MsgSearchResult():count(0),flag(0),targetid(0){}
	int count;      //��Ϣ����
	int8  flag;		//0x01�У�0x02Ů, 0x08ΪȺ��0 ���з�ŮΪ����
	int64 targetid;	//Ŀ��id
	std::string name; //Ŀ������
	std::string avatar;//Ŀ��ͷ��
};

struct FileInfo{
	FileInfo() :fileid(0),userid(0),targetid(0),size(0),time(0){}
	int64 fileid;                 //�ļ�ID
	int64 userid;                 //������ID
	int64 targetid;               //Ŀ��ID,������Ⱥ,Ҳ�������û�
	int64 size;                   //�ļ���С
	int64 time;                   //�ϴ�ʱ��
	std::string path;             //����·��
	std::string name;             //�ļ���
	std::string url;              //�ļ�url
	std::string encrypt_key;      //����KEY
};

struct OfflineMsg
{
	OfflineMsg():offline_type(0),count(0){}
	int offline_type;  /*1δ����Ϣ 2�豸�Ѷ���Ϣ*/
	int count;      //����
	std::shared_ptr<service::Msg> msg;
};


