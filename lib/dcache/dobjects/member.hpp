#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"


class disc_member_t {
public:
	disc_member_t() {}

	disc_member_t( nlohmann::json& member_data, disc_guild_ptr_t parent ) {
		// TODO: This
	}

public:
	disc_user_ptr_t user;
	std::string nick;

	std::map<dsnowflake_t, disc_role_ptr_t> roles;

	bool mute;
	bool deaf;
};
