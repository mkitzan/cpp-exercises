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
		Team *teams[MAX_TEAMS];
		
	public:
		League(char *name);
		~League();
		
		void		 get_name(char *container);
		unsigned int get_size();
		
		bool add_team(Team *t);
		bool remove_team(char *name);
	};
}

#endif
