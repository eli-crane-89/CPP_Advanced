#ifndef CONSOLESHAPEFACTORY_HPP
#define CONSOLESHAPEFACTORY_HPP

#include <tuple>

#include "ShapeFactory.hpp"

template<typename... Shapes>
class ConsoleShapeFactory : public ShapeFactory {
private:
	//Functions for shape creation
	void MakeShape(std::shared_ptr<CAD::Point>&);
	void MakeShape(std::shared_ptr<CAD::Line>&);
	void MakeShape(std::shared_ptr<CAD::Circle>&);

	//Function to iterate through variable length tuple
	//Must be implemented in header
	template <std::size_t ... Is>
	std::tuple<Shapes...> CreateShapeTuple(std::index_sequence<Is...>)
	{
		std::tuple<Shapes...> res;

		//Calls Make Shape with std::shared_ptr
		const int dummy[] = { 0, (MakeShape(std::get<Is>(res)), 0)... };
		static_cast<void>(dummy); // Avoid warning for unused variable.

		return res;
	}

public:
	//Constructor and Destructor
	ConsoleShapeFactory();
	~ConsoleShapeFactory();

	//Create Object Function
	std::tuple<Shapes...> CreateShapeTuple();
};

#ifndef CONSOLESHAPEFACTORY_CPP
#include "ConsoleShapeFactory.cpp"
#endif


#endif // !CONSOLESHAPEFACTORY_HPP
