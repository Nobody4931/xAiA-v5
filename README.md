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
- [ ] create http request wrappers
- [ ] create gateway client
	- [ ] create client context structure
	- [ ] create discord type enums
	- [ ] create discord object structures
	- [ ] create gateway handler
- [ ] create client cache
	- [ ] create event listeners

## configuration
if you cloned this repository off git, there would
be a missing header file in the `lib` directory named
`config.hpp` \
create it yourself and define these macros inside it

* PROGRAM_NAME - the program name
* PROGRAM_VERS - the program version
* PROGRAM_FNAME - the programs full name (aka the name
  concatenated with the version)
* CFG_TOKEN - your discord token

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
