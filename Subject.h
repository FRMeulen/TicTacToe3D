//Pragma
#pragma once

//Inclusions
#include "Observer.h"
#include <vector>

//Namespace
using namespace std;

//Class
class Subject
{
	
public:
	Subject();	//Constructor
	~Subject();	//Destructor

	vector<Observer*> observers;

	void notifyAll();
	void attach(Observer*);
	void detach(Observer*);
};

