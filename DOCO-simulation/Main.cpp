
/*
	DOCO Simulation: Main function
	Programming assignment 1 for CS307, spring 2022
	Author: Cole Zandbergen
*/

#include <iostream>
#include "DataParser.h"
#include "random.cpp"
#include "World.h"
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;



int main()
{
	//first, we need to get the XML file added in
	string XMLfile;
	cout << "Enter the filepath for where your DOCO data is found: ";
	//enter C:\Users\Cole\Downloads\DOCOData01.xml
	cin >> XMLfile;

	//next, find out what they want to name this simulation
	string simName;
	cout << "\nEnter a name for this simulation: ";
	cin >> simName;

	//finally, figure out where they want to store this output
	string outputDirectory;
	cout << "\nName the directory where you want this to be stored: ";
	cin >> outputDirectory;

	//Create the world object and pass in that file name
	World* world = new World(XMLfile.c_str()); //.c_str() converts string to const char* format

	srand(time(0)); //Before we start generating random numbers, change the seed so it won't always be the same
	int counter = 0; //initialize the counter variable
	while(world->getDOCOs()->getSize() > 0){ //run the simulation while there are still DOCOs living

		//first, create the output file
		ofstream outfile (outputDirectory + "/" + simName + "_" + to_string(counter) + ".txt");

		string updateString = world->update();
		//print to, then close the output file
		outfile << updateString << endl;
		outfile.close();

		counter++;

		//Sleep for one second
		chrono::seconds oneSecond(1);
		this_thread::sleep_for(oneSecond);
	}
	//When the loop ends, that means the simulation is finished
	cout << "Simulation finished!" << endl;
	return 0;

}