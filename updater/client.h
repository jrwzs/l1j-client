#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "sdl_user.h"
#include "config.h"
#include "connection.h"
#include "table.h"
#include "pack.h"

#define TRANSFER_AMOUNT 0x400

int run_client(void *moron);

class client
{
	public:
		client(sdl_user *stuff);
		~client();
		void init();
		
		//unsorted public functions
		void LoadDurationTable(const char *file);
		void init_codepage(unsigned long arg);
		
	private:
		sdl_user *graphics;
		config *main_config;
		connection *server;
		unsigned long checksum;
		pack *textpack;
		pack *tilepack;
		pack **spritepack;
		int num_sprite_pack;
		table bad_words;
		table strings;
		table teleport;
		table un_transaction;
		table important_items;
		table pet;
		table solvent;
		table todays_tip;
		
		int acp[2];	//-1, 0xec8a0 (a function pointer to badwords compare?)
		unsigned long serverId;	//0
		unsigned char countryCode;
		

		int get_updates(connection* server);
		int pack_resources();
		int init_packs();
		int init_strings();
		
		//unsorted functions
		void init_math_tables();
		int getNumber(char **buf);
};

#endif