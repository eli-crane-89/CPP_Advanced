#include <memory>
#include <iostream>

using namespace std;

int main()
{

	//a)

	using std::auto_ptr;
	// Define auto_ptr pointers instead of raw pointers
	std::auto_ptr <double> d(new double(1.0));

	// Dereference
	*d = 2.0;

	// Change ownership of auto_ptr
	// (after assignment, d is undefined)
	auto_ptr <double> d2 = d;
	*d2 = 3.0;

	//cout << "Auto values: " << *d.get() << ", " << *d2.get();

	//Runtime exception of: Unhandled exception thrown: read access on d

	//b) reimplmenet with unique pointer
	
	using std::unique_ptr;
	
	// Define auto_ptr pointers instead of raw pointers
	std::unique_ptr <double> du(new double(1.0));

	// Dereference
	*du = 2.0;

	// Change ownership of auto_ptr
	// (after assignment, d is undefined)
	unique_ptr <double> du2 = std::move(du);
	*du2 = 3.0;

	cout << "Unique values: " << *du.get() << ", " << *du2.get();

	////Runtime exception of: Unhandled exception thrown: read access on du, changing to unique pointer did not fix error


    return 0;
}

