/*
	This file contains the method for generating random numbers that will be used for this program
	Author: Cole Zandbergen
*/

#include <random>

using namespace std;

static int random(int min, int max) {
	random_device dev;
	mt19937 rng(dev);
	uniform_int_distribution<mt19937::result_type> dist(min, max);
	return dist(rng);
}