#pragma once

#include "Action.h"


class Move : public Action
{
private:
	Point p;
public:
	Move(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};