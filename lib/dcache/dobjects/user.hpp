#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dcache.hpp"


class disc_user_t {
public:
	disc_user_t()
		: id( 0 ) {}

	disc_user_t( dcache_t* dcache, nlohmann::json& user_data )
		: id( str_to_int<dsnowflake_t>( user_data["id"].get_ref<std::string&>() ) )
	{
		m_update( dcache, user_data );

		auto bot_it = user_data.find( "bot" );
		auto sys_it = user_data.find( "system" );

		bot = bot_it != user_data.end() ? bot_it->get<bool>() : false;
		system = sys_it != user_data.end() ? sys_it->get<bool>() : false;
	}

public:
	void m_update( dcache_t* dcache, nlohmann::json& user_data );

public:
	dsnowflake_t id;
	std::string username;
	uint16_t discriminator;

	bool bot;
	bool system;
};
