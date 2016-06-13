#pragma once
#include "User.h"

namespace service {
	struct _Contact__isset {
		_Contact__isset(void):isStar(false),isVip(false),pinyin(false),remark(false),server(false){}
		bool isStar;
		bool isVip;
		bool pinyin;
		bool remark;
		bool server;
	};
	class Contact : public User {
	public:
		Contact(void) :isStar(0), isVip(0){}
		virtual ~Contact(void){}
		void init(){}
		void __set_isStar(const int val){
			isStar = val;
			__isset.isStar = true;
		}
		void __set_isVip(const int val){
			isVip = val;
			__isset.isVip = true;
		}
		void __set_pinyin(const std::string val){
			pinyin = val;
			__isset.pinyin = true;
		}
		void __set_remark(const std::string val){
			remark = val;
			__isset.remark = true;
		}
		void __set_server(const std::string val){
			server = val;
			__isset.server = true;
		}
		bool operator == (const Contact & rhs)const{
			if (__isset.isStar != rhs.__isset.isStar)
				return false;
			else if (__isset.isStar && !(isStar == rhs.isStar))
				return false;
			if (__isset.isVip != rhs.__isset.isVip)
				return false;
			else if (__isset.isVip && !(isVip == rhs.isVip))
				return false;
			if (__isset.pinyin != rhs.__isset.pinyin)
				return false;
			else if (__isset.pinyin && !(pinyin == rhs.pinyin))
				return false;
			if (__isset.remark != rhs.__isset.remark)
				return false;
			else if (__isset.remark && !(remark == rhs.remark))
				return false;
			if (__isset.server != rhs.__isset.server)
				return false;
			else if (__isset.server && !(server == rhs.server))
				return false;
			return true;
		}
	public:
		int8 isStar;	       //�Ǳ���ѣ�1.�Ǳ���ѣ�2.�����Ǳ�
		int8 isVip;            //V����ѣ� 1.V�����,  2.����V��
		std::string pinyin;	   //����ƴ��
		std::string remark;    //��ע
		std::string server;    //������
		_Contact__isset __isset;
	};
}
