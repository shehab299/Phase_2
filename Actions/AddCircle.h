#pragma once

#include "Action.h"

//Add Circle Action class
class AddCircle : public Action
{
private:
	Point Center, Rad; //Circle parameters
	GfxInfo CrclGfxInfo;
public:
	AddCircle(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

};

