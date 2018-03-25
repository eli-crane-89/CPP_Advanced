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
	const bool operator== (const Proposition&) const;
	const bool operator!= (const Proposition&) const;
	const Proposition operator& (const Proposition&) const;
	const Proposition operator| (const Proposition&) const;
	const Proposition operator^ (const Proposition&) const;
	friend const Proposition operator% (const Proposition&, const Proposition&);
	friend const Proposition operator> (const Proposition&, const Proposition&); //biconditional, use > since does not have meaning for class
	friend std::ostream& operator<< (std::ostream&, const Proposition&);
	const Proposition operator! () const;

	//Assign bool
	operator bool();
};




#endif // !PROPOSITION_HPP
