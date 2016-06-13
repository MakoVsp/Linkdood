#pragma once
#include "../data/SDKTypes.h"
#include "../data/ErrorInfo.hpp"

#include <memory>
#include <functional>
#include <string>
#include <vector>

namespace service{

	namespace sdk{
		class SdkChannel;
	}
	class ISysSetService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��ISysSetService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(
			std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief setSysSet
		* @description: ����ϵͳ����
		* @param[in] type �����������
		* @param[in] info  ������ս���ص�
		************************************************************************/
		virtual void setSysSet(
			int type,std::string info, std::function<void(ErrorInfo& info)> await) = 0;

		/************************************************************************
		* @brief getSysSet
		* @description: ��ȡϵͳ����
		* @param[in] info  ������ս���ص�
		************************************************************************/
		virtual void getSysSet(
			std::function<void(ErrorInfo& info,std::string setinfo)> await) = 0;
	};

	std::shared_ptr<ISysSetService> getSysSetInstance(void);
}