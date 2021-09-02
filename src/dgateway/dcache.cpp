#include "dgateway/dcache.hpp"

#include <cstring>
#include <string>

#include <nlohmann/json.hpp>

#include "dgateway/dtypes.hpp"
#include "dgateway/dobjects.hpp"


std::shared_ptr<disc_guild_t> dcache_t::cache_guild( nlohmann::json& guild_data ) {
	dsnowflake_t id = std::stoull( guild_data["id"].get<std::string>() );

	auto unavailable_it = guild_data.find( "unavailable" );

	std::shared_ptr<disc_guild_t> guild( new disc_guild_t {
		.id = id,
		.name = guild_data["name"].get<std::string>(),
		.unavailable = unavailable_it != guild_data.end()
			? unavailable_it->get<bool>()
			: false
	} );

	return m_guilds[ id ] = guild;
}

std::shared_ptr<disc_user_t> dcache_t::cache_user( nlohmann::json& user_data ) {
	;
}
