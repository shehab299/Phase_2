#pragma once
#include "Action.h"
class PickByShapes :  public Action
{
	PickByShapes(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

