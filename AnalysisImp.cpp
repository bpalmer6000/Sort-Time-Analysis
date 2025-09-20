// P02_bpalmer
// Sort Time Analysis
// Brandon Palmer
// CIS 221
// Dencler

#include "AnalysisHeader.h"

// Defualt Constructor
Analysis::Analysis() {
	this->fileSize = 0;
	this->masterArray = NULL;
	this->workingArray = NULL;
	this->analysisTime;
}

// Initializes masterArray with all 0s based on number held in fileSize
void Analysis::AllocateArrays() {
	this->masterArray = new int[this->fileSize];
	this->workingArray = new int[this->fileSize];

	for (int i = 0; i < fileSize; i++) {
		this->masterArray[i] = 0;
		this->workingArray[i] = 0;
	}
}

// Deallocates all memory in working and masterArray in prep for next file or program finish
void Analysis::DeallocateArrays() {
	
	if (this->masterArray != NULL) {
		delete[] this->masterArray;
	}

	if (this->workingArray != NULL) {
		delete[] this->workingArray;
	}
}

/* Parses file to determine size needed for masterArray. Successful parsing
returns true. Unsuccessful parsing returns false.*/
bool Analysis::ParseFile(string inFile) {
	
	// Resets fileSize to 0 any time a new file is parsed
	this->fileSize = 0;

	// Local variable used to check that there is input left in a file
	string line = "";

	// Open file with read permission
	ifstream inputHandle(inFile , ios::in);

	// Check for file open
	if (inputHandle.is_open() == true) {
		// While there are lines left to read fileSize is incremented
		while (inputHandle >> line) {
			this->fileSize++;
		}
		// Closes file and returns true for successful parsing
		inputHandle.close();
		return true;
	}
	// Unsuccessful file opening results in error message and false return value
	else {
		cout << "ERROR: The file \"" << inFile << "\" could not be opened for reading..." << endl;
		return false;
	}
}

/* Copies file elements to masterArray. Successful copying returns true. 
Unsuccessful copying returns false.*/
bool Analysis::CopyFile(string inFile) {
	
	// Local variable to check that input from file is an integer value
	int checkInt = 0;

	// Used for index count
	int i = 0;

	// Open file with read permission
	ifstream inputHandle(inFile, ios::in);

	// Check for file open
	if (inputHandle.is_open() == true) {
		 
		// If file is open iterate through list, copying file values to respective array indexes
		for (int i = 0; i < this->fileSize; i++){
			// If input is an integer, add it to masterArray at index i
			if (inputHandle >> checkInt) {
				this->masterArray[i] = checkInt;
			}
			// Otherwise inform user and prompt for valid input
			else {

				cout << "Malformed input detected on line " << i << "." << endl;
				inputHandle.clear();
				inputHandle.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				rewind(stdin);

				cout << "Enter a number to substitute for the malformed value: ";
				cin >> this->masterArray[i];

				while (cin.fail()) {
					cout << "That is not a valid integer entry. Please try again." << endl;
					cin.clear();
					rewind(stdin);

					cout << "Enter a number to substitute for the malformed value: ";
					cin >> this->masterArray[i];
				}
			}
		}
		inputHandle.close();
		return true;
	}
	// Unsuccessful file opening results in error message and false return value
	else {
		cout << "ERROR: The file \"" << inFile << "\" could not be copied..." << endl;
		return false;
	}
}

// Performs bubble sort and displays sort time as soon as sort is finished.
void Analysis::BubbleSort() {

	// Copying masterArray to workingArray
	for (int i = 0; i < this->fileSize; i++) {
		this->workingArray[i] = this->masterArray[i];
	}

	bool swap = true;

	// Resets timer before sort
	analysisTime.Reset();

	// Starts timer as sort begins
	analysisTime.Start();

	while (swap == true) {
		swap = false;
		for (int i = 0; i <= this->fileSize - 2; i++) {
			int j = i + 1;
			if (this->workingArray[i] > this->workingArray[j]) {
				int temp = this->masterArray[j];
				this->workingArray[j] = this->workingArray[i];
				this->workingArray[i] = temp;
				swap = true;
			}
		}
	}

	// Stops timer when sort finishes
	analysisTime.Stop();

	cout << fixed << left << setw(32) << "Elapsed Time <Bubble Sort>" << ":";
	analysisTime.DisplayTimerInfo();
}

// Performs selection sort and displays sort time as soon as sort is finished.
void Analysis::SelectionSort() {

	// Copying masterArray to workingArray
	for (int i = 0; i < this->fileSize; i++) {
		this->workingArray[i] = this->masterArray[i];
	}

	// Resets timer before sort
	analysisTime.Reset();

	// Starts timer as sort begins
	analysisTime.Start();

	for (int i = 0; i < this->fileSize - 1; i++) {
		int currentMin = i;
		for (int j = i + 1; j < this->fileSize; j++) {
			if (this->workingArray[j] < this->workingArray[currentMin])
				currentMin = j;
		}

		int tempNum = this->workingArray[i];
		this->workingArray[i] = this->workingArray[currentMin];
		this->workingArray[currentMin] = tempNum;
	}

	// Stops timer when sort finishes
	analysisTime.Stop();

	cout << fixed << left << setw(32) << "Elapsed Time <Selection Sort>" << ":";
	analysisTime.DisplayTimerInfo();
}

// Performs insertion sort and displays sort time as soon as sort is finished.
void Analysis::InsertionSort() {

	// Copying masterArray to workingArray
	for (int i = 0; i < this->fileSize; i++) {
		this->workingArray[i] = this->masterArray[i];
	}

	int currentValue = 0;
	
	// Resets timer before sort
	analysisTime.Reset();

	// Starts timer as sort begins
	analysisTime.Start();

	for (int i = 1; i < this->fileSize; i++) {
		int j = i - 1;
		currentValue = this->workingArray[i];
		while (this->workingArray[j] > currentValue && j >= 0) {
			this->workingArray[j + 1] = this->workingArray[j];
			j--;
		}
		this->workingArray[j + 1] = currentValue;
	}
	// Stops timer when sort finishes
	analysisTime.Stop();

	cout << fixed << left << setw(32) << "Elapsed Time <Insertion Sort>" << ":";
	analysisTime.DisplayTimerInfo();
}