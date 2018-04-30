#ifndef  SUBJECT_CPP
#define  SUBJECT_CPP

#include "Subject.hpp"
#include "Observer.hpp"

void Subject::Attach(Observer* obs) {
	_observers.push_back(obs);
}

void Subject::Detach(Observer* obs) {
	_observers.remove(obs);
}

void Subject::Notify() {
	for (auto it = _observers.begin(); it != _observers.end(); ++it) {
		(*it)->Update(this);
	}
}

#endif