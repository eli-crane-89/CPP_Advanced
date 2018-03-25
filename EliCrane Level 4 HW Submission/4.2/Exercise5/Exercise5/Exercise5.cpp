#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

auto lPrint = [](std::vector<int>& v, std::string msg) {
	std::cout << msg << ":\n";

	for (auto elem : v) {
		std::cout << elem << std::endl;
	}
};

int main()
{

	//a)
	//Function objects are useful in certain applications because of how naturally they work with
	//mathematical functional notation (e.g f(f(x))). When used as a unary or binary predicate
	//the fo is fairly straightforward, and using bind can easily emplace the correct argument
	//The problem with user defined function objects is that they are the user's owned, so all 
	//maintenance must be done by the user. The fos are fairly readable and templatable, so they
	//can be genericized pretty easily.

	//Lambdas are pretty similar to function objects in terms of readability for most situations
	//and can similaryl have their function arguments bound. They are slightly easier to write
	//than function objects. To a new programmer who isn't as familiar with variable capture,
	//they might be somewhat confusing to read if you come from a normal function only background.
	//Lambda also have the advantage they can be written directly into the algorithm, but this
	//futher compounds difficulty with readability. Because lambdas are not templatable, 
	//that makes them harder to generecize, and means that multiple lambdas with similar 
	//functionality may need to be maintained.

	//STL function objects should always be used if one exists that performs your specific 
	//functionality, since this reduces the code the developer must write and maintain.
	//STL functions though can sometimes look a like more esoteric and it can be harder
	//To find the definition than for a user defined function. Still, any time the developer
	//can reduce the amount of code they are responsible for, they shold probably do it, so
	//STL function objects should always be used. They are also all templatable and
	//genericized.

	//b)
	//Function object
	struct fo_Threshold {
		fo_Threshold() {}
		bool operator()(int x, int threshold) { return std::abs(x) > threshold == 0; }
	};

	//Lambda function
	auto l_Threshold = [](int x) {return std::abs(x) > 5; };

	//Define test vector
	std::vector<int> v1 = { -4,-6,1,7,5,4,8,9 };

	//Define threshold
	int threshold = 2;

	//Copy test vector to second vector for modifying
	auto v2 = v1;

	//Bind Threshold
	using namespace std::placeholders;
	auto bind_Threshold = std::bind(fo_Threshold(), _1, threshold); //Bind threshold

	//Use remove_if and erase to reconstruct vector with relevant elements
	//Function object
	v2.erase(std::remove_if(v2.begin(), v2.end(),  bind_Threshold), v2.end());
	lPrint(v2, "v1 after all numbers of abs value under 2 remove via function object");

	//Lambda
	//Copy test vector to second vector for modifying
	v2 = v1;
	
	v2.erase(std::remove_if(v2.begin(), v2.end(), l_Threshold), v2.end());
	lPrint(v2, "v1 after all numbers of abs value under 2 removed via lambda");

	//STL function object
	//Copy test vector to second vector for modifying
	//need third vector since operation will need to be performed twice
	//since STL has no way of mixing std::greater and std::abs
	v2 = v1;
	auto v3 = v1;

	auto bind_great_pos2 = std::bind(std::less<>(), _1, 2);
	auto bind_great_neg2 = std::bind(std::greater<>(), _1, -2);
	v2.erase(std::remove_if(v2.begin(), v2.end(), bind_great_pos2), v2.end());
	v3.erase(std::remove_if(v3.begin(), v3.end(), bind_great_neg2), v3.end());

	lPrint(v2, "v1 of all positive numbers with abs val greater than two after STL function");
	lPrint(v3, "v1 of all negative numbers with abs val greater than two after STL function");

	//c)
	//So, after using all three, I think function objects are the most flexible and easiest to maintain for user
	//defined functions. That being said, it is easier writing a lambda function so if you only need it once,
	//a lambda is better. I did realize you cannot bind a lambda, making it even harder to reuse. Trying to use
	//the STL function objects of greater and less demonstrates the biggest problems with STL: lack of flexbility.
	//There was simply no easy way to return the absolute values from a list and compare them to the threshold.
	//This is why I split the work into two functions. So while STL functions are good for their specific purpose
	//once you are at a point where you want functionality from multiple STLs, you are most likely going to have to
	//create your own lambda or function object.

    return 0;
}

