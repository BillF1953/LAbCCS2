
/*********************************************************************
** Program Filename: main Lab C
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: A program the reads a file into a dynamic array then reverses its text. 
** Input: example.txt (With some text in the file), example1.txt 
** Output: The text in example.txt reversed and written to example1.txt
** Citations:http://www.cplusplus.com/doc/tutorial/files/ and http://www.cplusplus.com/forum/general/76107/ and http://code.runnable.com/UpSpP5ymsslIAAFo/reading-a-file-into-an-array-for-c%2B%2B-and-fstream
********************************************************************/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "InputValid.hpp"


using std::ifstream;
using std::cout;
using std::ofstream;
using std::endl;


int main() {
		void displayMenu();
		int getChoice(InputValid);
		void continueOn(InputValid);
		int choice;
		char recursive(char* first, char* last);
		InputValid valid = InputValid();  // creates validation
		

	
		do {

			char b[75];
			char b1[75];
			int array_size = 50; // define the size of character array
			char * array = new char[array_size]; // allocating an array of 1kb
			int position = 0; //this will be used incremently to fill characters in the array 

			displayMenu();
			choice = getChoice(valid);

			if (choice == 1) {

				cout << "Please enter file name. This file will be opened" << endl;

				std::cin.getline(b, 75);   

				cout << "Please enter a file name. The string will be saved in this file. " << endl;
									
				std::cin.getline(b1, 75);


				cout << endl;
				

				ifstream fin(b); //opening an input stream for file test.txt

				try {
					/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
					stream could not be opened.*/
					if (!(fin.is_open())) {

						throw 10;  // throws error
					}

					//file opened successfully so we are here
					cout << "Reading data from file into array" << endl << endl;
					//this loop run until end of file (eof) does not occur
					while (!fin.eof())  // returns true when the end of the file is reached
					{
						if (position == array_size) {
							// doubles size of array
							int oldSize = array_size;  // for replacement
							array_size = array_size + array_size; // array size doubles
							char * array2 = new char[array_size];   // creates new array of double size

							for (int i = 0; i < oldSize; i++) {

								array2[i] = array[i];  // copy values to new array

							}

							delete[] array; // delete old array
							array = array2; // assign array point to new array of double size

						}

						fin.get(array[position]); //reading one character from file to array
						position++;

					}
					array[position - 1] = '\0'; //placing character array terminating character

					if (array[0] == '\0') {

						throw 'a';
					}

					cout << "Printing Data in Array." << endl;
					//this loop display all the charaters in array till \0 
					for (int i = 0; array[i] != '\0'; i++)
					{
						cout << array[i];
					}
					cout << endl << endl;

					continueOn(valid);
				}
			
				catch (int x) // catches int error
				{
					cout << "File could not be opened. Exiting program now." << endl << endl;
					break; 
				}
				catch (char a) { // char for no data in file

					cout << "File has no data. Exiting program now." << endl << endl; // throws error for no data
					break;

				}

				/*********************************************************************
				** Section: Swaps Array
				** Description: Changes every letters position. For example Hello World becomes dlroW olleH
				** Parameters: array
				** Pre-Conditions: Array must have values
				** Post-Conditions: Swapped Array written to example.txt
				** Citation: http://www.cplusplus.com/doc/tutorial/files/ "Input/output with files" Accessed July 5, 8:30 pm
				*********************************************************************/

				cout << "Swapping array" << endl;

				recursive(array, array + position - 2); // sends array to be swapped

				for (int i = 0; array[i] != '\0'; i++)
				{
					cout << array[i];  // prints swapped array
				}
				cout << endl << endl;

				continueOn(valid);

				/*********************************************************************
				** Section: writes to file
				** Description: writes to file
				** Parameters: example.txt, array
				** Pre-Conditions: file must be read in and recursed
				** Post-Conditions: end of main
				** Citation: http://www.cplusplus.com/doc/tutorial/files/ "Input/output with files" Accessed July 5, 8:30 pm
				*********************************************************************/

				ofstream myfile1(b1);
				try {

					if (!(myfile1.is_open())) // if file cannot be opened throws error
					{
						throw 10;
					}
					{
						for (int i = 0; array[i] != '\0'; i++) {

							myfile1 << array[i];


						}
						cout << "Reversed String written to file, "; 
						myfile1.close();
					}
				}
				catch (...)  // catchs any exception type  
				{
					cout << "File could not be opened. Exiting program now."; // prints out unable to open file
					break; 
				}
			}

			cout << "returning to main menu. " << endl << endl;

		}while (choice != 2);
		
		return 0;
	}

/*********************************************************************
** Function: recursive
** Description: swaps an array
** Parameters: two char pointers, one to the first value in the array and one to the last
** Pre-Conditions: main() called after file read in. 
** Post-Conditions: file written out. 
** Citation: http://www.cplusplus.com/forum/general/76107/ "JL Borges" Posted: July 27, 2012 at 9:12 am
	*********************************************************************/

char recursive(char* first, char* last){


	if (first < last)  // breaks when "last" elements cross "first" elements
		{
			std::swap(*first, *last);     // swaps first and last items
			recursive(first + 1, last - 1); // increments recursion by moving 1 forward from the front and 1 back from the back
		}
	
}

/*********************************************************************
** Function: displayMenu
** Description: Displays Menu of Options for Sum Game
** Parameters: void
** Pre-Conditions: Start of Program
** Post-Conditions: getChoice()
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


void displayMenu() {


	cout << "\nWelcome to Lab C\nPlease Select a Number\n\n";
	cout << "1. Pick Text Files to be Read In and Written out in Reverse.\n";
	cout << "2. Quit the Program\n\n";


}
/*********************************************************************
** Function:  getChoice
** Description: gets number of Choice
** Parameters:  InputValid
** Pre-Conditions: DisplayMenu()
** Post-Conditions: Switch and Array Entry
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


int getChoice(InputValid valid) {

	int choice;
	choice = valid.validateInt();
	while (choice < 1 || choice > 2) {

		cout << "The only valid choices are 1 or 2. Please re-enter.\n";
		choice = valid.validateInt();

	}

	return choice;




}


/*********************************************************************
** Function:  continueOn
** Description: Pauses program after tasks
** Parameters: InputValid
** Pre-Conditions: switch case 1, case 2 and case 3
** Post-Conditions: displaymenu()
** Citation:
*********************************************************************/

void continueOn(InputValid valid) {
	char entry = '0';
	do {


		cout << "Please enter 'c' to continue.\n";
		entry = valid.validateChar();



	} while (entry != 'c');

}












