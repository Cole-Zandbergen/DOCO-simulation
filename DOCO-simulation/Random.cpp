/*
	This file contains the method for generating random numbers that will be used for this program
	Author: Cole Zandbergen
*/

#include <random>


using namespace std;

static int random(int min, int max) {
    int size = max - min + 1;
    int n = rand() % size;
    n += min;
	cout << "Generated the random number " << n << endl;
	return n;
}