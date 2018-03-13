#include <memory>
#include <iostream>

int main()
{
	//a)
	std::shared_ptr<double> sp_d(new double(1.0));
	std::cout << "sp_d has the following number of references: " << sp_d.use_count() << std::endl; //1

	std::weak_ptr<double> wp_d = sp_d;
	std::cout << "sp_d has the following number of references: " << sp_d.use_count() << std::endl; //1

	//The weak pointer does not create a new reference

	//b)
	//Assing a weak pointer to a shared pointer
	std::shared_ptr<std::weak_ptr<double>> sp_wp(new std::weak_ptr<double>);

	std::cout << std::boolalpha << "sp_wp is null: " << (sp_wp == nullptr) << std::endl; //false

	//c)
	std::weak_ptr<double> wp_1;
	std::weak_ptr<double> wp_copy = wp_1;
	std::cout << "wp_1 has the following number of references: " << wp_1.use_count() << std::endl; //0

	//Reuse from question b
	std::cout << "sp_wp has the following number of references: " << sp_wp.use_count() << std::endl; //1

	//When assigning a weak pointer to a weak pointer no references are created, but when assigning a weak pointer
	//to a shared pointer, a reference is created to the shared_ptr



    return 0;
}

