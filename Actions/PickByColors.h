#pragma once
#include "Action.h"
class PickByColors:public Action
{
private:
public :
	PickByColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

