#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int convertToInt(char* num);

int main() {
	char input[200];
	int array[100];
	
	char test1[5] = {'3', '1'};
	char test2[5] = {'4', '5'};
	char test3[5] = {'2'};
	char test4[5] = {'9', '8', '7'};

	cout << convertToInt(test1) << endl;
	cout << convertToInt(test2) << endl;
	cout << convertToInt(test3) << endl;
	cout << convertToInt(test4) << endl;


	/*cout << "Please enter a series of numbers separated by a space: ";
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
	}*/	
	return 0;
}

int convertToInt(char* num) {
	int fin = 0;
	int power = strlen(num) - 1;
	cout << power << endl;
	for (int i = 0; i < strlen(num); i++) {
		cout << num[i] << endl;
		cout << pow(10, power-i);
		cout << num[i] * pow(10, power-i) << endl;
		fin += num[i] * pow(10, power-i);
	}
	return fin;
}	
