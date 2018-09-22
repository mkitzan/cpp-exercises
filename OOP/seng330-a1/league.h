#ifndef LEAGUE
#define LEAGUE

#include "hockey.h"
#include "team.h"

namespace Hockey {
	class League {
	private:
		char         name[MAX_NAME_LEN];
		unsigned int size;
		
	protected:
		Team teams[MAX_TEAMS];
		
	public:
		League();
		League(char *name);
		
		void copy(League l);
		
		void		 get_name(char *container);
		unsigned int get_size();
		
		int add_team(Team t);
		int remove_team(char *name);
	};
}

#endif
