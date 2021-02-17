#pragma once
#include <iostream>
using namespace std;

class convert {
public:
	void getWord();
	void convertToASCII();
	void ASCIItoBinary();
	void letterToBin(int n);
	void fileManagement();

private:
	char word[256] = { 0 };
	int * asciiValues;
	int * binNum;
	int * binTranslation;
};
