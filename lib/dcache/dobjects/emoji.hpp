#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <string>

#include <nlohmann/json.hpp>

#include "dcache/dobjects.hpp"
#include "dcache/dtypes.hpp"


class disc_emoji_t {
public:
	disc_emoji_t()
		: id( 0 ) {}

	disc_emoji_t( nlohmann::json& emoji_data, disc_guild_ptr_t parent_guild ) {
		// TODO: This
	}

public:
	dsnowflake_t id;
	std::string name;

	bool colons;
	bool animated;
	bool available;
};
