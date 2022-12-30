#pragma once

#include "Action.h"

class Undo : public Action
{
private:

public:
	Undo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};