#pragma once
#include "mynamespace.h"
class CToString
{
private:
	char cToString[32];
public:
	CToString();
	~CToString();
	//void Initialize();
	//void Update();
	//void Render();
	//void Release();

	void Attack_ToString(int _eAttack);
	void Armor_ToString(int _eArmor);
	char* Get_cToString() { return cToString; }
};

