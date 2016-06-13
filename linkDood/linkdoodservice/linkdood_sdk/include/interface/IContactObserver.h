#pragma once
#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"
#include "../data/SDKTypes.h"

#include <memory>
#include <vector>

namespace service {
	class Contact;
}

class IContactObserver {
public:
	/************************************************************************
	* @brief onListChanged
	* @description: ������ϵ��ˢ��
	* @param[in] operType �����������
	* 0x01 �����˱�ʶ����գգ��б���������б���
	* 0x02�������˱�ʶ���գ��б�β����������б���
	* 0x04 �����˱�ʶ�����к���������
	* 0x08 �����˱�ʶ���ӵ�ǰ�գ��б��и��������б������������ʶ���
	* 0x10 �����˱�ʶ���ӵ�ǰ�գ��б���ɾ�������б������������ʶ���
	* @param[in] users	  ����������ϵ��
	************************************************************************/
	virtual void onListChanged(int operType, std::vector<service::Contact>& users) = 0;

	/************************************************************************
	* @brief onAvatarChanged
	* @description: ������ϵ��ͷ�����
	* @param[in] userid ������ϵ��ID
	* @param[in] avatar	  ����ͷ��
	************************************************************************/
	virtual void onAvatarChanged(int64 userid, std::string avatar) = 0;

	/************************************************************************
	* @brief onContactInfoChanged
	* @description: ������ϵ����Ϣ����
	* @param[in] operType �����������
	* @param[in] users	  ������ϵ����Ϣ
	************************************************************************/
	virtual void onContactInfoChanged(int operType, service::User& users) = 0;

	/************************************************************************
	* @brief onOnlineChanged
	* @description: ������ϵ����Ϣ����
	* @param[in] status ��������״̬
	************************************************************************/
	virtual void onOnlineChanged(OnlineState& status) = 0;
};