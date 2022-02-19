/*
	Source file for the World class
	Author:Cole Zandbergen
*/

#include <iostream>
#include <fstream>
#include "Grid.h"
#include "DOCOList.h"
#include "DataParser.h"
#include "World.h"
#include "DOCOList.h"

using namespace std;


World::World(const char* filename) {
	DataParser* parser = parser->getInstance(filename);
	map = createGrid(parser->getDOCOWorldHeight(), parser->getDOCOWorldWidth());
	DOCOs = new DOCOList();
	addDOCOs();
	parser->
}
