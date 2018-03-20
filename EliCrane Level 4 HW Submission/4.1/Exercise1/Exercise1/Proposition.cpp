
#include <bitset>

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

//Operators
Proposition Proposition::operator==(const Proposition& propComp) {
	if (Proposition::data[0] == propComp.data[0]) {
		return Proposition(true);
	}

	return false;
}

Proposition Proposition::operator!=(const Proposition& propComp) {
	if (Proposition::data[0] != propComp.data[0]) {
		return Proposition(true);
	}

	return false;
}

Proposition Proposition::operator&(const Proposition& propComp) {
	if (Proposition::data[0] && propComp.data[0]) {
		return Proposition(true);
	}

	return false;
}

//Proposition Proposition::operator&(const bool bl) {
//	//Only return true if Prop is true and bool is true
//	if (Proposition::data[0] == bl == true) {
//		return true;
//	}
//
//	return Proposition(false);
//}
//
//Proposition Proposition::operator|(const bool bl) {
//	//Return true if Prop is true or bool is true
//	if (Proposition::data[0] == true || bl == true) {
//		return Proposition(true);
//	}
//
//	return Proposition(false);
//}

Proposition Proposition::operator|(const Proposition& propComp) {
	if (Proposition::data[0] | propComp.data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

Proposition Proposition::operator^(const Proposition& propComp) {
	if (propComp.data[0] | Proposition::data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

Proposition Proposition::operator!() {
	if (!Proposition::data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

Proposition operator%(const Proposition& propCompA, const Proposition& propCompB) {
	if (propCompA.data[0] && propCompB.data[0]) {
		return Proposition(true);
	}
	else if (!propCompA.data[0]){
		return Proposition(true);
	}

	return Proposition(false);
}

Proposition operator>(const Proposition& propCompA, const Proposition& propCompB) {
	if (propCompA.data[0] == propCompB.data[0]) {
		return Proposition(true);
	}

	return Proposition(false);
}

std::ostream& operator<<(std::ostream& stream, const Proposition& prop) {
	stream << std::boolalpha << prop.data[0];
	return stream;
}

Proposition::operator bool()  {
	return Proposition::data[0];
}




