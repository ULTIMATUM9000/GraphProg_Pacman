#include  "gameengine.h"
#include "graphics.h" //showscene

#include "input.h" //keypressed
#include "ghostai.h" //ghost

void PrepareEngine(int* argc, char** argv)
{
	
	glutInit(argc, argv); //Initialize Glut here
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH); //Do double buffer for smoother rendering and animation
	glutInitWindowSize(640, 480); 	//Modify the window Size
	glutInitWindowPosition(0, 0); //Set the window position
	glutCreateWindow("GAME ENGINE WINDOW");
	InitializeComponents(640, 480);

	Initialize(); //Call the Initialize Function

	//Register the functions
	glutDisplayFunc(&ShowScene);
	glutReshapeFunc(&ResizeScene);
	glutTimerFunc(0, timer, 0);
	glutIdleFunc(&ShowScene);

	glutKeyboardFunc(KeyPressed); //PARA SA KEYBOARD INPUTZ
	glutKeyboardUpFunc(KeyPressedUp);

	glutMainLoop(); //Start the render loop
}

