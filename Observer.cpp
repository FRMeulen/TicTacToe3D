//Inclusions
#include "Observer.h"
#include "Subject.h"
#include <iostream>

//Constructor
Observer::Observer(Subject* subject) {

}

//Destructor
Observer::~Observer() {
	// Detach Observer from attached subject
	if (subject != NULL) {
		subject->detach(this);
	}
}

//This class is abstract