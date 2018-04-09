#include <boost\unordered_set.hpp>
#include <iostream>
#include <set>

#include "Point.hpp"
#include "StopWatch.hpp"

using namespace Eli::CAD;

auto lPrintBoostMS = [](const boost::unordered_multiset<Point, Point>& um) {
	for (auto elem : um) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl;
};


auto lPrintMS = [](const std::multiset<Point, Point>& ms) {
	for (auto elem : ms) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl;
};



int main()
{
	StopWatch sw;

	//a)
	//This multiset used std::hash function
	std::cout << "a) Using std::hash\n";

	//Define multiset
	boost::unordered_multiset<Point, Point> um1;

	//Define Points
	Point p1(1, 2);
	Point p2(1, 3);

	//Emplace
	sw.StartStopWatch();
	um1.emplace(Point(1, 2));
	sw.StopStopWatch();
	std::cout << "Time to emplace Point(1, 2): " << sw.GetTime() << std::endl;

	sw.Reset();
	sw.StartStopWatch();
	um1.emplace(p1);
	sw.StartStopWatch();
	std::cout << "Time to emplace p1: " << sw.GetTime() << std::endl;

	//It is quicker to emplace an already constructed object, than emplace a new object

	//Inserts
	sw.Reset();
	sw.StartStopWatch();
	um1.insert(Point(1,3));
	sw.StopStopWatch();
	std::cout << "Time to insert Point(1, 2): " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	um1.insert(p2);
	sw.StopStopWatch();
	std::cout << "Time to insert p2: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	um1.emplace(p2);
	sw.StartStopWatch();
	std::cout << "Time to emplace p2 again to check for increase in time: " << sw.GetTime() << std::endl;

	//It is slower to insert p2 than to emplace p1, just to make sure that execution time was not increasing and that
	//was causing the discrepency, I emplaced p2 after, and it was still quicker. Again, inserting p2 was faster than
	//insert Point(1, 2)

	//Remove
	//Make copies
	auto um1_copy1 = um1;
	auto um1_copy2 = um1;

	sw.Reset();
	sw.StartStopWatch();
	um1_copy1.erase(p1); //Erase p1s
	um1_copy1.erase(p2); //Erase p2s
	lPrintBoostMS(um1_copy1);
	sw.StopStopWatch();
	std::cout << "Time to erase: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	um1_copy2.clear();
	sw.StopStopWatch();
	std::cout << "Time to clear: " << sw.GetTime() << std::endl;
	lPrintBoostMS(um1_copy2);

	//Clearing was quicker than erasing, makes sense since erase must compare each element

	//b)
	//This multiset used the custom function
	std::cout << "\nb) Using custom function\n";

	//clear multiset
	um1.clear();

	//Emplace
	sw.StartStopWatch();
	um1.emplace(Point(1, 2));
	sw.StopStopWatch();
	std::cout << "Time to emplace Point(1, 2): " << sw.GetTime() << std::endl;

	sw.Reset();
	sw.StartStopWatch();
	um1.emplace(p1);
	sw.StartStopWatch();
	std::cout << "Time to emplace p1: " << sw.GetTime() << std::endl;

	//My custom hash function was slower for the Point(1,2) emplacement, but faster for the p1 emplacement

	//Inserts
	sw.Reset();
	sw.StartStopWatch();
	um1.insert(Point(1, 3));
	sw.StopStopWatch();
	std::cout << "Time to insert Point(1, 2): " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	um1.insert(p2);
	sw.StopStopWatch();
	std::cout << "Time to insert p2: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	um1.emplace(p2);
	sw.StartStopWatch();
	std::cout << "Time to emplace p2 again to check for increase in time: " << sw.GetTime() << std::endl;

	//My custom hash function was slower to insert both Point(1,3) and p2, emplacing p2 again took immeasurably low time

	//Remove
	//Make copies
	um1_copy1 = um1;
	um1_copy2 = um1;

	sw.Reset();
	sw.StartStopWatch();
	um1_copy1.erase(p1); //Erase p1s
	um1_copy1.erase(p2); //Erase p2s
	lPrintBoostMS(um1_copy1);
	sw.StopStopWatch();
	std::cout << "Time to erase: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	um1_copy2.clear();
	sw.StopStopWatch();
	std::cout << "Time to clear: " << sw.GetTime() << std::endl;
	lPrintBoostMS(um1_copy2);

	//The custom function was slower to erase, but took the same time to clear. This makes sense since clearing does
	//not require a comparison


	//c)
	//This std::multiset uses std::hash function in comparator
	std::cout << "\nc) Using std::multiset and std::hash in the comparator\n";

	//Define multiset
	std::multiset<Point, Point> ms1;

	//Emplace
	sw.StartStopWatch();
	ms1.emplace(Point(1, 2));
	sw.StopStopWatch();
	std::cout << "Time to emplace Point(1, 2): " << sw.GetTime() << std::endl;

	sw.Reset();
	sw.StartStopWatch();
	ms1.emplace(p1);
	sw.StartStopWatch();
	std::cout << "Time to emplace p1: " << sw.GetTime() << std::endl;

	//It took less time to emplace Point(1,2) and the time difference was very small for emplacing p1

	//Inserts
	sw.Reset();
	sw.StartStopWatch();
	ms1.insert(Point(1, 3));
	sw.StopStopWatch();
	std::cout << "Time to insert Point(1, 2): " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	ms1.insert(p2);
	sw.StopStopWatch();
	std::cout << "Time to insert p2: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	ms1.emplace(p2);
	sw.StartStopWatch();
	std::cout << "Time to emplace p2 again to check for increase in time: " << sw.GetTime() << std::endl;

	//It was faster to insert Point(1,3) and p2 into the multiset than to emplace Point(1,2), but slower than emplacing p1


	//Remove
	//Make copies
	auto ms1_copy1 = ms1;
	auto ms1_copy2 = ms1;

	sw.Reset();
	sw.StartStopWatch();
	ms1_copy1.erase(p1); //Erase p1s
	ms1_copy1.erase(p2); //Erase p2s
	lPrintMS(ms1_copy1);
	sw.StopStopWatch();
	std::cout << "Time to erase: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	ms1_copy2.clear();
	sw.StopStopWatch();
	std::cout << "Time to clear: " << sw.GetTime() << std::endl;
	lPrintMS(ms1_copy2);

	//It was slower to erase the multiset, but faster to clear the std multiset

	//c)
	//This multiset used the custom function
	std::cout << "\nc) Using std::multiset and custom hash function in comparator\n";

	//clear multiset
	ms1.clear();

	//Emplace
	sw.StartStopWatch();
	ms1.emplace(Point(1, 2));
	sw.StopStopWatch();
	std::cout << "Time to emplace Point(1, 2): " << sw.GetTime() << std::endl;

	sw.Reset();
	sw.StartStopWatch();
	ms1.emplace(p1);
	sw.StartStopWatch();
	std::cout << "Time to emplace p1: " << sw.GetTime() << std::endl;

	//The custom function is slower to emplace Point(1,2), but it takes the same time to emplace p1 as the std::hash function 

	//Inserts
	sw.Reset();
	sw.StartStopWatch();
	ms1.insert(Point(1, 3));
	sw.StopStopWatch();
	std::cout << "Time to insert Point(1, 2): " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	ms1.insert(p2);
	sw.StopStopWatch();
	std::cout << "Time to insert p2: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	ms1.emplace(p2);
	sw.StartStopWatch();
	std::cout << "Time to emplace p2 again to check for increase in time: " << sw.GetTime() << std::endl;

	//It was slower to insert Point(1,3) and p2 into the multiset than the boost unordered multiset

	//Remove
	//Make copies
	ms1_copy1 = ms1;
	ms1_copy2 = ms1;

	sw.Reset();
	sw.StartStopWatch();
	ms1_copy1.erase(p1); //Erase p1s
	ms1_copy1.erase(p2); //Erase p2s
	lPrintMS(ms1_copy1);
	sw.StopStopWatch();
	std::cout << "Time to erase: " << sw.GetTime() << std::endl;
	sw.Reset();
	sw.StartStopWatch();
	ms1_copy2.clear();
	sw.StopStopWatch();
	std::cout << "Time to clear: " << sw.GetTime() << std::endl;
	lPrintMS(ms1_copy2);

	//It was slower to both erase and clear the std multiset over the boost multiset

	


    return 0;
}

