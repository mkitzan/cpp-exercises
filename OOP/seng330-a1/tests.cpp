#include <iostream>
#include <algorithm>
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
	char p1[] = "McDavid";
	char p2[] = "Draisaitl";
	char name[MAX_NAME_LEN];
	vector<Player> players;
	
	Team t(oilers);
	Player pl1(p1, 108, CENTER), pl2(p2, 70, CENTER);
	
	t.get_name(name);
	assert(!strncmp(name, oilers, MAX_NAME_LEN));
	cout << "Team get_name passed" << endl;
	
	assert(t.get_points() == 0);
	cout << "Team get_points (empty) passed" << endl;
	
	assert(t.get_size() == 0);
	cout << "Team get_points (empty) passed" << endl;
	
	assert(!t.remove_player(p1));
	cout << "Team remove_player (empty) passed" << endl;
	
	t.add_player(pl1);
	t.add_player(pl2);
	
	players = t.get_players();
	players[0].get_name(name);
	assert(!strncmp(name, p1, MAX_NAME_LEN));
	cout << "Team get_players passed" << endl;
	
	t.sort();
	
	players = t.get_players();
	players[0].get_name(name);
	assert(!strncmp(name, p2, MAX_NAME_LEN));
	cout << "Team sort passed" << endl;
	
	assert(t.get_points() == 178);
	cout << "Team get_points (!empty) passed" << endl;
	
	assert(t.get_size() == 2);
	cout << "Team get_points (!empty) passed" << endl;
	
	assert(t.remove_player(p1));
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
	
	vector<Team> teams;
	
	Team   team1(t1), team2(t2);
	Player pl1(p1, 108, CENTER), pl2(p2, 70, CENTER), pl3(p3, 84, WINGER), pl4(p4, 64, CENTER);
	League league(l1);
	
	league.get_name(name);
	assert(!strncmp(name, l1, MAX_NAME_LEN));
	cout << "League get_name passed" << endl;
	
	assert(league.get_size() == 0);
	cout << "League get_size passed" << endl;
	
	assert(league.remove_team(t1) == 0);
	cout << "League remove_team (empty) passed" << endl;
	
	team1.add_player(pl1);
	team1.add_player(pl2);
	
	league.add_team(team1);
	assert(league.get_size() == 1);
	
	team2.add_player(pl3);
	team2.add_player(pl4);
	
	league.add_team(team2);
	assert(league.get_size() == 2);
	
	teams = league.get_teams();
	teams[0].get_name(name);
	assert(!strncmp(name, t1, MAX_NAME_LEN));
	cout << "League get_teams passed" << endl;
	
	league.sort();
	
	teams = league.get_teams();
	teams[0].get_name(name);
	assert(!strncmp(name, t2, MAX_NAME_LEN));
	cout << "League sort passed" << endl;
	
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
