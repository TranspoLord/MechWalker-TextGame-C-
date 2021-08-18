#include "IDGen.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


double IDGen::CreateID() {
	bool found = false;
	for (int x = 0; x < IDList.size(); x++) {
		if (find(IDList.begin(), IDList.end(), x) != IDList.end()) {
			IDList.push_back(x);
			return x;
		}
	}
}

void IDGen::TestID() {
	cout << endl;
	for (int x = 0; x < this->IDList.size(); ++x) {
		cout << "ID @ " << x << " is: " << IDList.at(x) << endl;
	}
	cout << endl;
}

vector <double> IDGen::GetIDList() {
	return this->IDList;
}

void IDGen::DeleteID(double id) {
	for (int x = 0; x < IDList.size(); ++x) {
		if (IDList.at(x) == id) {
			IDList.erase(IDList.begin() + x);

		}
	}
}