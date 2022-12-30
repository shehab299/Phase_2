#pragma once
#pragma once
#include"Action.h"
class ChangeColor : public Action
{
private:
	ActionType NewColor;
	color undoclr;
	color redoclr;
public:
	ChangeColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

};
