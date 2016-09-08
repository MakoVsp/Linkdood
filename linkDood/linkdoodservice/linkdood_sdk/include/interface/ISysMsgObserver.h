#pragma once
#include"../data/SysMsg.h"

#include <memory>
#include <vector>


class ISysMsgObserver {
public:
	/************************************************************************
	* @brief onSysMessageNotice
	* @description: ����ϵͳ��Ϣ
	* @param[in] msg ������Ϣ
	* @param[in] unreadcount ����δ������
	************************************************************************/
	virtual void onSysMessageNotice(SysMsg& msg, int unreadcount = 0) = 0;
};