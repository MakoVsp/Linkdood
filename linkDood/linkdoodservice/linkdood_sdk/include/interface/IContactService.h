#pragma once

#include "../data/SDKTypes.h"
#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"

#include <memory>
#include <functional>
#include <string>
#include <vector>

namespace service{

	namespace sdk{
		class SdkChannel;
	}
	class IContactService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��AuthService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(
			std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief addContact
		* @description: �����ϵ��
		* @param[in] userid ������ϵ��ID
		* @param[in] remark ������ϵ�˱�ע������Ϊ��
		* @param[in] info   ������֤��Ϣ
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void addContact(
			const int64 userid, const std::string& remark, const std::string& info, std::function<void(ErrorInfo& info)> await) = 0;

		/************************************************************************
		* @brief getVerifyType
		* @description: ��ȡ��ϵ����֤��ʽ
		* @param[in] userid ������ϵ��ID
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getVerifyType(
			const int64 userid, std::function<void(ErrorInfo&, ContactVerifyType&)> await) = 0;

		/************************************************************************
		* @brief removeContact
		* @description: ɾ����ϵ��
		* @param[in] userid ������ϵ��ID
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void removeContact(
			const int64 userid, std::function<void(ErrorInfo&)> await) = 0;

		/************************************************************************
		* @brief updateContactInfo
		* @description: ������ϵ����Ϣ���Ǳ�&V��&��ע��
		* @param[in] info ������ϵ����Ϣ
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void updateContactInfo(
			User& info, std::function<void(ErrorInfo&)> await) = 0;

		/************************************************************************
		* @brief getContactList
		* @description: ��ȡ��ϵ���б�
		************************************************************************/
		virtual void getContactList(void) = 0;

		/************************************************************************
		* @brief getContactOnline
		* @description: ��ȡ��ϵ������״̬
		* @param[in] users ������ϵ�˼��� ���Ϊ�����������ϵ��״̬
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getContactOnline(
			std::vector<int64> users, std::function<void(std::vector<OnlineState>& status)> await) = 0;

		/************************************************************************
		* @brief getContactInfo
		* @description: ��ȡ��ϵ����Ϣ
		* @param[in] users ������ϵ�˼��� ���Ϊ�����������ϵ��״̬
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getContactInfo(
			const int64 userid, std::function<void(ErrorInfo&, User&)> await) = 0;

		/************************************************************************
		* @brief getContactExtendInfo
		* @description: ��ȡ��ϵ����չ��Ϣ
		* @param[in] userid ������ϵ��id
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getContactExtendInfo(
			const int64 userid, std::function<void(ErrorInfo&, User&)> await) = 0;
	};

	std::shared_ptr<IContactService> getContactInstance(void);
}