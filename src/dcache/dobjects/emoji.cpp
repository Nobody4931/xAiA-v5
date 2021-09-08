#include <string>

#include <nlohmann/json.hpp>

#include "dcache/dcache.hpp"
#include "dcache/dobjects/emoji.hpp"
#include "dcache/dobjects/guild.hpp"


void disc_emoji_t::m_update( dcache_t* dcache, nlohmann::json& emoji_data, disc_guild_t* parent_guild ) {
	name = emoji_data["name"].get<std::string>();

	colons = emoji_data["require_colons"].get<bool>();
	animated = emoji_data["animated"].get<bool>();
	available = emoji_data["available"].get<bool>();
}
