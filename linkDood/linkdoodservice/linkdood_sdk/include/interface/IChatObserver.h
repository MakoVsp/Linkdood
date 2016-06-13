#pragma once

#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"

#include "../data/SDKTypes.h"
#include <memory>

class IChatObserver {
public:
	/************************************************************************
	* @brief onMessageNotice
	* @description: ��������Ϣ֪ͨ
	* @param[in] flag ����-1����������0�����ɹ�
	************************************************************************/
	virtual void onMessageNotice(std::shared_ptr<service::Msg> msg) = 0;

	/************************************************************************
	* @brief onAvatarChanged
	* @description: ����ͷ�����
	* @param[in] targetid ����Ŀ��ID���˻���Ⱥ
	* @param[in] avatar   ����·��
	************************************************************************/
	virtual void onAvatarChanged(int64 targetid, std::string avatar) = 0;

	/************************************************************************
	* @brief onOfflineMsgChanged
	* @description: ����������Ϣ֪ͨ
	* @param[in] msgs ����������Ϣ����
	************************************************************************/
	virtual void onOfflineMsgChanged(std::vector<OfflineMsg> msgs) = 0;

	/************************************************************************
	* @brief onListChanged
	* @description: �����Ự�б����֪ͨ
	* @param[in] flag �����б��־
	* 1:0x01����һ����,���� ��Ҫ����ԭ��������
	* 2:0x02  �м�İ���������ԭ�������ݺ���׷��
	* 3:0x04  ���İ�����������Ự�������
	* @param[in] chats ����Ự����
	************************************************************************/
	virtual void onListChanged(int flag, std::vector<std::shared_ptr<service::User> > chats) = 0;
};