#ifndef PROPOSITION_HPP
#define PROPOSITION_HPP

#include <bitset>

// A class representing true/false
class Proposition
{
private:
	std::bitset<1> data;
public:

	//Constructors
	Proposition();
	Proposition(bool);
	Proposition(std::bitset<1>);

	//Boolean operators
	Proposition operator==(const Proposition&);
	Proposition operator!=(const Proposition&);
	Proposition operator&(const Proposition&);
	//Proposition operator&(const bool); //For when a bool is encountered
	Proposition operator|(const Proposition&);
	//Proposition operator|(const bool); //For when a bool is encountered
	Proposition operator^(const Proposition&);
	friend Proposition operator %(const Proposition&, const Proposition&);
	friend Proposition operator>(const Proposition&, const Proposition&); //biconditional, use > since does not have meaning for class
	friend std::ostream& operator<<(std::ostream&, const Proposition&);
	Proposition operator!();

	//Assign bool
	operator bool();
};




#endif // !PROPOSITION_HPP
