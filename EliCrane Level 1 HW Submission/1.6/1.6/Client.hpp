#ifndef Client_HPP
#define Client_HPP

#include <list>

// C++ 98 approach
// Data storage types
template <typename T> struct Storage
{
	// Possible ADTs and their memory allocators
	// typedef std::vector<T, CustomAllocator<T>> type;
	// typedef std::vector<T, std::allocator<T>> type;

	typedef std::list<T, std::allocator<T>> type;

};

template<typename T>
using type = std::list<T, std::allocator<T>>;

template <typename T>
class Client
{
	// An example of Composition
private:
	typename type<T> data; // typename mandatory
						   //typename Storage<T>::type data; // typename mandatory
public:
	Client(int n, const T& val) : data(n, val) {}
	void print() const {
		std::for_each(data.begin(), data.end(),
			[](const T& n) { std::cout << n << ","; });
		std::cout << '\n';
	}
};

#endif