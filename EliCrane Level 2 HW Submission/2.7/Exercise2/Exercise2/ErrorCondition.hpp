#ifndef ERRORCONDITION_HPP
#define ERRORCONDITION_HPP

#include <tuple>
#include <string>

//Create Alias
using tupError = std::tuple<std::string, int, std::string>;

//Create function to return tuple
tupError parseErrorCond(std::error_condition& ec) {

	tupError te = std::make_tuple(ec.message(), ec.value(),ec.category().name());

	return te;
}

#endif