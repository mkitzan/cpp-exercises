#ifndef PLAYER
#define PLAYER

#include "hockey.h"

namespace Hockey {
	class Player {
	private:
		char         name[MAX_NAME_LEN];
		unsigned int points;
		Role         position;
		
	public:
		Player(char *name, unsigned int points, Role position);
		Player(const Player &p);
		
		void		 get_name(char *container);
		unsigned int get_points();
		Role		 get_position();
		
		void set_points(unsigned int points);
		void add_points(unsigned int points);
		void reset_points();
		
		bool operator<(Player p);
	};
}

#endif
