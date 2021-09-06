#include "dcache/dobjects/guild.hpp"

#include <memory>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"
#include "dcache/dobjects/role.hpp"
#include "dcache/dobjects/emoji.hpp"


void disc_guild_t::m_update( dcache_t* dcache, nlohmann::json& guild_data ) {
	auto unavailable_it = guild_data.find( "unavailable" );
	if ( unavailable_it != guild_data.end() && unavailable_it->get<bool>() == true ) {
		unavailable = true;
		return;
	}

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

	// Update emojis
	for ( nlohmann::json& emoji_data : guild_data["emojis"] ) {
		auto emoji_id = str_to_int<dsnowflake_t>( guild_data["id"].get_ref<std::string&>() );
		auto emoji_it = emojis.find( emoji_id );

		if ( emoji_it == emojis.end() ) {
			emojis[ emoji_id ] = std::make_shared<disc_emoji_t>( dcache, emoji_data, this );
		} else emoji_it->second->m_update( dcache, emoji_data, this );
	}

	// Update primitive fields
	name = guild_data["name"].get<std::string>();
	unavailable = false;

	auto owner_it = members.find(
		str_to_int<dsnowflake_t>( guild_data["owner_id"].get_ref<std::string&>() ) );
	if ( owner_it != members.end() ) {
		owner = owner_it->second;
	} else owner.reset();
}
