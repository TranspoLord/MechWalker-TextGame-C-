#pragma once
#ifndef ENEMY_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Enemy {
public:
	void SetIsBoss(bool isBoss = false);
	bool GetIsBoss();
	void SetNeedBacon(bool theBacon = false);
	void SetRequiredItems(vector <Item> baconList);
	void SetHp(double health);
	void SetShield(double shield);
	void SetDmg(double dmg);
	void SetName(string name);
	void AddToReqItems(Item item);

	bool GetTheBacon();
	vector <Item> GetRequiredItems();
	double GetHp();
	double GetShield();
	double GetDmg();
	string GetName();

	void SetID(double ID);
	double GetEnemyID();

private:
	bool theBoss, theBacon;
	vector <Item> reqItems;
	double health, shield, dmg;
	string enemyName;
	double enemyID;

};





#endif ENEMY_H
