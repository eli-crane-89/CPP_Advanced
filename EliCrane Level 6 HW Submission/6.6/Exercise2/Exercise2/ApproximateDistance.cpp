#ifndef APPROXIMATEDISTANCE_CPP
#define APPROXIMATEDISTANCE_CPP

#include <cmath>

#include "ApproximateDistance.hpp"

double ApproximateDistance::Distance(const CAD::Point& p1, const CAD::Point& p2) {

	return std::abs(p1.Y() - p2.Y()) + std::abs(p1.X() - p2.X());

}
#endif