#ifndef EXACTDISTANCE_CPP
#define EXACTDISTANCE_CPP

#include <cmath>

#include "ExactDistance.hpp"


double ExactDistance::Distance(const CAD::Point& p1, const CAD::Point& p2) {

	return std::sqrt(std::pow(p1.Y() - p2.Y(), 2) + std::pow(p1.X() - p2.X(), 2));

}
#endif