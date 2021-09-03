#pragma once


#define DOBJECTS_DECLARATIONS_ONLY

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "dcache/dtypes.hpp"


class disc_user_t {
public:
	disc_user_t()
		: id( 0 ) {}

	disc_user_t( nlohmann::json& user_data ) {
		// TODO: This
	}

public:
	dsnowflake_t id;
	std::string username;
	uint16_t discriminator;

	bool bot;
	bool system;
};
