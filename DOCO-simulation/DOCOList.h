#pragma once
/*
	Header file for the DOCOList class
	The DOCOList will contain all of the DOCOs that are alive in the DOCO world
	Author: Cole Zandbergen
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "DOCO.h"

using namespace std;

class DOCOList
{
private:
	vector<DOCO*> DOCOs;

public:
	DOCOList();
	~DOCOList();
	void update();
	void addDOCO(DOCO* d);
};