#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
using namespace std;

namespace Eli {
	namespace CAD {
		class Shape;
	}
}

class Eli::CAD::Shape {
private:
	int m_id;

public:

	//Constructors
	Shape();

	//Helper Methods
	virtual std::string ToString() const;
	int ID();
	virtual void Draw() const = 0;
	void Print() const;


	//Operator overload functions
	Shape& operator = (const Shape&);

	//Destructor
	virtual ~Shape();

};
#endif
