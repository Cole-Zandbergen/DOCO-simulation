/*
	Source file for the World class
	Author:Cole Zandbergen
*/
#pragma once
#include <iostream>
#include <fstream>
#include "Grid.h"
#include "DOCOList.h"
#include "DataParser.h"
#include "World.h"
#include "DOCOList.h"
#include <vector>
//#include "Random.cpp"
#include <string>
#include "DOCO.h"


using namespace std;


//getInstance method returns the current instance, or creates a new one with a new filename
World* World::getInstance(const char* filename) {
	static World* theInstance;
	if (theInstance == nullptr) {
		return new World(filename);
	}
	else if(strcmp(theInstance->inputFile, filename) == 0) {
		return theInstance;
	}
	else {
		delete theInstance;
		theInstance = new World(filename);
		return theInstance;
	}
}

//Default private constructor - since this class is a singleton
World::World(const char* filename) {
	inputFile = filename;
	DOCOCreator = DOCOCreator->getInstance();
	DataParser* parser = parser->getInstance(inputFile);
	map = createGrid(parser->getDOCOWorldWidth(), parser->getDOCOWorldHeight());
	DOCOs = new DOCOList();
	/*
		Create placeholder variables for the X and Y coordinates, as well as a char
		because the method requires a char as a parameter
		will pass them as a reference so that they can be modified by the method
	*/
	int x, y;
	char temp[20];
	
	
	while(parser->getDOCOData(temp, &x, &y)){
		//string s = string(temp);
		addDOCO(x, y, temp); //add doco to the list
		memset(temp, 0, 20);
	}
	
	while (parser->getObstacleData(&x, &y)) {
		map->getCell(x, y)->setObstacle();
	}

	map->addFoodPellets(parser->getFoodCount());
}

//Default destructor
World::~World(){
	delete map;
	delete DOCOs;
}

/*
	createGrid method
	This method returns a pointer to a newly created grid with the specified width and height
*/
Grid* World::createGrid(int width, int height){
	return new Grid(width, height);
}

/*
	addDOCO method
	This method adds a DOCO into the world by initializing it, then inserting it into the DOCOs list.
*/
void World::addDOCO(int x, int y, string type){
	//To add a DOCO, we need to send it a cell to spawn into
	//Then we also need to send it a type so that the factory knows which behavior pattern to give the DOCO
	Cell* homeCell = map->getCell(x, y);
	DOCO* d = DOCOCreator->createDOCO(homeCell, type);
	DOCOs->addDOCO(d);
	homeCell->addDOCO(d->display());
}

/*
	update method
	This method outputs necessary information about the world.
	The output string will be populated with all of this information, then returned.
	This method also displays the map itself to the console, so the user can view it in real time.
*/
string World::update(){
	string output = "World update snapshot:\n\n";

	string DOCOupdate = DOCOs->update();
	string foodPellets = map->addFoodPellets(random(0, 10));

	string mapDisplay = map->display();
	
	output += mapDisplay;
	output += foodPellets;
	output += "Number of DOCOs still alive: " + to_string(DOCOs->getSize()) + "\n";
	output += DOCOupdate;

	cout << mapDisplay << endl << endl;
	cout << foodPellets;
	cout << DOCOs->getSize() << " DOCOs are still alive." << endl;

	return output;
}

//Gets the list of DOCOs
DOCOList* World::getDOCOs(){
	return DOCOs;
}