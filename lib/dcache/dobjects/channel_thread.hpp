#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <nlohmann/json.hpp>

#include "dcache/dobjects.hpp"
#include "dcache/dobjects/channel_base.hpp"


class disc_channel_thread_t : public disc_channel_base_t {
public:
	disc_channel_thread_t()
		: disc_channel_base_t() {}

	disc_channel_thread_t( nlohmann::json& channel_data, disc_guild_ptr_t parent_guild )
		: disc_channel_base_t( channel_data, parent_guild )
	{
		// TODO: This
	}

public:
	disc_channel_text_ptr_t parent;

	bool archived;
	bool joined;
};
