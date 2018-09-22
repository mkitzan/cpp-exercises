#ifndef TEAM
#define TEAM

#include "hockey.h"
#include "player.h"

namespace Hockey {
	class Team {
	private:
		char         name[MAX_NAME_LEN];
		unsigned int size;
		
	protected:
		Player *players[MAX_PLAYERS];
		
	public:
		Team(char *name);
		~Team();
		
		void		 get_name(char *container);
		unsigned int get_points();
		unsigned int get_size();
		
		int add_player(Player *p);
		int remove_player(char *name);
	};
}

#endif
