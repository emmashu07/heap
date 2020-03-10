/*
 * Emma Shu, 3/10/2020: Heap utilizes a heapsort algorithm to build a max heap from an
 * input by converting it to an integer array and building the heap.
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

int convertToInt(char* num);
void swap(int place1, int place2, int* array);
//int findLastNode(int* array);
int inputToInt(char* input, int* array);
int fileToInt(char* fileName, int* array);
void heapify(int* array, int index, int size);
void makeHeap(int* array, int size);

int main() {
	char input[200];
	char fileName[50];
	char forC[10];
	int* array = new int[100];
	int size;

	cout << "Please enter whether you would like to input through file or console: ";
	cin.get(forC, 10);
	cin.ignore(10, '\n');

	if (strcmp(forC, "FILE") == 0) {
		cout << "Please enter a file name: ";
		cin.get(fileName, 50);
		cin.ignore(50, '\n');
		size = fileToInt(fileName, array);
	}
	else if (strcmp(forC, "CONSOLE") == 0) {
		cout << "Please enter a series of numbers separated by a space: ";
		cin.get(input, 200);
		cin.ignore(200, '\n');
		size = inputToInt(input, array);	
	}
	else {
		cout << "Please enter FILE or CONSOLE." << endl;
	}	

	makeHeap(array, size);

	return 0;
}

int convertToInt(char* num) { // Using a char array, make an int.
	int fin = 0;
	int power = strlen(num) - 1;
	for (int i = 0; i < strlen(num); i++) {
		int digit = num[i] - '0';
		fin += digit * pow(10, power-i);
	}
	return fin;
}	

void swap(int place1, int place2, int* array) { // Exchange two nodes in an array.
	int temp = array[place1];
	array[place1] = array[place2];
	array[place2] = temp;
}

int inputToInt(char* input, int* array) { // Take the input and convert it into an int array.
	int arrayIndex = 1;
	array[0] = -1;
	for (int i = 0; i < strlen(input); i++) {
		if (!isspace(input[i]) && isdigit(input[i])) {
			int index = 0;
			char* num = new char[3];
			num[index] = input[i];
			index++;
			while (!isspace(input[i+1])) {
				i++;
				num[index] = input[i];
			        index++;
			}
			num[index] = '\0';
			array[arrayIndex] = convertToInt(num);
		        arrayIndex++;
		}
	}
	cout << "Original: ";
	for (int i = 1; i < arrayIndex; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
	return arrayIndex;
}

int fileToInt(char* fileName, int* array) { // File input to int array, utilizes input to int.
	char input[200];
	int size;
	ifstream file(fileName);
	if (file.is_open()) {
		file.getline(input, 200);
		file.close();
		size = inputToInt(input, array);	
		return size;
	}
	else {
		cout << "Unable to open file." << endl;
		return -1;
	}
}	

// Failed algorithm.
/*int findLastNode(int* array) {
	int depth = 0;
	int lastNode;
	int size = pow(2, depth);
	while (size_of(array) > size) {
		num++;
		size += pow(2, depth);
	}
	lastNode = size - pow(2, depth);
	while (2*lastNode > size_of(array)) {
		lastNode--;
	}
	return lastNode;
}*/

void heapify(int* array, int index, int size) { // Compares to child nodes and swaps accordingly, recursive.
	int compare = index; // Original node.
	int left = 2 * index; // Left child node.
	int right = 2 * index + 1; // Right child node.
	 
	if (left <= size && array[left] > array[compare]) {
		compare = left;
	}
	if (right <= size && array[right] > array[compare]) {
		compare = right;
	}
	if (compare != index) {
		swap(compare, index, array);
		heapify(array, compare, size);
	}
}

void makeHeap(int* array, int size) { // Build a heap, pseudocode used: https://www.cc.gatech.edu/classes/cs3158_98_fall/heapsort.html
	/*for (int i = 0; i < size_of(array); i++) {
	}	
	array[0] = -1;
	int n = 1;
	int largest = array[n];
	if (largest < array[2n]) {
		swap(n, 2n, array);
		largest = array[n];
	}*/
	int start = (size/2) - 1; // Start at the first non-leaf node.

	for (int i = start; i > 0; i--) {
		heapify(array, i, size);
	}		
	
	/*int span = size / 2 + 1;
	int depth = log(span) / log(2);
		
	for (int i = size; i > 0; i--) {
		int index = 0;
		while (index < depth) {
			cout << '\t';
			index++;
		}
	}*/
		

	cout << "Heapsort: ";
	for (int i = 1; i < size; i++) {
		cout << array[i] << ' ';
		array[i] = -1;
	}
	cout << endl;
}
