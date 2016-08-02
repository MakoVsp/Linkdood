#pragma once

#include "../data/LoginInfo.hpp"
#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"

#include <functional>
#include <memory>
#include <string>

namespace service {
	namespace sdk{
		class SdkChannel;
	}
	class IAuthService {
	public:
		
		/************************************************************************
		* @brief init
		* @description: ��ʼ��AuthService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(std::shared_ptr<sdk::SdkChannel> channel) = 0;

		//////////////////////////////////////////////////////////////////////////
		//	ע����ؽӿ�

		/************************************************************************
		* @brief getRegCode
		* @description: ��ȡע����֤��
		* @param[in] server �����������ַ��������IP����
		* @param[in] account ����ע���˺� ������ֻ��˻���ʽΪ��0086158********��
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void getRegCode(
			const std::string& server, const std::string& account, std::function<void(ErrorInfo& info, int timeout/*��ʱ*/)> await) = 0;

		/************************************************************************
		* @brief signup
		* @description: ע���û�
		* @param[in] regCode �����������ַ��������IP����
		* @param[in] user    �����û���������ʹ����ʵ����
		* @param[in] pwd	 ����ע������
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void signup(
			const std::string& regCode, const std::string user, const std::string& pwd, std::function<void(ErrorInfo& info)> await)=0;
		
		/************************************************************************
		* @brief getPasswordRule
		* @description: ��ȡ���븴�Ӷ�
		************************************************************************/
		virtual void getPasswordRule(void)=0;

		//////////////////////////////////////////////////////////////////////////
		//	��¼��ؽӿ�

		/************************************************************************
		* @brief getLoginHistory
		* @description: ��ȡ��¼��ʷ��¼
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void getLoginHistory(
			std::function<void(std::vector<LoginInfo>)> await)=0;

		/************************************************************************
		* @brief login
		* @description: ��¼
		* @param[in] user �����û��� ������ֻ��˻���ʽΪ��0086158********��
		* @param[in] pwd ��������
		* @param[in] server �����������ַ��������IP����
		* @param[inout] await ������յ��ý���Ļص�����
		* @return:	int64 ���ص�ǰִ�еĲ���ID������ȡ���ô�ִ��
		************************************************************************/
		virtual int64 login(
			const std::string& user, const std::string& pwd, const std::string& server, std::function<void(ErrorInfo& err, int64 userid/*�û�ID*/)> await)=0;
		
		/************************************************************************
		* @brief login
		* @description: �Զ���¼�����������룩
		* @param[in] userid �����û�ID 
		* @param[in] server �����������ַ��������IP����
		* @param[inout] await ������յ��ý���Ļص�����
		* @return:	int64 ���ص�ǰִ�еĲ���ID������ȡ���ô�ִ��
		************************************************************************/
		virtual int64 login(const int64 userid, const std::string& server, std::function<void(ErrorInfo& err, int64 userid/*�û�ID*/)> await) = 0;
		
		/************************************************************************
		* @brief logout
		* @description: �ǳ�
		************************************************************************/
		virtual void logout(void)=0;

		/************************************************************************
		* @brief abortLogin
		* @description: ȡ����¼
		* @param[in] operateid �����Ӧ��¼������ID
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void abortLogin(
			const int64 operateid, std::function<void(ErrorInfo& err)> await)=0;

		/************************************************************************
		* @brief verifyImgCode
		* @description: ��֤��¼��֤����߻�ȡ��һ����֤��
		* @param[in] account �����¼�˺�
		* @param[in] code	 ������֤������ codeΪ�����ȡ��һ����֤��
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void verifyImgCode(
			const std::string& account, const std::string& code, std::function<void(ErrorInfo& err, std::string& img/*��һ����֤ͼƬ*/)> await)=0;

		/************************************************************************
		* @brief setLoginInfo
		* @description: ���õ�¼��Ϣ
		* @param[in] flag    �����¼���� �Ƿ��ס������Ƿ��Զ���¼�İ�λ��
		* @param[in] userid  �����û�ID
		* @param[in] account �����û��˺�
		* @param[in] avatar	 �����û�ͷ��
		* @param[in] name    �����û�����
		************************************************************************/
		virtual void setLoginInfo(
			int flag, int64 userid, std::string account, std::string avatar, std::string name) = 0;

		/************************************************************************
		* @brief getSecUrl
		* @description: ��ȡ��ȫ����URL
		* @param[in] server ������ҵ������
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void getSecUrl(
			const std::string& server, std::function<void(ErrorInfo& err, std::string url)> await) = 0;

		//////////////////////////////////////////////////////////////////////////
		//	�˺���ؽӿ�
		/************************************************************************
		* @brief getAccountInfo
		* @description: ��ȡ�˻���Ϣ
		************************************************************************/
		virtual void getAccountInfo(void) = 0;

		/************************************************************************
		* @brief updateAccountInfo
		* @description: �����û���Ϣ
		* @param[in] user �����û���Ϣ
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void updateAccountInfo(
			User& user, std::function<void(ErrorInfo& info)> await) = 0;

		/************************************************************************
		* @brief changePassword
		* @description: �޸�����
		* @param[in] oldPw ���������
		* @param[in] newPw ����������
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void changePassword(
			const std::string& oldPw, const std::string& newPw, std::function<void(ErrorInfo& info)> await) = 0;

		/************************************************************************
		* @brief setSetting
		* @description: �����˺�������
		* @param[in] flag ��������������
		* @param[in] type ��������������
		* @param[inout] await ������յ��ý���Ļص�����
		*
		*  type = 1: �����Ƿ���ʾ������Ϣ flag: 0��ʾ 1����ʾ Ĭ��0
		*  type = 3: ���ö����Ų��� flag: 0���� 1������ Ĭ��0
		*  type = 4: �����ֻ��Ų��� flag: 0���� 1������ Ĭ��0
		*  type = 5: ��������Ų��� flag: 0���� 1������ Ĭ��0
		*  type = 6: ���÷������   flag: 0��ʾ���� 1����ʾ���� Ĭ��0
		*  type = 7: ����Ϣ֪ͨ�Ƿ����� flag: 0���� 1������ Ĭ��0
		*  type = 12: ���������Ϣ֪ͨ�Ƿ����� flag: 0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
		*  type = 13: ���������V�����ʼ������ flag: 0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
		*  type = 14: �������������@�����ʼ������ flag: 0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
		************************************************************************/
		virtual void setSetting(
			int8 flag, int type, std::function<void(ErrorInfo& info)> await) = 0;

		/************************************************************************
		* @brief getSetting
		* @description: ��ȡ�˺�������
		* @param[in] type �����ȡ������������
		* typeΪ1���򷵻�ֵΪvalue_i64��һλ ���type=0,���������ֶΣ�ÿ���ֶ���ռ��λ��type���Ӧ
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void getSetting(
			int type, std::function<void(ErrorInfo&, UserSetting&)> await) = 0;

		/************************************************************************
		* @brief setPrivateSetting
		* @description: ������˽����
		* @param[in] PrivateSetting �������õ���˽������
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void setPrivateSetting(PrivateSetting ps, std::function<void(int code)> await) = 0;

		/************************************************************************
		* @brief getPrivateSetting
		* @description: ��ȡ��˽����
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void getPrivateSetting(std::function<void(int, PrivateSetting&)> await) = 0;

		/************************************************************************
		* @brief getClientKey
		* @description: ��ȡCLIENTKEY
		************************************************************************/
		virtual void getClientKey(void)=0;

	};

	std::shared_ptr<IAuthService> getAuthInstance(void);
}