#pragma once
#ifndef DOBJECTS_HEADER_HPP
#define DOBJECTS_HEADER_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <map>

#include "dgateway/dtypes.hpp"


struct dguild_t;

struct drole_t;

struct dchannel_base_t;
struct dchannel_category_t;
struct dchannel_text_t;
struct dchannel_voice_t;
struct dchannel_thread_t;
struct dchannel_dm_t;
struct dchannel_group_dm_t;

struct dperm_overwrites_t;

struct dmember_t;

struct demoji_t;

struct duser_t;


struct dguild_t {
	dsnowflake_t id;
	std::string name;
	dmember_t* owner;
	std::map<dsnowflake_t, drole_t*> roles;
	std::map<dsnowflake_t, dchannel_base_t*> channels;
	std::map<dsnowflake_t, dchannel_base_t*> threads;
	std::map<dsnowflake_t, dmember_t*> members;
	std::map<dsnowflake_t, demoji_t*> emojis;
	bool unavailable;
};


struct drole_t {
	dsnowflake_t id;
	std::string name;
	uint32_t color;
	uint32_t position;
	dpermissions_type permissions;
	bool hoist;
	bool managed;
	bool mentionable;
	bool boost_role;
};


struct dchannel_base_t {
	dsnowflake_t id;
	dchannel_type type;
	dguild_t* guild;
	uint32_t position;
	std::vector<dperm_overwrites_t*> overwrites;
	std::string name;
};

struct dchannel_category_t : public dchannel_base_t {
};

struct dchannel_text_t : public dchannel_base_t {
	std::string topic;
	dchannel_category_t* parent;
	bool nsfw;
};

struct dchannel_voice_t : public dchannel_base_t {
	dchannel_category_t* parent;
	uint32_t user_limit;
};

struct dchannel_thread_t : public dchannel_base_t {
	dchannel_text_t* parent;
	bool archived;
	bool joined;
};

struct dchannel_dm_t : public dchannel_base_t {
	std::vector<duser_t*> recipients;
};

struct dchannel_group_dm_t : public dchannel_dm_t {
	dsnowflake_t owner;
};


struct dperm_overwrites_t {
	dsnowflake_t id;
	dperm_overwrites_type type;
	dpermissions_type allow;
	dpermissions_type deny;
};


struct dmember_t {
	duser_t* user;
	std::string nick;
	std::vector<drole_t*> roles;
	bool deaf;
	bool mute;
};


struct demoji_t {
	dsnowflake_t id;
	std::string name;
	bool colons;
	bool animated;
	bool available;
};

struct duser_t {
	dsnowflake_t id;
	std::string username;
	uint16_t discriminator;
	bool bot;
	bool system;
};

#endif
