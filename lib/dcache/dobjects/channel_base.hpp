#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <cstdint>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dcache.hpp"


class disc_channel_base_t {
public:
	disc_channel_base_t()
		: id( 0 ) {}

	disc_channel_base_t( dcache_t* dcache, nlohmann::json& channel_data, disc_guild_t* parent_guild )
		: id( str_to_int<dsnowflake_t>( channel_data["id"].get_ref<std::string&>() ) )
	{ m_update( dcache, channel_data, parent_guild ); }

public:
	virtual void m_update( dcache_t* dcache, nlohmann::json& channel_data, disc_guild_t* parent_guild );

public:
	dsnowflake_t id;
	std::string name;

	uint32_t position;
	disc_channel_type type;
	disc_guild_ptr_t guild;
	std::vector<disc_channel_overwrites_ptr_t> overwrites;
};
