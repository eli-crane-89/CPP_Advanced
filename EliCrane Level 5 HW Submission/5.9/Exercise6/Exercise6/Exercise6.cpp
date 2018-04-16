#include <boost\signals2.hpp>
#include <iostream>


typedef boost::signals2::signal<void(double& d)> Signal;

void exterior(double& dInit) {
	std::cout << "The initial value is: " << dInit << std::endl;
}

void hardware(double& dInit) {
	dInit *= 100;
	std::cout << "The dInit has been multiplied by 100 to be transported to the hardware layers.\n";
}

struct data {
	void operator()(double& dHardware) {
		dHardware /= 100;
		std::cout << "The dHardware value has been divided by 100 to be turned into data.\n";
	}
};

void communication(double& dData) {
	std::cout << "Data of: " << dData << " has been stored in the database.\n";
}


int main()
{
	//a)
	Signal Exterior;
	Signal Hardware;
	Signal Data;
	Signal Communication;

	Exterior.connect(&exterior);
	Hardware.connect(&hardware);
	data d;
	Data.connect(d);
	Communication.connect(&communication);

	//b)
	Exterior.connect(Hardware);
	Hardware.connect(Data);
	Data.connect(Communication);

	//c) Test the program
	double dat = 1.3;
	Exterior(dat);



    return 0;
}

