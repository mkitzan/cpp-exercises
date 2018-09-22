#include <iostream>
#include <assert.h>
#include <string.h>
#include "hockey.h"
#include "player.h"
#include "team.h"
#include "league.h"
using namespace std;
using namespace Hockey;

void player_tests() {
	char oilers[] = "McDavid";
	char name[MAX_NAME_LEN];
	
	Player p(oilers, 108, CENTER);
	
	p.get_name(name);
	assert(!strncmp(name, oilers, MAX_NAME_LEN));
	cout << "Player get_name passed" << endl;
	
	assert(p.get_points() == 108);
	cout << "Player get_points passed" << endl;
	
	assert(p.get_position() == CENTER);
	cout << "Player get_position passed" << endl;
}


void team_tests() {
	char oilers[] = "Oilers";
	char p_name[] = "McDavid";
	char name[MAX_NAME_LEN];
	
	Team t(oilers);
	Player *p = new Player(p_name, 108, CENTER);
	
	t.get_name(name);
	assert(!strncmp(name, oilers, MAX_NAME_LEN));
	cout << "Team get_name passed" << endl;
	
	assert(t.get_points() == 0);
	cout << "Team get_points (empty) passed" << endl;
	
	assert(t.get_size() == 0);
	cout << "Team get_points (empty) passed" << endl;
	
	assert(!t.remove_player(p_name));
	cout << "Team remove_player (empty) passed" << endl;
	
	t.add_player(p);
	
	assert(t.get_points() == 108);
	cout << "Team get_points (!empty) passed" << endl;
	
	assert(t.get_size() == 1);
	cout << "Team get_points (!empty) passed" << endl;
	
	assert(t.remove_player(p_name));
	cout << "Team remove_player (!empty) passed" << endl;
}


void league_tests() {
	char l1[] = "NHL";
	char t1[] = "Oilers";
	char t2[] = "Flames";
	char p1[] = "McDavid";
	char p2[] = "Draisaitl";
	char p3[] = "Gaudreau";
	char p4[] = "Monahan";
	char name[MAX_NAME_LEN];
	
	Team   *team;
	League league(l1);
	
	league.get_name(name);
	assert(!strncmp(name, l1, MAX_NAME_LEN));
	cout << "League get_name passed" << endl;
	
	assert(league.get_size() == 0);
	cout << "League get_size passed" << endl;
	
	assert(league.remove_team(t1) == 0);
	cout << "League remove_team (empty) passed" << endl;
	
	team = new Team(t1);
	team->add_player(new Player(p1, 108, CENTER));
	team->add_player(new Player(p2, 70, CENTER));
	
	league.add_team(team);
	assert(league.get_size() == 1);
	
	team = new Team(t2);
	team->add_player(new Player(p3, 84, WINGER));
	team->add_player(new Player(p4, 64, CENTER));
	
	league.add_team(team);
	assert(league.get_size() == 2);
	cout << "League add_team passed" << endl;
	
	assert(league.remove_team(t1) == 1);
	cout << "League remove_team (!empty) passed" << endl;
}


int main() {
	player_tests();
	cout << endl;
	
	team_tests();
	cout << endl;
	
	league_tests();
	cout << endl;

	return 0;
}
