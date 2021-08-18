#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Item.h"

using namespace std;

//Sets name of Item
void Item::SetName(string name) {
	this->itemName = name;
}

//Sets the dmg value and multiplier of the item
void Item::SetDmg(double dmgValue, double dmgMult) {
	this->dmgValue = dmgValue;
	this->dmgMult = dmgMult;
}

//Sets the hp value, multiplier, and hp type(true:health, false:Shield) of the item
void Item::SetHp(double hpValue, double hpMult, bool hpType) {
	this->hpValue = hpValue;
	this->hpMult = hpMult;
	this->hpType = hpType;
}

//Sets the bacon value(whether or not the item is needed to complete the game) and the Required Items vector to pick up said item
void Item::SetRequirements(bool baconItem,  vector <Item> itemReqList) {
	this->baconItem = baconItem;
	if (itemReqList.size() > 0)
	{
		this->itemReqList.resize(itemReqList.size());
		this->itemReqList = itemReqList;
	}
}

//Sets the item description
void Item::SetInfo(vector <string> descriptions) {
	//1: Item Desc, 2: Item Pickup, 3: Dont have item, 4: Dont have item 2, 
	this->itemDescs.resize(4);
	for (int x = 0; x < itemDescs.size(); ++x) {
		this->itemDescs.at(x) = descriptions.at(x);
	}
}

//Sets the item's pickup keywords
void Item::SetPickups(vector <string> pickups) {
	this->pickupStrings = pickups;
}

//Prints info/desc of the item
void Item::PrintInfo() {
	cout << setfill('*');
	cout << "\tITEM DESCRIPTONS\t" << endl;
	cout << setfill(' ');
	cout << "Description: " << this->itemDescs.at(1) << endl;
	cout << "Item Pickup: " << this->itemDescs.at(2) << endl;
	cout << "Dont have item 1: " << this->itemDescs.at(3) << endl;
	cout << "Dont have item 2: " << this->itemDescs.at(4) << endl;
	cout << "***Pickup Keywords***" << endl;
	for (int x = 0; x < pickupStrings.size(); ++x)
	{
		cout << pickupStrings.at(x) << endl;
	}
	cout << "***Required Items***" << endl;
	for (int x = 0; x < itemReqList.size(); ++x)
	{
		string name = itemReqList.at(x).GetName();
		cout << name << endl;
	}
	cout << endl;
}

//Prints the stats about the item
void Item::PrintStats() {
	cout << setfill('*');
	cout << "\tITEM STATS\t" << endl;
	cout << setfill(' ');
	cout << "Name: " << this->itemName << endl;
	cout << "Damage Value: " << this->dmgValue << "  Damage Multiplier: " << this->dmgMult << endl;
	cout << "Health Value: " << this->hpValue << "  Health Multiplier: " << this->hpMult;
	if (this->hpType)
		cout << " Health Type: Heatlh" << endl;
	else
		cout << " Health Type: Shield" << endl;
	cout << "Bacon Item: " << this->baconItem << endl;
	cout << "Required Item(s): ";
	for (int x = 0; x <= this->itemReqList.size(); ++x)
	{
		cout << "\t" << this->itemReqList.at(x).itemName << endl;
	}
	cout << endl;
}

//Returns the name 
string Item::GetName() {
	return this->itemName;
}

//Returns the dmg value
double Item::GetDmgValue() {
	return this->dmgValue;
}

//Returns the dmg multiplier
double Item::GetDmgMult() {
	return this->dmgMult;
}

//Returns the hp value
double Item::GetHpValue() {
	return this->hpValue;
}

//Returns the hp multiplier
double Item::GetHpMult() {
	return this->hpMult;
}

//Returns the hp typez
bool Item::GetHpType() {
	return this->hpType;
}

//Returns the bacon bool
bool Item::GetBacon() {
	return this->baconItem;
}

//Returns the required items for this item
vector <Item> Item::GetReqList() {
	return itemReqList;
}

void Item::SetID(double ID) {
	this->itemID = ID;
}

double Item::GetItemID() {
	return this->itemID;
}

