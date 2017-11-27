#pragma once
#ifndef __CHANNELSERVER_H__
#define __CHANNELSERVER_H__
#ifndef _WIN32
#include <tr1/unordered_map>
#else
#include <unordered_map>
#endif
#include <BaseServer.h>
#include "ClientInfo.h"
#include <Vector3.h>
#include <objectpool.h>
#include <UdpListener.h>
#include<vector>
#include <Timer.h>
#include "pch.h"
using namespace RakNet;
class ChannelRoom;
class ChannelClient;
class Timer;
typedef std::vector<ChannelClient*>::iterator ClientIterator;
typedef std::vector<ChannelRoom*>::iterator RoomIterator;
typedef std::pair<uint64_t, ChannelClient*> UdpClientMapPair;
typedef std::tr1::unordered_map<uint64_t, ChannelClient*> UdpClientMap;
typedef std::tr1::unordered_map<uint64_t, ChannelClient*>::iterator UdpClientIterator;
struct ChannelConfig
{
	char ip[64];
	char pwd[64];
	char data_config_path[64];
	int port;
	int max_client;
	int max_room;
	int max_health;
	int max_game_time;
	int max_blance_time;
	int max_loading_time;
	int max_ready_time;
	int rebirth_time;
public:
	ChannelConfig();
};
class ChannelServer:public BaseServer,public UdpListener
{
public:
	ChannelServer();
	~ChannelServer();
	virtual void OnUdpClientMessage(Packet* p);
	virtual void OnUdpClientDisconnected(Packet* p);
	virtual void OnUdpAccept(Packet* p);
	virtual void OnKeepAlive(Packet* p);
	virtual bool Init();
	virtual int Run();
	void Update(float time);
	ChannelRoom* GetRoom(int state,bool check_full=true);
	ChannelRoom* CreateNewRoom();
	void FreeRoom(ChannelRoom* room);
	void RemoveClient(ChannelClient* c);
	void RemoveClient(uint64_t connectionID);
	bool GetWeaponInfo(WeaponInfo &info,WeaponType type);
	bool GetSkillInfo(SkillInfo &info, SkillType type);
	bool RandomBrithPos(Vector3 &v3);
	bool RandomDropPos(Vector3 &v3);
	bool GetDropItemPos(Vector3 &v3, int index);
public:
	ChannelConfig m_Config;
	ObjectPool<ChannelClient> m_ClientPool;
	ObjectPool<ChannelRoom> m_RoomPool;
	ObjectPool<DropItemInfo>m_DropItemPool;
	std::vector<ChannelRoom*> m_RoomList;
	
private:
	UdpClientMap m_UdpClientMap;
	Timer m_UpdateTimer;
public:
	DropItemRefreshInfo gDropRefreshItems[DROP_ITEM_COUNT];
	Vector3 gDropRefreshPoints[MAX_DROP_POINT_COUNT];
	int gDropRefreshPointsCount;
	SkillInfo gSkillInfos[DROP_ITEM_COUNT];
};
extern ChannelServer gChannelServer;


#endif // !__CHANNELSERVER_H__


