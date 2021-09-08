#include "dcache/dobjects/member.hpp"

#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"
#include "dcache/dobjects/guild.hpp"


void disc_member_t::m_update( dcache_t* dcache, nlohmann::json& member_data, disc_guild_t* parent_guild ) {
	// TODO: Update user

	// Update roles
	auto& all_roles = parent_guild->roles;

	for ( nlohmann::json& role_id_data : member_data["roles"] ) {
		auto role_id = str_to_int<dsnowflake_t>( role_id_data.get_ref<std::string&>() );
		auto role_it = all_roles.find( role_id );

		if ( role_it != all_roles.end() ) {
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
