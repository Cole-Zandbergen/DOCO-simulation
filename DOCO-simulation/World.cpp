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
void World::addDOCO(int x, int y){
	DOCO* d = new DOCO(map->getCell(x, y)); //create the DOCO that needs to be added to the list
	DOCOs->addDOCO(d);
	map->getCell(x, y)->addDOCO();
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