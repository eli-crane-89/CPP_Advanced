
#include "CClasses.hpp"
#include "Point.hpp"

template<typename T>
using Shared = std::shared_ptr<T>;

int main()
{

	//b) Confirm use count of shared pointer
	std::shared_ptr<double> commonVal(new double(3.1415));
	cout << "The use count after initializating: " << commonVal.use_count() << endl; //1

	{
		C1<double> object1(commonVal);
		cout << "The use count after creating C1: " << commonVal.use_count() << endl; //2

		object1.print();
		cout << "The use count after printing C1: " << commonVal.use_count() << endl; //2
	}

	cout << "The use count after C1 exits scope: " << commonVal.use_count() << endl; //1

	{
		C2<double> object2(commonVal);
		cout << "The use count after creating C2: " << commonVal.use_count() << endl; //2

		object2.print();
		cout << "The use count after printing C2: " << commonVal.use_count() << endl; //2
	}

	cout << "The use count after C2 exits scope: " << commonVal.use_count() << endl; //1

	//Sharing commonVal
	std::shared_ptr<double> commonValCopy = commonVal;
	cout << "The use count after copy sharing equals: " << commonVal.use_count() << endl; //2
	cout << "The use count of commonValCopy equals: " << commonValCopy.use_count() << endl; //2

	//Assigning commonVal
	std::shared_ptr<double> commonValAssign;
	commonValAssign = commonVal;
	cout << "The use count after copy assigning equals: " << commonVal.use_count() << endl; //3
	cout << "The use count of commonValAssign equals: " << commonValAssign.use_count() << endl; //3

	//Compare
	if (commonValAssign == commonValCopy) {
		cout << "The two pointers are the same." << endl;
	}
	else {
		cout << "the two pointers are different" << endl;
	}

	//Transfer ownership
	std::shared_ptr<double> commonValNew = std::move(commonVal);
	if (commonVal == nullptr) {
		cout << "Ownership has been transferred" << endl; //This prints
	}

	//Check for unique
	if (commonValNew.unique()) {
		cout << "This is the sole owner of this resource." << endl;
	}
	else {
		cout << "This is not the sole owner of this resource." << endl; //This prints
	}

	//Swap pointers
	std::shared_ptr<double> swapPointer(new double(5.0));

	commonValNew.swap(swapPointer);

	cout << "The value of commonValNew is now: " << *commonValNew << " and the value of swapPointer is: " << *swapPointer; //Two values swapped
	cout << " and the value of commonValAssign is now: " << *commonValAssign << endl; //This still points to original memory
	cout << "The use count of commonValNew after swapping is now: " << commonValNew.use_count() << endl; //1
	cout << "The use count of commonValAssign after swapping is now: " << commonValAssign.use_count() << endl; //3

	//Give up ownership
	swapPointer.reset();
	cout << "The use count of commonValAssign after giving up ownership is now: " << commonValAssign.use_count() << endl; //2
	if (swapPointer == nullptr) {
		cout << "swapPointer has been reset." << endl; //This prints
	}

	//c) With user defined type
	cout << "\nPart c\n" << endl;

	std::shared_ptr<Point> commonPoint(new Point(3.1415,1.0));
	cout << "The use count after initializating: " << commonPoint.use_count() << endl; //1

	{
		C1<Point> object1_pt(commonPoint);
		cout << "The use count after creating C1<Point>: " << commonPoint.use_count() << endl; //2

		object1_pt.print();
		cout << "The use count after printing C1<Point>: " << commonPoint.use_count() << endl; //2
	}

	cout << "The use count after C1<Point> exits scope: " << commonPoint.use_count() << endl; //1

	{
		C2<Point> object2_pt(commonPoint);
		cout << "The use count after creating C2<Point>: " << commonPoint.use_count() << endl; //2

		object2_pt.print();
		cout << "The use count after printing C2<Point>: " << commonPoint.use_count() << endl; //2
	}

	cout << "The use count after C2<Point> exits scope: " << commonPoint.use_count() << endl; //1

	//Sharing commonPoint
	std::shared_ptr<Point> commonPointCopy = commonPoint;
	cout << "The use count after copy sharing equals: " << commonPoint.use_count() << endl; //2
	cout << "The use count of commonPointCopy equals: " << commonPointCopy.use_count() << endl; //2

	//Assigning commonPoint
	std::shared_ptr<Point> commonPointAssign;
	commonPointAssign = commonPoint;
	cout << "The use count after copy assigning equals: " << commonPoint.use_count() << endl; //3
	cout << "The use count of commonPointAssign equals: " << commonPointAssign.use_count() << endl; //3

	//Compare
	if (commonPointAssign == commonPointCopy) {
		cout << "The two pointers are the same." << endl;
	}
	else {
		cout << "the two pointers are different" << endl;
	}

	//Transfer ownership
	std::shared_ptr<Point> commonPointNew = std::move(commonPoint);
	if (commonPoint == nullptr) {
		cout << "Ownership has been transferred" << endl; //This prints
	}

	//Check for unique
	if (commonPointNew.unique()) {
		cout << "This is the sole owner of this resource." << endl;
	}
	else {
		cout << "This is not the sole owner of this resource." << endl; //This prints
	}

	//Swap pointers
	std::shared_ptr<Point> swapPointPointer(new Point(1.5, 5.0));

	commonPointNew.swap(swapPointPointer);

	cout << "The value of commonPointNew is now: " << *commonPointNew << " and the value of swapPPointointer is: " << *swapPointPointer; //Two values swapped
	cout << " and the value of commonPointAssign is now: " << *commonPointAssign << endl; //This still points to original memory
	cout << "The use count of commonPointNew after swapping is now: " << commonPointNew.use_count() << endl; //1
	cout << "The use count of commonPointAssign after swapping is now: " << commonPointAssign.use_count() << endl; //3

	//Give up ownership
	swapPointPointer.reset();
	cout << "The use count of commonPointAssign after giving up ownership is now: " << commonPointAssign.use_count() << endl; //2
	if (swapPointPointer == nullptr) {
		cout << "swapPointPointer has been reset." << endl; //This prints
	}

    return 0;
}

