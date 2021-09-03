#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"

class disc_role_t {
public:
	disc_role_t()
		: id( 0 )
		, color( 0 )
		, position( 0 )
		, permissions( static_cast<disc_permissions_type>( 0 ) )
		, hoist( false )
		, managed( false )
		, mentionable( false )
		, boost_role( false ) {}

	disc_role_t( nlohmann::json& role_data, disc_guild_ptr_t parent ) {
		// TODO: This
	}

public:
	dsnowflake_t id;
	std::string name;

	uint32_t color;
	uint32_t position;
	disc_permissions_type permissions;

	bool hoist;
	bool managed;
	bool mentionable;
	bool boost_role;
};
