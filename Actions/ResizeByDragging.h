#pragma once
#include "Action.h"
class ResizeByDragging : public Action
{
private:
	Point p;
public:
	ResizeByDragging(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
