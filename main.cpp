#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int convertToInt(char* num);

int main() {
	char input[200];
	int array[100];
	
	cout << "Please enter a series of numbers separated by a space: ";
	cin.get(input, 200);
	cin.ignore(200, '\n');
	
	char* num;
	int arrayIndex = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (!isspace(input[i])) {
			int index = 0;
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
