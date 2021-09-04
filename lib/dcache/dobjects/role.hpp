#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"


class disc_role_t {
public:
	disc_role_t()
		: id( 0 ) {}

	disc_role_t( nlohmann::json& role_data, disc_guild_t* parent_guild )
		: id( str_to_integer<dsnowflake_t>( role_data["id"].get_ref<std::string&>() ) )
	{ m_update( role_data ); }

public:
	void m_update( nlohmann::json& role_data ) {
		name = role_data["name"].get<std::string>();
		color = role_data["color"].get<uint32_t>();
		position = role_data["position"].get<uint32_t>();
		permissions = str_to_integer<disc_permissions_type>( role_data["permissions"].get_ref<std::string&>() );
		hoist = role_data["hoist"].get<bool>();
		managed = role_data["managed"].get<bool>();
		mentionable = role_data["mentionable"].get<bool>();

		// type null wtf???
		// https://discord.com/developers/docs/topics/permissions#role-object-role-tags-structure

		// auto tags_it = role_data.find( "tags" );
		// if ( tags_it != role_data.end() ) {
		// 	auto boost_role_it = tags_it->find( "premium_subscriber" );
		// 	if ( boost_role_it != tags_it->end() ) {
		// 		boost_role = boost_role_it->get<bool>();
		// 	}
		// }
	}

public:
	dsnowflake_t id;
	std::string name;

	uint32_t color;
	uint32_t position;
	disc_permissions_type permissions;

	bool hoist;
	bool managed;
	bool mentionable;
	// bool boost_role;
};
