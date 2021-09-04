#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <memory>
#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dobjects/role.hpp"
#include "dcache/dobjects/member.hpp"


class disc_guild_t {
public:
	disc_guild_t()
		: id( 0 ) {}

	disc_guild_t( nlohmann::json& guild_data )
		: id( str_to_integer<dsnowflake_t>( guild_data["id"].get_ref<std::string&>() ) )
	{ m_update( guild_data ); }

public:
	// was going to toss this into a source file but it was
	// originally supposed to be the constructor so nah
	inline void m_update( nlohmann::json& guild_data ) {
		// Update roles
		for ( nlohmann::json& role_data : guild_data["roles"] ) {
			auto role_id = str_to_integer<dsnowflake_t>( role_data["id"].get_ref<std::string&>() );
			auto role_it = roles.find( role_id );

			if ( role_it == roles.end() ) {
				roles[ role_id ] = std::make_shared<disc_role_t>( role_data, this );
			} else role_it->second->m_update( role_data, this );
		}

		// TODO: Update channels
		// TODO: Update threads

		// Update members
		auto members_it = guild_data.find( "members" );
		if ( members_it != guild_data.end() ) {
			for ( nlohmann::json& member_data : members_it.value() ) {
				auto member_id = str_to_integer<dsnowflake_t>( member_data["id"].get_ref<std::string&>() );
				auto member_it = members.find( member_id );

				if ( member_it == members.end() ) {
					members[ member_id ] = std::make_shared<disc_member_t>( member_data, this );
				} else member_it->second->m_update( member_data, this );
			}
		}

		// TODO: Update emojis

		// Update primitive fields
		name = guild_data["name"].get<std::string>();

		auto unavailable_it = guild_data.find( "unavailable" );
		unavailable = unavailable_it != guild_data.end() ? unavailable_it->get<bool>() : false;

		auto owner_it = members.find( str_to_integer<dsnowflake_t>( guild_data["owner_id"].get_ref<std::string&>() ) );
		if ( owner_it != members.end() ) {
			owner = owner_it->second;
		}

		// TODO: Force load owner if not found?
		// - For large guilds with like 1000+ members
		// - Probably not, doubt I'll ever even talk in those servers, much less handle commands there
	}

public:
	dsnowflake_t id;
	std::string name;

	disc_member_ptr_t owner;

	std::map<dsnowflake_t, disc_role_ptr_t> roles;
	std::map<dsnowflake_t, disc_channel_base_ptr_t> channels;
	std::map<dsnowflake_t, disc_channel_base_ptr_t> threads;
	std::map<dsnowflake_t, disc_member_ptr_t> members;
	std::map<dsnowflake_t, disc_emoji_ptr_t> emojis;

	bool unavailable;
};
