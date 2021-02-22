/*
 * ZooClass.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 1920202_snhu
 */

using namespace std;

#include "ZooClass.h"


Crocodile::Crocodile(int code, string name, int eggs){
	this->code = code;
	this->name = name;
	this->numberOfEggs = eggs;
	this->type = "Oviparous";
	this->subType = "Crocodile";
	this->nurse = 0;
}

Goose::Goose(int code, string name, int eggs){
	this->code = code;
	this->name = name;
	this->numberOfEggs = eggs;
	this->type = "Oviparous";
	this->subType = "Goose";
	this->nurse = 0;
}

Pelican::Pelican(int code, string name, int eggs){
	this->code = code;
	this->name = name;
	this->numberOfEggs = eggs;
	this->type = "Oviparous";
	this->subType = "Pelican";
	this->nurse = 0;
}

Bat::Bat(int code, string name, int nurse) {
	this->code = code;
	this->name = name;
	this->nurse = nurse;
	this->type = "Mammal";
	this->subType = "Bat";
	this->numberOfEggs = 0;
}

Whale::Whale(int code, string name, int nurse) {
	this->code = code;
	this->name = name;
	this->nurse = nurse;
	this->type = "Mammal";
	this->subType = "Whale";
	this->numberOfEggs = 0;
}

SeaLion::SeaLion(int code, string name, int nurse) {
	this->code = code;
	this->name = name;
	this->nurse = nurse;
	this->type = "Mammal";
	this->subType = "SeaLion";
	this->numberOfEggs = 0;
}
