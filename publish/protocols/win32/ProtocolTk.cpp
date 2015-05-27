#include "ProtocolTk.h"
#include "stdlib.h"



namespace cocos2d
{
	namespace plugin
	{

		string strFormat(const char* format, ...)
		{
			return "";
		}

		string ProtocolTk::s_isFirstLaunch = "0";	//�Ƿ������û������û���1�� ���û�(0)
		string ProtocolTk::s_userName = "";			//�û���
		string ProtocolTk::s_userID = "";			//�û�ID
		string ProtocolTk::s_areaID = "";			//�˺�����
		string ProtocolTk::s_channel = "";			//ע������

		ProtocolTk::ProtocolTk()
		{
		}

		ProtocolTk::~ProtocolTk()
		{
		}

		void ProtocolTk::configDeveloperInfo(TTkDeveloperInfo devInfo)
		{
		}

		// ��ʼ��
		void ProtocolTk::onInitBF(const string& appID, const string& channel, const string& groupID, const string& isFirstLaunch, int tvMode)
		{
		}

		// ����
		void ProtocolTk::onPlayerAccountBF(int nFlag, const string& isFirstLogin, const string& userName, const string& userID, const string& areaID, const string& userType, const string& userLevel)
		{
		}

		// 0�㳬ʱ�¼�
		void ProtocolTk::onLoginDurationBF(const string& time)
		{
			// SDK�Ѵ��� ����
		}

		// �ǳ�
		void ProtocolTk::onLoginOutBF(const string& dayTime, const string& oneTime)
		{
		}

		// ����������
		void ProtocolTk::onGameBegin(const string& userLevel)
		{
		}

		// ����
		void ProtocolTk::onGameTask(const string& userLevel, const string& taskType, const string& taskName, const string& amount)
		{
		}

		// �ͱ�����������
		void ProtocolTk::onSilverCost(const string& dibaoType, const string& dibaoCost)
		{
		}

		// �Զ���ƴ��¼�
		void ProtocolTk::onCustomTimesEveBF(const string& eve_ID, const string& eve_Lab, map<string, string>& eve)
		{
		}

		// �Զ����ֵ�¼�
		void ProtocolTk::onCustomNumberEveBF(const string& eve_ID, const string& eve_Lab, const string& _value, map<string, string>& eve)
		{
		}

		// ������ߡ���Ʒ
		void ProtocolTk::onPayShoppingBF(const string& pay_type, const string& pay_price, const string& shop_id, const string& shop_name)
		{
		}

		// ע��
		void ProtocolTk::onRegisterBF(const string& ptId, const string& numId, const string& userType)
		{
		}

		//�Զ����¼�(����)
		void ProtocolTk::onEventSingleBF(const string& eveID)
		{
		}

		//�Զ����¼�(��������key(eveID) + ��key(eveLAB) Ŀǰֻ֧��eveID ����eveID��eveLAB��ͬһֵ)
		void ProtocolTk::onEventDoubleBF(const string& eveID, const string& eveLAB)
		{
		}

		//�Զ����¼�(map eveID��eveLAB��ͬһֵ)
		void ProtocolTk::onEventMapBF(const string& eveID, const string& eveLAB, map<string, string>& eve)
		{
		}

		/////////////////////////////////////////////////////////////////////////

		void ProtocolTk::onInitBF_android(int isUserNew, string areaId, string areaName, string serverId, string serverName, string channelName, string device_code, string appId, int tvMode)
		{
		}

		void ProtocolTk::onPlayerAccountBF_android(int type, int isUserNew, string userName, string userId
			, string userType, string areaId, string areaName, string serverId, string serverName, string reason,
			string channelName, string roomName, string userLevel)
		{
		}

		void ProtocolTk::onCostSilver_android(string dibaoType, string dibaoCost)
		{
		}

		void ProtocolTk::onGameTask_android(
			string userLevel, string taskType, string taskName, string amount)
		{
		}

		void ProtocolTk::onGameBegin_android(string userLevel)
		{
		}


		void ProtocolTk::onLoginOutBF_android()
		{
		}

		void ProtocolTk::onEventSingleBF_android(string eveId)
		{
		}

		void ProtocolTk::onEventDoubleBF_android(string eveId, string eveLab)
		{
		}

		void ProtocolTk::onEventMapBF_android(string eveId, string eveLab, string mapMsg)
		{
		}

void ProtocolTk::javaLog(const char* logTag, const char* pFormat, ...)
{
}

		/////////////////////////////////////////////////////////////////////


	}
} // namespace cocos2d { namespace plugin {


