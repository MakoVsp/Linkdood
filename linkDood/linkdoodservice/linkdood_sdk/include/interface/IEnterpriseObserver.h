#pragma once
#include "../data/SDKTypes.h"
#include <memory>

class IEnterpriseObserver {
public:
	/************************************************************************
	* @brief onUpdateRootFinished
	* @description: ��ҵ���ڵ�������֪ͨ
	* @param[in] flag ����-1����������0�����ɹ�
	************************************************************************/
	virtual void onUpdateRootFinished(void) = 0;
};