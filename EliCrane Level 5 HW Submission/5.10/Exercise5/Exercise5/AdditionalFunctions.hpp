#ifndef ADDITIONALFUNCTIONS_HPP
#define ADDITIONALFUNCTIONS_HPP

#include <tuple>
#include <boost/numeric/ublas/vector.hpp>
#include <functional>
#include <algorithm>

#include <iostream>

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;
using value_type = double;
using intFunc = std::function<bool(const double, const double)>;

template <typename T, template <typename S, typename Alloc> class Container, typename TAlloc>
Result find_sequential_greater(const Container<T, TAlloc>& container, value_type x)
{
	//Need to do j < container.size() - 1
	for (std::size_t j = 0; j < container.size() - 1; ++j)
	{
		if (container[j] <= x && container[j + 1] > x)
		{
			return std::make_tuple(
				std::make_tuple(j, j + 1), true);
		}
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
}

//For find if
bool IsLTE(const double i, const double num) {
	if (i <= num) {
		return true;
	}

	return false;
}

//Find if 
template <typename T, template <typename S, typename Alloc> class Container, typename TAlloc = std::allocator<T>>
Result find_if_sequential_greater(const Container<T, TAlloc>& container, value_type x) {

	using namespace std::placeholders;

	//Bind Is Less Than or Equal and Is Greater Than function
	intFunc func_lte = IsLTE;
	auto bind_lte = std::bind(func_lte, _1, x);

	//Define iterators to store values
	Container::const_iterator it_first = container.begin();
	Container::const_iterator it_second;
	Container::const_iterator it_end = container.end();

	while (it_first != it_end) {
		it_first = std::find_if(it_first, it_end, bind_lte);

		//if it_first is found continue
		if (it_first != it_end) {

			it_second = it_first;
			//Increment it_second and check if value greater than x
			if (++it_second != it_end && *(it_second) > x) {

				//Return distance
				int index_first = std::distance(container.begin(), it_first);

				return std::make_tuple(std::make_tuple(index_first, index_first + 1), true);
			}

			//Increment it_first
			it_first++;
		}
	}

	return std::make_tuple(std::make_tuple(999, 999), false);

}


////Lower bound
//
////Predictate 
//bool lbPred(const double d1, const double d2) {
//	return d1 <= d2;
//}
//
//template <typename T, template <typename S, typename Alloc> class Container, typename TAlloc>
//Result lower_bound_sequential_greater(const Container<T, TAlloc>& container, value_type x) {
//
//	//const iterators to store values
//	Container::const_iterator it_first = container.begin();
//	Container::const_iterator it_end = container.end();
//
//	while (it_first != it_end) {
//		//searching for index + 1
//		//find elem that is greater than or equal to x
//		//Use Predicate to check if the value is <= before executing algorithm
//		it_first = std::lower_bound(it_first, it_end, x, lbPred);
//
//		if (it_first != it_end) {
//			//Make sure term is not beginning term
//			if (it_first != container.begin()) {
//
//				//Return distance
//				int index_first = std::distance(container.begin(), it_first);
//
//				return std::make_tuple(std::make_tuple(index_first - 1, index_first), true);
//			}
//			//Increment it_first
//			it_first++;
//		}
//
//	}
//
//	return std::make_tuple(std::make_tuple(999, 999), false);
//}
//
////Upper bound
//
////Predictate 
//bool ubPred(const double d1, const double d2) {
//	return d1 < d2;
//}
//
//template <typename T, template <typename S, typename Alloc> class Container, typename TAlloc>
//Result upper_bound_sequential_greater(const Container<T, TAlloc>& container, value_type x) {
//
//	//const iterators to store values
//	Container::const_iterator it_first = container.begin();
//	Container::const_iterator it_end = container.end();
//
//	while (it_first != it_end) {
//		//searching for index + 1
//		//find elem that is greater than or equal to x
//		//Use Predicate to check if the value is > x before executing algorithm
//		it_first = std::upper_bound(it_first, it_end, x, ubPred);
//
//		if (it_first != it_end) {
//			//Make sure term is not beginning term
//			if (it_first != container.begin()) {
//
//				//Return distance
//				int index_first = std::distance(container.begin(), it_first);
//
//				return std::make_tuple(std::make_tuple(index_first - 1, index_first), true);
//			}
//			//Increment it_first
//			it_first++;
//		}
//
//	}
//
//	return std::make_tuple(std::make_tuple(999, 999), false);
//}
//
////Using Equal_Range
//
////Predictate 
//bool erPred(const double d1, const double d2) {
//	return d1 < d2;
//}
//
//template <typename T, template <typename S, typename Alloc> class Container, typename TAlloc>
//Result equal_range_sequential_greater(const Container<T, TAlloc>& container, value_type x) {
//
//	//const iterators to store values
//	Container::const_iterator it_first = container.begin();
//	Container::const_iterator it_end = container.end();
//
//	while (it_first != it_end) {
//		//find elem that is greater than or equal to x
//		//Use Predicate to check if the value is <= before executing algorithm
//		auto it_pair = std::equal_range(it_first, it_end, x, erPred);
//
//		if (it_pair.first != it_end) {
//
//			//If .first != .second, that signifies .first is the first element and index has been found
//			if (it_pair.first != it_pair.second) {
//				//Return distance
//				int index_first = std::distance(container.begin(), it_pair.first);
//
//				return std::make_tuple(std::make_tuple(index_first, index_first + 1), true);
//			}
//			//If it_pair.first == it_pair.second that signifies that no equal term was found, but a higher one was
//			else if (it_pair.first == it_pair.second) {
//				if (it_pair.first == container.begin()) {
//					//Increment if it_pair.first is first term and continue with loop
//					it_first++;
//				}
//				else {
//					//else the index + 1 has been found
//
//					//Return distance
//					int index_first = std::distance(container.begin(), it_pair.first);
//
//					return std::make_tuple(std::make_tuple(index_first - 1, index_first), true);
//				}
//			}
//
//		}
//		else {
//			//Trigger exit condition
//			it_first = it_end;
//		}
//	}
//
//	return std::make_tuple(std::make_tuple(999, 999), false);
//}
//
////Find if Not
//
//bool IsE(const double i, const double num) {
//
//	if (i == num) {
//		return true;
//	}
//
//	return false;
//}
//
//template <typename T, template <typename S, typename Alloc> class Container, typename TAlloc>
//int find_if_not_equal(const Container<T, TAlloc>& container, value_type x) {
//
//	using namespace std::placeholders;
//
//	//Bind Is Equal Function
//	intFunc func_e = IsE;
//	auto bind_e = std::bind(func_e, _1, x);
//
//	//Define iterators to store values
//	Container::const_iterator it_first = container.begin();
//	Container::const_iterator it_end = container.end();
//
//
//	it_first = std::find_if_not(it_first, it_end, bind_e);
//
//	//if it_first is found continue
//	if (it_first != it_end) {
//
//		//Return distance
//		return std::distance(container.begin(), it_first);
//	}
//
//	return 999;
//
//}

#endif