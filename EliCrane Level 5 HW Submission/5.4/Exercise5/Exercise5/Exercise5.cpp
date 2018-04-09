#include <iostream>
#include <unordered_set>
#include <string>

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

int main()
{
	std::unordered_set<std::string> us_string;

	BucketInformation(us_string); //Starts with a minimum of 8 buckets
	
	//d)
	us_string.rehash(12); //Rehashing past 8 causes the buckets to rise to 16
	BucketInformation(us_string);
	us_string.rehash(20); //Rehashing to 20 causes the buckets to rise to 32
	BucketInformation(us_string);
    return 0;
}

