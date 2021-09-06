#include "dcache/dobjects/guild.hpp"

#include <memory>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"
#include "dcache/dobjects/role.hpp"


void disc_guild_t::m_update( dcache_t* dcache, nlohmann::json& guild_data ) {
	// Update roles
	for ( nlohmann::json& role_data : guild_data["roles"] ) {
		auto role_id = str_to_int<dsnowflake_t>( role_data["id"].get_ref<std::string&>() );
		auto role_it = roles.find( role_id );

		if ( role_it == roles.end() ) {
			roles[ role_id ] = std::make_shared<disc_role_t>( dcache, role_data, this );
		} else role_it->second->m_update( dcache, role_data, this );
	}

	// TODO: Update channels
	// TODO: Update threads
	// TODO: Update members
	// TODO: Update emojis

	// Update primitive fields
	name = guild_data["name"].get<std::string>();

	auto unavailable_it = guild_data.find( "unavailable" );
	unavailable = unavailable_it != guild_data.end() ? unavailable_it->get<bool>() : false;

	auto owner_it = members.find(
		str_to_int<dsnowflake_t>( guild_data["owner_id"].get_ref<std::string&>() ) );
	if ( owner_it != members.end() ) {
		owner = owner_it->second;
	} else owner.reset();
}
