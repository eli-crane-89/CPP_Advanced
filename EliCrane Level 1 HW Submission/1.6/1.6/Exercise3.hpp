#ifndef EXERCISE3_HPP
#define EXERCISE3_HPP

struct B
{
	explicit B(int) {} //Remove explicit from the line for everything to conpile
	explicit B(int, int) {}
	explicit operator int() const { return 0; }
};

void Exercise3() {
	std::cout << std::endl << "Exercise3: " << std::endl;

	//B b1 = 1; // a) this line does not compile because of explict B(int) constructor
	B b2(3); // b
	B b3{ 7,3 }; // c
	B b4 = (B)42; // d
}

#endif