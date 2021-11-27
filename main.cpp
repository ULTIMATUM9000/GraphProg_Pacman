#include "gameengine.h" 

#include "Vector3.h"
#include "input.h"
#include "ghostai.h"
#include <ctime>
#include "sound.h"

extern int score=0; //scoreboard
GameObject Grid;

Player player;

Barrier Wall[55];
Food Pellet[363];
bool Pellettruth[363] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //60
						 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //60
						 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,1,1};
Food PowerPellet[5];
bool PowerPellettruth[5]= { 1,1,1,1,1 };
bool activate = false; //activate power pellet
float PowerPelletRed = 255.0f;
clock_t startAnimTime = 0; //powerpellet glowing time
clock_t endAnimTime = 0; //powerpellet end time
int animElapsed = 0;

Ghost ghost[4];
bool Ghosttruth[4] = { 1,1,1,1 };

clock_t startTime = 0; //run only if activate pellet
clock_t endTime = 0; //run on time
float elapsed = 0; //timer

int death=0;
void Initialize() { 
	SoundBegin();

	dummy.Position.X = -0.5f;
	dummy.Position.Y = -10.5f;

	moveGhost[0].Position.X = -0.5f;
	moveGhost[0].isMoving = true;

	moveGhost[1].Position.Y = 0.5f;
	moveGhost[1].isMoving = true;

	moveGhost[2].Position.Y = 0.5f;
	moveGhost[2].isMoving = true;

	moveGhost[3].Position.X = -0.5f;
	moveGhost[3].isMoving = true;

	ghost[0].SetColor(1.0f, 0.0f, 0.0f, 0.0f); //RED
	ghost[0].Scale(Vector3(2.0f, 2.0f, 0.0f));

	ghost[1].SetColor(0.0f, 1.0f, 1.0f, 0.0f); //Blue
	ghost[1].Scale(Vector3(2.0f, 2.0f, 0.0f));

	ghost[2].SetColor(1.0f, 0.0f, 1.0f, 0.0f); //Violet
	ghost[2].Scale(Vector3(2.0f, 2.0f, 0.0f));

	ghost[3].SetColor(1.0f, 0.5f, 0.0f, 0.0f); //Orange
	ghost[3].Scale(Vector3(2.0f, 2.0f, 0.0f));

	PowerPellet[0].SetColor(1, 0, 0,0);
	PowerPellet[0].Scale(Vector3(1.0, 1.0,0));
	PowerPellet[0].Translate(Vector3(-3.5f , -10.5f, 0));

	PowerPellet[1].SetColor(1, 0, 0, 0);
	PowerPellet[1].Scale(Vector3(1.0, 1.0, 0));
	PowerPellet[1].Translate(Vector3(-15.5f, -10.5f, 0));

	PowerPellet[2].SetColor(1, 0, 0, 0);
	PowerPellet[2].Scale(Vector3(1.0, 1.0, 0));
	PowerPellet[2].Translate(Vector3(15.5f, -10.5f, 0));

	PowerPellet[3].SetColor(1, 0, 0, 0);
	PowerPellet[3].Scale(Vector3(1.0, 1.0, 0));
	PowerPellet[3].Translate(Vector3(15.5f, 12.5f, 0));

	PowerPellet[4].SetColor(1, 0, 0, 0);
	PowerPellet[4].Scale(Vector3(1.0, 1.0, 0));
	PowerPellet[4].Translate(Vector3(-15.5f, 12.5f, 0));

#pragma region Pellets
	for (int i = 0; i < 35; ++i)
	{
		//Pellet[i].SetColor(1, 0, 0, 0);
		Pellet[i].Translate(Vector3(-9.5f, -14.5f + i, 0.0));
		
	}

	for (int i = 35; i < 70; ++i)
	{
		//Pellet[i].SetColor(1, 0, 0, 0);
	
		Pellet[i].Translate(Vector3(8.5f, -49.5f + i, 0.0));
		
	}

	for (int i = 70; i < 79; ++i)
	{
		//Pellet[i].SetColor(0, 1, 0, 0);

		Pellet[i].Translate(Vector3(-88.5f+ i, 12.5f, 0.0));
		
	}

	for (int i = 79; i < 96; ++i)
	{
		//Pellet[i].SetColor(0, 1, 0, 0);
		
		Pellet[i].Translate(Vector3(-87.5f + i, 12.5f, 0.0));
		
	}

	for (int i = 96; i < 105; ++i)
	{
		//Pellet[i].SetColor(0, 1, 0, 0);

		Pellet[i].Translate(Vector3(-86.5f + i, 12.5f, 0.0));
	
	}

	for (int i = 105; i < 114; ++i)
	{
		//Pellet[i].SetColor(0.0, 1.0, 0.0, 0.0);

		Pellet[i].Translate(Vector3(-123.5f + i, 7.5f, 0.0));

	}

	for (int i = 114; i < 123; ++i)
	{
		//Pellet[i].SetColor(0.0, 1.0, 0.0, 0.0);

		Pellet[i].Translate(Vector3(-104.5f + i, 7.5f, 0.0));
	
	}

	for (int i = 123; i < 127; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-18.5f, -114.5f + i, 0.0));
		
	}

	for (int i = 127; i < 134; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-18.5f, -113.5f + i, 0.0));
	
	}

	for (int i = 134; i < 138; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(17.5f, -125.5f + i, 0.0));
	
	}

	for (int i = 138; i < 145; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(17.5f, -124.5f + i, 0.0));
		
	}

	for (int i = 145; i < 153; ++i)
	{
		//Pellet[i].SetColor(0.0, 1.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-162.5f + i, 19.5f, 0.0));
		
	}

	for (int i = 153; i < 160; ++i)
	{
		//Pellet[i].SetColor(0.0, 1.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-161.5f + i, 19.5f, 0.0));
	
	}

	for (int i = 160; i < 167; ++i)
	{
		//Pellet[i].SetColor(0.0, 1.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-158.5f + i, 19.5f, 0.0));
	
	}

	for (int i = 167; i < 175; ++i)
	{
		//Pellet[i].SetColor(0.0, 1.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-157.5f + i, 19.5f, 0.0));
	
	}

	for (int i = 175; i < 181; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-2.5f, -161.5f + i, 0.0));

	}

	for (int i = 181; i < 187; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(1.5f, -167.5f + i, 0.0));
	
	}

	for (int i = 187; i < 191; ++i)
	{
		//Pellet[i].SetColor(1.0, 0.0, 0.0, 0.0);
		Pellet[i].Translate(Vector3(-5.5f, -178.5f + i, 0.0));

	}

	//bottom map
	for (int i = 191; i < 228; ++i)
	{
		Pellet[i].Translate(Vector3(-209.5f + i, -18.5f, 0.0)); //bottom pellets 
	}

	for (int i = 228; i < 233; ++i)
	{
		Pellet[i].Translate(Vector3(-18.5f, -246.5f + i, 0.0)); //bottom left pellets
	}

	for (int i = 233; i < 238; ++i)
	{
		Pellet[i].Translate(Vector3(17.5f, -251.5f + i, 0.0)); //bottom right pellets
	}

	for (int i = 238; i < 242; ++i)
	{
		Pellet[i].Translate(Vector3(1.5f, -255.5f + i, 0.0)); //middle right pellets
	}

	for (int i = 242; i < 246; ++i)
	{
		Pellet[i].Translate(Vector3(-2.5f, -259.5f + i, 0.0)); //middle left pellets	
	}

	for (int i = 246; i < 254; ++i)
	{
		Pellet[i].Translate(Vector3(-263.5f + i, -14.5f, 0.0));
	}

	for (int i = 254; i < 262; ++i)
	{
		Pellet[i].Translate(Vector3(-244.5f + i, -14.5f, 0.0));
	}

	for (int i = 262; i < 265; ++i)
	{
		Pellet[i].Translate(Vector3(-259.5f + i, -14.5f, 0.0));
	}

	for (int i = 265; i < 268; ++i)
	{
		Pellet[i].Translate(Vector3(-270.5f + i, -14.5f, 0.0));
	}

	/*---------------------------------*/
	for (int i = 268; i < 272; ++i)
	{
		Pellet[i].Translate(Vector3(4.5f, -259.5f + i, 0.0));
	}

	for (int i = 272; i < 275; ++i)
	{
		Pellet[i].Translate(Vector3(-276.5f + i, 8.5f, 0.0));
	}

	for (int i = 275; i < 278; ++i)
	{
		Pellet[i].Translate(Vector3(-273.5f + i, 8.5f, 0.0));
	}

	for (int i = 278; i < 295; ++i)
	{
		Pellet[i].Translate(Vector3(-286.5f + i, -10.5f, 0.0));
	}

	for (int i = 295; i < 301; ++i)
	{
		Pellet[i].Translate(Vector3(-313.5f + i, -10.5f, 0.0));
	}

	for (int i = 301; i < 307; ++i)
	{
		Pellet[i].Translate(Vector3(-288.5f + i, -10.5f, 0.0));
	}

	for (int i = 307; i < 310; ++i)
	{
		Pellet[i].Translate(Vector3(-13.5f, -320.5f + i, 0.0));
	}

	for (int i = 310; i < 313; ++i)
	{
		Pellet[i].Translate(Vector3(-5.5f, -323.5f + i, 0.0));
	}

	for (int i = 313; i < 316; ++i)
	{
		Pellet[i].Translate(Vector3(4.5f, -326.5f + i, 0.0));
	}

	for (int i = 316; i < 319; ++i)
	{
		Pellet[i].Translate(Vector3(12.5f, -329.5f + i, 0.0));
	}

	for (int i = 319; i < 322; ++i)
	{
		Pellet[i].Translate(Vector3(-18.5f, -328.5f + i, 0.0));
	}

	for (int i = 322; i < 325; ++i)
	{
		Pellet[i].Translate(Vector3(-2.5f, -331.5f + i, 0.0));
	}

	for (int i = 325; i < 328; ++i)
	{
		Pellet[i].Translate(Vector3(1.5f, -334.5f + i, 0.0));
	}

	for (int i = 328; i < 331; ++i)
	{
		Pellet[i].Translate(Vector3(17.5f, -337.5f + i, 0.0));
	}

	for (int i = 331; i < 340; ++i)
	{
		Pellet[i].Translate(Vector3(-349.5f + i, -6.5f, 0.0));
	}

	for (int i = 340; i < 347; ++i)
	{
		Pellet[i].Translate(Vector3(-348.5f + i, -6.5f, 0.0));
	}

	for (int i = 347; i < 354; ++i)
	{
		Pellet[i].Translate(Vector3(-345.5f + i, -6.5f, 0.0));
	}

	for (int i = 354; i < 363; ++i)
	{
		Pellet[i].Translate(Vector3(-344.5f + i, -6.5f, 0.0));
	}
#pragma endregion
}

void UpdatePellet() {

	for (int j = 0; j != 363; j++)
	{
		glPushMatrix();
		Pellet[j].Scale(Vector3(0.25f, 0.25f, 0));
		if (Pellettruth[j] == true)
		{
			Pellet[j].RenderPellet();
		}
		else
			glPopMatrix();
	}

	for(int j=0; j!=5; ++j)  //POWERPELLETS
	{
		glPushMatrix();           
		if (PowerPellettruth[j] == true)
		{
			PowerPellet[j].RenderPellet();
		}
		else
			glPopMatrix();
	}
	
	for (int j = 0; j != 4; ++j) //GHOSTTT 
	{
		glPushMatrix();
		if (Ghosttruth[j] == true)
		{
			ghost[j].RenderCube();
		}
		else
			glPopMatrix();
	}
}

void UpdateWalls()
{

	/*Wall[0].SetColor(0.0, 0.0, 1.0, 0.0);
	Wall[0].Translate(Vector3(-4.0, 0.0, 0.0));
	Wall[0].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[0].RenderCube();*/

#pragma region "ghost cage"
	//left wall
	Wall[0].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[0].Translate(Vector3(-4.0, 1.0, 0.0));
	Wall[0].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[0].RenderCube();

	//upper wall
	Wall[1].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[1].Translate(Vector3(-0.5, 3.0, 0.0));
	Wall[1].Scale(Vector3(7.0, 1.0, 0.0));
	Wall[1].RenderCube();

	//right wall
	Wall[2].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[2].Translate(Vector3(3.0, 1.0, 0.0));
	Wall[2].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[2].RenderCube();

	//lower wall
	Wall[3].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[3].Translate(Vector3(-0.5, -1.0, 0.0));
	Wall[3].Scale(Vector3(7.0, 1.0, 0.0));
	Wall[3].RenderCube();
#pragma endregion

#pragma region "lower map"

	Wall[4].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[4].Translate(Vector3(-0.5, -4.5, 0.0));
	Wall[4].Scale(Vector3(8.0, 2.0, 0.0));
	Wall[4].RenderCube();

	Wall[5].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[5].Translate(Vector3(-0.5, -7.5, 0.0));
	Wall[5].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[5].RenderCube();

	Wall[6].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[6].Translate(Vector3(5.0, -8.5, 0.0));
	Wall[6].Scale(Vector3(5.0, 2.0, 0.0));
	Wall[6].RenderCube();

	Wall[7].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[7].Translate(Vector3(-6.0, -8.5, 0.0));
	Wall[7].Scale(Vector3(5.0, 2.0, 0.0));
	Wall[7].RenderCube();

	Wall[8].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[8].Translate(Vector3(-0.5, -15.5, 0.0));
	Wall[8].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[8].RenderCube();

	Wall[9].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[9].Translate(Vector3(-0.5, -12.5, 0.0));
	Wall[9].Scale(Vector3(8.0, 2.0, 0.0));
	Wall[9].RenderCube();

	Wall[10].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[10].Translate(Vector3(-7.5, -13.5, 0.0));
	Wall[10].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[10].RenderCube();

	Wall[11].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[11].Translate(Vector3(-10.5, -16.5, 0.0));
	Wall[11].Scale(Vector3(14.0, 2.0, 0.0));
	Wall[11].RenderCube();

	Wall[12].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[12].Translate(Vector3(6.5, -13.5, 0.0));
	Wall[12].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[12].RenderCube();

	Wall[13].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[13].Translate(Vector3(9.5, -16.5, 0.0));
	Wall[13].Scale(Vector3(14.0, 2.0, 0.0));
	Wall[13].RenderCube();

	Wall[14].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[14].Translate(Vector3(13.0, -8.5, 0.0));
	Wall[14].Scale(Vector3(7.0, 2.0, 0.0));
	Wall[14].RenderCube();

	Wall[15].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[15].Translate(Vector3(-14.0, -8.5, 0.0));
	Wall[15].Scale(Vector3(7.0, 2.0, 0.0));
	Wall[15].RenderCube();

	Wall[16].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[16].Translate(Vector3(10.5, -11.5, 0.0));
	Wall[16].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[16].RenderCube();

	Wall[17].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[17].Translate(Vector3(-11.5, -11.5, 0.0));
	Wall[17].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[17].RenderCube();

	Wall[18].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[18].Translate(Vector3(-7.5, -3.0, 0.0));
	Wall[18].Scale(Vector3(2.0, 5.0, 0.0));
	Wall[18].RenderCube();

	Wall[19].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[19].Translate(Vector3(6.5, -3.0, 0.0));
	Wall[19].Scale(Vector3(2.0, 5.0, 0.0));
	Wall[19].RenderCube();

	//bottom wall
	Wall[20].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[20].Translate(Vector3(-0.5, -20.0, 0.0));
	Wall[20].Scale(Vector3(40.0, 1.0, 0.0));
	Wall[20].RenderCube();

	//lower left wall
	Wall[21].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[21].Translate(Vector3(-20., -12.5, 0.0));
	Wall[21].Scale(Vector3(1.0, 16.0, 0.0));
	Wall[21].RenderCube();

	Wall[23].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[23].Translate(Vector3(-17.0, -12.5, 0.0));
	Wall[23].Scale(Vector3(5.0, 2.0, 0.0));
	Wall[23].RenderCube();

	Wall[26].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[26].Translate(Vector3(-15.5, -5.0, 0.0));
	Wall[26].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[26].RenderCube();

	Wall[28].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[28].Translate(Vector3(-11.0, -3.0, 0.0));
	Wall[28].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[28].RenderCube();

	Wall[30].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[30].Translate(Vector3(-15.5, -1.0, 0.0));
	Wall[30].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[30].RenderCube();

	//lower right wall
	Wall[22].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[22].Translate(Vector3(19.0, -12.5, 0.0));
	Wall[22].Scale(Vector3(1.0, 16.0, 0.0));
	Wall[22].RenderCube();

	Wall[24].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[24].Translate(Vector3(16.0, -12.5, 0.0));
	Wall[24].Scale(Vector3(5.0, 2.0, 0.0));
	Wall[24].RenderCube();

	Wall[25].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[25].Translate(Vector3(14.5, -5.0, 0.0));
	Wall[25].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[25].RenderCube();

	Wall[27].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[27].Translate(Vector3(10.0, -3.0, 0.0));
	Wall[27].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[27].RenderCube();

	Wall[29].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[29].Translate(Vector3(14.5, -1.0, 0.0));
	Wall[29].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[29].RenderCube();

#pragma endregion

#pragma region "upper map"

	Wall[40].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[40].Translate(Vector3(6.5, 6.5, 0.0));
	Wall[40].Scale(Vector3(2.0, 10.0, 0.0));
	Wall[40].RenderCube();

	Wall[41].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[41].Translate(Vector3(-7.5, 6.5, 0.0));
	Wall[41].Scale(Vector3(2.0, 10.0, 0.0));
	Wall[41].RenderCube();

	Wall[42].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[42].Translate(Vector3(-5.5, 6.5, 0.0));
	Wall[42].Scale(Vector3(4.0, 2.0, 0.0));
	Wall[42].RenderCube();

	Wall[43].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[43].Translate(Vector3(4.5, 6.5, 0.0));
	Wall[43].Scale(Vector3(4.0, 2.0, 0.0));
	Wall[43].RenderCube();

	Wall[44].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[44].Translate(Vector3(-0.5, 10.5, 0.0));
	Wall[44].Scale(Vector3(8.0, 2.0, 0.0));
	Wall[44].RenderCube();

	Wall[45].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[45].Translate(Vector3(-0.5, 7.5, 0.0));
	Wall[45].Scale(Vector3(2.0, 4.0, 0.0));
	Wall[45].RenderCube();

	Wall[46].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[46].Translate(Vector3(-14.0, 10.0, 0.0));
	Wall[46].Scale(Vector3(7.0, 3.0, 0.0));
	Wall[46].RenderCube();

	Wall[47].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[47].Translate(Vector3(13.0, 10.0, 0.0));
	Wall[47].Scale(Vector3(7.0, 3.0, 0.0));
	Wall[47].RenderCube();

	Wall[48].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[48].Translate(Vector3(13.0, 16.0, 0.0));
	Wall[48].Scale(Vector3(7.0, 5.0, 0.0));
	Wall[48].RenderCube();

	Wall[49].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[49].Translate(Vector3(-14.0, 16.0, 0.0));
	Wall[49].Scale(Vector3(7.0, 5.0, 0.0));
	Wall[49].RenderCube();

	Wall[50].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[50].Translate(Vector3(-6.0, 16.0, 0.0));
	Wall[50].Scale(Vector3(5.0, 5.0, 0.0));
	Wall[50].RenderCube();

	Wall[51].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[51].Translate(Vector3(5.0, 16.0, 0.0));
	Wall[51].Scale(Vector3(5.0, 5.0, 0.0));
	Wall[51].RenderCube();

	Wall[52].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[52].Translate(Vector3(-0.5, 17.0, 0.0));
	Wall[52].Scale(Vector3(2.0, 7.0, 0.0));
	Wall[52].RenderCube();

	//ceiling wall
	Wall[39].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[39].Translate(Vector3(-0.5, 21.0, 0.0));
	Wall[39].Scale(Vector3(40.0, 1.0, 0.0));
	Wall[39].RenderCube();

	//upper left wall
	Wall[31].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[31].Translate(Vector3(-15.5, 2.0, 0.0));
	Wall[31].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[31].RenderCube();

	Wall[33].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[33].Translate(Vector3(-11.0, 4.0, 0.0));
	Wall[33].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[33].RenderCube();

	Wall[35].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[35].Translate(Vector3(-15.5, 6.0, 0.0));
	Wall[35].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[35].RenderCube();

	Wall[37].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[37].Translate(Vector3(-20., 13.5, 0.0));
	Wall[37].Scale(Vector3(1.0, 16.0, 0.0));
	Wall[37].RenderCube();

	//upper right wall
	Wall[32].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[32].Translate(Vector3(14.5, 2.0, 0.0));
	Wall[32].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[32].RenderCube();

	Wall[34].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[34].Translate(Vector3(10.0, 4.0, 0.0));
	Wall[34].Scale(Vector3(1.0, 5.0, 0.0));
	Wall[34].RenderCube();

	Wall[36].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[36].Translate(Vector3(14.5, 6.0, 0.0));
	Wall[36].Scale(Vector3(10.0, 1.0, 0.0));
	Wall[36].RenderCube();

	Wall[38].SetColor(0.0f, 0.0f, 1.0f, 0.0f);
	Wall[38].Translate(Vector3(19.0, 13.5, 0.0));
	Wall[38].Scale(Vector3(1.0, 16.0, 0.0));
	Wall[38].RenderCube();
#pragma endregion
}
//This is called every frame
void Update() {
	CheckTranslate();
	CheckDeath();
	CheckGhostCollision();
	CheckPelletCollision();
	CheckPowerPelletTimer();
	PowerPelletBlinking();
	CheckWallCollision();
	CheckOutOfBounds();
}

int main(int argc, char** argv) 
{
	PrepareEngine(&argc, argv);
}

void CheckTranslate()
{
	ghost[0].Translate(Vector3(moveGhost[0].Position.X, 12.5f, 0)); //red
	ghost[1].Translate(Vector3(-9.5f, moveGhost[1].Position.Y, 0)); //blue
	ghost[2].Translate(Vector3(8.5f, moveGhost[2].Position.Y, 0)); //violet
	ghost[3].Translate(Vector3(moveGhost[3].Position.X, -18.5f, 0)); //orange

	player.Translate(Vector3(dummy.Position.X, dummy.Position.Y, 0));
	player.SetColor(1.0f, 1.0f, 0.0f, 0.0f);
	player.Scale(Vector3(1.5f, 1.5f, 0));
	player.RenderCube();

	dummy.Position = dummy.Position + dummy.Velocity; //updates position

	if (dummy.isMoving == true)
	{
		dummy.Velocity = (dummy.Velocity + dummy.Acceleration) * 0.024f; //updates movement speed and direction
	}
}

void CheckDeath()
{
	if (death == 3)
	{
		std::cout << "-------------------GAME OVER------------------------" << std::endl;
		system("pause");
		exit(0);
	}
}

void CheckGhostCollision()
{
	// Ghost Hit Pacman, Pacman Goes back to start
	if (!activate)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (Ghosttruth[i])
			{
				if (GameObject::HittingCollision(player.CheckCollision(ghost[i])))
				{
					SoundDeath();
					dummy.Position.X = -0.5f;
					dummy.Position.Y = -10.5f;
					++death;
				}
			}
		}
	}

	if (activate) //IF POWER PELLET IS TRUEEE
	{
		for (int i = 0; i != 5; ++i)
		{
			ghost[0].SetColor(1, 1, 1, 0);
			ghost[1].SetColor(1, 1, 1, 0);
			ghost[2].SetColor(1, 1, 1, 0);
			ghost[3].SetColor(1, 1, 1, 0);

			if (Ghosttruth[i])
			{
				if (GameObject::HittingCollision(player.CheckCollision(ghost[i]))) //GHOSSSSSSSSSTT
				{
					SoundEatGhost();
					score += 50;
					std::cout << "EATTTTTTT: " << score << std::endl;
					Ghosttruth[i] = false;

					ghost[i].Scale(Vector3(0, 0, 0));
					moveGhost[i].Position.X = 0; moveGhost[i].Position.Y = 0;  moveGhost[i].Position.Z = 0;
				}
			}
		}
	}
}

void CheckPelletCollision()
{
	for (int i = 0; i != 363; ++i)   //PELETTTTTTTS DELETEEE
	{
		if (GameObject::HittingCollision(player.CheckCollision(Pellet[i])))
		{
			SoundWaka();
			++score;
			std::cout << "THIS IS SCORE: " << score << std::endl;
			Pellettruth[i] = false;

			Pellet[i].Scale(Vector3(0, 0, 0));
			Pellet[i].Translate(Vector3(0, 0, 0));
		}
	}

	for (int i = 0; i != 5; ++i)   //POWERPELLLETTTTTT DELETE
	{
		if (GameObject::HittingCollision(player.CheckCollision(PowerPellet[i])))
		{
			startTime = clock(); //running time minus just starting time. 
			activate = true; //if true can eat ghost

			std::cout << "POWAHHH" << std::endl; //delete
			PowerPellet[i].Scale(Vector3(0, 0, 0));
			PowerPellet[i].Translate(Vector3(0, 0, 0));
			PowerPellettruth[i] = false;

			if (activate)
			{
				SoundEatfruit();
			}
		}
	}
}

void CheckPowerPelletTimer()
{
	endTime = clock();

	elapsed = int((endTime - startTime) / CLOCKS_PER_SEC);
	if (elapsed >= 10) //if countup reaches, resets
	{
		activate = false; //powerpellet ends
		elapsed = 0;

		ghost[0].SetColor(1.0f, 0.0f, 0.0f, 0.0f); //RED
		ghost[1].SetColor(0.0f, 1.0f, 1.0f, 0.0f); //Blue
		ghost[2].SetColor(1.0f, 0.0f, 1.0f, 0.0f); //Violet
		ghost[3].SetColor(1.0f, 0.5f, 0.0f, 0.0f); //Orange
	}
}

void PowerPelletBlinking()
{
	endAnimTime = clock();

	animElapsed = int((endAnimTime - startAnimTime) / CLOCKS_PER_SEC);

	if (animElapsed % 2 == 0)
	{
		PowerPelletRed = 0.0f;
	}
	else
	{
		PowerPelletRed = 255.0f;
	}

	PowerPellet[0].SetColor(PowerPelletRed / 255, 0, 0, 0);
	PowerPellet[1].SetColor(PowerPelletRed / 255, 0, 0, 0);
	PowerPellet[2].SetColor(PowerPelletRed / 255, 0, 0, 0);
	PowerPellet[3].SetColor(PowerPelletRed / 255, 0, 0, 0);
	PowerPellet[4].SetColor(PowerPelletRed / 255, 0, 0, 0);
}

void CheckWallCollision()
{
	for (int i = 0; i != 55; ++i) // collission wall
	{
		if (GameObject::HittingCollision(player.CheckCollision(Wall[i])))
		{
			if (wallhitright)
			{
				dummy.isMoving = false;
				dummy.Velocity = (dummy.Velocity + dummy.Acceleration) * 0;
				dummy.Position.X = dummy.Position.X - 0.20f;
			}
			if (wallhitleft)
			{
				dummy.isMoving = false;
				dummy.Velocity = (dummy.Velocity + dummy.Acceleration) * 0;
				dummy.Position.X = dummy.Position.X + 0.20f;
			}
			if (wallhitup)
			{
				dummy.isMoving = false;
				dummy.Velocity = (dummy.Velocity + dummy.Acceleration) * 0;
				dummy.Position.Y = dummy.Position.Y - 0.20f;
			}
			if (wallhitdown)
			{
				dummy.isMoving = false;
				dummy.Velocity = (dummy.Velocity + dummy.Acceleration) * 0;
				dummy.Position.Y = dummy.Position.Y + 0.20f;
			}
		}
	}
}

void CheckOutOfBounds()
{
	if (dummy.Position.X >= 20.0f) //outside
	{
		dummy.Position.X = -19.0f;
	}
	if (dummy.Position.X <= -20.0f)
	{
		dummy.Position.X = 19.0f;
	}
}