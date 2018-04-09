#include "Line.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

namespace Eli {
	namespace CAD {

		Line::Line() : Shape(), startPoint(Point()), endPoint(Point()) {}

		Line::Line(Point start, Point end) : Shape(), startPoint(start), endPoint(end) {}

		Line::Line(const Line& line) : Shape(line), startPoint(line.startPoint), endPoint(line.endPoint) {}

		void Line::StartPoint(Point start) {
			startPoint = start;
		}

		Point Line::StartPoint() const {
			return startPoint;
		}

		void Line::EndPoint(Point end) {
			endPoint = end;
		}

		Point Line::EndPoint() const {
			return endPoint;
		}
		std::string Line::ToString() const {

			std::string s = Shape::ToString();

			//Use a stringstream
			std::stringstream ss;
			ss << setprecision(5) << "The line has a length of: " << Line::Length();
			ss << " with " << s;
			ss << " and starts at " << startPoint.ToString() << " and ends at " << endPoint.ToString();

			//Convert to string
			return ss.str();
		}

		double Line::Length() const {

			//Returns distance from the end point to the start point
			return endPoint.Distance(startPoint);
		}

		void Line::Draw() const {
			cout << "This draws " << Line::ToString() << endl;
		}

		Line& Line::operator = (const Line& source) {
			if (this != &source)
			{
				Shape::operator=(source);
				startPoint = source.startPoint;
				endPoint = source.endPoint;
			}

			return *this;
		}

		std::ostream& operator << (std::ostream& stream, const Line& line) {
			stream << setprecision(5) << "The line has a length of: " << line.Length();
			stream << " and starts at " << line.startPoint << " and ends at " << line.endPoint << endl;

			return stream;
		}

		//Delegates functionality to the hash_value
		std::size_t hash_value(const Line& line) {
			return Eli::CAD::hash_value(line.startPoint) + Eli::CAD::hash_value(line.endPoint);
		}

		Line::~Line() {
		}
	}
}
