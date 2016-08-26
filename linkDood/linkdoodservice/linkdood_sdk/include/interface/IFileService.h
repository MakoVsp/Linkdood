#pragma once

#include "../data/SDKTypes.h"
#include "../data/ErrorInfo.hpp"
#include "../data/packet.h"

#include <memory>
#include <functional>
#include <string>
#include <vector>

namespace service{

	typedef enum FileOperType
	{
		FILE_UPLOAD = 1,
		FILE_DOWNLOAD
	};

	namespace sdk{
		class SdkChannel;
	}
	class IFileService {
	public:
		/************************************************************************
		* @brief init
		* @description: ��ʼ��FileService
		* @param[in] channel ����SdkChannel��ʵ�������ڵ���SDK�ӿ�
		* @return:	bool �ɹ�:true, ʧ��:false
		************************************************************************/
		virtual bool init(
			std::shared_ptr<sdk::SdkChannel> channel) = 0;

		/************************************************************************
		* @brief uploadAvatar
		* @description: �ϴ�ͷ��
		* @param[in] path ����ͷ�񱾵�·��
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void uploadAvatar(
			std::string path, std::function<void(std::string orgijson, std::string thumbjson, int code)> await) = 0;

		/************************************************************************
		* @brief uploadFile
		* @description: �ϴ��ļ�
		* @param[in] path �����ļ�����·��
		* @param[in] property �����ļ�����
		* @param[in] await  ������ս���ص�
		* @return int64 �����û������ļ�����Ĳ���id
		************************************************************************/
		virtual int64 uploadFile(
			std::string path, std::string property, std::function<void(int64 tagetid, int64 operid, std::string jasoninfo, int code)> await, std::function<void(int32 extra_req, int32 process, std::string info)> pro) = 0;

		/************************************************************************
		* @brief downloadFile
		* @description: �����ļ�
		* @param[in] path ��������·��
		* @param[in] url ����url
		* @param[in] property �����ļ�����
		* @param[in] await  ������ս���ص�
		* @return int64 �����û������ļ�����Ĳ���id
		************************************************************************/
		virtual int64 downloadFile(
			std::string path, std::string url, std::string property, std::function<void(ErrorInfo& info, std::string localpath, int64 tagetid)> await, std::function<void(int32 extra_req, int32 process, std::string info)> pro) = 0;

		/************************************************************************
		* @brief uploadImage
		* @description: �ϴ���Ƭ
		* @param[in] thumbimg ��������ͼ
		* @param[in] srcimg ����ԭͼ
		* @param[in] property ����ͼƬ����
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void uploadImage(
			std::string thumbimg, std::string srcimg, std::string property, std::function<void(int64 tagetid, std::string orgijson, std::string thumbjson, int code)> await, std::function<void(int32 extra_req, int32 process, std::string info)> pro = nullptr) = 0;

		/************************************************************************
		* @brief downloadImage
		* @description: ����ͼƬ
		* @param[in] url ����ͼƬurl
		* @param[in] property ����ͼƬ����
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void downloadImage(
			std::string url, std::string property, std::function<void(ErrorInfo& info, std::string imgname, int64 targetid)> await, std::function<void(int32 extra_req, int32 process, std::string info)> pro = nullptr) = 0;


		/************************************************************************
		* @brief decryptFile
		* @description: �����ļ�
		* @param[in] encryptkey �����������
		* @param[in] srcpath ����ԭͼ·��
		* @param[in] destpath ������ܺ�ͼƬ·��
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual bool decryptFile(
			std::string encryptkey,std::string srcpath,std::string destpath) = 0;

		/************************************************************************
		* @brief getFileList
		* @description: ��ȡ�ļ��б�
		* @param[in] targetid �����ѯ����id
		* @param[in] fileid ������ʼ�ļ�id
		* @param[in] count ��������
		* @param[in] flag ����ƫ�Ʊ�־0Ϊ����1Ϊ����
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void getFileList(
			int64 targetid, int64 fileid, int count, int flag, std::function<void(ErrorInfo& info, std::vector<FileInfo> files)> await) = 0;

		/************************************************************************
		* @brief cancel
		* @description: ȡ���ļ�����
		* @param[in] opertype ����������� 
		* @param[in] id �����ļ�id
		* @param[in] await  ������ս���ص�
		************************************************************************/
		virtual void cancel(FileOperType opertype, int64 id, std::function<void(int)> await) = 0;
	};

	std::shared_ptr<IFileService> getFileInstance(void);
}