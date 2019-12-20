// mitkadem3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Compiler.h"
using namespace std;
int main(int argc, char* argv[]){
	fstream input_file;
	if (argc < 2) {
		std::cout << "please provide file name!";
		exit(0);
	}
	//open file
	input_file.open(argv[1], ios::in);
	if (!input_file) {
		throw "could not open file!";
	}
	std::cout << "main program started";
	Compiler cm;
	cm.read(input_file);
	

    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
