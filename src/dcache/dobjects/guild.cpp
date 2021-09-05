#include "dcache/dobjects/guild.hpp"

#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"


void disc_guild_t::m_update( dcache_t* dcache, nlohmann::json& guild_data ) {
	// TODO: Update roles
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
