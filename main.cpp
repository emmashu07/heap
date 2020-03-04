#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

struct Node {
	int data;
};

int convertToInt(char* num);
int* inputToInt(char* input);
int* fileToInt(char* fileName);

int main() {
	char input[200];
	char fileName[50];
	char forC[10];
	int* array;

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

int* inputToInt(char* input) {
	int arrayIndex = 0;
	int array[100];
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
