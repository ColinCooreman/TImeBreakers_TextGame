#include "stdafx.h"
#include "Music.h"

//#include "fmod.h"

Music::Music()
{

	
}


Music::~Music()
{
}

void Music::PlaySoundFromFile(const string path)
{
	//const char *tempPath = path.c_str();
	////Create a 2D Sound
	//FMOD_System_CreateStream(m_pFMODSystem, tempPath, FMOD_LOOP_NORMAL, 0, &m_pSound);
	//FMOD_System_PlaySound(m_pFMODSystem, m_pSound,0, m_Looping, m_pChannel);
}

void Music::Update()
{
	//while (m_Looping)
	//{
	//	PlaySoundFromFile("Music\ES_Observations 2 - Gunnar Johnsén.mp3");
	//}
}