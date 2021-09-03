#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <map>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"
#include "dcache/dobjects/channel_base.hpp"


class disc_channel_dm_t : public disc_channel_base_t {
public:
	disc_channel_dm_t()
		: disc_channel_base_t() {}

	disc_channel_dm_t( nlohmann::json& channel_data, disc_guild_ptr_t parent )
		: disc_channel_base_t( channel_data, parent )
	{
		// TODO: This
	}

public:
	std::map<dsnowflake_t, disc_user_ptr_t> recipients;
};
