#include <iostream>
#include <string.h>
#include "league.h"
using namespace Hockey;

Hockey::League::League() {}


Hockey::League::League(char *name) {
	strncpy(this->name, name, MAX_NAME_LEN);
	this->size = 0;
}


void Hockey::League::copy(League l) {
	unsigned int i;
	
	for(i = 0; i < this->size; i++)
		this->teams[i].copy(l.teams[i]);
	
	l.get_name(this->name);
	this->size = l.get_size();
}


void Hockey::League::get_name(char *container) {
	strncpy(container, this->name, MAX_NAME_LEN);
}


unsigned int Hockey::League::get_size() {
	return this->size;
}


int Hockey::League::add_team(Team t) {
	if(this->size >= MAX_TEAMS) return 0;
	
	this->teams[this->size++].copy(t);
	return 1;
}

int Hockey::League::remove_team(char *name) {
	unsigned int i, found = 0;
	char temp[MAX_NAME_LEN];
	
	for(i = 0; i < this->size; i++) {
		if(found) {
			this->teams[i-1].copy(this->teams[i]);
			continue;
		} 
		
		this->teams[i].get_name(temp);
		
		if(!strncmp(temp, name, MAX_NAME_LEN)) {
			found = 1;
			this->size--;
		}
	}
	
	return found;
}
