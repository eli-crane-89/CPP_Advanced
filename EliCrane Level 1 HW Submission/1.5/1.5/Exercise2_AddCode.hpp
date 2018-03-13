#ifndef EXERCISE2_ADDCODE_HPP
#define EXERCISE2_ADDCODE_HPP


template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
	//Sum with tail function
	static T sum(const Tuple& pack) {
		return std::get<N - 1>(pack) + Calculator<T, Tuple, N - 1>::sum(pack);
	}

	//Average calls sum and divides by N
	static T average(const Tuple& pack) {
		return Calculator<T, Tuple, N>::sum(pack) / static_cast<T>(N);
	}

	///Maximum
	static T maximum(const Tuple& pack) {
		return std::get<N - 1>(pack) > Calculator<T, Tuple, N - 1>::maximum(pack) ? std::get<N - 1>(pack) : Calculator<T, Tuple, N - 1>::maximum(pack);
	}

};


//Tail functions
template<typename T, typename Tuple> struct Calculator<T, Tuple, 1>
{
	static T sum(const Tuple& pack) {
		return std::get<0>(pack);
	}

	static T maximum(const Tuple& pack) {
		return std::get<0>(pack);
	}
};

#endif