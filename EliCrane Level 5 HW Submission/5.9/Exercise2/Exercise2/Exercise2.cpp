#include <boost\signals2.hpp>
#include <iostream>
#include <functional>
#include <memory>

void slot_first() {
	std::cout << "The first slot is called." << std::endl;
}

auto slot_third = []() {
	std::cout << "This third slot is called.\n";
};

struct slot_fourth
{
	double data;

	slot_fourth() { data = 0; }
	slot_fourth(double data) { data = data; }

	void operator() () { std::cout << "This fourth slot ends it all.\n"; }
};

//b)
struct MyStruct
{
	double val;
	MyStruct(double v) { val = v; }

	void modify(double newValue)
	{
		val = newValue;
		std::cout << "A third slot " << val << std::endl;
	}
};


int main()
{
	//a) Put in own slot group:

	//Make signal
	boost::signals2::signal<void()> sig;

	//Connect slots
	sig.connect(0, &slot_first);
	auto l1 = sig.connect(1, []() {std::cout << "This second slot is called.\n"; }); //Pass lambda as parameter
	std::function<void()> f = slot_third;
	auto l2 = sig.connect(2, f); //pass lambda as function object
	slot_fourth sf(3);
	auto fo = sig.connect(3, sf);

	//emit signal
	sig();

	//Make signal
	boost::signals2::signal<void(double)> sig2;

	//Connect slots
	MyStruct ms(4);
	using namespace std::placeholders;
	auto f2 = std::bind(&MyStruct::modify, &ms, std::placeholders::_1); //Bind member function
	sig2.connect(0, f2);

	//Emit signal
	sig2(4);

	sig.disconnect(0); //disconnects first slot
	sig();
	sig.disconnect(1); //disconnects second slot
	sig();
	sig.disconnect_all_slots(); //does nothing
	sig();
	sig.disconnect(2); //disconnects third slot
	sig.disconnect(3); //disconnects fourth slot
	sig();

	// Define potential emitters
	boost::signals2::signal<void()> signalA;
	boost::signals2::signal<void()> signalB;
	boost::signals2::signal<void()> signalC;
	boost::signals2::signal<void()> signalD;

	// Define slots
	auto slotB = []() {std::cout << "Slot B called by B\n " << std::endl; };
	auto slotC = []() {std::cout << "Slot C called by C\n " << std::endl; };
	auto slotD1 = []() {std::cout << "Slot D1 called by D\n " << std::endl; };
	auto slotD2 = []() {std::cout << "Slot D2 called by D\n " << std::endl; };

	//Connect slots
	signalA.connect(0, signalB);
	auto CconnB = signalB.connect(0, signalC);
	signalC.connect(0, signalD);
	signalB.connect(1, slotB);
	signalC.connect(1, slotC);
	signalD.connect(1, slotD1);
	signalD.connect(2, slotD2);

	//Emit signals
	std::cout << "Signal A: " << std::endl;
	signalA();
	std::cout << "Signal B: " << std::endl;
	signalB();
	std::cout << "Signal C: " << std::endl; //Emits all of signal B
	signalC();
	std::cout << "Signal D: " << std::endl;
	signalD();

	//Disconnect
	CconnB.disconnect(); //Disconnects slot C, so only slotB remains
	std::cout << "Signal B: " << std::endl;
	signalB();

	//b)
	//Output appears to be the same, but I could use signal.disconnect(group #) to disconnect a slot;

	return 0;
}

