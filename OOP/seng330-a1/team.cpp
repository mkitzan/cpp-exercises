#include <string.h>
#include <iostream>
#include "team.h"
using namespace std;
using namespace Hockey;


Hockey::Team::Team(char *name) {
	strncpy(this->name, name, MAX_NAME_LEN);
	this->size = 0;
}

Hockey::Team::~Team() {
	while(this->size)
		delete this->players[--this->size];
}


void Hockey::Team::get_name(char *container) {
	strncpy(container, this->name, MAX_NAME_LEN);
}


unsigned int Hockey::Team::get_points() {
	unsigned int i, sum = 0;
	
	for(i = 0; i < this->size; i++)
		sum += this->players[i]->get_points();
	
	return sum;
}

unsigned int Hockey::Team::get_size() {
	return this->size;
}


int Hockey::Team::add_player(Player *p) {
	if(this->size >= MAX_PLAYERS) 
		return 0;
	
	this->players[this->size++] = p;
	return 1;
}


int Hockey::Team::remove_player(char *name) {
	unsigned int i, found = 0;
	char temp[MAX_NAME_LEN];
	
	for(i = 0; i < this->size; i++) {
		if(found) {
			this->players[i-1] = this->players[i];
			continue;
		} 
		
		this->players[i]->get_name(temp);
		
		if(!strncmp(temp, name, MAX_NAME_LEN)) {
			found = 1;
			delete this->players[i];
		}
	}
	
	if(found)
		this->size--;
	
	return found;
}
