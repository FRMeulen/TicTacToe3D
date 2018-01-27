//Inclusions
#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include <vector>

//Namespace
using namespace std;

//Constructor
Subject::Subject()
{
}

//Destructor
Subject::~Subject()
{
	//For every observer...
	for (int i = 0; i < observers.size(); i++) {
		//...remove subject
		observers[i]->subject = NULL;
	}
}

//Methods
void Subject::notifyAll() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->update();
	}
}

void Subject::attach(Observer *obs) {
	observers.push_back(obs);
}

void Subject::detach(Observer *obs) {
	for (int i = 0; i < observers.size(); i++) {	//For every observer in list...
		if (observers[i] == obs) {	//...check if [i] is this one...
			observers.erase(observers.begin() + i);	//...and if so remove pointer from vector
			obs->subject = NULL;
		}
	}
}