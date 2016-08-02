#pragma once

#include "../data/Msg.h"
#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"
#include "../data/SDKTypes.h"
#include "../data/Note.h"

#include <functional>
#include <memory>
#include <string>


namespace service {
	namespace sdk{
		class SdkChannel;
	}
	class IChatService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��ChatService��
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief getChatList
		* @description: ��ȡ�Ự�б�
		************************************************************************/
		virtual void getChatList(void) = 0;

		/************************************************************************
		* @brief removeChat
		* @description: �Ƴ��Ự
		* @param[in] targetid ����Ự��Ӧ��ID��Ⱥ������
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void removeChat(int64 targetid, std::function<void(ErrorInfo&)> await) = 0;

		/************************************************************************
		* @brief setChatTop
		* @description: ���ûỰ�ö�
		* @param[in] targetid ����Ự��Ӧ��ID��Ⱥ������
		* @param[in] type	  ����0���ö� 1�ö�
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void setChatTop(int64 targetid, int type, std::function<void(int)> await) = 0;

		/************************************************************************
		* @brief sendMessage
		* @description: ������Ϣ
		* @param[in] msg ������Ϣ
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void sendMessage(Msg& msg, std::function<void(ErrorInfo&, int64/*����ʱ��*/,int64/*��ϢID*/)> await) = 0;

		/************************************************************************
		* @brief deleteMessage
		* @description: ɾ����Ϣ
		* @param[in] targetid ����Ự��Ӧ��ID��Ⱥ������
		* @param[in] msgs ����Ҫɾ������ϢID����
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void deleteMessage(int64 targetid, std::vector<int64> msgs, std::function<void(ErrorInfo&)> await) = 0;

		/************************************************************************
		* @brief setMessageRead
		* @description: ������Ϣ�Ѷ�
		* @param[in] targetid ����Ự��Ӧ��ID��Ⱥ������
		* @param[in] msgs ����Ҫɾ������ϢID����
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void setMessageRead(int64 targetid, int64 msgid) = 0;

		/************************************************************************
		* @brief getMessages
		* @description: ��ȡ��Ϣ
		* @param[in] targetid ����Ự��Ӧ��ID��Ⱥ������
		* @param[in] msgid �����ѯ��Ϣ����ʼID�����Ӹ���Ϣ����һ����Ϣ��ʼ��ѯ
		* @param[in] count �����ѯ��Ϣ����
		* @param[in] flag  ������һҳ������һҳ ����ƫ�� 0������ƫ�� 1
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getMessages(int64 targetid, int64 msgid, int count, int flag, std::function<void(ErrorInfo&, int64/*�Ự��ID*/, std::vector<MsgPtr>)> await) = 0;

		/************************************************************************
		* @brief getUnReadMessages
		* @description: ��ȡδ����Ϣ�б�
		************************************************************************/
		virtual void getUnReadMessages(void) = 0;

		/************************************************************************
		* @brief searchMessage
		* @description: ȫ�ֲ�����Ϣ
		* @param[in] key	   ������ҹؼ���
		* @param[in] property  ������ҵĸ�������
		* @param[in] await     ������ս���ص�
		************************************************************************/
		virtual void searchMessage(std::string key, MsgSearchProperty& property, std::function<void(ErrorInfo&, std::vector<MsgSearchResult>&)> await) = 0;

		/************************************************************************
		* @brief addNote
		* @description: ����ղ�
		* @param[in] note  �����ղ���Ϣ
		* @param[in] await ������ս���ص�
		************************************************************************/
		virtual void addNote(Note&note,std::function<void(ErrorInfo&)>await)=0;

		/************************************************************************
		* @brief deleteNote
		* @description: ɾ���ղ�
		* @param[in] notes  ����Ҫɾ�����ղ���Ϣid�б�
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void deleteNote(std::vector<int64> notes, std::function<void(ErrorInfo&)>await) = 0;


		/************************************************************************
		* @brief getNoteList
		* @description: ��ȡ�ղ��б�
		* @param[in] beginid    ��ʼ��ϢID offsetflag = 0 beginid = 0ʱ�������������ϢId���в���
		* @param[in] count      ��ѯ������
		* @param[in] offsetflag ƫ�Ʊ�־ 0.��ϢId�ɴ�Сƫ�� 1.��ϢId��С����ƫ��
		* @param[in] await		������ս���ص�
		************************************************************************/
		virtual void getNoteList(int64 beginid, int32 count, int8 offsetflag, std::function<void(ErrorInfo&,std::vector<Note>&)>await)=0;

		/************************************************************************
		* @brief editNote
		* @description: �༭�ղ���Ϣ
		* @param[in] note		�����ղ���Ϣ
		* @param[in] await		������ս���ص�
		************************************************************************/
		virtual void editNote(Note&note, std::function<void(ErrorInfo&)>await) = 0;
	};

	std::shared_ptr<IChatService> getChatInstance(void);
}