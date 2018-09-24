#ifndef LEAGUE
#define LEAGUE

#include "hockey.h"
#include "team.h"

namespace Hockey {
	class League {
	private:
		char name[MAX_NAME_LEN];
		std::vector<Team> teams;
		
	public:
		League(char *name);
		~League();
		
		void		 get_name(char *container);
		unsigned int get_size();
		std::vector<Team> get_teams();
		
		bool add_team(Team t);
		bool remove_team(char *name);
		
		void sort();
	};
}

#endif
