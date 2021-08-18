#pragma once
#ifndef IDGEN_H
#include <vector>

using namespace std;

class IDGen {
public:
	double CreateID();
	vector <double> GetIDList();
	void TestID();
	void DeleteID(double id);

private:
	vector <double> IDList{ 0 };
	int vectorSize = 1;

};



#endif IDGEN_H
