#pragma once


#include <cstdint>

enum disc_gate_op_type : uint8_t {
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

enum disc_gate_close_op_type : uint16_t {
	CLOSE_OP_LOGGED_OUT_1          = 1000,
	CLOSE_OP_LOGGED_OUT_2          = 1001,
	CLOSE_OP_UNKNOWN_ERROR         = 4000,
	CLOSE_OP_UNKNOWN_OPCODE        = 4001,
	CLOSE_OP_DECODE_ERROR          = 4002,
	CLOSE_OP_NOT_AUTHENTICATED     = 4003,
	CLOSE_OP_AUTHENTICATION_FAILED = 4004,
	CLOSE_OP_ALREADY_AUTHENTICATED = 4005,
	CLOSE_OP_INVALID_SEQ           = 4007,
	CLOSE_OP_RATE_LIMITED          = 4008,
	CLOSE_OP_SESSION_TIMED_OUT     = 4009,
	CLOSE_OP_INVALID_SHARD         = 4010,
	CLOSE_OP_SHARDING_REQUIRED     = 4011,
	CLOSE_OP_INVALID_API_VERSION   = 4012,
	CLOSE_OP_INVALID_INTENTS       = 4013,
	CLOSE_OP_DISALLOWED_INTENTS    = 4014,
};
