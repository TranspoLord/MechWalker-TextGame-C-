#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "bunkerRoom.h"

using namespace std;
bool matchEnemyReq = false;


//Sets the room name
void bunkerRoom::SetName(string name) {
	this->roomName = name;
}

//Checks if north is null using pntr, then sets the room to the north
void bunkerRoom::SetLocationNorth(bunkerRoom *north) {
	if(north != NULL)
		this->northRoom = north;

}

//Checks if east is null using pntr, then sets the room to the east
void bunkerRoom::SetLocationEast(bunkerRoom *east) {
	if (east != NULL)
		this->eastRoom = east;
}

//Checks if south is null using pntr, then sets the room to the south
void bunkerRoom::SetLocationSouth(bunkerRoom *south) {
	if (south != NULL)
		this->southRoom = south;
}

//Checks if west is null using pntr, then sets the room to the west
void bunkerRoom::SetLocationWest(bunkerRoom *west) {
	if (west != NULL)
		westRoom = west;
}

//Sets item for the room
void bunkerRoom::SetItem(Item item){
	this->roomItem = item;
}

/*
Sets a room desc. 
	0: Enter desc with item in room 
	1: Enter desc without item in room
	2: Dont have required item to enter room
	3: Has required item to enter room
	4: 
*/
void bunkerRoom::SetRoomDesc(int type, string description) {
	roomDesc.resize(4);
	this->roomDesc.at(type) = description;
}

//Sets the enemy for the room
void bunkerRoom::SetEnemy(Enemy enemy) {
	this->roomEnemy = enemy;
}

//Sets the room bacon requirements to match the enemy requirements
void bunkerRoom::MatchEnemyRequirements() {
	Enemy* enemyPtr = &roomEnemy;
	if (enemyPtr != nullptr)
	{
		reqRoomItems = roomEnemy.GetRequiredItems();
		matchEnemyReq = true;
	}
	else
		cout << "Enemy requirements for: " << roomEnemy.GetName() << " was never set" << endl;

}

//Adds an item req to enter the room
void bunkerRoom::AddRoomReq(Item item) {
	this->reqRoomItems.push_back(item);
}

//Get functions
Enemy bunkerRoom::GetEnemy() {
	return roomEnemy;
}

string bunkerRoom::GetName() {
	return roomName;
}

Item bunkerRoom::GetItem() {
	return this->roomItem;
}

bunkerRoom* bunkerRoom::GetNorth() {
	if (northRoom != nullptr)
		return northRoom;
	else
		cout << "No room here or nullPtr at GetNorth" << endl;
}

bunkerRoom* bunkerRoom::GetEast() {
	if (eastRoom != nullptr)
		return eastRoom;
	else
		cout << "No room here or nullPtr at GetEast" << endl;
}

bunkerRoom* bunkerRoom::GetSouth() {
	if (southRoom != nullptr)
		return southRoom;
	else
		cout << "No room here or nullPtr at GetSouth" << endl;
}

bunkerRoom* bunkerRoom::GetWest() {
	if (westRoom != nullptr)
		return westRoom;
	else
		cout << "No room here or nullPtr at GetWest" << endl;
}

/*Gets a room desc.
	0: Enter desc with item in room
	1: Enter desc without item in room
	2: Dont have required item to enter room
	3: Has required item to enter room
	4:
*/
string bunkerRoom::GetRoomDesc(int type) {
	return roomDesc.at(type);
}

void bunkerRoom::ReadTextForBunker(string path) {
	bunkerRoom *room = this;
	ifstream tempFile;
	string fileName = path + this->GetName() + "-bunkerRoom.txt";
	string contents;
	tempFile.open(fileName);

	getline(tempFile, contents);
	this->roomName = RemoveStrings(contents, "Name: ");

	getline(tempFile, contents);
	this->roomDesc.at(0) = RemoveStrings(contents, "Desc 0: ");
	getline(tempFile, contents);
	this->roomDesc.at(1) = RemoveStrings(contents, "Desc 1: ");
	getline(tempFile, contents);
	this->roomDesc.at(2) = RemoveStrings(contents, "Desc 2: ");
	getline(tempFile, contents);
	this->roomDesc.at(3) = RemoveStrings(contents, "Desc 3: ");

	getline(tempFile, contents);
	//cout << RemoveStrings(contents, "Room North: ") << endl;
	getline(tempFile, contents);
	//cout << RemoveStrings(contents, "Room East: ") << endl;
	getline(tempFile, contents);
	//cout << RemoveStrings(contents, "Room South: ") << endl;
	getline(tempFile, contents);
	//cout << RemoveStrings(contents, "Room West: ") << endl;

	getline(tempFile, contents);
	//cout << RemoveStrings(contents, "Item Name: ") << endl;
	getline(tempFile, contents);
	//<< RemoveStrings(contents, "Enemy Name: ") << endl;
	tempFile.close();

}

void bunkerRoom::BunkerToText(string path) {
	cout << "Bunkertotext" << endl;

	ofstream tempFile;
	string fileName = path + this->GetName() + "-bunkerRoom.txt";
	tempFile.open(fileName);
	tempFile << "Name: " << this->GetName() << endl;
	for (int x = 0; x < this->roomDesc.size(); ++x) 
	{
		tempFile << "Desc " << x << ": " << this->GetRoomDesc(x) << endl;
	}
	tempFile << "Room North: " << this->GetNorth()->GetName() << " ID: " << this->GetNorth()->GetRoomID() << endl;
	tempFile << "Room East: " << this->GetEast()->GetName() << " ID: " << this->GetEast()->GetRoomID() << endl;
	tempFile << "Room South: " << this->GetSouth()->GetName() << " ID: " << this->GetSouth()->GetRoomID() << endl;
	tempFile << "Room West: " << this->GetWest()->GetName() << " ID: " << this->GetWest()->GetRoomID() << endl;

	tempFile << "Item Name: " << this->GetItem().GetName() << " ID: " << this->GetItem().GetItemID() << endl;
	tempFile << "Enemy Name: " << this->GetEnemy().GetName() << " ID: " << this->GetEnemy().GetEnemyID() << endl;
	tempFile.close();

}


string bunkerRoom::RemoveStrings(string contents, string target) {
	int found = -1;
	do {
		found = contents.find(target, found + 1);
		if (found != -1)
		{
			contents = contents.substr(0, found) + contents.substr(found + target.length());
		}
	} while (found != -1);
	return contents;
}

void bunkerRoom::SetRoomID(double ID) {
	this->roomID = ID;
}

double bunkerRoom::GetRoomID() {
	return this->roomID;
}
