#pragma once

#include "User.h"

//��������
enum ChatType{
	BUDDY_CHAT = 1,       //��������
	GROUP_CHAT = 2,       //Ⱥ������
	SYSTEM_MSG = 3,       //ϵͳ��Ϣ
	STRANGER_CHAT = 4,    //İ��������
	ENT_USER_CHAT = 5,    //��ҵ��Ա����
	PHONE_CHAT            //�ҵ��豸
};

namespace service {
	class Chat : public User {
	public:
		Chat(void) :msg_type(0),chat_type(0),oper_type(0),sub_type(0),unread_count(0),last_msgid(0),msg_time(0){}
		virtual ~Chat(void){}
		void init(void){}
		bool operator == (const Chat& rhs)const {
			if (msg_type != rhs.msg_type)
				return false;
			if (chat_type != rhs.chat_type)
				return false;
			if (oper_type != rhs.oper_type)
				return false;
			if (sub_type != rhs.sub_type)
				return false;
			if (unread_count != rhs.unread_count)
				return false;
			if (last_msgid != rhs.last_msgid)
				return false;
			if (msg_time != rhs.msg_time)
				return false;
			if (last_msg != rhs.last_msg)
				return false;
			return true;
		}
	public:
		int msg_type;		 //	��Ϣ����;1��HTML, 2:TEXT, 3��AUDIO, 4��POSITION, 5��IMG, 6��FILE, 7��CARD,  8��TIP
		int chat_type;	     //  ��������
		int oper_type;       //  �����
		int sub_type;        //  �Ӳ������ͱ�ʾ,�ö�����������
		int unread_count;    //δ����Ϣ����
		int64 last_msgid;    //���һ����ϢID
		int64 msg_time;      //��Ϣʱ��
		std::string last_msg;//���һ����Ϣ
	};
}