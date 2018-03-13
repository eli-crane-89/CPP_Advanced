#ifndef  DEPRECATED_HPP
#define DEPRECATED_HPP

#include <iostream>

//Global variable
int[[deprecated("Pluto is not a planet.")]] numOfPlanets = 9;

//Global Function
[[deprecated("Use new function")]] void GlobalDepFunc() {};


//Deprecated Class
class [[deprecated("Use New class")]] DepClass{};


//Class with deprecated member
class NewClass{

public:

	[[deprecated("This is a deprecated function.")]] void depMember(int& noPlanets) {};
};

//Deprecated enum
enum [[deprecated("Small planets no longer accurate")]] SmallPlanets{ Pluto, Mercury };

//Deprecated enum class
enum class[[deprecated("Only 1 class remain")]] day {sun, mon};

//Deprecated Template Class
template<typename T>
class DepTemplate {};

//Specialization
template<>
class [[deprecated("Calling int on this template is deprecated.")]] DepTemplate<int> {};

//Lambda Function
[[deprecated("The lambda is down.")]] auto depLambda = []() {};


#endif // ! DEPRECATED_HPP