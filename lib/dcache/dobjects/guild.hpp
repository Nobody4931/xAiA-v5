#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <cstdint>
#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"

class disc_guild_t {
public:
	disc_guild_t()
		: id( 0 )
		, unavailable( true ) {}

	disc_guild_t( nlohmann::json& guild_data ) {
		// TODO: This
	}

public:
	dsnowflake_t id;
	std::string name;

	disc_member_ptr_t owner;

	std::map<dsnowflake_t, disc_role_ptr_t> roles;
	std::map<dsnowflake_t, disc_channel_base_ptr_t> channels;
	std::map<dsnowflake_t, disc_channel_base_ptr_t> threads;
	std::map<dsnowflake_t, disc_member_ptr_t> members;
	std::map<dsnowflake_t, disc_emoji_ptr_t> emojis;

	bool unavailable;
};
