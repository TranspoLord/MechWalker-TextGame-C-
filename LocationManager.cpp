#include <iostream>
#include "LocationManager.h"
#include <vector>

using namespace std;

void LocationManager::SetALocation(int row, int col, double roomID) {
	bool locationClear = true;
	if (!intialized) {
		cout << "*****Vector of vectors roomLocation not initialized!*****" << endl;
		return;
	}
	else {
		if (roomLocation[row][col] == 0)
		{
			roomLocation[row][col] = roomID;
		}
		else
		{
			cout << "*****Room location already has an ID*****" << endl;
			return;
		}
	}

}

void LocationManager::InitializeLocation(int rows = 20, int cols = 20) {
	roomLocation.resize(rows);
	for (int x = 0; x < roomLocation.size(); x++) {
		roomLocation[x].resize(cols);
	}
	intialized = true;
}

void LocationManager::DeleteRoom(double roomID) {
	for (int x = 0; x < roomLocation.size(); ++x) {
		vector<int> row = roomLocation[x];
		for (int i = 0; i < row.size(); ++i) {
			if (roomLocation[x][i] == roomID) {
				roomLocation[x][i] = 0;
				return;
			}
		}
	}
}

void LocationManager::PrintGrid() {
	cout << endl;
	cout << "^^^^^^^^^^^^Printing bunker room grid^^^^^^^^^^^^" << endl;
	for (int x = 0; x < roomLocation.size(); ++x) {
		vector<int> row = roomLocation[x];
		for (int i = 0; i < row.size(); ++i) {
			cout << roomLocation[x][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

double LocationManager::GetRoomLocation(int row, int col) {
	return roomLocation[row][col];
}

