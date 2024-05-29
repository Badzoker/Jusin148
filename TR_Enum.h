#pragma once
enum JOB
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	LOAD,
	JOBEND
};
enum EQUIP
{
	WEAPON = 1000,
	SUB_WEAPON = 1500,
	EQUIP_END
};
enum POTION
{
	HEAL_POTION = 100,
	MANA_POTION = 150,
	POTION_END
};
enum ATTACK_TYPE
{
	ATTACK_NORMAL = 0,
	ATTACK_MAGIC,
	ATTACK_LIGHT,
	ATTACK_CHAOS,
	ATTACK_TYPE_END
};
enum ARMOR_TYPE
{
	ARMOR_HEAVY = 0,
	ARMOR_LIGHT,
	ARMOR_MEDIUM,
	ARMOR_TYPE_END
};
enum ITEM_TYPE
{
	MAIN_EQUIP = 0,
	SUB_EQUIP,
	HEAL,
	MANA,
	ITEM_TYPE_END
};