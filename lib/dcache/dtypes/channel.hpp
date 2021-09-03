#pragma once


#include <cstdint>

enum disc_channel_type : uint8_t {
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

enum disc_channel_overwrites_type : uint8_t {
	CHANNEL_OVER_ROLE   = 0,
	CHANNEL_OVER_MEMBER = 1,
};
