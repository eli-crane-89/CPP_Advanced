#include "Shape.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;


namespace CAD {
		
	Shape::Shape() {
		m_id = rand();
	}

	std::string Shape::ToString() const {

		//Use a stringstream
		std::stringstream ss;
		ss << "ID: " << m_id;

		//Convert to string
		return ss.str();
	}
		
	int Shape::ID() {
		return m_id;
	}

	void Shape::Print() const{
		cout << ToString() << endl;
	}

	Shape& Shape::operator = (const Shape& source) {
		if (this != &source) {
			m_id = source.m_id;
		}

		return *this;
	}

	Shape::~Shape() {
	}



}
