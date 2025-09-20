// P02_bpalmer
// Sort Time Analysis
// Brandon Palmer
// CIS 221
// Dencler

#pragma once

// Include TimerHeader.h for methods utilizing timer
#include "TimerHeader.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class Analysis {
private:
	int* masterArray;
	int* workingArray;
	int fileSize;
	Timer analysisTime;
public:
	// Default Constructor
	Analysis();

	// Initializes masterArray and workingArray with all 0s based on number held in fileSize
	void AllocateArrays();

	// Deallocates all memory in master and workingArray in prep for next file or program finish
	void DeallocateArrays();

	// Parses file to determine size needed for arrays
	bool ParseFile(string inf);

	// Copies elements from file in to masterArray
	bool CopyFile(string inf);

	// Performs bubble sort on workingArray
	void BubbleSort();

	// Performs selection sort on workingArray
	void SelectionSort();

	// Performs insertion sort on workingArray
	void InsertionSort();
};