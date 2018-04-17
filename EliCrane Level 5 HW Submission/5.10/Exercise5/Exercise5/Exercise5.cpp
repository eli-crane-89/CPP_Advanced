#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <vector>
#include "AdditionalFunctions.hpp"

int main()
{

	//a)
	boost::numeric::ublas::vector<double> v(6); //Must declare vector size
	v.insert_element(0, 1.3);
	v.insert_element(1, 4.0);
	v.insert_element(2, 4.19);
	v.insert_element(3, 4.7);
	v.insert_element(4, 4.2);
	v.insert_element(5, 4.1);

	std::vector<double> v2;
	v2.push_back(2.3);
	v2.push_back(2.5);
	v2.push_back(1.4);

	Result res = find_sequential_greater(v, 4.0);
	std::cout << (std::get<0>(std::get<0>(res))) << std::endl; //1
	std::cout << (std::get<1>(std::get<0>(res))) << std::endl; //2
	std::cout << (std::get<1>(res)) << std::endl; //1 (true)

	res = find_sequential_greater(v, 15.0);
	std::cout << (std::get<0>(std::get<0>(res))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res))) << std::endl; //999
	std::cout << (std::get<1>(res)) << std::endl; //0 (false)

	Result res2 = find_sequential_greater(v2, 2.2);
	std::cout << (std::get<0>(std::get<0>(res2))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res2))) << std::endl; //999
	std::cout << (std::get<1>(res2)) << std::endl; //0 (false)

	res2 = find_sequential_greater(v2, 2.3);
	std::cout << (std::get<0>(std::get<0>(res2))) << std::endl; //0
	std::cout << (std::get<1>(std::get<0>(res2))) << std::endl; //1
	std::cout << (std::get<1>(res2)) << std::endl; //1 (true)

	//Using find_if function
	Result res3 = find_if_sequential_greater(v, 4.0);
	std::cout << (std::get<0>(std::get<0>(res3))) << std::endl; //1
	std::cout << (std::get<1>(std::get<0>(res3))) << std::endl; //2
	std::cout << (std::get<1>(res3)) << std::endl; //1 (true)

	//Using find_if function
	res3 = find_if_sequential_greater(v, 15.0);
	std::cout << (std::get<0>(std::get<0>(res3))) << std::endl; //1
	std::cout << (std::get<1>(std::get<0>(res3))) << std::endl; //2
	std::cout << (std::get<1>(res3)) << std::endl; //1 (true)

	//Using find_if function
	Result res4 = find_if_sequential_greater(v2, 2.2);
	std::cout << (std::get<0>(std::get<0>(res4))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res4))) << std::endl; //999
	std::cout << (std::get<1>(res4)) << std::endl; //0 (false)

	//Using find_if function
	res4 = find_if_sequential_greater(v2, 2.31);
	std::cout << (std::get<0>(std::get<0>(res4))) << std::endl; //0
	std::cout << (std::get<1>(std::get<0>(res4))) << std::endl; //1
	std::cout << (std::get<1>(res4)) << std::endl; //1 (true)

	//b)
	std::cout << "\nb)\n";

	//Using bound function
	Result res5 = lower_bound_sequential_greater(v, 4.0);
	std::cout << (std::get<0>(std::get<0>(res5))) << std::endl; //1
	std::cout << (std::get<1>(std::get<0>(res5))) << std::endl; //2
	std::cout << (std::get<1>(res5)) << std::endl; //1 (true)

	res5 = lower_bound_sequential_greater(v, 15.0);
	std::cout << (std::get<0>(std::get<0>(res5))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res5))) << std::endl; //999
	std::cout << (std::get<1>(res5)) << std::endl; //0 (false)

	Result res6 = lower_bound_sequential_greater(v2, 2.2);
	std::cout << (std::get<0>(std::get<0>(res6))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res6))) << std::endl; //999
	std::cout << (std::get<1>(res6)) << std::endl; //0 (false)

	res6 = lower_bound_sequential_greater(v2, 2.3);
	std::cout << (std::get<0>(std::get<0>(res6))) << std::endl; //0
	std::cout << (std::get<1>(std::get<0>(res6))) << std::endl; //1
	std::cout << (std::get<1>(res6)) << std::endl; //1 (true)

	//Using Upper
	Result res7 = upper_bound_sequential_greater(v, 4.0);
	std::cout << (std::get<0>(std::get<0>(res7))) << std::endl; //1
	std::cout << (std::get<1>(std::get<0>(res7))) << std::endl; //2
	std::cout << (std::get<1>(res7)) << std::endl; //1 (true)

	res7 = upper_bound_sequential_greater(v, 15.0);
	std::cout << (std::get<0>(std::get<0>(res7))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res7))) << std::endl; //999
	std::cout << (std::get<1>(res7)) << std::endl; //0 (false)

	Result res8 = upper_bound_sequential_greater(v2, 2.2);
	std::cout << (std::get<0>(std::get<0>(res8))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res8))) << std::endl; //999
	std::cout << (std::get<1>(res8)) << std::endl; //0 (false)

	res8 = upper_bound_sequential_greater(v2, 2.3);
	std::cout << (std::get<0>(std::get<0>(res8))) << std::endl; //0
	std::cout << (std::get<1>(std::get<0>(res8))) << std::endl; //1
	std::cout << (std::get<1>(res8)) << std::endl; //1 (true)


	//c) 
	std::cout << "\nc)\n";

	//Using Equal_Range
	res7 = equal_range_sequential_greater(v, 4.0);
	std::cout << (std::get<0>(std::get<0>(res7))) << std::endl; //0
	std::cout << (std::get<1>(std::get<0>(res7))) << std::endl; //1
	std::cout << (std::get<1>(res7)) << std::endl; //1 (true)

	res7 = equal_range_sequential_greater(v, 15.0);
	std::cout << (std::get<0>(std::get<0>(res7))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res7))) << std::endl; //999
	std::cout << (std::get<1>(res7)) << std::endl; //0 (false)

	res8 = equal_range_sequential_greater(v2, 2.2);
	std::cout << (std::get<0>(std::get<0>(res8))) << std::endl; //999
	std::cout << (std::get<1>(std::get<0>(res8))) << std::endl; //99
	std::cout << (std::get<1>(res8)) << std::endl; //0 (false)

	res8 = equal_range_sequential_greater(v2, 2.3);
	std::cout << (std::get<0>(std::get<0>(res8))) << std::endl; //0
	std::cout << (std::get<1>(std::get<0>(res8))) << std::endl; //1
	std::cout << (std::get<1>(res8)) << std::endl; //1 (true)

	//d)
	std::cout << "\nd)\n";
	auto res9 = find_if_not_equal(v2, 2.3);
	std::cout << res9 << std::endl;







	return 0;
}
