#pragma once
#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H
#include <SFML/Audio.hpp>
using namespace sf;
class SoundEngine {
private:
	SoundBuffer m_ShootBuffer, m_PlayerExplodeBuffer, m_InvaderExplodeBuffer, m_ClickBuffer;
	Sound m_ShootSound, m_PlayerExplodeSound, m_InvaderExplodeSound, m_UhSound, m_OhSound, m_ClickSound;
public:
	SoundEngine();
	static void playShoot();
	static void playPlayerExplode();
	static void playInvaderExplode();
	static void playClick();
	static SoundEngine* m_s_Instance;
};
#endif