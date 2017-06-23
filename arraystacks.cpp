/*
  Choy, Oscar
  CS A200
  February 4, 2016
  
  This is a program that implements two stacks into a single array. In works in conjuction with
  a program that does the following: It prompts the user to enter the maximum possible number of
  integers that will be entered for the purposes of being sorted into the two stacks. It will then
  prompt the user to actually enter the numbers to be sorted. The program will then sort the numbers
  into the two stacks. One stack, the "SmallValues" stack, will contain only the numbers that are
  below 1000. The other stack, "LargeValues", will contain only the numbers that are above 1000. The
  functions "printSmallValues" and "printLargeValues" will then print out the entries in their
  respective stacks.
*/

#include <iostream>

using namespace std;

void processStacks(int givenArray[], int arrSize, int smallCount, int bigCount);
void printSmallValues(int givenArray[], int smallCount);
void printLargeValues(int givenArray[], int arrSize, int largeCount);

int main() {
	int lowCount = -1, highCount, arraySize;

	cout << "Enter max number of integers: ";
	
	cin >> arraySize;

	highCount = arraySize;
	int *intArray = new int[arraySize];

	processStacks(intArray, arraySize, lowCount, highCount);

	delete intArray;

	system("Pause");
	return 0;
}
// This is the "processStacks" function. It does most of the actual work of prompting the
// user to enter the integers, and stores then in the stacks, both of which are implemented
// in the same array.
void processStacks(int givenArray[], int arrSize, int smallCount, int bigCount) {

	int inputNum;

	cout << "Enter integers (-1 to quit): ";
	cin >> inputNum;

	while (inputNum >= 0) {
		if (inputNum > 1000) {
			bigCount--;
			givenArray[bigCount] = inputNum;
		} else {
			smallCount++;
			givenArray[smallCount] = inputNum;
		}
		cin >> inputNum;
	}

	printSmallValues(givenArray, smallCount);
	printLargeValues(givenArray, arrSize, bigCount);
}
// This is the "printSmallValues" function. It prints out all the values entered into
// the "smallValues stack", implemented in the same array as the "largeValues stack".
void printSmallValues(int givenArray[], int smallCount) {
	cout << "\nStack with small values: ";
	while (smallCount >= 0) {
		cout << givenArray[smallCount] << " ";
		smallCount--;
	}
	cout << endl;
}

// This is the "printLargeValues" function. It prints out all the values entered into
// the "largeValues stack", implemented in the same array as the "smallValues stack".
void printLargeValues(int givenArray[], int arrSize, int largeCount) {
	cout << "Stack with large values: ";
	while (largeCount < arrSize) {
		cout << givenArray[largeCount] << " ";
		largeCount++;
	}
	cout << "\n" << endl;
}
