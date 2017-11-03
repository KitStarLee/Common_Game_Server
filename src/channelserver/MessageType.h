#pragma once
enum ClientMessage
{
	CM_MESSAGE_START = 0,
	CM_PLAYER_INFO,
	CM_REQUEST_JOIN_GAME,
	CM_SYNC_TRANSFROM,
	CM_SHOOT,
	CM_HIT_CHARACTER,
	CM_USE_SKILL_WEAPON,
	CM_MESSAGE_END,
	CM_JOYSTICK,
	CM_RESURRECTION,
	CM_SUPPLY_CHANGE,					// 补给改变
	CM_ADD_NEW_WEAPON,          //添加新的武器
};
enum ServerMessage
{
	SM_MESSAGE_START = 0,
	SM_WEAPON_SORT,
	SM_CAN_ENTER_GAME,
	SM_REPONSE_JOIN_GAME,
	SM_ROOM_INFO,
	SM_ROOM_ENTER,
	SM_ROOM_LEAVE,
	SM_GAME_LOGADING,
	SM_CHARACTER_JOIN,
	SM_SYNC_TRANSFROM,
	SM_SHOOT,
	SM_PLAYER_HELTH_CHANGE,
	SM_PLAYER_LEAVE,
	SM_USE_SKILL_WEAPON,
	SM_SKILL_STATE_CHANGE,
	SM_MESSAGE_END,
	SM_JOYSTICK,
	SM_RESURRECTION,
	SM_UPDATE_PLAY_INFO,			// 更新用户数据
	SM_SUPPLY_CHANGE,					// 补给改变
	SM_ADD_NEW_WEAPON,          //添加新的武器
};
typedef enum 
{
	ERROR_NONE=0,
	ERROR_CREATE_ROOM,
}ChannelError;
struct PlayerSkillState
{
public:
	static const int None = 0;
	static const int Shield = 1 << 1;
};
