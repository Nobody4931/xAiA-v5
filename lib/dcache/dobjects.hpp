#pragma once


#include <memory>


class disc_guild_t;

class disc_role_t;

class disc_channel_base_t;
class disc_channel_category_t;
class disc_channel_text_t;
class disc_channel_voice_t;
class disc_channel_dm_t;
class disc_channel_groupdm_t;
class disc_channel_thread_t;
class disc_channel_overwrites_t;

class disc_member_t;

class disc_emoji_t;

class disc_user_t;


typedef std::shared_ptr<disc_guild_t>              disc_guild_ptr_t;

typedef std::shared_ptr<disc_role_t>               disc_role_ptr_t;

typedef std::shared_ptr<disc_channel_base_t>       disc_channel_base_ptr_t;
typedef std::shared_ptr<disc_channel_category_t>   disc_channel_category_ptr_t;
typedef std::shared_ptr<disc_channel_text_t>       disc_channel_text_ptr_t;
typedef std::shared_ptr<disc_channel_voice_t>      disc_channel_voice_ptr_t;
typedef std::shared_ptr<disc_channel_dm_t>         disc_channel_dm_ptr_t;
typedef std::shared_ptr<disc_channel_groupdm_t>    disc_channel_groupdm_ptr_t;
typedef std::shared_ptr<disc_channel_thread_t>     disc_channel_thread_ptr_t;
typedef std::shared_ptr<disc_channel_overwrites_t> disc_channel_overwrites_ptr_t;

typedef std::shared_ptr<disc_member_t>             disc_member_ptr_t;

typedef std::shared_ptr<disc_emoji_t>              disc_emoji_ptr_t;

typedef std::shared_ptr<disc_user_t>               disc_user_ptr_t;


#ifndef DOBJECTS_DECLARATIONS_ONLY

#include "dcache/dobjects/guild.hpp"
#include "dcache/dobjects/role.hpp"
#include "dcache/dobjects/channel_base.hpp"
#include "dcache/dobjects/channel_category.hpp"
#include "dcache/dobjects/channel_text.hpp"
#include "dcache/dobjects/channel_voice.hpp"
#include "dcache/dobjects/channel_dm.hpp"
#include "dcache/dobjects/channel_groupdm.hpp"
#include "dcache/dobjects/channel_thread.hpp"

#endif // DOBJECTS_DECLARATIONS_ONLY
