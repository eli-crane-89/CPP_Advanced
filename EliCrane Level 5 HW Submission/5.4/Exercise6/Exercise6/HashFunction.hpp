#ifndef HASHFUNCTION_HPP
#define HASHFUNCTION_HPP

#include <iostream>
#include <unordered_set>
#include <string>
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



template <typename Key, typename Hash, typename EqPred>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c) //
{
	std::cout << "\nBucket information relating to unordered set.." << std::endl;

	std::cout << "Current number of elements in set: " << c.size() << std::endl;
	//a)
	std::cout << "Number of buckets: " << c.bucket_count() << std::endl;
	std::cout << "Maximum number of possible buckets: " << c.max_bucket_count() << std::endl;
	//b)
	std::cout << "Current load factor: " << c.load_factor() << std::endl;
	std::cout << "Current maximum load factor: " << c.max_load_factor() << std::endl;
	//c)
	for (std::size_t i = 0; i < c.bucket_count(); ++i) {
		std::cout << "Size of bucket: " << i << ", " << c.bucket_size(i) << std::endl;
	}
}

#endif
