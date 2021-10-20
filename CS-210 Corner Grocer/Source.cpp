#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include "cornergrocer.h"

using namespace std;

int main()
{
	int userCommand;
	string userItem;

	//Display initial menu and get user's initial input
	DisplayMenu();
	cin >> userCommand;

	//Loop while the user hasn't chosen to exit...
	while (userCommand != 4) {

		//If a valid int was entered...
		if (userCommand) {

			//Take action based on user command
			switch (userCommand) {

				// User selected '1. Purchase counts'
				case 1:
					// Count the item frequency for each item and output
					NumberOfTimesEach();

					break;

				// User selected '2. Specific item purchase count'
				case 2:

					//Prompt the user to specify the item to look for
					cout << "Which item would you like to look for?: ";
					cin >> userItem;

					//Count the # of times it appears in the file and output the count
					NumberOfTimesSpecific(userItem);

					break;

				// User selected '3. Display purchase histogram'
				case 3:

					// Create frequency.dat, then display a histogram based on the information
					DisplayHistogram();

					break;

				// Any other user input
				default:

					//Display error message
					cout << "\nInvalid input.\n" << endl;

					break;
			}

		}
		//User entered invalid non-int
		else {

			//Display error message
			cout << "\nInvalid input. Please enter an integer.\n" << endl;

			//Clear and ignore cin buffer
			cin.clear();
			cin.ignore();

		}

		//Display menu and ask user for another input
		DisplayMenu();
		cin >> userCommand;

	}

	//Display goodbye message before exiting program
	cout << "\nGoodbye.\n";

	/*CallProcedure("printsomething");
	cout << callIntFunc("PrintMe", "House") << endl;
	cout << callIntFunc("SquareValue", 2);*/

}