// TODO: Honestly the much better way of doing this could've been
// to just make all those disc_*_t's be classes and have the
// constructor/destructor handle everything for me instead... lol

// TODO:
// - Make dcache into a separate static library
// - Make a dobjects folder and for each one make a separate header file
// - Make a bundle dobjects.hpp file
// - Make all dobjects be classes, and have their constructor be the
//   equivalent of their dcache_t::cache() function

#pragma once
#ifndef DCACHE_HEADER_HPP
#define DCACHE_HEADER_HPP

#include <memory>
#include <map>

#include <nlohmann/json.hpp>

#include "dgateway/dtypes.hpp"
#include "dgateway/dobjects.hpp"

class dcache_t {
public:
	// TODO: Literally all of these
	std::shared_ptr<disc_guild_t> cache_guild( nlohmann::json& guild_data );
	std::shared_ptr<disc_user_t> cache_user( nlohmann::json& user_data );

	std::shared_ptr<disc_role_t> cache_role( nlohmann::json& role_data, std::shared_ptr<disc_guild_t> parent );
	std::shared_ptr<disc_channel_base_t> cache_channel( nlohmann::json& channel_data, std::shared_ptr<disc_guild_t> parent );
	std::shared_ptr<disc_member_t> cache_member( nlohmann::json& member_data, std::shared_ptr<disc_guild_t> parent );
	std::shared_ptr<disc_emoji_t> cache_emoji( nlohmann::json& emoji_data, std::shared_ptr<disc_guild_t> parent );

public:
	inline std::map<dsnowflake_t, std::shared_ptr<disc_guild_t>>& get_guilds() { return m_guilds; }
	inline std::map<dsnowflake_t, std::shared_ptr<disc_user_t>>& get_users() { return m_users; }

	inline std::shared_ptr<disc_guild_t> get_guild( dsnowflake_t id ) {
		auto guild_it = m_guilds.find( id );
		if ( guild_it == m_guilds.end() )
			return nullptr;
		return guild_it->second;
	}

	inline std::shared_ptr<disc_user_t> get_user( dsnowflake_t id ) {
		auto user_it = m_users.find( id );
		if ( user_it == m_users.end() )
			return nullptr;
		return user_it->second;
	}

private:
	std::map<dsnowflake_t, std::shared_ptr<disc_guild_t>> m_guilds;
	std::map<dsnowflake_t, std::shared_ptr<disc_user_t>> m_users;
};

#endif
