//Pragma
#pragma once

//Class
class Observer
{
public:
	Observer();	//Constructor
	~Observer();	//Destructor
	virtual void update() = 0;
};