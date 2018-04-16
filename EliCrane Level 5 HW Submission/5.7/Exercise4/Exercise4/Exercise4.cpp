#include <iostream>
#include <string>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <tuple>
#include <vector>

template<typename T>
void populateSet(T& set, const std::vector<std::string>& vLeft, const std::vector<int>& vRight) {

	//Define the value type for the specific set
	typedef T::value_type VT;

	//Mutates set
	for (auto i = 0; i < vLeft.size(); ++i) {
		set.insert(VT(vLeft[i], vRight[i]));
	}
}

template<typename T>
void printSet(const T& set) {

	//Prints set
	for (auto elem : set) {
		std::cout << "L: " << elem.left << ", R: " << elem.right << std::endl;
	}
	std::cout << std::endl;
}

using namespace boost::bimaps;

//c) modified for custom comparators
template<class CompLeft>
using SetList2 = bimap <set_of<std::string, CompLeft>, list_of<int>>; //Cannot use comparator on list

template<class CompLeft, class CompRight>
using SetSet2 = bimap <set_of<std::string, CompLeft>, set_of<int, CompRight>>; 

template<class CompLeft>
using SetUnordered2 = bimap <set_of<std::string, CompLeft>, unordered_set_of<int>>; //Cannot use comparator on unordered

template<class CompLeft>
using MultisetList2 = bimap <multiset_of<std::string, CompLeft>, list_of<int>>; //Cannot use comparator on list

template<class CompLeft, class CompRight>
using MultisetSet2 = bimap <multiset_of<std::string, CompLeft>, set_of<int, CompRight>>; 

template<class CompLeft>
using MultisetUnordered2 = bimap <multiset_of<std::string, CompLeft>, unordered_set_of<int>>; //Cannot use comparator on unordered

template<class CompRight>
using UnorderedSet2 = bimap <unordered_set_of<std::string>, set_of<int, CompRight>>; //Cannot use comparator on unordered



int main()
{

	//a)
	//Set List
	typedef bimap
	<
	set_of<std::string>,
	list_of<int>
	> SetList;

	//Set Set
	typedef bimap
	<
	set_of<std::string>,
	set_of<int>
	> SetSet;

	//Set UnOrdered
	typedef bimap
	<
	set_of<std::string>,
	unordered_set_of<int>
	> SetUnordered;

	//Multiset List
	typedef bimap
	<
	multiset_of<std::string>,
	list_of<int>
	> MultisetList;

	//Multiset Set
	typedef bimap
	<
	multiset_of<std::string>,
	set_of<int>
	> MultisetSet;

	//Multiset Unordered
	typedef bimap
	<
	multiset_of<std::string>,
	unordered_set_of<int>
	> MultisetUnordered;

	//Unordered List
	typedef bimap
	<
	unordered_set_of<std::string>,
	list_of<int>
	>UnorderedList;

	//Unordered Set
	typedef bimap
	<
	unordered_set_of<std::string>,
	set_of<int>
	> UnorderedSet;

	//Unordered Unordered
	typedef bimap
	<
	unordered_set_of<std::string>,
	unordered_set_of<int>
	> UnorderedUnordered;

	//b)

	//create vector of strings to ingest:
	std::vector<std::string> vLeft;// = { "Hello" ,"A string" ,"A string" ,"A Fling","How Now" };
	vLeft.push_back("Hello");
	vLeft.push_back("A string");
	vLeft.push_back("A string");
	vLeft.push_back("A Fling");
	vLeft.push_back("How Now");

	std::vector<int> vRight;
	vRight.push_back(1);
	vRight.push_back(2);
	vRight.push_back(3);
	vRight.push_back(4);
	vRight.push_back(4);

	//Set List
	SetList sl;
	populateSet<SetList>(sl, vLeft, vRight);
	printSet(sl);

	SetList2<std::greater<>> sl2;
	populateSet<SetList2<std::greater<>>>(sl2, vLeft, vRight);
	printSet(sl2);

	//Set Set
	SetSet ss;
	populateSet<SetSet>(ss, vLeft, vRight);
	printSet(ss);

	SetSet2<std::greater<>, std::greater<>> ss2;
	populateSet<SetSet2<std::greater<>, std::greater<>>>(ss2, vLeft, vRight);
	printSet(ss2);

	//Set Unordered
	SetUnordered su;
	populateSet<SetUnordered>(su, vLeft, vRight);
	printSet(su);

	SetUnordered2<std::greater<>> su2;
	populateSet<SetUnordered2<std::greater<>>>(su2, vLeft, vRight);
	printSet(su2);

	//Multiset List
	MultisetList ml;
	populateSet<MultisetList>(ml, vLeft, vRight);
	printSet(ml);

	MultisetList2<std::greater<>> ml2;
	populateSet<MultisetList2<std::greater<>>>(ml2, vLeft, vRight);
	printSet(ml2);

	//Multiset Set
	MultisetSet ms;
	populateSet<MultisetSet>(ms, vLeft, vRight);
	printSet(ms);

	MultisetSet2<std::greater<>, std::greater<>> ms2;
	populateSet<MultisetSet2<std::greater<>, std::greater<>>>(ms2, vLeft, vRight);
	printSet(ms2);

	//Multiset Unordered
	MultisetUnordered mu;
	populateSet<MultisetUnordered>(mu, vLeft, vRight);
	printSet(mu);

	MultisetUnordered2<std::greater<>> mu2;
	populateSet<MultisetUnordered2<std::greater<>>>(mu2, vLeft, vRight);
	printSet(mu2);

	//Unordered List
	UnorderedList ul;
	populateSet<UnorderedList>(ul, vLeft, vRight);
	printSet(ul);

	UnorderedSet2<std::greater<>> us2;
	populateSet<UnorderedSet2<std::greater<>>>(us2, vLeft, vRight);
	printSet(us2);

	//Multiset Set
	UnorderedSet us;
	populateSet<UnorderedSet>(us, vLeft, vRight);
	printSet(us);

	//Multiset Unordered
	UnorderedUnordered uu;
	populateSet<UnorderedUnordered>(uu, vLeft, vRight);
	printSet(uu);

    return 0;
}

