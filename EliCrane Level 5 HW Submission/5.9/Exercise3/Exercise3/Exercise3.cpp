#include <boost\signals2.hpp>
#include <iostream>
#include <algorithm>
#include <vector>

struct BootstrapCheck
{
	// Iterate in slots and return first 'false'
	// value; otherwise, 'true'
	typedef bool result_type;

template <typename InputIterator>
bool operator()(InputIterator first, InputIterator last) const
{
	while (first != last)
	{
		if (!*first)
			return false;
		++first;
	}
	return true;
}
};

int main()
{
	//b)
	boost::signals2::signal<bool(), BootstrapCheck> sig;
	sig.connect([] {return true; });
	sig.connect([] {return false; });
	sig.connect([] {return true; });

	//c)
	sig();

	std::cout << sig() << std::endl;
	//Returns false because of second slot

    return 0;
}

