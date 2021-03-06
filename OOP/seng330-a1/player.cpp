#include <string.h>
#include "player.h"
using namespace Hockey;


Hockey::Player::Player(char *name, unsigned int points, Role position) {
	strncpy(this->name, name, MAX_NAME_LEN);
	this->points = points;
	this->position = position;
}


Hockey::Player::Player(const Player &p) : points(p.points), position(p.position) {
	strncpy(this->name, p.name, MAX_NAME_LEN);
}


void Hockey::Player::get_name(char *container) {
	strncpy(container, this->name, MAX_NAME_LEN);
}


unsigned int Hockey::Player::get_points() {
	return this->points;
}


Role Hockey::Player::get_position() {
	return this->position;
}


void Hockey::Player::set_points(unsigned int points) {
	this->points = points;
}


void Hockey::Player::add_points(unsigned int points) {
	this->points += points;
}


void Hockey::Player::reset_points() {
	this->points = 0;
}


bool Hockey::Player::operator<(Player p) {
	return this->get_points() < p.get_points();
}
