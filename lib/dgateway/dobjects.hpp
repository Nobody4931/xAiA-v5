#pragma once
#ifndef DOBJECTS_HEADER_HPP
#define DOBJECTS_HEADER_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <map>

#include "dgateway/dtypes.hpp"


struct disc_guild_t;

struct disc_role_t;

struct disc_channel_base_t;
struct disc_channel_category_t;
struct disc_channel_text_t;
struct disc_channel_voice_t;
struct disc_channel_thread_t;
struct disc_channel_dm_t;
struct disc_channel_groupdm_t;

struct disc_perm_overwrites_t;

struct disc_member_t;

struct disc_emoji_t;

struct disc_user_t;


struct disc_guild_t {
	dsnowflake_t id;
	std::string name;
	disc_member_t* owner;
	std::map<dsnowflake_t, disc_role_t*> roles;
	std::map<dsnowflake_t, disc_channel_base_t*> channels;
	std::map<dsnowflake_t, disc_channel_base_t*> threads;
	std::map<dsnowflake_t, disc_member_t*> members;
	std::map<dsnowflake_t, disc_emoji_t*> emojis;
	bool unavailable;
};


struct disc_role_t {
	dsnowflake_t id;
	std::string name;
	uint32_t color;
	uint32_t position;
	disc_permissions_type permissions;
	bool hoist;
	bool managed;
	bool mentionable;
	bool boost_role;
};


struct disc_channel_base_t {
	dsnowflake_t id;
	disc_channel_type type;
	disc_guild_t* guild;
	uint32_t position;
	std::vector<disc_perm_overwrites_t*> overwrites;
	std::string name;
};

struct disc_channel_category_t : public disc_channel_base_t {
};

struct disc_channel_text_t : public disc_channel_base_t {
	std::string topic;
	disc_channel_category_t* parent;
	bool nsfw;
};

struct disc_channel_voice_t : public disc_channel_base_t {
	disc_channel_category_t* parent;
	uint32_t user_limit;
};

struct disc_channel_thread_t : public disc_channel_base_t {
	disc_channel_text_t* parent;
	bool archived;
	bool joined;
};

struct disc_channel_dm_t : public disc_channel_base_t {
	std::vector<disc_user_t*> recipients;
};

struct disc_channel_groupdm_t : public disc_channel_dm_t {
	dsnowflake_t owner;
};


struct disc_perm_overwrites_t {
	dsnowflake_t id;
	disc_perm_overwrites_type type;
	disc_permissions_type allow;
	disc_permissions_type deny;
};


struct disc_member_t {
	disc_user_t* user;
	std::string nick;
	std::vector<disc_role_t*> roles;
	bool deaf;
	bool mute;
};


struct disc_emoji_t {
	dsnowflake_t id;
	std::string name;
	bool colons;
	bool animated;
	bool available;
};

struct disc_user_t {
	dsnowflake_t id;
	std::string username;
	uint16_t discriminator;
	bool bot;
	bool system;
};

#endif
