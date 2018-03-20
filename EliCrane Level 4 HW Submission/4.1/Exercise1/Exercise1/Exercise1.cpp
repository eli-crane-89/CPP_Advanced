#include <iostream>

#include "Proposition.hpp"

int main()
{

	//a)
	Proposition p_def = Proposition(); //default
	Proposition p_bool = Proposition(true); //bool
	Proposition p_bitset = Proposition(std::bitset<1>("1")); //with true bitset
	Proposition p_bitset2 = Proposition(std::bitset<1>("0")); //for second false proposition

	//b)
	std::cout << std::boolalpha << "Equal to: " << (p_bool == p_bitset) << std::endl;
	std::cout << std::boolalpha << "Not Equal to: " << (p_def != p_bitset2) << std::endl;
	std::cout << std::boolalpha << "Or: " << (p_def | p_bool) << std::endl;
	std::cout << std::boolalpha << "And: " << (p_def & p_bool) << std::endl;
	std::cout << std::boolalpha << "Xor: " << (p_def ^ p_bool) << std::endl;
	std::cout << std::boolalpha << "Conditional1: " << (p_def % p_bool) << std::endl;
	std::cout << std::boolalpha << "Conditional2: " << (p_bool % p_def) << std::endl;
	std::cout << std::boolalpha << "BiConditional: " << (p_def % p_bitset2) << std::endl;
	std::cout << std::boolalpha << "Not: " << (!p_def) << std::endl;

	//Assignment
	bool bl = p_def;
	std::cout << std::boolalpha << "Assignment1: " << bl << std::endl;
	bl = p_bitset;
	std::cout << std::boolalpha << "Assignment2: " << bl << std::endl;

	//c)
	std::cout << "Demorgan's Laws:\n";
	std::cout << "NOT (A OR B) == NOT(A) AND NOT(B): " << (!(p_def | p_bool) == (!p_def & !p_bool)) << std::endl;
	std::cout << "NOT (A AND B) == NOT(A) OR NOT(B): " << (!(p_def & p_bool) == (!p_def | !p_bool)) << std::endl;

	//d)
	std::cout << "Distributive Laws:\n";
	std::cout << "A AND(B OR C) == (A AND B) OR (A OR C): " << ((p_bitset & (p_def | p_bool)) == ((p_bitset & p_def) | (p_bitset & p_bool))) << std::endl;
	std::cout << "A OR(B AND C) == (A OR B) AND (A OR C): " << ((p_bitset | (p_def & p_bool)) == ((p_bitset | p_def) & (p_bitset | p_bool))) << std::endl;

	//e)
	std::cout << "[A -> (B -> C)] <-> [(A & B) -> C]: " << ((p_bitset % (p_def % p_bool)) > ((p_bitset & p_def) % p_bool)) << std::endl;

    return 0;
}

