//////Add Keyboard Input functionality to your game engine. 
//Make sure to hide the OpenGL implementation from the user.
//Add a player GameObject to your program that will move 
//when pressing the WASD keys.

#ifndef INPUT_H
#define INPUT_H

#include "vector3.h"
#include "gameengine.h"
#include "gameobject.h"


enum Keys {
	A = 97,
	B = 98,
	C = 99,
	D = 100,
	E = 101,
	F = 102,
	G = 103,
	H = 104,
	I = 105,
	J = 106,
	K = 107,
	L = 108,
	M = 109,
	N = 110,
	O = 111,
	P = 112,
	Q = 113,
	R = 114,
	S = 115,
	T = 116,
	U = 117,
	V = 118,
	W = 119,
	X = 120,
	Y = 121,
	Z = 122
};


class Input {

public:
	Keys letter;

	void isPressed(Keys letter); 

	Player setPlace;
};


extern Player dummy;   
extern GameObject getObject(Player object); 

extern bool wallhitleft, wallhitright,wallhitup,wallhitdown; 
extern bool wallhitleft1, wallhitright1, wallhitup1, wallhitdown1; //example: pag moving X axis tas colliding bawal mag press ng up or down?

extern void KeyPressed(unsigned char key, int x, int y);
extern void KeyPressedUp(unsigned char key, int x, int y);
#endif



