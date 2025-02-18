#include <string>
#include <memory>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"
#include "dcache/dobjects/member.hpp"
#include "dcache/dobjects/guild.hpp"
#include "dcache/dobjects/user.hpp"


void disc_member_t::m_update( dcache_t* dcache, nlohmann::json& member_data, disc_guild_t* parent_guild ) {
	// Update user
	auto& all_users = dcache->get_users();

	auto user_data_it = member_data.find( "user" );
	if ( user_data_it == member_data.end() ) {
		auto user_id = str_to_int<dsnowflake_t>( user_data_it->at( "id" ).get_ref<std::string&>() );
		auto user_it = all_users.find( user_id );

		if ( user_it == all_users.end() ) {
			all_users[ user_id ] = std::make_shared<disc_user_t>( dcache, user_data_it.value() );
		} else user_it->second->m_update( dcache, user_data_it.value() );
	}

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
