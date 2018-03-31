#ifndef RANDOMFUNCTION_HPP
#define RANDOMFUNCTION_HPP

#include <functional>
#include <vector>


using namespace std::placeholders;
//Create type with return T and
//engine for distribution
template<typename T, class Engine>
using t_dist = std::function<T(Engine)>;

template<typename T, typename Dist, typename Engine>
std::vector<T> GenericNumberGeneration(Dist dist, Engine eng, int N) {
	std::vector<T> vRet;
	
	//Generate N random numbers along the distribution
	for (int i = 0; i < N; i++) {
		vRet.push_back(dist(eng));
	}
	return vRet;
}



#endif
