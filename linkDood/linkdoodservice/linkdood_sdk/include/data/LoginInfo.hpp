#pragma once

#include "SDKTypes.h"
#include <string>
#include <vector>
namespace service {

#define KEEPPASSWD 2
#define AUTOLOGIN 4

    class LoginInfo
    {
    public:
		LoginInfo():isRemberPass(false), isAutoLogin(false), status(0), userId(0), last_login_time(0){};
		virtual ~LoginInfo(){};

		int32 status;
		int32 isRemberPass;              //�Ƿ��ס����
		int32 isAutoLogin;               //�Զ���¼ 
		int64 userId;                    //�û�id
		int64 last_login_time;           //�ϴε�½ʱ��
        std::string server;              //������
        std::string name;               //�û���
		std::string account;			//�˺�
        std::string user_icon;          //ͷ��
        std::string area_num;           //������           
    };

}// namespace service
