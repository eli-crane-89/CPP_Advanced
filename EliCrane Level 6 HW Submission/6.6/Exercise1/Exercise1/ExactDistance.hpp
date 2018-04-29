#ifndef EXACTDISTANCE_HPP
#define EXACTDISTANCE_HPP

#include "DistanceStrategy.hpp"

class ExactDistance : public DistanceStrategy {

public:
	double Distance(const CAD::Point&, const CAD::Point&);

};

#endif