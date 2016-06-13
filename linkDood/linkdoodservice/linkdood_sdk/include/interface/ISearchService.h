#pragma once

#include "../data/packet.h"
#include "../data/ErrorInfo.hpp"

#include <functional>
#include <memory>
#include <string>

namespace service {
	namespace sdk{
		class SdkChannel;
	}

	class ISearchService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��ISearchService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief searchFromNet
		* @description: ��������в���
		* @param[in] key ����ؼ���
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void searchFromNet(
			const std::string& key, std::function<void(ErrorInfo& info,SearchResult& res)> await) = 0;

		/************************************************************************
		* @brief searchFromLocal
		* @description: �ӱ������ݿ���в���
		* @param[in] key ����ؼ���
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void searchFromLocal(
			const std::string& key, std::function<void(ErrorInfo& info, SearchResult& res)> await) = 0;

		/************************************************************************
		* @brief getUserInfo
		* @description: �ӱ������ݿ���в���
		* @param[in] userid �����û�ID
		* @param[inout] await ������յ��ý���Ļص�����
		************************************************************************/
		virtual void getUserInfo(
			const int64 userid, std::function<void(ErrorInfo& info, User& user)> await) = 0;

	};

	std::shared_ptr<ISearchService> getSearchInstance(void);
}