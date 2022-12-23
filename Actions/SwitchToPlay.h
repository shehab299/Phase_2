#pragma once
#include"Action.h"
class SwitchToPlay:public Action
{
private:
public:
	SwitchToPlay(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

