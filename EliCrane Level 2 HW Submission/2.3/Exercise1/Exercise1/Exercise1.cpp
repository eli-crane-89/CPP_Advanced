#include <iostream>

#include "Deprecated.hpp"

using namespace std;

int main()
{
	//I am unable to build the project and instead get errors.

	GlobalDepFunc(); //Throws Compiler Error C4996 and then 'GlobalDepFunc', followed by my custom message
	int nPlanets = numOfPlanets;  //Same compiler error with class name and custom message
	DepClass dc = DepClass(); //Same compiler error with class name and custom message
	NewClass nc = NewClass();  
	nc.depMember(nPlanets); //Same compiler error with class name and custom message
	SmallPlanets sp = Pluto; //Same compiler error with class name and custom message
	day d = day::sun; //Same compiler error with class name and custom message
	int i = 4;
	DepTemplate<int> tc = DepTemplate<int>(); //Same compiler error with class name and custom message
	depLambda(); //Same compiler error with class name and custom message



    return 0;
}

