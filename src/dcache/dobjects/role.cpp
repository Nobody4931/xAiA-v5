#include "dcache/dobjects/role.hpp"

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"
#include "dcache/dobjects/guild.hpp"


void disc_role_t::m_update( dcache_t* dcache, nlohmann::json& role_data, disc_guild_t* parent_guild ) {
	name = role_data["name"].get<std::string>();

	color = role_data["color"].get<uint32_t>();
	position = role_data["position"].get<uint32_t>();
	permissions = static_cast<disc_permissions_type>(
		str_to_int<uint64_t>( role_data["permissions"].get_ref<std::string&>() ) );

	hoist = role_data["hoist"].get<bool>();
	mentionable = role_data["mentionable"].get<bool>();
}
