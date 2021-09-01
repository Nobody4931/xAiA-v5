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

#endif
