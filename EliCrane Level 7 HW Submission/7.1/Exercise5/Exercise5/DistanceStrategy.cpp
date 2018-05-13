#ifndef DISTANCESTRATEGY_CPP
#define DISTANCESTRATEGY_CPP

#include "DistanceStrategy.hpp"
#include "Point.hpp"

DistanceStrategy::DistanceStrategy() {};
DistanceStrategy::DistanceStrategy(std::function<double(const CAD::Point&, const CAD::Point&)> strat) : _func(strat) {};

DistanceStrategy::~DistanceStrategy() {};

void DistanceStrategy::SetStrategy(std::function<double(const CAD::Point&, const CAD::Point&)> strat) {
	_func = strat;
};

double DistanceStrategy::Distance(const CAD::Point& p1, const CAD::Point& p2) const{
	return _func(p1, p2);
}


#endif