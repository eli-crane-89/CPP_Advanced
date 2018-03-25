
#include <bitset>
#include <iostream>

#include "Proposition.hpp"

//Constructors
Proposition::Proposition() : data(std::bitset<1>()) {};

Proposition::Proposition(bool bl) {
	if (bl) {
		data = std::bitset<1>("1");
	}
	else {
		data = std::bitset<1>();
	}
};

Proposition::Proposition(std::bitset<1> bst) : data(bst) {};

const bool Proposition::operator==(const Proposition& propComp) const{

	if (Proposition::data[0] == propComp.data[0]) {
		return true;
	}
	return false;
}

const bool Proposition::operator!=(const Proposition& propComp) const{
	if (Proposition::data[0] != propComp.data[0]) {
		return true;
	}

	return false;
}

const Proposition Proposition::operator&(const Proposition& propComp) const{
	if (Proposition::data[0] && propComp.data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

const Proposition Proposition::operator|(const Proposition& propComp) const{
	if (Proposition::data[0] | propComp.data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

const Proposition Proposition::operator^(const Proposition& propComp) const {
	if (propComp.data[0] | Proposition::data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

const Proposition Proposition::operator!() const{
	if (!Proposition::data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

const Proposition operator%(const Proposition& propCompA, const Proposition& propCompB) {
	if (propCompA.data[0] && propCompB.data[0]) {
		return Proposition(true);
	}
	else if (!propCompA.data[0]){
		return Proposition(true);
	}

	return Proposition(false);
}

const Proposition operator>(const Proposition& propCompA, const Proposition& propCompB) {
	if (propCompA.data[0] == propCompB.data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

std::ostream& operator<<(std::ostream& stream, const Proposition& prop) {
	stream << std::boolalpha << prop.data[0];
	return stream;
}

Proposition::operator bool() {
	return Proposition::data[0];
}




