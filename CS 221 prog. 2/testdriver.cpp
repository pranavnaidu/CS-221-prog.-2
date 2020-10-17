//Pranav Naidu, CS-221-02, Programming Assignment 2
//******************************************************

//includes the header files, the necessary libraries for the program
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "QueType.h"
#include "CountedQueType.h"

using namespace std;

// create objects for each class
CountedQueType countedQueue(5);
QueType queue;

int line_count = 0;

int main() {

	// Declarations

	string inString[25];
	string command, var_memo;
	double var_amount;
	int i = 0, length_of_inputString = 0, blank_pos = 0, curr_pos = 0, blank_count = 0;
	bool end_of_string;

	//file identifiers and files used
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");

	//reads the input file and loads line contents into in-memory input array.
	while (getline(inFile, inString[i])) {
		i++;
	}

	line_count = i;

	// for each input line, identify command to be executed, and perform the command action.

	for (i = 0; i < 30; i++) {
		// Using blank space between words in input line as a delimiter 
		// split command from input array 

		length_of_inputString = inString[i].length();

		end_of_string = false;
		curr_pos = 0;
		blank_count = 0;
		var_amount = 0;
		command = "";
		var_memo = "";

		while (!end_of_string) { // find space character in input and split string into components

			blank_pos = 0;
			blank_pos = inString[i].find(" ", curr_pos + 1);

			if (blank_pos == -1 && blank_count == 0) {
				command = inString[i];
				blank_count++;
			}
			else
			{
				blank_count++;
				switch (blank_count) {  //switch case for the input array contents, depending on how many blanks are in the line.
				case 1:
					command = inString[i].substr(curr_pos, (blank_pos - curr_pos));
					break;
				case 2:
					var_memo = inString[i].substr(curr_pos + 1, (blank_pos - curr_pos - 1));
					break;
				case 3:
					var_amount = stod(inString[i].substr(curr_pos + 1, (blank_pos - curr_pos - 1)));
					break;
				}
				curr_pos = blank_pos;

			}

			if (blank_count > 0 && blank_pos == -1) {
				end_of_string = true;

			}
		}
		inFile.close();  //closed the input file
		cout << "Command is: " << command << endl;

		// project steps

		countedQueue.new_item.memo = var_memo;
		countedQueue.new_item.amount = var_amount;

		// insert steps for each command ... if command = get user, then do corresponding function... 

		if (command == "GetLength") { //gets the length of the list

			cout << "The list has " << countedQueue.GetLength() << " items in it." << endl << endl;
			outFile << "Number of items in the list: " << countedQueue.GetLength() << endl;
		}

		else if (command == "GetTotalExpense") {  //returns the sum of the expenses

			var_amount = 0;
			var_amount = countedQueue.GetTotalExpenses();
			cout << "Get Total Expenses command executed. The total expenses are: " << var_amount << endl << endl;
			outFile << "The total expense cost is: " << var_amount << endl;
		}

		else if (command == "Enqueue") { //puts the item into the queue

			if (countedQueue.GetLength() < 5) {
				countedQueue.Enqueue(countedQueue.new_item);
				cout << countedQueue.GetLength() << " items in the list." << endl << endl;
				outFile << countedQueue.GetLength() << " items in the list." << endl;
			}
			else {
				cout << "The list is full. " << endl << endl;
			}

		}

		else if (command == "Dequeue") {  //deletes the item from the list

			countedQueue.Dequeue(countedQueue.new_item);

			cout << "Delete Item command executed. There are now " << countedQueue.GetLength() << " items in the list." << endl << endl;
			outFile << countedQueue.GetLength() << " items in the list." << endl;
		}

		else if (command == "IsFull") { //returns true if the list is full, false if not full.

			cout << "Is Full command executed." << endl;

			if (countedQueue.isFull()) {
				cout << "The list is full. " << endl << endl;
				outFile << "The list is full. " << endl;
			}

			else {
				cout << "The list is not full. " << endl << endl;
				outFile << "The list is not full. " << endl;
			}
		}

		else if (command == "MakeEmpty") { //makes the list empty and ready for new items

			countedQueue.MakeEmpty();
			cout << "Make Empty command executed. The list is now empty. " << endl << endl;
			outFile << "The list is now empty." << endl;
		}

		else if (command == "IsEmpty") {  //returns a boolean value of whether the queue is empty or not.
			cout << "Is Empty command executed." << endl << endl;
			if (countedQueue.isEmpty()) {
				cout << "The list is empty." << endl << endl;
				outFile << "The list is empty." << endl;
			}
			else {
				cout << "The list is not empty" << endl << endl;
				outFile << "The list is not empty." << endl;
			}
		}

		else if (command == "Quit") {  //exits the program
			cout << "Processed quit command. All contents are on output.txt" << endl << endl;
			outFile << "Quit" << endl;
			outFile.close();
			exit(0);
		}
	}

}

