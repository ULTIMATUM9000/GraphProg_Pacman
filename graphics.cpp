#include "graphics.h"

//The function that will be called when our window is resized

void ResizeScene(int width, int height) {
	//Prevent a divide by zero if the window is too small
	if (height == 0)
		height = 1;

	//Reset the current viewport and perspective transformation
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void ShowScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 55.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	//This is where we draw
	UpdateWalls();
	UpdatePellet();
	Update(); //can be used cus got called at gameengine???
	glFlush();
	glutSwapBuffers();
}

void InitializeComponents(int width, int height) {
	GLfloat aspectRatio;
	//select background color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//Initialize viewing values
	// Clear both screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//Reset projection matrix
	glLoadIdentity();
	//Calculate the aspect ratio of the window
	aspectRatio = (GLfloat)width / (GLfloat)height;  //para fixed //kakaturo lang sa grhapicsprog
	gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}