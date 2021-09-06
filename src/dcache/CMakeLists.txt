add_library(dcache STATIC
	"dobjects/guild.cpp"
	"dobjects/role.cpp"
	# "dobjects/channel_base.cpp"
	# "dobjects/channel_category.cpp"
	# "dobjects/channel_text.cpp"
	# "dobjects/channel_voice.cpp"
	# "dobjects/channel_dm.cpp"
	# "dobjects/channel_groupdm.cpp"
	# "dobjects/channel_thread.cpp"
	# "dobjects/member.cpp"
	# "dobjects/emoji.cpp"
	# "dobjects/user.cpp"
)

target_include_directories(dcache PRIVATE
	"${PROJECT_LIB_FOLDER}")

target_link_libraries(dcache PUBLIC
	${REQUIRED_LIBS})
target_include_directories(dcache PUBLIC
	${REQUIRED_INCS})
