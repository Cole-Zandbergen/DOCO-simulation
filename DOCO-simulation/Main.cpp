#include <iostream>
#include "DataParser.h"
#include <random>

using namespace std;

static int random(int min, int max){
	random_device dev;
	mt19937 rng(dev);
	uniform_int_distribution<mt19937::result_type> dist(min, max);
	return dist(rng);
}

int main()
{
	//first, we need to get the XML file added in
	string file;
	cout << "Enter the filepath for your data: ";
	//enter C:\Users\Cole\Downloads\DOCOData01.xml
	cin >> file;
	DataParser* parser = parser->getInstance(file.c_str()); //.c_str converts string to const char* format
	cout << parser->getFoodCount() << endl;
}