#pragma once
#include "Action.h"
class MoveByDragging :public Action
{
private:
	Point p;
public:
	MoveByDragging(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

