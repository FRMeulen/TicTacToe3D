//Inclusions
#include "Observer.h"
#include "Subject.h"
#include <iostream>

//Constructor
Observer::Observer(Subject *subject)
{
	// Attach observer to subject
	subject->attach(this);
}

//Destructor
Observer::~Observer()
{
	// Detach Observer from attached subject
	if (subject != NULL)
	{
		subject->attach(this);
	}
}

//This class is abstract