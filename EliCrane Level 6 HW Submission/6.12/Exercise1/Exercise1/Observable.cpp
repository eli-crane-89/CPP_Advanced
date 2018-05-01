#ifndef OBSERVABLE_CPP
#define OBSERVABLE_CPP

#include "Observable.hpp"

void Observable::AddObservable(const std::shared_ptr<Observable>& obs) {
	_observers.push_back(obs);
}

void Observable::DeleteObservable(const std::shared_ptr<Observable>& obs) {
	_observers.remove(obs);
}

void Observable::NotifyObservables() {
	for (auto iter = _observers.begin(); iter != _observers.end(); ++iter) {
		(*iter).get()->Update();
	}
}

#endif