#pragma once
#include "stdafx.h"
//#include "fmod.h"
class Music
{
public:
	Music();
	virtual ~Music();
	void Update();
	void PlaySoundFromFile(const string path);
//private:
//	enum InputIds :int
//	{
//		Play,
//		Play3D,
//		IncreaseVolume,
//		DecreaseVolume
//	};
//
//	FMOD_RESULT m_FMODResult;
//	FMOD_SYSTEM *m_pFMODSystem;
//	FMOD_SOUND *m_pSound, *m_pSoundTrigger, *m_p3DSound;
//	FMOD_CHANNEL **m_pChannel, *m_pChannelTrigger, *m_pChannel3D;
//	float m_Volume;
	bool m_Looping = true;
};

