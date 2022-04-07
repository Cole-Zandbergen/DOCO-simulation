//================================================================
// DataParser.h
// Purpose: Implementation file for the DataParser utility class.
// Author: Dr. Rick Coleman
//================================================================
#define _CRT_SECURE_NO_DEPRECATE // Shut up MS, about strcpy(), etc.
#define _CRT_SECURE_NO_WARNINGS  //   just don't say anything.
#include "DataParser.h"
#include <cctype>

using namespace std;

//------------------------------------------------
// Default constructor
//------------------------------------------------
DataParser::DataParser()
{
	// Initialize everything
	m_iWorldWidth = -1;
	m_iWorldHeight = -1;
	m_iNumDOCOs = 0;
	m_iNextDOCOIndex = 0;
	m_iNextObsIndex = 0;
	m_iObstacleCount = 0;
}

//------------------------------------------------
// Open data file and init everything
//------------------------------------------------
void DataParser::initParser(const char* fileName)
{
	// Initialize everything
	char line[128];
	strcpy(m_sFileName, fileName); // save file name

	inFile = new ifstream();
	inFile->open(m_sFileName, fstream::in); // Open the data file

	if (inFile->is_open())
	{
		// Get the basic information
		while (getNextLine(line, 127))
		{
			if (strcmp(line, "<GRID_WIDTH>") == 0)
			{
				getNextLine(line, 127); // Get grid width
				m_iWorldWidth = atoi(line);
			}
			else if (strcmp(line, "<GRID_HEIGHT>") == 0)
			{
				getNextLine(line, 127); // Get grid height
				m_iWorldHeight = atoi(line);
			}
			else if (strcmp(line, "<DOCO>") == 0)
			{
				m_iNumDOCOs++; // Count all DOCOs
			}
			else if (strcmp(line, "<FOOD>") == 0)
			{
				getNextLine(line, 127); // Get grid width
				m_iFoodCount = atoi(line);
			}
			else if (strcmp(line, "<OBSTACLE>") == 0)
			{
				m_iObstacleCount++; // Count all Obstacles
			}
		}
		inFile->close();
	}
	else
		cout << "Failed to open file\n";
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
DataParser::~DataParser()
{
}

//------------------------------------------------
// Get the singleton instance
//------------------------------------------------
DataParser* DataParser::getInstance(const char* fileName)
{
	static DataParser* instance = NULL;
	if (instance == NULL) // If first time calling
	{
		instance = new DataParser();
		instance->initParser(fileName);
	}
	return instance;
}

//------------------------------------------------
// Get the width of the world
//------------------------------------------------
int DataParser::getDOCOWorldWidth()
{
	return m_iWorldWidth;
}

//------------------------------------------------
// Get the height of the world
//------------------------------------------------
int DataParser::getDOCOWorldHeight()
{
	return m_iWorldHeight;
}

//------------------------------------------------
// Get the number of DOCOs in the world
//------------------------------------------------
int DataParser::getDOCOCount()
{
	return m_iNumDOCOs;
}

//--------------------------------------------------------------------------
// Get the information on a DOCO
// Args: movement - Pointer to character array to hold movement type string
//       xpos - Pointer to int into which starting X position of the DOCO
//					will be placed.
//       ypos - Pointer to int into which starting Y position of the DOCO
//					will be placed.
// Returns: TRUE if data is valid.  Returns FALSE when all DOCOs have been
//				read.
//--------------------------------------------------------------------------
bool DataParser::getDOCOData(char* movement, int* xpos, int* ypos)
{
	int dNum = 0;
	char line[128];
	// Reopen the file
	inFile = new ifstream();
	inFile->open(m_sFileName, fstream::in);
	if (inFile->is_open())
	{
		// Read to the the current DOCO count
		while (getNextLine(line, 127))
		{
			if (strcmp(line, "<DOCO>") == 0) // Got one
			{
				if (dNum == m_iNextDOCOIndex)
				{
					// Get data on this one
					while (getNextLine(line, 127))
					{
						// Get the type
						if (strcmp(line, "<MOVEMENT>") == 0)
						{
							if (getNextLine(line, 127))
							{
								strcpy(movement, line); // Set the movement style
							}
							else
								return false; // Oops!
						}
						else if (strcmp(line, "<XPOS>") == 0)
						{
							if (getNextLine(line, 127))
							{
								*xpos = atoi(line); // Set the X position
							}
							else
								return false; // Oops!
						}
						else if (strcmp(line, "<YPOS>") == 0)
						{
							if (getNextLine(line, 127))
							{
								*ypos = atoi(line); // Set the X position
							}
							else
								return false; // Oops!
						}
						else if (strcmp(line, "</DOCO>") == 0)
						{
							m_iNextDOCOIndex++; // Increment for next call to this function
							return true; // Got it
						}
					} // end while
				} // end if(sNum == nextSensor)
				else
				{
					dNum++; // Check the next one
				}
			}
		}
		inFile->close();
	} // end if file open
	return false; // If we get here we have got all the DOCOs
}

//------------------------------------------------
// Get the information on food
//------------------------------------------------
int DataParser::getFoodCount()
{
	return m_iFoodCount;
}

//------------------------------------------------
// Get obstacle count
//------------------------------------------------
int DataParser::getObstacleCount()
{
	return m_iObstacleCount;
}

//--------------------------------------------------------------------------
// Get the information on an obstacle
// Args: xpos - Pointer to int into which the X position of the obstacle
//					will be placed.
//       ypos - Pointer to int into which the Y position of the obstacle
//					will be placed.
// Returns: TRUE if data is valid.  Returns FALSE when all obstacles have 
//				been read.
//--------------------------------------------------------------------------
bool DataParser::getObstacleData(int* xpos, int* ypos)
{
	int dNum = 0;
	char line[128];
	// Reopen the file
	inFile = new ifstream();
	inFile->open(m_sFileName, fstream::in);
	if (inFile->is_open())
	{
		// Read to the the current Obstacle count
		while (getNextLine(line, 127))
		{
			if (strcmp(line, "<OBSTACLE>") == 0) // Got one
			{
				if (dNum == m_iNextObsIndex)
				{
					// Get data on this one
					while (getNextLine(line, 127))
					{
						// Get the xPOS
						if (strcmp(line, "<XPOS>") == 0)
						{
							if (getNextLine(line, 127))
							{
								*xpos = atoi(line); // Set the X position
							}
							else
								return false; // Oops!
						}
						else if (strcmp(line, "<YPOS>") == 0)
						{
							if (getNextLine(line, 127))
							{
								*ypos = atoi(line); // Set the X position
							}
							else
								return false; // Oops!
						}
						else if (strcmp(line, "</OBSTACLE>") == 0)
						{
							m_iNextObsIndex++; // Increment for next call to this function
							return true; // Got it
						}
					} // end while
				} // end if(sNum == nextSensor)
				else
				{
					dNum++; // Check the next one
				}
			}
		}
		inFile->close();
	} // end if file open
	return false; // If we get here we have got all the DOCOs
}

//------------------------------------------------
// Function: getNextLine()
// Purpose: Reads lines from a file and places
//   them in buffer, removing any leading white
//   space.  Skips blank lines. Ignors comment
//   lines starting with <!-- and ending with -->
//   
// Args:  buffer -- char array to read line into.
//        n -- length of buffer.
// Returns: True if a line was successfully read,
//    false if the end of file was encountered.
// Notes: Function provided by instructor.
//------------------------------------------------
bool DataParser::getNextLine(char* buffer, int n)
{
	bool    done = false;
	char    tempBuf[128];
	char* temp;
	while (!done)
	{
		inFile->getline(tempBuf, n); // Read a line from the file

		if (inFile->good())          // If a line was successfully read check it
		{
			if (strlen(tempBuf) == 0)     // Skip any blank lines
				continue;
			else if (strncmp(tempBuf, "<!--", 4) == 0) // Skip comment lines
				continue;
			else done = true;    // Got a valid data line so return with this line
		}
		else
		{
			strcpy(buffer, "");  // Clear the buffer array
			return false;        // Flag end of file
		}
	} // end while
	// Remove white space from end of string
	temp = &tempBuf[strlen(tempBuf)]; // point to closing \0
	temp--; // back up 1 space
	while (isspace(*temp))
	{
		*temp = '\0'; // Make it another NULL terminator
		temp--;  // Back up 1 char
	}
	// Remove white space from front of string
	temp = tempBuf;
	while (isspace(*temp)) temp++; // Skip leading white space
	// Copy remainder of string into the buffer
	strcpy(buffer, temp);
	return true;  // Flag a successful read
}
