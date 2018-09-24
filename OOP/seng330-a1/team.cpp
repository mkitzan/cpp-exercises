#include <iostream>
#include <algorithm>
#include <string.h>
#include "team.h"
using namespace std;
using namespace Hockey;


Hockey::Team::Team(char *name) {
	strncpy(this->name, name, MAX_NAME_LEN);
}


Hockey::Team::Team(const Team &t) {
	strncpy(this->name, t.name, MAX_NAME_LEN);
	this->players = vector<Player>(t.players);
}


Hockey::Team::~Team() {
	this->players.clear();
}


void Hockey::Team::get_name(char *container) {
	strncpy(container, this->name, MAX_NAME_LEN);
}


unsigned int Hockey::Team::get_points() {
	unsigned int i, sum = 0;
	
	for(i = 0; i < this->players.size(); i++)
		sum += this->players[i].get_points();
	
	return sum;
}


unsigned int Hockey::Team::get_size() {
	return this->players.size();
}


vector<Player> Hockey::Team::get_players() {
	vector<Player> copy(this->players);
	return copy; //stackoverflow says this is kosher, idk
}


bool Hockey::Team::add_player(Player p) {
	if(this->players.size() >= MAX_PLAYERS) 
		return false;
	
	this->players.push_back(p);
	return true;
}


bool Hockey::Team::remove_player(char *name) {
	unsigned int i;
	bool found = false;
	char temp[MAX_NAME_LEN];
	
	for(i = 0; i < this->players.size(); i++) {
		this->players[i].get_name(temp);
		
		if(!strncmp(temp, name, MAX_NAME_LEN)) {
			found = true;
			this->players.erase(this->players.begin()+i);
			break;
		}
	}
	
	return found;
}


void Hockey::Team::sort() {
	std::sort(this->players.begin(), this->players.end());
}


bool Hockey::Team::operator<(Team t) {
	return this->get_points() < t.get_points();
}
