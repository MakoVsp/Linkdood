#pragma once
#include "../data/ErrorInfo.hpp"
#include "../data/SDKTypes.h"
#include <memory>

namespace service {
	class User;
}
class IAuthObserver {
public:
	/************************************************************************
	* @brief onConnectChanged
	* @description: ������������״̬
	* @param[in] flag ����-1����������0�����ɹ�
	************************************************************************/
	virtual void onConnectChanged(int flag) = 0;

	/************************************************************************
	* @brief onLoginResultObserver
	* @description: �������µ�¼���
	* @param[in] info �����¼��� 
	* @param[in] userid �����¼���û�ID
	************************************************************************/
	virtual void onLoginResultObserver(service::ErrorInfo& info, int64 userid) = 0;

	/************************************************************************
	* @brief onDBUpdateFinished
	* @description: �������ݿ������������
	* @param[in] val ����1���
	************************************************************************/
	virtual void onDBUpdateFinished(int val) = 0;

	/************************************************************************
	* @brief onLogoutChanged
	* @description: �����ǳ����
	* @param[in] info ������
	************************************************************************/
	virtual void onLogoutChanged(service::ErrorInfo& info) = 0;

	/************************************************************************
	* @brief onAccountInfoChanged
	* @description: �����û���Ϣ�޸�
	* @param[in] info ������
	************************************************************************/
	virtual void onAccountInfoChanged(service::User& info) = 0;

	/************************************************************************
	* @brief onClientKeyChanged
	* @description: �����ͻ���KEY
	* @param[in] clientKey ����Key
	************************************************************************/
	virtual void onClientKeyChanged(service::ErrorInfo& info, std::string& clientKey) = 0;

	/************************************************************************
	* @brief onPasswordRuleChanged
	* @description: �������븴�Ӷ�
	* @param[in] rule �����������
	************************************************************************/
	virtual void onPasswordRuleChanged(service::ErrorInfo& info, int16 rule) = 0;

	/************************************************************************
	* @brief onAvatarChanged
	* @description: ����ͷ�����
	* @param[in] avatar �������غõ�ͷ���ļ���
	************************************************************************/
	virtual void onAvatarChanged(std::string avatar) = 0;

};