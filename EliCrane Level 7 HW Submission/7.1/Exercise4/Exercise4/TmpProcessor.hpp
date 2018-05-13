#ifndef TMPPROCESSOR_HPP
#define TMPPROCESSOR_HPP

#include <functional>

//Define types
// Function categories
template <typename T>
using FactoryFunction = std::function<T()>;
template <typename T>
using ComputeFunction = std::function<T(const T& t)>;
template <typename T>
using DispatchFunction = std::function<void(T& t)>;

// Class with Input-Processing-Output
template <typename T>
class TmpProcessor
{ // No inheritance used

private:
	FactoryFunction<T> _factory;
	ComputeFunction<T> _compute;
	DispatchFunction<T> _dispatch;

public:
	TmpProcessor(const FactoryFunction<T>& factory,
		const ComputeFunction<T>& compute,
		const DispatchFunction<T>& dispatch);

	// The template method pattern
	virtual void algorithm() final;
};

#ifndef TMPPROCESSOR_CPP
#include "TmpProcessor.cpp"
#endif

#endif