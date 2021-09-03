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
		: id( 0 ) {}

	disc_role_t( nlohmann::json& role_data, disc_guild_ptr_t parent_guild ) {
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
