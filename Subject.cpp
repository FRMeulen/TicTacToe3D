//Inclusions
#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"
#include <vector>

//Namespace
using namespace std;

//Fields
std::vector<Observer*> observerList;

//Constructor
Subject::Subject()
{
}

//Destructor
Subject::~Subject()
{
}

//Methods
void Subject::notifyAll() {
	for (int i = 0; i < observerList.size; i++) {
		observerList[i]->update();
	}
}

void Subject::attach(Observer *obs) {
	observerList.push_back(obs);
}

void Subject::detach(Observer *obs) {
	for (int i = 0; i < observerList.max_size; i++) {
		if (observerList[i] == obs) {
			observerList.erase(observerList.begin() + i - 1);
		}
	}
}