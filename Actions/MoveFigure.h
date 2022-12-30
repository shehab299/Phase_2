#pragma once
#include"Action.h"
#include "..\Figures\CFigure.h"
class MoveFigure : public Action
{

private:
	Point p;
public:
	MoveFigure(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

};
