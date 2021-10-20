#include <Python.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>
#include "cornergrocer.h"

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int CallIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
	NAME: DisplayMenu()
	DESCRIPTION: Displays the main menu for collecting user input
	PARAMS: none
	RETURNS: none
*/
void DisplayMenu() {

	//Display the main menu
	cout << "*********************************************" << endl;
	cout << "***            Grocery Tracker            ***" << endl;
	cout << "*********************************************\n" << endl;
	cout << "1. Purchase counts" << endl;
	cout << "2. Specific item purchase count" << endl;
	cout << "3. Display purchase histogram" << endl;
	cout << "4. Exit the program" << endl;
	cout << "Please enter your selection (1, 2, 3, or 4): ";

}

/*
	NAME: NumberOfTimesEach()
	DESCRIPTION: Runs Python function "CountAllItems()". Counts all items in ProgramInput.txt 
				 file and outputs the counts
	PARAMS: none
	RETURNS: none
*/
void NumberOfTimesEach() {

	//Run the Python function "CountAllItems"
	CallProcedure("CountAllItems");

}

/*
	NAME: NumberOfTimesSpecific(string itemName)
	DESCRIPTION: Runs Python function "CountSpecificItem(x)". Counts number of times itemName
				 occurs in ProgramInput.txt
	PARAMS: string itemName - name of item to be searched for
	RETURNS: 1
*/
int NumberOfTimesSpecific(string itemName) {

	// Output the # of times the item was purchased, returned from Python function CountSpecificItem(x)
	cout << "\n" << itemName << " was purchased " << CallIntFunc("CountSpecificItem", itemName) << " time(s)\n" << endl;

	// return 1
	return 1;

}

/*
	NAME: DisplayHistogram()
	DESCRIPTION: Runs Python function "WriteFrequencies()" to write frequency.dat. Gets each count
				 from frequency.dat and outputs a histogram for each item type purchased
	PARAMS: none
	RETURNS: none
*/
void DisplayHistogram() {

	/*
		VARIABLE DECLARATIONS
			ifstream inFS :  file input stream used to read frequency.dat
			string currLine :  used to store each line of the file while processing
			int lineCount :  tracks the # of the line being read, starting at 1 
			int i :  used in 'For' loop
	*/
	ifstream inFS;
	string currLine;
	int lineCount, i;

	//Run Python function "WriteFrequencies", which writes frequencies to frequency.dat
	CallProcedure("WriteFrequencies");

	//Open the 'frequency.dat' file
	inFS.open("frequency.dat");

	//If the file fails to open...
	if (!inFS.is_open()) {

		//Output an error message and exit
		cout << "Error loading file \'frequency.dat\'" << endl;
		exit;

	}

	//Set lineCount's initial value to 1
	lineCount = 1;

	//Output newline for formatting
	cout << "\n";

	//While there is content left to read in the file...
	while (!inFS.eof()) {

		//The next line is assigned to currLine
		inFS >> currLine;

		//If the current line's lineCount is odd (item name)...
		if (lineCount % 2 != 0) {

			//Output the line contents as an item name - right aligned, min width
			cout << setw(15) << right << currLine << " ";
		}

		//If the current line's lineCount is even (item count)...
		else {

			//Loop a number of times equal to the int value of currLine (the item count)...
			for (i = 0; i < stoi(currLine); ++i) {

				//Print asterisk
				cout << "*";

			}

			//Newline after each item's histogram
			cout << endl;

		}

		//Increment lineCount for the next line's value
		lineCount++;
	}

	//Close the file 'frequency.dat'
	inFS.close();

	//End with a final newline for formatting purposes
	cout << "\n";
}