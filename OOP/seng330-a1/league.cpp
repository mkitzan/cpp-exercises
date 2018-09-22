#include <iostream>
#include <string.h>
#include "league.h"
using namespace Hockey;


Hockey::League::League(char *name) {
	strncpy(this->name, name, MAX_NAME_LEN);
	this->size = 0;
}


Hockey::League::~League() {
	while(this->size)
		delete this->teams[--this->size];
}


void Hockey::League::get_name(char *container) {
	strncpy(container, this->name, MAX_NAME_LEN);
}


unsigned int Hockey::League::get_size() {
	return this->size;
}


int Hockey::League::add_team(Team *t) {
	if(this->size >= MAX_TEAMS) 
		return 0;
	
	this->teams[this->size++] = t;
	return 1;
}

int Hockey::League::remove_team(char *name) {
	unsigned int i, found = 0;
	char temp[MAX_NAME_LEN];
	
	for(i = 0; i < this->size; i++) {
		if(found) {
			this->teams[i-1]= this->teams[i];
			continue;
		} 
		
		this->teams[i]->get_name(temp);
		
		if(!strncmp(temp, name, MAX_NAME_LEN)) {
			found = 1;
			delete this->teams[i];
		}
	}
	
	if(found)
		this->size--;
	
	return found;
}
