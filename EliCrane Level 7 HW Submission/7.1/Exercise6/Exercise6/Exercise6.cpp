#include <iostream>
#include <list>
#include <deque>

#include <boost/signals2.hpp>

#include "Counter.hpp"
#include "DoubleFormat.hpp"
#include "LongFormat.hpp"

int main()
{
	//a) using list
	//Create Counter
	Counter<std::list>* c(new Counter<std::list>);

	//Create Observers to attach
	DoubleFormat df;
	LongFormat lf;

	std::function<void(double)> f_df = std::bind(&DoubleFormat::Update, &df, std::placeholders::_1);
	std::function<void(double)> f_lf = std::bind(&LongFormat::Update, &lf, std::placeholders::_1);

	//Add Observers
	c->Attach(&f_df);
	c->Attach(&f_lf);

	//Increment and Decrement to Check Notifications
	c->IncreaseCounter(3.4);
	c->IncreaseCounter(4.5);
	c->DecreaseCounter(7.3);
	//Both observers being notified

	//Remove process
	c->Detach(&f_df);
	std::cout << "Removed observer:\n";
	c->DecreaseCounter(9.9);
	std::cout << std::endl;
	//Process successfully removed

	//b) using deque
	Counter<std::deque>* c_deque(new Counter<std::deque>);
	
	//Add Observers
	c_deque->Attach(&f_df);
	c_deque->Attach(&f_lf);

	//Increment and Decrement to Check Notifications
	c_deque->IncreaseCounter(3.4);
	c_deque->IncreaseCounter(4.5);
	c_deque->DecreaseCounter(7.3);
	//Both observers being notified

	//Remove process
	c_deque->Detach(&f_df);
	std::cout << "Removed observer:\n";
	c_deque->DecreaseCounter(9.9);
	std::cout << std::endl;
	//Process successfully removed

	//c) boost singals
	//Create signal
	boost::signals2::signal<void(double)> c_signal;

	//Make connections to formatters
	boost::signals2::connection conn1 = c_signal.connect(f_df);
	boost::signals2::connection conn2 = c_signal.connect(f_lf);

	//Call signal
	c_signal(3342.4);

	//Disconnect and re call
	conn2.disconnect();
	c_signal(5.5469);

	//Block connection
	boost::signals2::shared_connection_block b{ conn1 };
	c_signal(9943434); //Nothing happens since only active connection is blocked

	//Unblock connection
	b.unblock();
	c_signal(111111111); 
	


	return 0;
}
