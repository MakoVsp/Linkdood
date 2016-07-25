#pragma once
#include "../data/packet.h"
#include <memory>
#include <functional>
#include <string>
namespace service {
	namespace sdk { class SdkChannel; }

	class IUpdateService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��IUpdateService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief checkUpdate
		* @description: ������
		* @param[in] cur_ver ���뵱ǰ�汾��Ϣ
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void checkUpdate(const std::string& cur_ver, std::function<void(UpdateInfo& info, int code)> await)=0;

		/************************************************************************
		* @brief dataRecovery
		* @description: �������ݻָ�
		* @param[in] dbpath �������ݿ�·��
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void dataRecovery(const std::string& dbpath, std::function<void(int code)> await) = 0;
	};

	std::shared_ptr<IUpdateService> getUpdateInstance(void);
}