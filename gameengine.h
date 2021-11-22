
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <glut.h>  // start 
#include <iostream>
#include "gameobject.h"



void Initialize(); //Function will be called once at the beginning of our program  //gets defined at MAIN.cpp
void UpdateWalls();
void UpdatePellet();
void Update(); //This function will be called inside the render loop          //gets defined at MAIN.cpp //
void PrepareEngine(int* argc, char** argv); 

void CheckTranslate();
void CheckDeath();
void CheckGhostCollision();
void CheckPelletCollision();
void CheckPowerPelletTimer();
void CheckWallCollision();
void CheckOutOfBounds();

#endif
