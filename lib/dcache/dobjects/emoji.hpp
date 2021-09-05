#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"


class disc_emoji_t {
public:
	disc_emoji_t()
		: id( 0 ) {}

	disc_emoji_t( dcache_t* dcache, nlohmann::json& emoji_data, disc_guild_t* parent_guild )
		: id( str_to_int<dsnowflake_t>( emoji_data["id"].get_ref<std::string&>() ) )
	{ m_update( dcache, emoji_data, parent_guild ); }

public:
	void m_update( dcache_t* dcache, nlohmann::json& emoji_data, disc_guild_t* parent_guild );

public:
	dsnowflake_t id;
	std::string name;

	bool colons;
	bool animated;
	bool available;
};
