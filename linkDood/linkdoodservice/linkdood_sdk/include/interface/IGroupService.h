#pragma once
#include "../data/ErrorInfo.hpp"
#include "../data/Group.h"
#include"../data/packet.h"

#include <functional>
#include <memory>
#include <string>
#include <vector>
namespace service{

    namespace sdk{
        class SdkChannel;
    }
    class IGroupService {
    public:
        /************************************************************************
        * @brief init
        * @description: �1�7�1�7�0�3�1�7�1�7GroupService�1�7�1�7
        * @param[in] channel �1�7�1�7�1�7�1�7SdkChannel�1�7�1�7�0�6�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�1�1�7�1�7�1�7SDK�1�7�0�3�1�7
        * @return:	bool �1�7�0�6�1�7:true, �0�2�1�7�1�7:false
        ************************************************************************/
        virtual bool init(std::shared_ptr<sdk::SdkChannel> channel) = 0;

        /************************************************************************
        * @brief createGroup
        * @description: �1�7�1�7�1�7�1�7�0�5
        * @param[in] level �1�7�1�7�1�7�1�7�0�5�1�7�0�7�1�7
        * @param[in] name �1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7�1�7
        * @param[in] members   �1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�3
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void createGroup(
            int level, std::string& name, std::vector<int64>& members, std::function<void(ErrorInfo& info, int64 &res)> await) = 0;

        /************************************************************************
        * @brief addGroup
        * @description: �1�7�1�7�0�5
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] verify_info �1�7�1�7�1�7�1�7�1�7�1�7�0�8�1�7�1�7�0�4
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void addGroup(
            int64 groupid, std::string& verify_info, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief removeGroup
        * @description: �1�7�1�7�0�3�0�5
        * @param[in] type �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void removeGroup(
            int type, int64 groupid, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief transferGroup
        * @description: �0�8�1�7�1�7�0�5
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] userid �1�7�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7�1�7id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void transferGroup(
            int64 groupid, int64 userid, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief setGroupSet
        * @description: �1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7�1�7
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] verify_type �1�7�1�7�1�7�1�7�1�7�1�7�0�8�1�7�1�7�1�7�1�7
        * @param[in] is_allow �1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�3�1�7�1�7�1�7�1�7�1�7�0�4�1�7
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void setGroupSet(
            int64 groupid, int8 verify_type, int8 is_allow, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief setGroupInfo
        * @description: �1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�4
        * @param[in] group �1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�4
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void setGroupInfo(
            Group group, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief getGroupList
        * @description: �1�7�1�7�0�0�0�5�1�7�҄1�7
        ************************************************************************/
        virtual void getGroupList(void) = 0;

        /************************************************************************
        * @brief getGroupSet
        * @description: �1�7�1�7�0�0�0�5�1�7�1�7�1�7�1�7
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void getGroupSet(
            int64 groupid, std::function<void(ErrorInfo& info,int8 verify_type,int8 is_allow)> await) = 0;

        /************************************************************************
        * @brief getGroupInfo
        * @description: �1�7�1�7�0�0�0�5�1�7�1�7�0�4
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void getGroupInfo(
            int64 groupid, std::function<void(ErrorInfo& info,Group group)> await) = 0;

        /************************************************************************
        * @brief inviteMember
        * @description: �1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�3
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] members �1�7�1�7�1�7�1�7�1�7�1�7�0�3�1�7�1�7�1�7�1�7
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void inviteMember(
            int64 groupid,std::vector<int64> members,std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief removeMember
        * @description: �1�7�0�9�1�7�0�5�1�7�1�7�0�3
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] userid �1�7�1�7�1�7�1�7�1�7�1�7�0�8�1�7�0�9�1�7�1�7�0�5�1�7�0�3id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void removeMember(
            int64 groupid, int64 userid, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief setMemberInfo
        * @description: �1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�3�1�7�1�7�0�4
        * @param[in] member �1�7�1�7�1�7�1�7�1�7�1�7�0�3�1�7�1�7�0�4
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void setMemberInfo(
            User& member, std::function<void(ErrorInfo& info)> await) = 0;

        /************************************************************************
        * @brief getMemberInfo
        * @description: �1�7�1�7�0�0�0�5�1�7�1�7�0�3�1�7�1�7�0�4
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] userid �1�7�1�7�1�7�1�7�1�7�1�7�0�3id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void getMemberInfo(
            int64 groupid,int64 userid, std::function<void(ErrorInfo& info,User& member)> await) = 0;

        /************************************************************************
        * @brief getMemberList
        * @description: �1�7�1�7�0�0�0�5�1�7�1�7�0�3�1�7�҄1�7
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void getMemberList(
            int64 groupid, std::function<void(ErrorInfo& info, std::vector<std::shared_ptr<User> > members)> await) = 0;

        /************************************************************************
        * @brief getGroupFileList
        * @description: �1�7�1�7�0�0�0�5�1�7�0�4�1�7�1�7�҄1�7
        * @param[in] groupid �1�7�1�7�1�7�1�7�0�5id
        * @param[in] beginid �1�7�1�7�1�7�1�7�1�7�1�7�0�3id
        * @param[in] count �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
        * @param[in] flag �1�7�1�7�1�7�1�7�0�1�1�7�0�7�1�7�0�40�0�2�1�7�1�7�1�7�1�71�0�2�1�7�1�7�1�7�1�7
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void getGroupFileList(
            int64 groupid,int64 beginid,int count,int8 flag, std::function<void(ErrorInfo& info, std::vector<FileInfo> fileInfos)> await) = 0;

        /************************************************************************
        * @brief deleteGroupFile
        * @description: �0�1�1�7�1�7�0�5�1�7�0�4�1�7
        * @param[in] files �1�7�1�7�1�7�1�7�0�5�1�7�0�4�1�7id
        * @param[in] await  �1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�3�1�7
        ************************************************************************/
        virtual void deleteGroupFile(
            std::vector<int64>files, std::function<void(ErrorInfo& info)> await) = 0;

    };
    std::shared_ptr<IGroupService> getGroupInstance(void);
}
