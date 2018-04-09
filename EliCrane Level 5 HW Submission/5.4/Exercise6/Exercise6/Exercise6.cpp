#include "HashFunction.hpp"
#include "StructS.hpp"

int main()
{
	//a)
	std::unordered_set<S, SHash, SEqual> mySet;
	S s1("hello","goodbye"), s2("reachout","touch faith"), s3("whatever","talk to the hand"), s4("whatever", "talkto the hand"), s5("reachout", "touchfaith");
	mySet.emplace(s1);
	mySet.emplace(s2);
	mySet.emplace(s3);
	mySet.emplace(s4);
	mySet.emplace(s5);

	//b)
	BucketInformation(mySet);

	//There are 8 buckets and a load factor of .625 (5/8)
	//Bucket 1 contains s1, s3 and s4, bucket 5 contains s5 and bucket 6 contains s2
	//indicating a possible relationship between similar values and hash bucket

    return 0;
}

