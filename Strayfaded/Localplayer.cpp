#include "include.h"


DWORD Localplayer::Get()
{
	return *(DWORD*)(Global_GameModule + dwLocalPlayer);
}
int Localplayer::GetHealth()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iHealth);
	return -1;
}

int Localplayer::GetTeam()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iTeamNum);
	return -1;
}

int Localplayer::CrosshairID()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iCrosshairId);
	return -1;
}

bool Localplayer::Exists()
{
	Engine E;
	if (*(DWORD*)(Global_GameModule + dwLocalPlayer))
		return true;
	return false;
}
void Localplayer::ForceJump()
{
	Engine E;
	*(DWORD*)(Global_GameModule + dwForceJump) = 6;
}
void Localplayer::ForceAttack()
{
	*(int*)(Global_GameModule + dwForceAttack) = 5;
}

void Localplayer::StopAttack()
{
	*(int*)(Global_GameModule + dwForceAttack) = 4;
}