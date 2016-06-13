#pragma once

#include "SDKTypes.h"
#include <string>

namespace service {
	struct _Usesr__isset {
		_Usesr__isset(void) :gender(false), time_zone(false),
		id(false), name(false), avatar(false), thumb_avatar(false),extends(false){}
		bool gender;
		bool time_zone;
		bool id;
		bool name;
		bool avatar;
		bool thumb_avatar;
		bool extends;
	};
	class User {
	public:
		User() :gender(0), time_zone(0), id(0){}
		~User(){}
		virtual void init(){}
		void __set_gender(const int val){
			gender = val;
			_user_isset.gender = true;
		}
		void __set_time_zone(const int val){
			time_zone = val;
			_user_isset.time_zone = true;
		}
		void __set_id(const int64 val){
			id = val;
			_user_isset.id = true;
		}
		void __set_name(const std::string& val){
			name = val;
			_user_isset.name = true;
		}
		void __set_avatar(const std::string& val){
			avatar = val;
			_user_isset.avatar = true;
		}
		void __set_thumb_avatar(const std::string& val){
			thumb_avatar = val;
			_user_isset.thumb_avatar = true;
		}
		void __set_extends(const std::string& val){
			extends = val;
			_user_isset.extends = true;
		}
		bool operator == (const User & rhs)const {
			if (_user_isset.avatar != rhs._user_isset.avatar)
				return false;
			else if (_user_isset.avatar && !(avatar == rhs.avatar))
				return false;
			if (_user_isset.gender != rhs._user_isset.gender)
				return false;
			else if (_user_isset.gender && !(gender == rhs.gender))
				return false;
			if (_user_isset.id != rhs._user_isset.id)
				return false;
			else if (_user_isset.id && !(id == rhs.id))
				return false;
			if (_user_isset.name != rhs._user_isset.name)
				return false;
			else if (_user_isset.name && !(name == rhs.name))
				return false;
			if (_user_isset.thumb_avatar != rhs._user_isset.thumb_avatar)
				return false;
			else if (_user_isset.thumb_avatar && !(thumb_avatar == rhs.thumb_avatar))
				return false;
			if (_user_isset.time_zone != rhs._user_isset.time_zone)
				return false;
			else if (_user_isset.time_zone && !(time_zone == rhs.time_zone))
				return false;
			if (_user_isset.extends != rhs._user_isset.extends)
				return false;
			else if (_user_isset.extends && !(extends == rhs.extends))
				return false;
			return true;
		}
	public:
		int gender; //�Ա�:1��2Ů0����
		int time_zone;//ʱ��
		int64 id;//id
		std::string name; //����
		std::string avatar;//ԭͼͼ��
		std::string extends;//��չ�ֶ�
		std::string thumb_avatar;//����ͼ
		_Usesr__isset _user_isset;
	};

	template<typename T>
	T& userCast(User& val){ return dynamic_cast<T&>(val); }
}
