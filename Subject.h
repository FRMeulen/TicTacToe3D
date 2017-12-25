//Pragma
#pragma once

//Namespace
using namespace std;

//Inclusions
#include "Observer.h"
#include "AlphaObserver.h"
#include "BinObserver.h"

//Class
class Subject
{
	
public:
	Subject();	//Constructor
	~Subject();	//Destructor

	void notifyAll();
	void attach(Observer*);
	void detach(Observer*);
};

