#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dcache.hpp"


class disc_role_t {
public:
	disc_role_t()
		: id( 0 ) {}

	disc_role_t( dcache_t* dcache, nlohmann::json& role_data, disc_guild_t* parent_guild )
		: id( str_to_integer<dsnowflake_t>( role_data["id"].get_ref<std::string&>() ) )
	{ m_update( dcache, role_data, parent_guild ); }

public:
	void m_update( dcache_t* dcache, nlohmann::json& role_data, disc_guild_t* parent_guild );

public:
	dsnowflake_t id;
	std::string name;

	uint32_t color;
	uint32_t position;
	disc_permissions_type permissions;

	bool hoist;
	bool managed;
	bool mentionable;
	// bool boost_role;
};
