#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <nlohmann/json.hpp>

#include "dcache/dobjects.hpp"
#include "dcache/dobjects/channel_dm.hpp"


class disc_channel_groupdm_t : public disc_channel_dm_t {
public:
	disc_channel_groupdm_t()
		: disc_channel_dm_t() {}

	disc_channel_groupdm_t( nlohmann::json& channel_data, disc_guild_ptr_t parent_guild )
		: disc_channel_dm_t( channel_data, parent_guild )
	{
		// TODO: This
	}

public:
	disc_user_ptr_t owner;
};
