#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dcache.hpp"


class disc_member_t {
public:
	disc_member_t() {}

	disc_member_t( dcache_t* dcache, nlohmann::json& member_data, disc_guild_t* parent_guild ) {
		m_update( dcache, member_data, parent_guild );
	}

public:
	void m_update( dcache_t* dcache, nlohmann::json& member_data, disc_guild_t* parent_guild );

public:
	disc_user_ptr_t user;
	std::string nick;

	std::map<dsnowflake_t, disc_role_ptr_t> roles;

	bool mute;
	bool deaf;
};
