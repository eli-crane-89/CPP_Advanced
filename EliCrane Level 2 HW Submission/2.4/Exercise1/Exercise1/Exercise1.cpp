#include <iostream>
#include <memory>

#include "Point.hpp"

//d)
//Define typedef
template<typename T>
using UniquePointer = std::unique_ptr<T>;

int main()
{

	//a)
	//{  
	//	try {// Block with raw pointer lifecycle
	//		double* d = new double(1.0);
	//		Point* pt = new Point(1.0, 2.0);// Two-d Point class

	//		//Throw error
	//		throw 20;

	//		// Dereference and call member functions
	//		*d = 2.0;
	//		(*pt).X(3.0);// Modify x coordinate
	//		(*pt).Y(3.0);// Modify y coordinate

	//					 // Can use operators for pointer operations
	//		pt->X(3.0);// Modify x coordinate
	//		pt->Y(3.0);// Modify y coordinate

	//		// Explicitly clean up memory (if you have not forgotten)
	//		delete d;
	//		delete pt;
	//	}

	//	catch (int e){
	//		throw "Delete not called leaving dangling raw pointers";
	//	}
	//}

	//b
	//{
	//	try {// Use unique pointers
	//		UniquePointer<double> d(new double(1.0));
	//		UniquePointer<Point> pt(new Point(1.0, 2.0));// Two-d Point class

	//		//Throw error
	//		throw 20;

	//		// Dereference and call member functions
	//		*d = 2.0;
	//		(*pt).X(3.0);// Modify x coordinate
	//		(*pt).Y(3.0);// Modify y coordinate

	//		// Can use operators for pointer operations
	//		pt->X(3.0);// Modify x coordinate
	//		pt->Y(3.0);// Modify y coordinate

	//		// No longer need delete
	//		//delete d;
	//		//delete pt;
	//	}

	//	catch (int e) {
	//		throw "Unique pointers automatically cleaned up";
	//	}
	//}

	//c)
	Point* rawPoint = new Point(3.0, 4.5);
	
	//Set unique pointers equal to same raw pointer
	UniquePointer<Point> pt1(rawPoint);
	//UniquePointer<Point> pt2(rawPoint); //Throws run time error

	//Assigning a unique pointer to another unique pointer
	UniquePointer<double> d1(new double(7.0));
	//UniquePointer<double> d2 = d1; //Compile error, it is a deleted function

	//Transfer pointer ownership
	UniquePointer<double> d3 = std::move(d1); //Move semantics to transfer ownership

	//Check for ownership transfer
	if (d1 == nullptr) {
		std::cout << "d1 ownership transferred to d3, which now has a value of: " << *d3 << std::endl;
	}


    return 0;
}

