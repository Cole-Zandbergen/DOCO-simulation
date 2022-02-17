#include <iostream>
#include "DataParser.h"

using namespace std;
int main()
{
	//first problem is that we need to instantiate the parser and read something from it
	//just to make sure it works
	//Can't compile this on mac but i added these comments on my mac!
	//pushing these to github to make sure they work on vs later...
	DataParser* parser = parser->getInstance("DOCOData01.xml");
	cout << parser->getFoodCount() << endl;
	return 0;
}