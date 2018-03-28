#ifndef RANDOMFUNCTION_HPP
#define RANDOMFUNCTION_HPP

#include <functional>
#include <vector>
#include <random>

//Create type with return T and
//engine for distribution
template<typename T, class Engine>
using t_dist = std::function<T(Engine)>;

template<typename T, class Engine>
std::vector<T> GenericNumberGeneration(t_dist<T, Engine>& dist, int N) {
	std::vector<T> vRet;
	
	//Use random device for true random numbers
	std::random_device rd;

	for (int i = 0; i < N; i++) {
		vRet.push_back(dist(Engine(rd())));
	}
	return vRet;
}



#endif
