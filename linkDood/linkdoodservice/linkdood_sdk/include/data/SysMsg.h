#pragma once
#include "SDKTypes.h"
#include<string>
struct SysMsgRespInfo
{
	SysMsgRespInfo() :targetid(0),msgid(0),msgtype(0),opertype(0){}
	int64 targetid;//Ŀ��ID
	int64 msgid;   //��ϢID
	int   msgtype; //��Ϣ����
	int   opertype;//�����
	std::string info;//��Ϣ�ظ�����
};

struct SysMsg
{
	SysMsg():msgid(0),targetid(0),time(0),msgtype(0),isresponse(0),isread(0),opertype(0),subtype(0){}
	int64 msgid;       //��ϢID
	int64 targetid;    //Ŀ��ID
	int64 time;        //ʱ��
	int64 operUserid;  //������ID
	int   msgtype;     //��Ϣ����
	int   isresponse;  //�Ƿ��Ӧ
	int   isread;      //�Ƿ��Ѷ�
	int   opertype;    //�����
	int   subtype;     //�Ӳ������ͱ�ʾ,�ö�����������
	std::string name;  //��Ϣ��Դ����
	std::string operUser; //����������
	std::string avatar;//��Ϣ��Դͷ��
	std::string info;  //��Ϣ����
};