#pragma once
#ifndef BUNKERROOM_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

using namespace std;

class bunkerRoom {

public:
	void SetName(string roomName);																		//Sets room name
	void SetLocationNorth(bunkerRoom *north);
	void SetLocationEast(bunkerRoom *east);
	void SetLocationSouth(bunkerRoom *south);
	void SetLocationWest(bunkerRoom *west);
	void SetItem(Item item);
	void SetRoomDesc(int type, string description);
	void SetEnemy(Enemy enemy);
	void MatchEnemyRequirements();
	void AddRoomReq(Item item);

	Enemy GetEnemy();
	Item GetItem();
	string GetName();
	bunkerRoom* GetNorth();
	bunkerRoom* GetEast();
	bunkerRoom* GetSouth();
	bunkerRoom* GetWest();
	string GetRoomDesc(int type);

	void ReadTextForBunker(string path);
	void BunkerToText(string path);

	void SetRoomID(double ID);
	double GetRoomID();


protected:
	string RemoveStrings(string contents, string target);

private:
	string roomName;
	vector <string> roomDesc;
	bunkerRoom *northRoom, *eastRoom, *southRoom, *westRoom;
	bool baconItem = false, hasID = false;
	vector <Item> reqRoomItems;
	Item roomItem;
	Enemy roomEnemy;

	double roomID = 9999;
};



#endif BUNKERROOM_H