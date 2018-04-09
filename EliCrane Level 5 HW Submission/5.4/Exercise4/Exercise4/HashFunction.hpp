#ifndef HASHFUNCTION_HPP
#define HASHFUNCTION_HPP

#include <boost\functional\hash.hpp>

template <typename T>
void hash_value(std::size_t& seed, const T& val)
{
	boost::hash_combine(seed, val);
}

template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args)
{
	boost::hash_combine(seed, val);
	hash_value(seed, args...);
}

//Auxiliary function
template <typename... Types>
std::size_t hash_value(const Types&... args)
{
	std::size_t seed = 0;
	hash_value(seed, args...);
	return seed;
}

#endif
