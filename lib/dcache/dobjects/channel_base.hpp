#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <cstdint>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"


class disc_channel_base_t {
public:
	disc_channel_base_t()
		: id( 0 ) {}

	disc_channel_base_t( nlohmann::json& channel_data, disc_guild_ptr_t parent_guild ) {
		// TODO: This
	}

public:
	dsnowflake_t id;
	std::string name;

	uint32_t position;
	disc_channel_type type;
	disc_guild_ptr_t guild;
	std::vector<disc_channel_overwrites_ptr_t> overwrites;
};
