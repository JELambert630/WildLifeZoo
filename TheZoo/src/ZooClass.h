/*
 * ZooClass.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1920202_snhu
 */

#ifndef ZOOCLASS_H_
#define ZOOCLASS_H_
using namespace std;
#include <iostream>

class Animal {
public:
	string name;
	int code;
	string type;
	string subType;
	int numberOfEggs;
	int nurse;
};

class Oviparous : public Animal {
public:

};

class Mammal : public Animal{
public:

};



class Crocodile : public Oviparous {
public:
	Crocodile(int, string, int);
};

class Goose : public Oviparous {
public:
	Goose(int, string, int);
};

class Pelican : public Oviparous {
public:
	Pelican(int, string, int);
};



class Bat : public Mammal {
public:
	Bat(int, string, int);
};

class Whale : public Mammal {
public:
	Whale(int, string, int);
};

class SeaLion : public Mammal {
public:
	SeaLion(int, string, int);
};


#endif /* ZOOCLASS_H_ */
