#ifndef DISTANCESTRATEGY_HPP
#define DISTANCESTRATEGY_HPP

#include "Point.hpp"

namespace CAD {
	class Point;
}

class DistanceStrategy {
public:
	virtual double Distance(const CAD::Point&, const CAD::Point&) = 0;
};
#endif
