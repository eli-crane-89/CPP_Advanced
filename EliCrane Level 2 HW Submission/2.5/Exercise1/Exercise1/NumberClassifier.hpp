#ifndef NUMBERCLASSIFIER_HPP
#define NUMBERCLASSIFIER_HPP


template <typename T>
const char* Classify(T t)
{
	switch (std::fpclassify(t))
	{
	case FP_INFINITE:  return "Inf";
	case FP_NAN: return "NaN";
	case FP_NORMAL:    return "normal";
	case FP_SUBNORMAL: return "subnormal";
	case FP_ZERO: return "zero";
	default:  return "unknown";
	}
}

#endif