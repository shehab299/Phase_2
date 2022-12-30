#pragma once
#include"Action.h"
class SwitchToDraw :public Action
{
private:
public:
	SwitchToDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();

	virtual void redo();
};