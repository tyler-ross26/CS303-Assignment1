#include "Functions.h"

// Function to find an integer in the array
void find(int array[], int size, int num) {
	for (int i = 0; i < size; i++) {
		if (array[i] == num) {
			cout << num << " located at index " << i << endl;
			return;
		}
	}
	cout << "Integer not found" << endl;
}

// Function to modify an element at a specific index in the array
void modify(int array[], int index, int newVal, int oldVal) {
	oldVal = array[index];
	array[index] = newVal;
	cout << "Old value: " << oldVal << endl;
	cout << "New value: " << newVal << endl;
}

// Function to add a new value to the array
void add(int*& array, int& size, int& newVal) {
	array[size++] = newVal;
	cout << "Value added" << endl;
}

// Function to replace an element at a specific index with zero
void replace(int array[], int index) {
	array[index] = 0;
	cout << "Value replaced" << endl;
}
