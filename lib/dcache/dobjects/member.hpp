#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"


class disc_member_t {
public:
	disc_member_t() {}

	disc_member_t( nlohmann::json& member_data, disc_guild_t* parent_guild ) {
		m_update( member_data, parent_guild );
	}

public:
	inline void m_update( nlohmann::json& member_data, disc_guild_t* parent_guild ) {
		// TODO: Update user
		// - This isn't possible to do without the dcache object...

		// TODO: Update roles
		// - This isn't possible to do here either... I need to import the guild dobject
		// - Meaning I might have to move these into separate source files...

		for ( nlohmann::json& role_id_data : member_data["roles"] ) {
			auto role_id = str_to_integer<dsnowflake_t>( role_id_data.get_ref<std::string&>() );
			auto role_it = parent_guild->roles.find( role_id );

			if ( role_it != parent_guild->roles.end() ) {
				roles[ role_id ] = role_it->second;
			}
		}

		// Update primitive fields
		auto nick_it = member_data.find( "nick" );
		if ( nick_it != member_data.end() ) {
			nick = nick_it->get<std::string>();
		} else nick.clear();

		mute = member_data["mute"].get<bool>();
		deaf = member_data["deaf"].get<bool>();
	}

public:
	disc_user_ptr_t user;
	std::string nick;

	std::map<dsnowflake_t, disc_role_ptr_t> roles;

	bool mute;
	bool deaf;
};
