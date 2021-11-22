#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glut.h>
#include "vector3.h"


class GameObject {
private:

	Vector3 Position; 	             //position
	Vector3 Scaling;                 //scale
	float xRot, yRot, zRot, angle; 	 //rotation
	float r, g, b, a; 	             //color


public:
	GameObject(); //constructor

	GameObject(Vector3 Position, Vector3 Scaling, float xRot, float yRot, float zRot, float angle, float r, float g, float b, float a);

	~GameObject(); //decontructor



	void Translate(Vector3 Position);
	void Rotate(float x, float y, float z, float angle);
	void Scale(Vector3 Scale);
	void SetColor(float r, float g, float b, float a);

	 bool CheckCollision(GameObject test); //colission
	
	static void RenderCollision(GameObject test);
    static bool HittingCollision(bool x);

	void RenderCube();
    void RenderGrid();
	void RenderPellet();
};

class Barrier : public GameObject { 
public:
	Vector3 Position;
};


class Food : public GameObject { 
public:
	Vector3 Position;
};

class Player : public GameObject { //inherit para maaccess ung position tas dagdag narin bagong data na available lang kay class Player
public:
	Vector3 Position, Velocity, Acceleration, Direction;
	bool isMoving;
};

class Ghost : public GameObject { //inherit para maaccess ung position tas dagdag narin bagong data na available lang kay class Player
public:
	Vector3 Position, Velocity, Acceleration, Direction;
	bool isMoving;
};

#endif
