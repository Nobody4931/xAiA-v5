#pragma once


#define DOBJECTS_DECLARATIONS_ONLY
#define DCACHE_DECLARATION_ONLY

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

#include "util/str2num.hpp"
#include "dcache/dtypes.hpp"
#include "dcache/dobjects.hpp"


class disc_channel_overwrites_t {
public:
	disc_channel_overwrites_t()
		: id( 0 ) {}

	disc_channel_overwrites_t( nlohmann::json& overwrites_data )
		: id( str_to_int<dsnowflake_t>( overwrites_data["id"].get_ref<std::string&>() ) )
		, type( overwrites_data["type"].get<disc_channel_overwrites_type>() )
		, allow( static_cast<disc_permissions_type>(
			str_to_int<uint64_t>( overwrites_data["allow"].get_ref<std::string&>() ) ) )
		, deny( static_cast<disc_permissions_type>(
			str_to_int<uint64_t>( overwrites_data["allow"].get_ref<std::string&>() ) ) )
	{}

public:
	dsnowflake_t id;
	disc_channel_overwrites_type type;
	disc_permissions_type allow;
	disc_permissions_type deny;
};
