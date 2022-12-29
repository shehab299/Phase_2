#pragma once
#include "Action.h"
class ChangeDrawColor :public Action
{
private:
	ActionType color;
public:
	ChangeDrawColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

