#pragma once

#include "../data/SDKTypes.h"
#include "../data/ErrorInfo.hpp"
#include "../data/Org.h"
#include "../data/packet.h"

#include <memory>
#include <functional>
#include <string>
#include <vector>

namespace service{

	namespace sdk{
		class SdkChannel;
	}
	class IEnterpriseService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��IEnterpriseService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(
			std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief getSonOrgs
		* @description: ��ȡ����֯
		* @param[in] orgid ������֯id
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getSonOrgs(
			int64 orgid, std::function<void(ErrorInfo& info, std::vector<Org> orgs,std::vector<OrgUser> orgusers)> await) = 0;

		/************************************************************************
		* @brief getOnlineStates
		* @description: ��ȡ����״̬
		* @param[in] users �����û�id
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getOnlineStates(
			std::vector<int64> users, std::function<void(std::vector<OnlineState>& states)>await) = 0;

		/************************************************************************
		* @brief getOrgUserInfo
		* @description: ��ȡ��֯�û���Ϣ
		* @param[in] userid  �����û�id
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getOrgUserInfo(
			int64 userid, std::function<void(ErrorInfo& info, OrgUser& orguser)>await) = 0;

	};

	std::shared_ptr<IEnterpriseService> getEnterpriseInstance(void);
}