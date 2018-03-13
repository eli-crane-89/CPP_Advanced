#include <atomic>

#include "X.h"

int main()
{

	//a) Create pointer and assign value
	PointerType x = PointerType(new X());
	x->val = 237;

	std::cout << "x use count: " << x.use_count() << std::endl;

	//b)
	PointerType x2 = PointerType(new X());
	x2->val = 305.64778;

	std::cout << "x use count: " << x.use_count() << std::endl;
	std::cout << "x2 use count: " << x2.use_count() << std::endl;

	//Atomically Store x2 in x
	std::atomic_store(&x, x2);
	std::cout << "After atomic store, x is now: " << x->val << std::endl;
	std::cout << "x use count: " << x.use_count() << std::endl;
	std::cout << "x2 use count: " << x2.use_count() << std::endl;

	//c)
	PointerType x3 = PointerType(new X());
	x3->val = 3237.13;

	std::cout << "x use count: " << x.use_count() << std::endl;
	std::cout << "x2 use count: " << x2.use_count() << std::endl;
	std::cout << "x3 use count: " << x3.use_count() << std::endl;

	//Exchange
	std::atomic_exchange(&x, x3);
	std::cout << "After first atomic exchange, x use count is now: " << x.use_count() << std::endl;
	std::cout << "After first atomic exchange, x2 use count is now: " << x2.use_count() << std::endl;
	std::cout << "After first atomic exchange, x3 use count is now: " << x3.use_count() << std::endl;
	std::atomic_exchange(&x2, x3);
	std::cout << "After second atomic exchange, x is now: " << x->val << std::endl;
	std::cout << "After second atomic exchange, x2 is now: " << x2->val << std::endl;
	std::cout << "After second atomic exchange, x3 is now: " << x3->val << std::endl;


	//d)
	std::cout << "x use count: " << x.use_count() << std::endl;
	std::cout << "x2 use count: " << x2.use_count() << std::endl;
	std::cout << "x3 use count: " << x3.use_count() << std::endl;

	//The use count of x increments to 2 after x2 is atomically stored, after x2 is exchanged its use count becomes tied to x3
	//The use count x2 increments to 2 after x2 is atomically stored, decrements to 1 when x3 is exchanged to x, then becomes tied x3 when it is exchanged
	//The use count of x3 has increments each time it is exchanged

	//e)
	//Because multiple threads could access a shared pointer at the same time, it is impossible to guarantee concurrency when accessing the object

	//f
	std::cout << std::boolalpha << "Shared pointers are lock free: " << std::atomic_is_lock_free(&x) << std::endl;

    return 0;
}

