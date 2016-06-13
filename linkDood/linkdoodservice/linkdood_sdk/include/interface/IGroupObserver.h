#pragma once
#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"
#include"../data/User.h"
#include"../data/Group.h"

#include <memory>
#include <vector>

namespace service {
	class Group;
}

class IGroupObserver {
public:
	/************************************************************************
	* @brief onListChanged
	* @description: ����Ⱥ�б�ˢ��
	* @param[in] operType �����������
	* 0x01 �����˱�ʶ����գգ��б���������б���
	* 0x02�������˱�ʶ���գ��б�β����������б���
	* 0x04 �����˱�ʶ�����к���������
	* 0x08 �����˱�ʶ���ӵ�ǰ�գ��б��и��������б������������ʶ���
	* 0x10 �����˱�ʶ���ӵ�ǰ�գ��б���ɾ�������б������������ʶ���
	* @param[in] users	  ��������Ⱥ
	************************************************************************/
	virtual void onListChanged(std::vector<std::shared_ptr<service::User> >  group) = 0;

	/************************************************************************
	* @brief onGroupAvatarChanged
	* @description: ����Ⱥͷ�����
	* @param[in] avatar	  ����ͷ��
	************************************************************************/
	virtual void onGroupAvatarChanged(int64 groupid,std::string avatar) = 0;

	/************************************************************************
	* @brief onMemberAvatarChanged
	* @description: ������Աͷ�����
	* @param[in] userid �����ԱID
	* @param[in] avatar	  �����Աͷ��
	************************************************************************/
	virtual void onMemberAvatarChanged(int64 userid, std::string avatar) = 0;

	/************************************************************************
	* @brief onGroupInfoChanged
	* @description: ����Ⱥ��Ϣ����
	* @param[in] operType �����������
	* @param[in] operType ����Ⱥ��Ϣ
	************************************************************************/
	virtual void onGroupInfoChanged(int8 operType,service::Group& group) = 0;

	/************************************************************************
	* @brief onGroupLeaderChanged
	* @description: ����Ⱥ������
	* @param[in] userid ������Ⱥ��id
	* @param[in] user_name ������Ⱥ������
	* @param[in] group_name ����Ⱥ��
	************************************************************************/
	virtual void onGroupLeaderChanged(int64 userid, std::string user_name,int64 groupid,std::string group_name) = 0;

	/************************************************************************
	* @brief onMemberInfoChanged
	* @description: ����Ⱥ��Ա��Ϣ����
	* @param[in] info �����Ա��Ϣ
	************************************************************************/
	virtual void onMemberInfoChanged(int64 groupid, service::User& info) = 0;

	/************************************************************************
	* @brief onMemberListChanged
	* @description: ����Ⱥ��Ա�б����
	* @param[in] operType �����������
	* 0x01 �����˱�ʶ����գգ��б���������б���
	* 0x02�������˱�ʶ���գ��б�β����������б���
	* 0x04 �����˱�ʶ�����к���������
	* 0x08 �����˱�ʶ���ӵ�ǰ�գ��б��и��������б������������ʶ���
	* 0x10 �����˱�ʶ���ӵ�ǰ�գ��б���ɾ�������б������������ʶ���
	* @param[in] members	  ��������Ⱥ��Ա
	************************************************************************/
	virtual void onMemberListChanged(int operType, int64 groupid, std::vector<std::shared_ptr<service::User> > members) = 0;
};