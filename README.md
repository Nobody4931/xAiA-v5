# xAiA v5
my custom discord selfbot - because i hate a certain
whitespace based language

## features
- [ ] custom rich presence
- [ ] nitro sniper
- [ ] giveaway notifier
- [ ] custom commands
	- [ ] read/readall
	- [ ] blocksend

## todo
- [x] create http request wrappers
- [x] create gateway client
	- [x] create super properties generator
	- [x] create gateway handler
- [ ] create client cache
	- [x] create discord type enums
	- [ ] create discord object structures
	- [ ] create event listeners

## configuration
if you cloned this repository off git, there would
be a missing header file in the `lib` directory named
`config.hpp` \
create it yourself and define these macros inside it

* PROGRAM_NAME - the program name
* PROGRAM_VERS - the program version
* CFG_TOKEN - your discord token
* CFG_DAPI_VERS_API - discord api version to use ["9"]
* CFG_DAPI_VERS_GATE - discord gateway version to use ["9"]
* CFG_DAPI_HOSTNAME - discord hostname to use ["discord.com"]
* CFG_DAPI_PORT - discord port to use ["443"]
* CFG_DAPI_AGENT - user agent to use (use [this site](https://www.whatismybrowser.com/guides/the-latest-user-agent/))
* CFG_DAPI_AGENT_OS - user agent details (use [this site](https://developers.whatismybrowser.com/useragents/parse/))
* CFG_DAPI_AGENT_OS_VERSION - user agent details (use [this site](https://developers.whatismybrowser.com/useragents/parse/))
* CFG_DAPI_AGENT_BROWSER - user agent details (use [this site](https://developers.whatismybrowser.com/useragents/parse/))
* CFG_DAPI_AGENT_BROWSER_VERSION - user agent details (use [this site](https://developers.whatismybrowser.com/useragents/parse/))
* CFG_DAPI_LOCALE - locale to use ["en-US"]

## not really faq

### isnt this against the discord tos
yes - which is why this is a private repository \
also this project uses the undocumented user account
gateway instead of the bot gateway \
as a [wise diety](https://www.youtube.com/watch?v=l_Dz3TRNdbY)
once said, "its not a crime if you dont get caught"

### arent there tons of other selfbot tools out there
no those are all just rats lol \
or they use some completely outdated bot account gateway
