#pragma once
#include "Action.h"
class PickByShapesAndColors : public Action
{
	PickByShapesAndColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};


