#pragma once

#include "Action.h"


class Exit : public Action
{
private:
public:
	Exit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};