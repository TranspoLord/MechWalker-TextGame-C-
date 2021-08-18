#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "bunkerRoom.h"
#include "IDGen.h"
#include "LocationManager.h"

using namespace std;

void main()
{
	IDGen idManager;
	LocationManager localMan;
	bunkerRoom Entrance, HallwayNorth, SideStorage, A, B, C;

	Entrance.SetName("Entrance");
	HallwayNorth.SetName("North Hallway");
	SideStorage.SetName("Storage Room");
	Entrance.SetRoomID(idManager.CreateID());
	HallwayNorth.SetRoomID(idManager.CreateID());
	SideStorage.SetRoomID(idManager.CreateID());

	cout << Entrance.GetRoomID();
	cout << HallwayNorth.GetRoomID();
	cout << SideStorage.GetRoomID();

	cout << endl;

	localMan.InitializeLocation(4,4);
	localMan.SetALocation(1, 1, Entrance.GetRoomID());
	localMan.SetALocation(0, 1, HallwayNorth.GetRoomID());
	localMan.SetALocation(1, 0, SideStorage.GetRoomID());

	localMan.PrintGrid();
	idManager.TestID();
	
	
	


	


}