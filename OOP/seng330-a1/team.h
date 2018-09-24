#ifndef TEAM
#define TEAM

#include <vector>
#include "hockey.h"
#include "player.h"

namespace Hockey {
	class Team {
	private:
		char name[MAX_NAME_LEN];
		std::vector<Player> players;
		
	public:
		Team(char *name);
		Team(const Team &t);
		~Team();
		
		void		 get_name(char *container);
		unsigned int get_points();
		unsigned int get_size();
		std::vector<Player> get_players();
		
		bool add_player(Player p);
		bool remove_player(char *name);
		
		void sort();
		
		bool operator<(Team t);
	};
}

#endif
