#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <functional>
#include <iostream>

#include <boost\thread.hpp>

using FunctionType = std::function<double(double)>;

class Command
{
private:
	long ID; // priority of command
	FunctionType algo;
public:
	Command(const FunctionType& algorithm, long priority)
		: algo(algorithm), ID(priority) {}

	void Execute(double x) const {
		// Introduce delay to simulate a heavy algorithm
		boost::this_thread::sleep(
			boost::posix_time::millisec(5000));
		std::cout << algo(x) << '\n';
	}

	//changed to long return type
	long priority() const
	{
		return ID;
	}

	
};

//a) Comparator
struct CommandComparator {
	bool operator()(const Command& lhs, const Command& rhs) const {
		return lhs.priority() > rhs.priority();
	}
};

#endif