//Inclusions
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
	obs->subject = this;
}

void Subject::detach(Observer *obs) {
	//For every observer in list...
	for (int i = 0; i < observers.size(); i++) {
		//...check if [i] is this one...
		if (observers[i] == obs) {
			//...and if so remove pointer from vector
			observers.erase(observers.begin() + i);
			obs->subject = NULL;
		}
	}
}