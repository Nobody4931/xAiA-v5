#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dcache.hpp"


class disc_guild_t {
public:
	disc_guild_t()
		: id( 0 ) {}

	disc_guild_t( dcache_t* dcache, nlohmann::json& guild_data )
		: id( str_to_int<dsnowflake_t>( guild_data["id"].get_ref<std::string&>() ) )
	{ m_update( dcache, guild_data ); }

public:
	void m_update( dcache_t* dcache, nlohmann::json& guild_data );

public:
	dsnowflake_t id;
	std::string name;

	disc_member_ptr_t owner;

	// TODO: Item removal by gateway dispatch
	std::map<dsnowflake_t, disc_role_ptr_t> roles;
	std::map<dsnowflake_t, disc_channel_base_ptr_t> channels;
	std::map<dsnowflake_t, disc_channel_base_ptr_t> threads;
	std::map<dsnowflake_t, disc_member_ptr_t> members;
	std::map<dsnowflake_t, disc_emoji_ptr_t> emojis;

	bool unavailable;
};
