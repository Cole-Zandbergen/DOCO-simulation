#include <iostream>
#include "DataParser.h"

using namespace std;
int main()
{
	DataParser* parser = parser->getInstance("DOCOData01.xml");
	cout << parser->getFoodCount() << endl;
	return 0;
}