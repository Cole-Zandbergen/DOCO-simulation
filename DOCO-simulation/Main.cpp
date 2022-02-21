#include <iostream>
#include "DataParser.h"
#include "random.cpp"

using namespace std;



int main()
{
	/*
	//first, we need to get the XML file added in
	string file;
	cout << "Enter the filepath for your data: ";
	//enter C:\Users\Cole\Downloads\DOCOData01.xml
	cin >> file;
	DataParser* parser = parser->getInstance(file.c_str()); //.c_str converts string to const char* format
	cout << parser->getFoodCount() << endl;
	*/

	for (int i = 0; i < 10; i++) {
		cout << random(1, 10) << endl;
	}
}