#pragma once
#include "SDKTypes.h"

#include <vector>
#include <string>
#include <memory>

namespace service {

	enum MSG_TYPE{
		MSG_TYPE_HTML = 1,
		MSG_TYPE_TEXT,
		MSG_TYPE_AUDIO,
		MSG_TYPE_POSITION,
		MSG_TYPE_IMG,
		MSG_TYPE_FILE,
		MSG_TYPE_CARD,
		MSG_TYPE_TIP
	};
	class Msg {
	public:
		Msg(void) :msgtype(0), msgid(0), targetid(0), fromid(0), toid(0), 
			localid(0), active_type(0), related_msgid(0),time(0){}
		virtual ~Msg(void){}
		virtual void inti(void){}
		bool operator == (const Msg & rhs)const{
			if (msgtype != rhs.msgtype)
				return false;
			if (msgid != rhs.msgid)
				return false;
			if (targetid != rhs.targetid)
				return false;
			if (fromid != rhs.fromid)
				return false;
			if (toid != rhs.toid)
				return false;
			if (localid != rhs.localid)
				return false;
			if (related_users != rhs.related_users)
				return false;
			if (limit_range != rhs.limit_range)
				return false;
			if (body != rhs.body)
				return false;
			if (active_type != rhs.active_type)
				return false;
			if (related_msgid != rhs.related_msgid)
				return false;
			if (time != rhs.time)
				return false;
			return true;
		}
	public:
		int msgtype;    //��Ϣ����
		int active_type;//��Ϣ�¼����� 1.�ĺ󼴷� 2 ���ʱش� 3 �
		int64 msgid;    //��ϢID
		int64 targetid; //�Ự��ID��Ⱥ���û��ȣ�
		int64 fromid;   //������ID
		int64 toid;     //������ID
		int64 localid;  //����ID
		int64 related_msgid; //������ϢID
		int64 time;    //����ʱ��
		std::string body;//��Ϣ����
		std::vector<int64> related_users;//����ʱ��ص��û�ID
		std::vector<int64> limit_range; //@��Ա�б�
	};

	class MsgText : public Msg {
	public:
		MsgText(void){}
		void inti(void){}
		bool operator == (const MsgText& rhs)const {
			if (msg_properties != rhs.msg_properties)
				return false;
			return true;
		}
	public:
		std::string msg_properties;
	};

	class MsgFile : public Msg {
	public:
		MsgFile(void){}
		void init(void){}
		bool operator == (const MsgFile& rhs)const{
			if (states != rhs.states)
				return false;
			if (size != rhs.size)
				return false;
			if (fileid != rhs.fileid)
				return false;
			if (file_name != rhs.file_name)
				return false;
			if (file_path != rhs.file_path)
				return false;
			if (url != rhs.url)
				return false;
			if (encrypt_key != rhs.encrypt_key)
				return false;
			if (encrypt_user != rhs.encrypt_user)
				return false;
			return true;
		}
	public:
		int states;
		int64 size;  //�ļ���С
		int64 fileid;//�ļ�ID
		int64 encrypt_user;//������ID
		std::string file_name;//�ļ���
		std::string file_path;//�ļ�����·��
		std::string encrypt_key;//����KEY
		std::string url;//�ļ�URL
	};

	class MsgImg : public Msg {
	public:
		MsgImg(){}
		void init(void){}
		bool operator == (const MsgImg& rhs)const{
			if (width != rhs.width)
				return false;
			if (height != rhs.height)
				return false;
			if (file_name != rhs.file_name)
				return false;
			if (thumb_url != rhs.thumb_url)
				return false;
			if (main_url != rhs.main_url)
				return false;
			if (encrypt_key != rhs.encrypt_key)
				return false;
			if (encrypt_user != rhs.encrypt_user)
				return false;
			return true;
		}
	public:
		int width;   //ͼ����
		int height;  //ͼ��߶�
		int64 encrypt_user;  //������ID
		std::string thumb_url; //����ͼURL
		std::string main_url;  //��ͼURL
		std::string encrypt_key;//����KEY
		std::string file_name;   //�ļ���
	};

	typedef std::shared_ptr<Msg> MsgPtr;

	template<typename T>
	T& msgCast(Msg& val){ return dynamic_cast<T&>(val); }

	template <typename T>
	std::shared_ptr<T> msgPointCast(MsgPtr val){ return std::dynamic_pointer_cast<T>(val); }
	
}