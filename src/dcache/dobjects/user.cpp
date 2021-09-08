#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "dcache/dcache.hpp"
#include "dcache/dobjects/user.hpp"


void disc_user_t::m_update( dcache_t* dcache, nlohmann::json& user_data ) {
	username = user_data["username"].get<std::string>();
	discriminator = str_to_int<uint16_t>(
		user_data["discriminator"].get_ref<std::string&>() );
}
