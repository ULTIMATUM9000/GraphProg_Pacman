#include "sound.h"


void SoundBegin()
{
	PlaySound(TEXT("beginning.wav"), NULL, SND_ASYNC );
}

void SoundEatfruit()
{
	PlaySound(TEXT("fleeing.wav"), NULL, SND_ASYNC | SND_LOOP);
}


void SoundWaka()
{
	PlaySound(TEXT("waka.wav"), NULL, SND_ASYNC );
}

void SoundDeath()
{
	PlaySound(TEXT("death.wav"), NULL , SND_ASYNC);
}

void SoundEatGhost()
{
	PlaySound(TEXT("eatghost.wav"), NULL , SND_ASYNC);
}
