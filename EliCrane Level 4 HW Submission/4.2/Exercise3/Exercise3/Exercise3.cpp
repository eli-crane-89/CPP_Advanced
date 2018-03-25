#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>

auto lPrint = [](std::vector<int>& v, std::string msg) {
	std::cout << msg << ":\n";

	for (auto elem : v) {
		std::cout << elem << std::endl;
	}
};

int main()
{
	//create some vectors
	std::vector<int> v1({ 1,4,7,23,6,19,54,28,32,6,7,8,8 });
	lPrint(v1, "V1, before mutations");

	//a) Scale all values by a given factor.
	//Transform with predicate- modifying algorithm since it changes values of elements according to the provided formula
	std::transform(v1.begin(), v1.end(), v1.begin(), [](int i) {return i * 2; });
	lPrint(v1, "V1, after transform * 2");

	//b) Count the number of elements whose values are in a given range.
	//Count_if - Non Modifying algorithm - counts all elements that meet a certain critera
	int count_1_20 = std::count_if(v1.begin(), v1.end(), [](int i) {return (i >= 1 && i < 20); });
	std::cout << "There are " << count_1_20 << " terms in v1 between [1, 20)\n";

	//c) Find the average, minimum and maximum values in a container.
	//Average - Accumulate - Numeric - Accumulates elements
	//Minimum - min_element - Non Modifying - Returns iter to min_element
	//Maximum - max_element - Non Modifying - Returns iter to max_element
	std::cout << "The average of the terms in v1: " << (std::accumulate(v1.begin(), v1.begin(), 0) / v1.size()) << std::endl;
	std::cout << "The min element in v1 is: " << (*std::min_element(v1.begin(), v1.end()));
	std::cout << " and first occurs at element: " << std::distance(v1.begin(), std::min_element(v1.begin(), v1.end())) << std::endl;
	std::cout << "The max element in v1 is: " << (*std::max_element(v1.begin(), v1.end())) << std::endl;
	std::cout << " and first occurs at element: " << std::distance(v1.begin(), std::max_element(v1.begin(), v1.end())) << std::endl;

	//d) Find the first element that is(that is not) in a range.
	//find_if - Non Modifying - finds first element that meets formula criteria
	auto iter_fi = std::find_if(v1.begin(), v1.end(), [](int t) {return t < 1 || t >= 20; });
	std::cout << "The first element not in the range [1,20) in v1 is: " << (*iter_fi);
	std::cout << " and  occurs at element: " << std::distance(v1.begin(), iter_fi) << std::endl;

	//e) Search for all occurrences of ‘3456’ in the container.
	//since you are looking to return a vector of elements, you will need to get creative
	//for_each - Non Modifying for iterating through values
	auto v3456 = v1;
	v3456.push_back(3456);
	v3456[3] = 3456;
	v3456[7] = 3456;

	std::vector<int> vOccur;
	int posCounter = 0;
	std::for_each(v3456.begin(), v3456.end(), [&](int i) {
		if (i == 3456) {
			vOccur.push_back(posCounter);
		}
		posCounter++;
	});

	lPrint(vOccur, "Index of occurences of 3456 in v3546");

	//f) Determine if the elements in two ranges are equal.
	//Equal - Non Modifying - determines whether two containers are equal
	auto v1_copy = v1;
	std::cout << "v1 and v1_copy are equal: " << std::boolalpha << std::equal(v1.begin(), v1.end(), v1_copy.begin()) << std::endl;
	std::cout << "v1 and v3456 are equal: " << std::boolalpha << std::equal(v1.begin(), v1.end(), v3456.begin()) << std::endl;

	//g) Determine if a set is some permutation of ‘12345’.
	//is_permutation - Non Modifying - checks if two containers are permutations of each other
	std::vector<int> vp1({ 6,7,8,10,15 });
	std::vector<int> vp2({ 15,7,8,6,10 });
	std::cout << "vp2 is a permutation of vp1: " << std::boolalpha << std::is_permutation(vp1.begin(), vp1.end(), vp2.begin()) << std::endl;

	//h) Is a container already sorted ?
	//is_sorted - Non Modifying - checks if sorted
	std::cout << std::boolalpha << "vp1 is sorted: " << (std::is_sorted(vp1.begin(), vp1.end())) << std::endl;
	std::cout << std::boolalpha << "vp2 is sorted: " << (std::is_sorted(vp2.begin(), vp2.end())) << std::endl;

	//i) Copy a container into another container.
	//copy - Modifying - copies elements from one vector to another vector
	std::vector<int> vCop(5);
	std::copy(vp1.begin(), vp1.end(), vCop.begin());
	lPrint(vCop, "After copy vCop");

	//j) Move the last 10 elements of a container to the front.
	//rotate - Mutating - moves elements to different side of container
	std::rotate(v1.rbegin(), v1.rbegin() + 10, v1.rend());
	lPrint(v1, "v1 after rotate");

	//k) Swap two ranges at a given position.
	//swap_ranges - Modifying
	std::swap_ranges(v1.begin(), v1.begin() + 4, vp1.begin());
	lPrint(v1, "v1 after swap");
	lPrint(vp1, "vp1 after swap");

	//l) Generate values in a container based on some formula.
	//generate - Modifying - fills vector with numbers base on provided formula
	std::vector<int> vGen(20);
	std::generate(vGen.begin(), vGen.end(), [n = 0]()mutable{ return (++n) * n; });
	lPrint(vGen, "vGen after generate");

	//m) Replace all uneven numbers by zero.
	//replace_if - Modifying - replace all values that meet function criteria
	std::replace_if(vGen.begin(), vGen.end(), [](int t) {return (t % 2) != 0; }, 0);
	lPrint(vGen, "vGen after all odds replaced with 0");

	//n) Remove all elements whose value is less than 100.
	//remove_if - Modifying but does not resisze container, so needs to be used with erase
	vGen.erase(std::remove_if(vGen.begin(), vGen.end(), [](int t) {return t < 100;}), vGen.end());
	lPrint(vGen, "vGen after all numbers under 100 removed");

	//o) Shuffle a container randomly(pre - and post - C++11 versions).
	//random_shuffle - Mutating - old way - randomly shuffles elements in vector
	//shuffle - Mutating - new way - needs a randomizer provided - randomly shuffles elements in a vector according to random function
	std::random_shuffle(vGen.begin(), vGen.end());
	lPrint(vGen, "vGen after random_shuffle");
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(vGen.begin(), vGen.end(), g);
	lPrint(vGen, "vGen after shuffle");

	//p) Compute one - sided divided differences of the values in a container.
	//adjacent_difference - Numeric - returns adjacent differences for a vector

	std::vector<int> result(v1.size());
	//Not sure how to calculate divided differences because this apparently is a very common term
	std::adjacent_difference(v1.begin(), v1.end(), result.begin());
	lPrint(result, "divided differences for v1");

	

    return 0;
}

