#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <nlohmann/json.hpp>

#include "dcache/dobjects.hpp"
#include "dcache/dobjects/channel_base.hpp"
#include "dcache/dcache.hpp"


class disc_channel_thread_t : public disc_channel_base_t {
public:
	disc_channel_thread_t()
		: disc_channel_base_t() {}

	disc_channel_thread_t( dcache_t* dcache, nlohmann::json& channel_data, disc_guild_t* parent_guild )
		: disc_channel_base_t( dcache, channel_data, parent_guild )
	{ m_update( dcache, channel_data, parent_guild ); }

public:
	void m_update( dcache_t* dcache, nlohmann::json& channel_data, disc_guild_t* parent_guild ) override;

public:
	disc_channel_text_ptr_t parent;

	bool archived;
	bool joined;
};
