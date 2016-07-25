#pragma  once
#include "Contact.h"
namespace service {
	struct _EntExtendInfo__isset {
		_EntExtendInfo__isset(void) :sex(false), orgname(false), phonenum(false), porgname(false),
		postcode(false), address(false), fax(false), duty(false), enmail(false), enmobile(false),
		enname(false){}
		bool sex;			/*�Ա�*/
		bool orgname;		/*��֯��*/
		bool phonenum;		/*�ֻ���*/
		bool porgname;		/*����֯�������*/
		bool postcode;		/*��������*/
		bool address;		/*��ַ*/
		bool fax;			/*����*/
		bool duty;			/*ְλ*/
		bool enmail;		/*�����ʼ�*/
		bool enmobile;		/*�ֻ���*/
		bool enname;		/*����ҵ��֯�е�����*/
	};
	class EntExtendInfo : public Contact{
	public:
		EntExtendInfo():sex(0){}
		~EntExtendInfo(){}
		void init(){}
		void _set_sex(const int32 val){
			sex = val;
			__isset.sex = true;
		}
		void _set_orgname(const std::string val){
			orgname = val;
			__isset.orgname = true;
		}
		void _set_phonenum(const std::string val){
			phonenum = val;
			__isset.phonenum = true;
		}
		void _set_porgname(const std::string val){
			porgname = val;
			__isset.porgname = true;
		}
		void _set_postcode(const std::string val){
			postcode = val;
			__isset.postcode = true;
		}
		void _set_address(const std::string val){
			address = val;
			__isset.address = true;
		}
		void _set_fax(const std::string val){
			fax = val;
			__isset.fax = true;
		}
		void _set_duty(const std::string val){
			duty = val;
			__isset.duty = true;
		}
		void _set_enmail(const std::string val){
			enmail = val;
			__isset.enmail = true;
		}
		void _set_enmobile(const std::string val){
			enmobile = val;
			__isset.enmobile = true;
		}
		void _set_enname(const std::string val){
			enname = val;
			__isset.enname = true;
		}
	public:
		int32		sex;			/*�Ա�*/
		std::string orgname;		/*��֯��*/
		std::string phonenum;		/*�ֻ���*/
		std::string porgname;		/*����֯�������*/
		std::string postcode;		/*��������*/
		std::string address;		/*��ַ*/
		std::string fax;			/*����*/
		std::string duty;			/*ְλ*/
		std::string enmail;			/*�����ʼ�*/
		std::string enmobile;		/*�ֻ���*/
		std::string enname;			/*����ҵ��֯�е�����*/
		_EntExtendInfo__isset __isset;
	};
}