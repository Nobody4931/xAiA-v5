#pragma once


class dcache_t;

#ifndef DCACHE_DECLARATION_ONLY

#include <map>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"

class dcache_t {
public:
	inline disc_user_ptr_t get_user( dsnowflake_t id ) {
		auto user_it = m_users.find( id );
		if ( user_it == m_users.end() )
			return disc_user_ptr_t();
		return user_it->second;
	}

	inline disc_guild_ptr_t get_guild( dsnowflake_t id ) {
		auto guild_it = m_guilds.find( id );
		if ( guild_it == m_guilds.end() )
			return disc_guild_ptr_t();
		return guild_it->second;
	}

	// TODO: Get or create methods?

	// TODO: Cache methods

public:
	inline disc_user_ptr_t get_client() { return m_client; }
	inline std::map<dsnowflake_t, disc_user_ptr_t>& get_users() { return m_users; }
	inline std::map<dsnowflake_t, disc_guild_ptr_t>& get_guilds() { return m_guilds; }

private:
	disc_user_ptr_t m_client;
	std::map<dsnowflake_t, disc_user_ptr_t> m_users;
	std::map<dsnowflake_t, disc_guild_ptr_t> m_guilds;
};

#endif // DCACHE_DECLARATION_ONLY
