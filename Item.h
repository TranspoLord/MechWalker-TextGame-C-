#pragma once
#ifndef ITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
public:
	void SetName(string itemName = "PlaceHolder");
	void SetDmg(double dmgValue = 0, double dmgMult = 1);
	void SetHp(double hpValue = 0, double hpMult = 1, bool hpType = true);
	void SetRequirements(bool baconItem, vector <Item> itemReqList);
	void PrintStats();
	void SetInfo(vector <string> itemDescriptions);
	void SetPickups(vector <string> pickups);
	void PrintInfo();


	string GetName();
	double GetDmgValue();
	double GetDmgMult();
	double GetHpValue();
	double GetHpMult();
	bool GetHpType();
	bool GetBacon();
	vector <Item> GetReqList();

	void SetID(double ID);
	double GetItemID();

private:
	string itemName;
	vector <string> itemDescs;
	double dmgValue, dmgMult;
	double hpValue, hpMult;
	bool baconItem, hpType;
	vector <Item> itemReqList;
	vector <string> pickupStrings;
	double itemID;
	
};
#endif ITEM_H