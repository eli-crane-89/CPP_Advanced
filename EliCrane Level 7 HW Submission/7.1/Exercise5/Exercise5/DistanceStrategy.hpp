#ifndef DISTANCESTRATEGY_HPP
#define DISTANCESTRATEGY_HPP

#include <functional>

namespace CAD {
	class Point;
}


class DistanceStrategy {
private: 
	std::function<double(const CAD::Point&, const CAD::Point&)> _func;

public:
	//Constructors and Destructor
	DistanceStrategy(); //Default allows initialization without parameters
	DistanceStrategy(std::function<double(const CAD::Point&, const CAD::Point&)>);
	~DistanceStrategy();

	//Helper Methods
	void SetStrategy(std::function<double(const CAD::Point&, const CAD::Point&)>);
	double Distance(const CAD::Point&, const CAD::Point&) const;
	

};
#endif
