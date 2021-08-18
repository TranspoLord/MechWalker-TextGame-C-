#pragma once
#ifndef LOCATIONMANAGER_H
#include <vector>



using namespace std;


class LocationManager {
public:
	void SetALocation(int row, int col, double roomID);
	void InitializeLocation(int rows, int cols);
	void DeleteRoom(double roomID);
	void PrintGrid();
	double GetRoomLocation(int row, int col);
private:

protected:
	vector <vector<int>> roomLocation;
	bool intialized = false;
	
	



};




#endif LOCATIONMANAGER_H

