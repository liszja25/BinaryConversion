#include "conversion.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

ofstream binFile;

void convert::getWord() {
	bool correctWord = false;
	while (correctWord == false) {
		int i;
		cout << "Enter word to convert to binary: ";
		cin.getline(word, 255, '\n');
		cout << "Your word is: " << word << endl;
		cout << "Is this correct?\n"
			"1. Yes\n"
			"2. No" << endl;
		cout << "Your Choice: ";
		cin >> i;
		switch (i) {
		case 1:
			char filename[256];
			cout << "File Name: ";
			cin.ignore();
			cin.getline(filename, 255, '\n');
			cout << "Opening File For Writing..." << endl;
			correctWord = true;
			binFile.open(filename, ios::out | ios::app);
			if (binFile.is_open()) {
				binFile << "Word: " << word << endl;
			}
			else {
				cerr << "Error: Failed to open file for writing. Please try again." << endl;
				exit(1);
			}
			break;
		case 2: 
		default: 
			correctWord = false;
			cout << "I am sorry I misunderstood, please try again" << endl;
			cin.ignore();
			break;
		}
	}
}

void convert::convertToASCII() {
	int wordLen = strlen(word);
	asciiValues = new int[wordLen];
	for (int i = 0; i < wordLen; i++) {
		asciiValues[i] = int(word[i]);
	}
	cout << "The ASCII values for \"" << word << "\" are:" << endl;
	if (binFile.is_open()) {
		binFile << "ASCII Values: ";
	}
	else {
		cerr << "Error: Failed to write ASCII Values to file. Program terminated. Please try again." << endl;
		exit(2);
	}
	for (int j = 0; j < wordLen; j++) {
		if (j == wordLen - 1) {
			cout << asciiValues[j] << endl;
			if (binFile.is_open()) {
				binFile << asciiValues[j] << endl;
			}
			else {
				cerr << "Error: Failed to write ASCII Values to file. Program terminated. Please try again." << endl;
				exit(2);
			}
		}
		else {
			cout << asciiValues[j] << ", ";
			if (binFile.is_open()) {
				binFile << asciiValues[j] << ", ";
			}
			else {
				cerr << "Error: Failed to write ASCII Values to file. Program terminated. Please try again." << endl;
				exit(2);
			}
		}
	}

}

void convert::letterToBin(int n) {
	binNum = new int[32];
	int binNumber[32];
	int i, number;
	stringstream data;
	i = 0;
	while (n > 0) {
		binNumber[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
			cout << binNumber[j];
			if (binFile.is_open()) {
				binFile << binNumber[j];
			}
			else {
				cerr << "Error: Failed to write Binary Values to file. Program terminated. Please try again." << endl;
				exit(3);
			}
	}
}

void convert::ASCIItoBinary() {
	int wordLen = strlen(word);
	for (int i = 0; i < wordLen; i++) {
		letterToBin(asciiValues[i]);
		cout << " - " << word[i] << endl;
		if (binFile.is_open()) {
			binFile << " - " << word[i] << endl;
		}
		else {
			cerr << "Error: Failed to write Binary Values to file. Program terminated. Please try again." << endl;
			exit(4);
		}
	}
}

void convert::fileManagement() {
	if (binFile.is_open()) {
		binFile << "**************************************** \n" << endl;
		binFile.close();
		cout << "All Data Written Successfully" << endl;
	}
}