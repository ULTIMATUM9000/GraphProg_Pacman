#include "input.h"
#include "gameobject.h"

bool wallhitleft =false, wallhitright=false, wallhitup=false, wallhitdown=false;

Player dummy ;

float speed = 3.5f; //speed of the movement


void Input::isPressed(Keys letter) //this is double check?
{

	if (letter == Keys::D)
	{
		dummy.Velocity.Y = dummy.Direction.Y * 0.0f; //kapag moving ng Y axis, pag press ng D, titigil ung movement ng Y axis
		wallhitright = true; wallhitleft = false; wallhitup = false; wallhitdown = false;
		dummy.isMoving = true;
		dummy.Direction = Vector3(speed, 0.0f, 0.0f);
		dummy.Acceleration = dummy.Direction;
		getObject(dummy);
	}

	else if (letter == Keys::S)
	{
		dummy.Velocity.X = dummy.Direction.X * 0.0f;
		wallhitdown = true; wallhitleft = false; wallhitup = false; wallhitright = false;
		dummy.isMoving = true;
		dummy.Direction = Vector3(0.0f, -speed, 0.0f);
		dummy.Acceleration = dummy.Direction;
		getObject(dummy);
	}

	else if (letter == Keys::A)
	{
		dummy.Velocity.Y = dummy.Direction.Y * 0.0f;
		wallhitleft = true;	wallhitup = false; wallhitdown = false; wallhitright = false;
		dummy.isMoving = true;
		dummy.Direction = Vector3(-speed, 0.0f, 0.0f);
		dummy.Acceleration = dummy.Direction;
		getObject(dummy);
	}

	else if (letter == Keys::W)
	{
		dummy.Velocity.X = dummy.Direction.X * 0.0f;
		wallhitup = true;  wallhitleft = false; wallhitdown = false; wallhitright = false;
		dummy.isMoving = true;
		dummy.Direction = Vector3(0.0f, speed, 0.0f);
		dummy.Acceleration = dummy.Direction;
		getObject(dummy);
	}


}

GameObject getObject(Player object)
{
	dummy = object;
	return dummy;
}



void KeyPressed(unsigned char key, int x, int y)
{
	Input key1, key2, key3, key4; //each has x, y, and letter

	if (key == 100) //D = 100,
	{
		key1.letter = static_cast<Keys>(key); // this is equal to 100 //correct 
		key1.isPressed(key1.letter); // pass 100 to checker
	}

	if (key == 97) //A = 97,
	{
		key2.letter = static_cast<Keys>(key); //make 'char key' into 'enum Keys' tas ipasa sa 'Input obj.letter'
		key2.isPressed(key2.letter);
	}

	if (key == 119) //W = 119,
	{
		key3.letter = static_cast<Keys>(key);
		key3.isPressed(key3.letter);
	}

	if (key == 115) //S = 115,
	{
		key4.letter = static_cast<Keys>(key);
		key4.isPressed(key4.letter);
	}
}


void KeyPressedUp(unsigned char key, int x, int y)
{
		
	switch (key) {
	case 100: //D
		
		break;
	case 97: //A
	
		break;

	case 119: //W
		
		break;

	case 115: //S
		
		break;
	}
}


