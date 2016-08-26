#pragma once

#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"
#include "../data/SysMsg.h"

#include <memory>
#include <functional>
#include <string>
#include <vector>

namespace service{

	namespace sdk{
		class SdkChannel;
	}
	class ISysMsgService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��ISysMsgService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(
			std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief response
		* @description: ��Ӧ
		* @param[in] userid ������Ϣ��Ӧ��Ϣ
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void response(
			SysMsgRespInfo info,std::function<void(ErrorInfo& info)> await) = 0;

		/************************************************************************
		* @brief setMessagRead
		* @description: ������Ϣ�Ѷ�
		* @param[in] type �����������1 ����������֤���Ѷ�|2 �������󷵻ؿ��Ѷ�| 3 ������֤������Ϣ�Ѷ�|4 ����Ⱥ��֤��Ӧ��Ϣ�Ѷ�                      
		* @param[in] msgs ������Ϣid
		************************************************************************/
		virtual void setMessagRead(
			int type,std::vector<int64> msgs) = 0;

		/************************************************************************
		* @brief getMessages
		* @description: ��ȡ��Ϣ
		* @param[in] type  ������Ӧ��Ϣ���� 0 ȫ�� 1 �Ӻ������� 2 �Ӻ�����Ӧ 3 ��Ⱥ���� 4 ��Ⱥ
		* @param[in] count ��������
		* @param[in] msgid ������Ϣid
		* @param[in] flag   ����ƫ�Ʊ�־ 0 ����ƫ�� 1 ����ƫ�� 
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getMessages(
			int type,int count,int64 msgid,int flag, std::function<void(ErrorInfo info,std::vector<SysMsg> sysmsgs)>await) = 0;	

		/************************************************************************
		* @brief removeMessages
		* @description: ɾ����Ϣ��Ϣ
		* @param[in] type  ������Ӧ��Ϣ���� 0 ȫ�� 1 �Ӻ������� 2 �Ӻ�����Ӧ 3 ��Ⱥ���� 4 ��Ⱥ��Ӧ
		* @param[in] msgs ����Ҫɾ������Ϣid
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void removeMessages(
			int type, std::vector<int64> msgs, std::function<void(ErrorInfo info)> await) = 0;
	};

	std::shared_ptr<ISysMsgService> getSysMsgInstance(void);
}