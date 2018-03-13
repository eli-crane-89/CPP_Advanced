#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <chrono>

#include "Exercise2_AddCode.hpp"

using namespace std;

inline void Exercise2() {

	cout << endl << "Exercise2: " << endl;

	//a)
	string s1 = "Hello string!";
	string s2;

	s2 = std::move(s1);

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl << endl;

	//The moved string (s1) is now a blank string

	//b)
	int nRows = 100000;
	vector<int> vInt;
	for (int i = 0; i < nRows; i++) {
		vInt.push_back(i);
	}

	//Copy
	cout << "Time it takes to copy " << nRows << " rows:" << endl;
	std::chrono::time_point<std::chrono::system_clock> t_begin = std::chrono::system_clock::now();

	//Perform Copy
	vector<int> vIntCopy = vInt;

	std::chrono::time_point<std::chrono::system_clock> t_end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t_end - t_begin;

	cout << "Total seconds: " << elapsed_seconds.count() << endl;
	cout << "vInt has: " << vInt.size() << " rows." << endl;
	cout << "vIntCopy has: " << vIntCopy.size() << " rows." << endl << endl;

	//Move
	cout << "Time it takes to move " << nRows << " rows:" << endl;
	t_begin = std::chrono::system_clock::now();


	//Perform Move
	vIntCopy = std::move(vInt);

	t_end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds2 = t_end - t_begin;

	cout << "Total seconds: " << elapsed_seconds2.count() << endl;
	cout << "vInt has: " << vInt.size() << " rows." << endl;
	cout << "vIntCopy has: " << vIntCopy.size() << " rows." << endl << endl;

	cout << "Using move was approximately " << elapsed_seconds / elapsed_seconds2 << "x as fast." << endl << endl;
	//vInt was wiped to an array of size 0 after the move.

	//c) Swap Function

	vector<int> vSwap;
	for (int i = 0; i < nRows; i++) {
		vSwap.push_back(i);
	}

	//Copy Swap
	//There are 3 copies called
	cout << "Performing swap copy function" << endl << endl;
	t_begin = std::chrono::system_clock::now();

	//Perform copy swap
	SwapCopyStyle(vInt, vSwap);

	t_end = std::chrono::system_clock::now();
	elapsed_seconds = t_end - t_begin;

	cout << "Total seconds: " << elapsed_seconds.count() << endl;

	//Move Swap
	t_begin = std::chrono::system_clock::now();

	//Perform move swap
	SwapMoveStyle(vInt, vSwap);

	t_end = std::chrono::system_clock::now();
	elapsed_seconds2 = t_end - t_begin;

	cout << "Total seconds: " << elapsed_seconds2.count() << endl;

	cout << "Using move was approximately " << elapsed_seconds / elapsed_seconds2 << "x as fast." << endl << endl;
}

#endif