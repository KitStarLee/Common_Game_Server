#pragma once
enum ClientMessage
{
	CM_MESSAGE_START = 0,
	CM_PLAYER_INFO,
	CM_REQUEST_JOIN_GAME,
	CM_ROOM_START_GAME,
	CM_READY_IN_GAME,
	CM_INGAME_MOVE_DATA,
	CM_INGAME_SHOOT,
	CM_INGAME_HIT_CHARACTER,
	CM_INGMAE_EXPLODE_CHARACTER,
	CM_INGAME_GET_DROP_ITEM,
	CM_INGAME_USE_SKILL,
	CM_INGAME_KILL_SELF,
    CM_INGAME_EXIT,
};
enum ServerMessage
{
	SM_MESSAGE_START = 0,
	SM_CAN_ENTER_GAME,
	SM_ROOM_INFO,
	SM_ROOM_ENTER,
	SM_ROOM_HOST_CHANGE,
	SM_ROOM_LEAVE,
	SM_GAME_LOGADING,
	SM_LOADING_END,
	SM_INGAME_JOIN,
	SM_INGAME_ROOM_INFO,
	SM_INGAME_GAME_TIME,
	SM_INGAME_BIRTH,
	SM_INGAME_MOVE_DATA,
	SM_INGAME_SHOOT,
	SM_INGAME_STATE_CHANGE,
	SM_INGAME_CHARACTER_DEAD,
	SM_INGAME_CREATE_DROPITEM,
	SM_INGAME_REMOVE_DROPITEM,
	SM_INGAME_GET_SKILL,
	SM_INGAME_USE_SKILL,
	SM_INGAME_BUFF_STATE,
	SM_INGMAE_EXPLODE,
	//�������
	SM_INGAME_TO_BALANCE,
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
