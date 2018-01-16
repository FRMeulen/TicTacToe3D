//Pragma
#pragma once

//Class dependencies
class Subject;

//Class
class Observer
{
public:
	Subject * subject;	//Subject pointer
	Observer(Subject *);	//Constructor
	virtual ~Observer();	//Destructor
	virtual void update() = 0;	//Update
};

//This class is abstract