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
	//The problem with user defined function objects is that they are user owned, so all 
	//maintenance must be done by the programmer. The fos are fairly readable and templatable, so they
	//can be genericized pretty easily.

	//Lambdas are pretty similar to function objects in terms of readability for most situations
	//and can similaryl have their function arguments bound. They are slightly easier to write
	//than function objects. To a new programmer who isn't as familiar with variable capture,
	//they might be somewhat confusing to read if you come from a normal function only background.
	//Lambda also have the advantage they can be written directly into the algorithm, but this
	//futher compounds difficulty with readability. Because lambdas are not templatable, 
	//that makes them harder to generecize, and means that multiple lambdas with similar 
	//functionality may need to be maintained. Lambda can use variables by capture though,
	//which is powerful because it allows the access of variables defined outside of the function.

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
		bool operator()(int x, int threshold) { return std::abs(x) > threshold; }
	};

	

	//Define test vector
	std::vector<int> v1 = { -4,-6,1,7,5,4,8,9 };

	//Define threshold
	int threshold = 2;

	//Create result vector
	std::vector<int> vResult(v1.size());

	//Bind Threshold
	using namespace std::placeholders;
	auto bind_Threshold = std::bind(fo_Threshold(), _1, threshold); //Bind threshold

	//Function object
	//Use Copy if
	auto it = std::copy_if(v1.begin(), v1.end(), vResult.begin(), bind_Threshold);
	
	//Resize and print
	vResult.resize(std::distance(vResult.begin(), it));
	lPrint(vResult, "v1 after all numbers of abs value under 2 remove via function object");

	//Lambda

	//Create new result array to pass by capture
	std::vector<int> vLambdaRes;

	//Lambda function with variable capture
	auto l_Threshold = [&](int x) {if (std::abs(x) > threshold) { vLambdaRes.push_back(x); }};

	std::for_each(v1.begin(), v1.end(), l_Threshold);
	lPrint(vLambdaRes, "v1 after all numbers of abs value under 2 removed via lambda");

	//STL function object
	//since STL has no way of mixing std::greater and std::abs
	//I will need to do two separate checks and combine results
	auto bind_great_pos2 = std::bind(std::greater<>(), _1, 2);
	auto bind_less_neg2 = std::bind(std::less<>(), _1, -2);

	auto it_res = std::copy_if(v1.begin(), v1.end(), vResult.begin(), bind_less_neg2);
	std::copy_if(v1.begin(), v1.end(), it_res, bind_great_pos2);

	lPrint(vResult, "v1 of all positive numbers with abs val greater than two after STL function");


	//c)
	//So, after using all three, I think function objects are the most flexible and easiest to maintain for user
	//defined functions. That being said, it is easier writing a lambda function so if you only need it once,
	//a lambda is better. I did realize you cannot bind a lambda, making it even harder to reuse. That being said,
	//variable capture with lambas can be very powerful, and provides some usability that functors do not. Trying to use
	//the STL function objects of greater and less demonstrates the biggest problems with STL: lack of flexbility.
	//There was simply no easy way to return the absolute values from a list and compare them to the threshold.
	//This is why I split the work into two functions. So while STL functions are good for their specific purpose
	//once you are at a point where you want functionality from multiple STLs, you are most likely going to have to
	//create your own lambda or function object.

    return 0;
}

