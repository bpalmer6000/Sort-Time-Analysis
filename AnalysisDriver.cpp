// P02_bpalmer
// Sort Time Analysis
// Brandon Palmer
// CIS 221
// Dencler

#include "AnalysisHeader.h"

using namespace std;

int main() {
	
	Analysis sort;

	/* If Parsing or Copying fails (indicated by false return value)
	an error message is displayed and code continues. Otherwise sorts normally.*/
	cout << "Populating Arrays... <500 elements>" << endl;
	if (sort.ParseFile("NumFile500.txt")) {
		sort.AllocateArrays();
		sort.CopyFile("NumFile500.txt");
		cout << "Sorting..." << endl;
		sort.BubbleSort();
		sort.InsertionSort();
		sort.SelectionSort();
		cout << "SORTS COMPLETE!" << endl << endl;
		
	}
	sort.DeallocateArrays();


	cout << "Populating Arrays... <5000 elements>" << endl;
	if (sort.ParseFile("NumFile5K.txt")) {
		sort.AllocateArrays();
		sort.CopyFile("NumFile5K.txt");
		cout << "Sorting..." << endl;
		sort.BubbleSort();
		sort.InsertionSort();
		sort.SelectionSort();
		cout << "SORTS COMPLETE!" << endl << endl;
	}
	sort.DeallocateArrays();


	cout << "Populating Arrays... <25000 elements>" << endl;
	if (sort.ParseFile("NumFile25K.txt")) {
		sort.AllocateArrays();
		sort.CopyFile("NumFile25K.txt");
		cout << "Sorting..." << endl;
		sort.BubbleSort();
		sort.InsertionSort();
		sort.SelectionSort();
		cout << "SORTS COMPLETE!" << endl << endl;
	}
	sort.DeallocateArrays();


	cout << "Populating Arrays... <100000 elements>" << endl;
	if (sort.ParseFile("NumFile100K.txt")) {
		sort.AllocateArrays();
		sort.CopyFile("NumFile100K.txt");
		cout << "Sorting..." << endl;
		sort.BubbleSort();
		sort.InsertionSort();
		sort.SelectionSort();
		cout << "SORTS COMPLETE!" << endl << endl;
	}
	sort.DeallocateArrays();

	cout << "ANALYSIS COMPLETE..." << endl << "PRESS ANY KEY TO CONTINUE.";
}