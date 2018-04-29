#ifndef ORIGINPOINT_DEF
#define ORIGINPOINT_DEF

#include "Singleton.hpp"
#include "Point.hpp"

class OriginPoint : public Singleton<CAD::Point>
{
public:
	OriginPoint() {};
	OriginPoint(const OriginPoint & source) = delete;    // copy constructor

	// Assignment operator
	OriginPoint & operator = (const OriginPoint& source) = delete;

};

#endif // ! ORIGINPOINT_DEF
