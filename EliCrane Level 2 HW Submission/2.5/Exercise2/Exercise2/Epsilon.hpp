
template<typename T>
T calcEpsilon(T& epsilon) {
	while (static_cast<T>(1.0) + static_cast<T>(0.5)*epsilon != static_cast<T>(1.0))
	{
		epsilon *= static_cast<T>(0.5);
	}

	return epsilon;
}