#ifndef TMPPROCESSOR_CPP
#define TMPPROCESSOR_CPP

#include "TmpProcessor.hpp"

//Constructor
template<typename T>
TmpProcessor<T>::TmpProcessor(const FactoryFunction<T>& factory, const ComputeFunction<T>& compute, const DispatchFunction<T>& dispatch) :
	_factory(factory), _compute(compute), _dispatch(dispatch) {};

// The template method pattern
template<typename T>
void TmpProcessor<T>::algorithm()
{
	T val = _factory();
	T val2 = _compute(val);
	_dispatch(val2);
}


#endif