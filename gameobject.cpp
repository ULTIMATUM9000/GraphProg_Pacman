#include "gameobject.h"
#include <iostream>

#pragma region CONSTRUCTORS

GameObject::GameObject() {
	Position.X = 0; Position.Y = 0; Position.Z = 0;
	xRot = 0; yRot = 0; zRot = 0; angle = 0;
	Scaling.X = 1; Scaling.Y = 1; Scaling.Z = 1;
	r = 1.0f; g = 1.0f; b = 1.0f; a = 1.0f;

}

GameObject::GameObject(Vector3 position, Vector3 Scale, float xRot, float yRot, float zRot, float angle, float r, float g, float b, float a) {
	this->Position.X = Position.X;
	this->Position.Y = Position.Y;
	this->Position.Z = Position.Z;
	this->xRot = xRot;
	this->yRot = yRot;
	this->zRot = zRot;
	this->angle = angle;
	this->Scaling.X = Scaling.X;
	this->Scaling.Y = Scaling.Y;
	this->Scaling.Z = Scaling.Z;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

GameObject::~GameObject() {}
#pragma endregion

#pragma region METHODS
void GameObject::Translate(Vector3 Position) 
{
	this->Position.X = Position.X;
	this->Position.Y = Position.Y;
	this->Position.Z = Position.Z;
}

void GameObject::Rotate(float x, float y, float z, float angle) 
{
	this->xRot = x;
	this->yRot = y;
	this->zRot = z;
	this->angle = angle;
}

void GameObject::Scale(Vector3 Scaling) 
{
	this->Scaling.X = Scaling.X;
	this->Scaling.Y = Scaling.Y;
	this->Scaling.Z = Scaling.Z;
}

void GameObject::SetColor(float r, float g, float b, float a) 
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

bool GameObject::CheckCollision(GameObject test) 
{  
	//this is checker
	//bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
	//two.Position.x + two.Size.x >= one.Position.x;

	//check the X axis
	//kapag (PlayerPosition minus ObjectPosition) is less than (PlayerSize plus ObjectSize)
	if (abs(Position.X - test.Position.X) < (Scaling.X + test.Scaling.X)/2)
	{
		//check the Y axis
		if (abs(Position.Y - test.Position.Y) < (Scaling.Y + test.Scaling.Y) /2)
		{
			//check the Z axis
			//if (abs(Position.Z - test.Position.Z) < (Scaling.Z + test.Scaling.Z) / 1.5)
			//{
				return true;
			//}
		}
	}

	return false;
}

bool GameObject::HittingCollision(bool x)
{
	if (x == true)
	{
		return true;
	}

	return false;
}



void GameObject::RenderCube() 
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(Position.X, Position.Y, Position.Z);
	glRotatef(xRot, yRot, zRot, angle);
	glScalef(Scaling.X, Scaling.Y, Scaling.Z);
	glutSolidCube(1.0f);
	glPopMatrix();
}

void GameObject::RenderCollision(GameObject test) 
{ //para makita ung line ng collission
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1, 0);

	glVertex3f(test.Position.X - test.Scaling.X / 2, test.Position.Y + test.Scaling.Y / 2, test.Position.Z);
	glVertex3f(test.Position.X + test.Scaling.X / 2, test.Position.Y + test.Scaling.Y / 2, test.Position.Z);
	glVertex3f(test.Position.X + test.Scaling.X / 2, test.Position.Y - test.Scaling.Y / 2, test.Position.Z);
	glVertex3f(test.Position.X - test.Scaling.X / 2, test.Position.Y - test.Scaling.Y / 2, test.Position.Z);

	glEnd();
	glPopMatrix();
}

void GameObject::RenderGrid() 
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(Position.X, Position.Y, Position.Z);
	glRotatef(xRot, yRot, zRot, angle);
	glScalef(Scaling.X, Scaling.Y, Scaling.Z);

	//renders a box
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();

	glPopMatrix();
}

void GameObject::RenderPellet() 
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(Position.X, Position.Y, Position.Z);
	glRotatef(xRot, zRot, yRot, angle);
	glScalef(Scaling.X, Scaling.Y, Scaling.Z);
	glutSolidCube(1.0f);
	glPopMatrix();
}
#pragma endregion
