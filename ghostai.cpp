#include "ghostai.h"
#include "gameobject.h"

Ghost moveGhost[4];

int state1 = 1;
int state2 = 1;
int state3 = -1;
int state4 = -1;

float ghostSpeed = 0.07f;

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	switch (state1)
	{
	case 1: 
		if (moveGhost[0].Position.X < 17.4)
			moveGhost[0].Position.X += ghostSpeed;
		else
			state1 = -1;
		break;
	case -1: 
		if (moveGhost[0].Position.X > -18.4)
			moveGhost[0].Position.X -= ghostSpeed;
		else
			state1 = 1;
		break;
	}

	switch (state2)
	{
	case 1: 
		if (moveGhost[1].Position.Y < 19.5)
			moveGhost[1].Position.Y += ghostSpeed;
		else
			state2 = -1;
		break;
	case -1: 
		if (moveGhost[1].Position.Y > -14.5)
			moveGhost[1].Position.Y -= ghostSpeed;
		else
			state2 = 1;
		break;
	}

	switch (state3)
	{
	case 1: 
		if (moveGhost[2].Position.Y < 19.5)
			moveGhost[2].Position.Y += ghostSpeed;
		else
			state3 = -1;
		break;
	case -1: 
		if (moveGhost[2].Position.Y > -14.5)
			moveGhost[2].Position.Y -= ghostSpeed;
		else
			state3 = 1;
		break;
	}

	switch (state4)
	{
	case 1: 
		if (moveGhost[3].Position.X < 17.4)
			moveGhost[3].Position.X += ghostSpeed;
		else
			state4 = -1;
		break;
	case -1: 
		if (moveGhost[3].Position.X > -18.4)
			moveGhost[3].Position.X -= ghostSpeed;
		else
			state4 = 1;
		break;
	}
}
