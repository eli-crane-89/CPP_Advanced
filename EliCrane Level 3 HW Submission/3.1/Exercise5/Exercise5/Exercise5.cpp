#include <atomic>
#include <iostream>

int main()
{
	//a) Create atomics
	std::atomic<long long> a_llong = 11111111;
	std::atomic<bool> a_bool = true;
	std::atomic<int> a_int = 0;

	//b)
	std::cout << std::boolalpha << "a_llong is lock free: " << a_llong.is_lock_free() << std::endl;
	std::cout << std::boolalpha << "a_bool is lock free: " << a_bool.is_lock_free() << std::endl;
	std::cout << std::boolalpha << "a_int is lock free: " << a_int.is_lock_free() << std::endl;

	//c) atomic replacement
	std::atomic<long long> a_llong2 = 222222222;

	a_llong.exchange(a_llong2);


	//d) load an atomic object, must pass as pointer
	std::cout << "Loading value for atomic object: " << std::atomic_load(&a_llong) << std::endl;
    return 0;
}

