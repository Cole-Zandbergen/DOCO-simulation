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
#include <vector>
#include "Random.cpp"
#include <string>

using namespace std;


//Default constructor
World::World(const char* filename) {
	DataParser* parser = parser->getInstance(filename);
	map = createGrid(parser->getDOCOWorldWidth(), parser->getDOCOWorldHeight());
	DOCOs = new DOCOList();
	/*
	Create placeholder variables for the X and Y coordinates, as well as a char
	because the method requires a char as a parameter
	will pass them as a reference so that they can be modified by the method
	*/
	int x, y;
	char temp;
	while(parser->getDOCOData(&temp, &x, &y)){
		addDOCO(x, y); //add doco to the list
	}
}

//Default destructor
World::~World(){
	delete map;
	delete DOCOs;
}

Grid* World::createGrid(int width, int height){
	return new Grid(width, height);
}

void World::addDOCO(int x, int y){
	DOCO* d = new DOCO(map->getCell(x, y)); //create the DOCO that needs to be added to the list
	DOCOs->addDOCO(d);
	map->getCell(x, y)->addDOCO();
}


string World::update(){
	string output = "World update snapshot:\n\n\n";
	string foodPellets = map->addFoodPellets(random(1, 10));
	DOCOs->update();
	output += map->display();
	output += foodPellets; //this prints how many food pellets were added in this frame
	output += "Number of DOCOs still alive: " + to_string(DOCOs->getSize());
	return output;
}

DOCOList* World::getDOCOs(){
	return DOCOs;
}