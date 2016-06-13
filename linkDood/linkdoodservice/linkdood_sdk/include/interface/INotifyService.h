#pragma once
#include <memory>

class IAuthObserver;
class IContactObserver;
class IGroupObserver;
class IChatObserver;
class ISysMsgObserver;

typedef IAuthObserver* AuthObserverPtr;
typedef IContactObserver* ContactObserverPtr;
typedef IGroupObserver* GroupObserverPtr;
typedef IChatObserver* ChatObserverPtr;
typedef ISysMsgObserver* SysMsgObserverPtr;

namespace service {
	namespace sdk { class SdkChannel; }
	
	class INotifyService {
	public:
		
		/************************************************************************
		* @brief init
		* @description: ��ʼ��INotifyService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief setAuthObserver
		* @description: ������֤���������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void setAuthObserver(AuthObserverPtr observer) = 0;

		/************************************************************************
		* @brief removeAuthObserver
		* @description: �Ƴ���֤���������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void removeAuthObserver(AuthObserverPtr observer) = 0;

		/************************************************************************
		* @brief setAuthObserver
		* @description: ������ϵ�˼�������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void setContactObserver(ContactObserverPtr observer) = 0;

		/************************************************************************
		* @brief removeContactObserver
		* @description: �Ƴ���ϵ�˼�������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void removeContactObserver(ContactObserverPtr observer) = 0;

		/************************************************************************
		* @brief setGroupObserver
		* @description: ����Ⱥ��������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void setGroupObserver(GroupObserverPtr observer) = 0;

		/************************************************************************
		* @brief removeGroupObserver
		* @description: �Ƴ�Ⱥ��������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void removeGroupObserver(GroupObserverPtr observer) = 0;

		/************************************************************************
		* @brief setChatObserver
		* @description: ���ûỰ��������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void setChatObserver(ChatObserverPtr observer) = 0;

		/************************************************************************
		* @brief removeChatObserver
		* @description: �Ƴ��Ự��������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void removeChatObserver(ChatObserverPtr observer) = 0;

		/************************************************************************
		* @brief setSysMsgObserver
		* @description: ����ϵͳ��Ϣ��������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void setSysMsgObserver(SysMsgObserverPtr observer) = 0;

		/************************************************************************
		* @brief removeSysMsgObserver
		* @description: �Ƴ�ϵͳ��Ϣ��������
		* @param[in] observer �����������ʵ��
		************************************************************************/
		virtual void removeSysMsgObserver(SysMsgObserverPtr observer) = 0;
	};
	std::shared_ptr<INotifyService> getNotifyInstance(void);
}