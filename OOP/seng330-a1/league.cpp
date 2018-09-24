#include <iostream>
#include <algorithm>
#include <string.h>
#include "league.h"
using namespace std;
using namespace Hockey;


Hockey::League::League(char *name) {
	strncpy(this->name, name, MAX_NAME_LEN);
}


Hockey::League::~League() {
	this->teams.clear();
}


void Hockey::League::get_name(char *container) {
	strncpy(container, this->name, MAX_NAME_LEN);
}


unsigned int Hockey::League::get_size() {
	return this->teams.size();
}


vector<Team> Hockey::League::get_teams() {
	vector<Team> copy(this->teams);
	return copy; //stackoverflow says this is kosher, idk
}


bool Hockey::League::add_team(Team t) {
	if(this->teams.size() >= MAX_TEAMS) 
		return false;
	
	this->teams.push_back(t);
	return true;
}


bool Hockey::League::remove_team(char *name) {
	unsigned int i;
	bool found = false;
	char temp[MAX_NAME_LEN];
	
	for(i = 0; i < this->teams.size(); i++) {
		this->teams[i].get_name(temp);
		
		if(!strncmp(temp, name, MAX_NAME_LEN)) {
			found = true;
			this->teams.erase(this->teams.begin()+i);
			break;
		}
	}
	
	return found;
}


void Hockey::League::sort() {
	std::sort(this->teams.begin(), this->teams.end());
}
