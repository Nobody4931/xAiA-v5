#pragma once
#ifndef DTYPES_HEADER_HPP
#define DTYPES_HEADER_HPP

#include <cstdint>


typedef uint64_t dsnowflake_t;


enum dgate_op_type : uint8_t {
	OP_DISPATCH                     = 0,
	OP_HEARTBEAT                    = 1,
	OP_IDENTIFY                     = 2,
	OP_PRESENCE_UPDATE              = 3,
	OP_VOICE_STATE_UPDATE           = 4,
	OP_VOICE_SERVER_PING            = 5,
	OP_RESUME                       = 6,
	OP_RECONNECT                    = 7,
	OP_REQUEST_GUILD_MEMBERS        = 8,
	OP_INVALID_SESSION              = 9,
	OP_HELLO                        = 10,
	OP_HEARTBEAT_ACK                = 11,
	OP_GUILD_SYNC                   = 12,
	OP_DM_UPDATE                    = 13,
	OP_LAZY_REQUEST                 = 14,
	OP_LOBBY_CONNECT                = 15,
	OP_LOBBY_DISCONNECT             = 16,
	OP_LOBBY_VOICE_STATES_UPDATE    = 17,
	OP_STREAM_CREATE                = 18,
	OP_STREAM_DELETE                = 19,
	OP_STREAM_WATCH                 = 20,
	OP_STREAM_PING                  = 21,
	OP_STREAM_SET_PAUSED            = 22,
	OP_REQUEST_APPLICATION_COMMANDS = 24,
};

enum dgate_close_op_type : uint16_t {
	COP_LOGGED_OUT_1          = 1000,
	COP_LOGGED_OUT_2          = 1001,
	COP_UNKNOWN_ERROR         = 4000,
	COP_UNKNOWN_OPCODE        = 4001,
	COP_DECODE_ERROR          = 4002,
	COP_NOT_AUTHENTICATED     = 4003,
	COP_AUTHENTICATION_FAILED = 4004,
	COP_ALREADY_AUTHENTICATED = 4005,
	COP_INVALID_SEQ           = 4007,
	COP_RATE_LIMITED          = 4008,
	COP_SESSION_TIMED_OUT     = 4009,
	COP_INVALID_SHARD         = 4010,
	COP_SHARDING_REQUIRED     = 4011,
	COP_INVALID_API_VERSION   = 4012,
	COP_INVALID_INTENTS       = 4013,
	COP_DISALLOWED_INTENTS    = 4014,
};


enum dpermissions_type : uint64_t {
	PERM_CREATE_INSTANT_INVITE      = (1LL << 0),
	PERM_KICK_MEMBERS               = (1LL << 1),
	PERM_BAN_MEMBERS                = (1LL << 2),
	PERM_ADMINISTRATOR              = (1LL << 3),
	PERM_MANAGE_CHANNELS            = (1LL << 4),
	PERM_MANAGE_GUILD               = (1LL << 5),
	PERM_ADD_REACTIONS              = (1LL << 6),
	PERM_VIEW_AUDIT_LOG             = (1LL << 7),
	PERM_PRIORITY_SPEAKER           = (1LL << 8),
	PERM_STREAM                     = (1LL << 9),
	PERM_VIEW_CHANNEL               = (1LL << 10),
	PERM_SEND_MESSAGES              = (1LL << 11),
	PERM_SEND_TTS_MESSAGES          = (1LL << 12),
	PERM_MANAGE_MESSAGES            = (1LL << 13),
	PERM_EMBED_LINKS                = (1LL << 14),
	PERM_ATTACH_FILES               = (1LL << 15),
	PERM_READ_MESSAGE_HISTORY       = (1LL << 16),
	PERM_MENTION_EVERYONE           = (1LL << 17),
	PERM_USE_EXTERNAL_EMOJIS        = (1LL << 18),
	PERM_VIEW_GUILD_INSIGHTS        = (1LL << 19),
	PERM_CONNECT                    = (1LL << 20),
	PERM_SPEAK                      = (1LL << 21),
	PERM_MUTE_MEMBERS               = (1LL << 22),
	PERM_DEAFEN_MEMBERS             = (1LL << 23),
	PERM_MOVE_MEMBERS               = (1LL << 24),
	PERM_USE_VAD                    = (1LL << 25),
	PERM_CHANGE_NICKNAME            = (1LL << 26),
	PERM_MANAGE_NICKNAMES           = (1LL << 27),
	PERM_MANAGE_ROLES               = (1LL << 28),
	PERM_MANAGE_WEBHOOKS            = (1LL << 29),
	PERM_MANAGE_EMOJIS_AND_STICKERS = (1LL << 30),
	PERM_USE_APPLICATION_COMMANDS   = (1LL << 31),
	PERM_REQUEST_TO_SPEAK           = (1LL << 32),
	PERM_MANAGE_THREADS             = (1LL << 34),
	PERM_USE_PUBLIC_THREADS         = (1LL << 35),
	PERM_USE_PRIVATE_THREADS        = (1LL << 36),
	PERM_USE_EXTERNAL_STICKERS      = (1LL << 37),
};


enum dchannel_type : uint8_t {
	CHANNEL_GUILD_TEXT           = 0,
	CHANNEL_DM                   = 1,
	CHANNEL_GUILD_VOICE          = 2,
	CHANNEL_GROUP_DM             = 3,
	CHANNEL_GUILD_CATEGORY       = 4,
	CHANNEL_GUILD_NEWS           = 5,
	CHANNEL_GUILD_STORE          = 6,
	CHANNEL_GUILD_NEWS_THREAD    = 10,
	CHANNEL_GUILD_PUBLIC_THREAD  = 11,
	CHANNEL_GUILD_PRIVATE_THREAD = 12,
	CHANNEL_GUILD_STAGE_VOICE    = 13,
};

enum dperm_overwrites_type : uint8_t {
	PERM_OVER_ROLE   = 0,
	PERM_OVER_MEMBER = 1,
};

#endif
