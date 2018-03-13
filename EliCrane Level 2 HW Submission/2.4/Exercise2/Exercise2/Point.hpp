
class Point {
private:
	double _x;
	double _y;

public:
	Point(double x, double y) : _x(x), _y(y) {};

	void X(double x) { _x = x; };
	double X() { return _x; };
	void Y(double y) { _y = y; };
	double Y() { return _y; };

	//Overload << operator to print
	friend ostream& operator<<(ostream& os, const Point& pt) {
		os << "The point exists at (" << pt._x << "," << pt._y << ")";
		return os;
	}
};