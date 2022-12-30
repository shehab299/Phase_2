#pragma once


#include "Action.h"

class Redo : public Action
{
private:
public:
	Redo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

};

