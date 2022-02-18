#include <iostream>
#include "DataParser.h"

using namespace std;
int main()
{
	//first, we need to get the XML file added in
	string file;
	cout << "Enter the filepath for your data: ";
	//enter C:\Users\Cole\Downloads\DOCOData01.xml
	cin >> file;
	DataParser* parser = parser->getInstance(file.c_str()); //.c_str converts string to const char* format
	cout << parser->getFoodCount() << endl;
	return 0;
}