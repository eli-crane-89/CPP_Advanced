#include <ratio>
#include <iostream>

template<intmax_t im1, intmax_t im2>
void printRatio(std::ratio<im1, im2> r) {
	std::cout << r.num << "/" << r.den << std::endl;
}


int main()
{
	std::ratio<3, 4> three_fourths;
	std::ratio<2, 9> two_ninths;

	//a) make print ratios

	printRatio(three_fourths);
	printRatio(two_ninths);

	//b)
	//add
	typedef std::ratio<5, 6> five_sixths;
	typedef std::ratio<7, 5> seven_fifths;
	typedef std::ratio_add<five_sixths, seven_fifths> sum;
	typedef std::ratio_subtract<five_sixths, seven_fifths> sub;
	typedef std::ratio_multiply<five_sixths, seven_fifths> mul;
	typedef std::ratio_divide<five_sixths, seven_fifths> div;

	sum r_add;
	printRatio(r_add);
	sub r_sub;
	printRatio(r_sub);
	mul r_mul;
	printRatio(r_mul);
	div r_div;
	printRatio(r_div);

	//std::ra
    return 0;
}

