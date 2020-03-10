#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

int convertToInt(char* num);
void swap(int place1, int place2, int* &array);
int findLastNode(int* array);
int* inputToInt(char* input);
int* fileToInt(char* fileName);
int* heapify(int* array);

int main() {
	char input[200];
	char fileName[50];
	char forC[10];
	int* array;
	int* sArray;

	cout << "Please enter whether you would like to input through file or console: ";
	cin.get(forC, 10);
	cin.ignore(10, '\n');

	if (strcmp(forC, "FILE") == 0) {
		cout << "Please enter a file name: ";
		cin.get(fileName, 50);
		cin.ignore(50, '\n');
		array = fileToInt(fileName);
	}
	else if (strcmp(forC, "CONSOLE") == 0) {
		cout << "Please enter a series of numbers separated by a space: ";
		cin.get(input, 200);
		cin.ignore(200, '\n');
		array = inputToInt(input);	
	}
	else {
		cout << "Please enter FILE or CONSOLE." << endl;
	}	

	sArray = heapify(array);

	return 0;
}

int convertToInt(char* num) {
	int fin = 0;
	int power = strlen(num) - 1;
	for (int i = 0; i < strlen(num); i++) {
		int digit = num[i] - '0';
		fin += digit * pow(10, power-i);
	}
	return fin;
}	

void swap(int place1, int place2, int* &array) {
	int temp = array[place1];
	array[place1] = array[place2];
	array[place2] = temp;
}

int* inputToInt(char* input) {
	int arrayIndex = 1;
	int array[100];
	array[0] = -1;
	for (int i = 0; i < strlen(input); i++) {
		if (!isspace(input[i]) && isdigit(input[i])) {
			int index = 0;
			char* num = new char[5];
			num[index] = input[i];
			index++;
			while (!isspace(input[i+1])) {
				i++;
				num[index] = input[i];
			        index++;
			}
			array[arrayIndex] = convertToInt(num);
		        arrayIndex++;
		}
	}
	for (int i = 0; i < arrayIndex; i++) {
		cout << array[i] << endl;
	}
	return array;
}

int* fileToInt(char* fileName) {
	char input[200];
	int* array;
	ifstream file(fileName);
	if (file.is_open()) {
		file.getline(input, 200);
		file.close();
		array = inputToInt(input);	
		return array;
	}
	else {
		cout << "Unable to open file." << endl;
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

void heapify(int* &array, int size) {
	/*for (int i = 0; i < size_of(array); i++) {
	}	
	array[0] = -1;
	int n = 1;
	int largest = array[n];
	if (largest < array[2n]) {
		swap(n, 2n, array);
		largest = array[n];
	}*/
	int start = (size/2) - 1;

	for (int i = start; i > 0; i--) {
		int compare = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		 
		if (left < size && array[left] > array[compare]) {
			compare = left;
		}
		if (right < size && array[right] > array[compare]) {
			compare = right;
		}
		if (compare != i) {
			swap(compare, i, array);
		}
	}	
}
