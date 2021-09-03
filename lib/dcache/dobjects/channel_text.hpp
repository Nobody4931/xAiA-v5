#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <string>

#include <nlohmann/json.hpp>

#include "dcache/dobjects.hpp"
#include "dcache/dobjects/channel_base.hpp"


class disc_channel_text_t : public disc_channel_base_t {
public:
	disc_channel_text_t()
		: disc_channel_base_t()
		, nsfw( false ) {}

	disc_channel_text_t( nlohmann::json& channel_data, disc_guild_ptr_t parent )
		: disc_channel_base_t( channel_data, parent )
	{
		// TODO: This
	}

public:
	std::string topic;
	disc_channel_category_ptr_t parent;
	bool nsfw;
};
