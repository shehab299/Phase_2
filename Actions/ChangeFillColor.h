#pragma once
#include "Action.h"
class ChangeFillColor : public Action
{
private:
	ActionType color;
public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

