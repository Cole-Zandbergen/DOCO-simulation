//===========================================================
// DataParser.h
// Purpose: Interface file for the DataParser utility class.
// Author: Dr. Rick Coleman
//===========================================================
#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <iostream>
#include <fstream>

using namespace std;

class DataParser
{
	private:
		ifstream	*inFile;	     // DOCO world definition file
		int			m_iWorldWidth;   // Number of cells wide for the DOCO grid world
		int			m_iWorldHeight;  // Number of cells high for the DOCO grid world
		int			m_iNumDOCOs;     // Number of DOCOs in the world
		int			m_iNextDOCOIndex;// Index of next DOCO to read
		char        m_sFileName[64]; // Data file
		int			m_iFoodCount;    // Number of initial food pellets
		int			m_iObstacleCount;// Number of obstacles
		int			m_iNextObsIndex; // Index of next obstacle to read

		DataParser();  // Private constructor for singleton

	public:
		~DataParser();
		void initParser(const char *fileName);
		static DataParser *getInstance(const char *fileName);
		int getDOCOWorldWidth();
		int getDOCOWorldHeight();
		int getDOCOCount();
		bool getDOCOData(char *movement, int *xpos, int *ypos);
		int getFoodCount();
		int getObstacleCount();
		bool getObstacleData(int *xpos, int *ypos);
		bool getNextLine(char *buffer, int n);
};
#endif
