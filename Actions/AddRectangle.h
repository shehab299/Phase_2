#pragma once

#include "Action.h"

//Add Rectangle Action class
class AddRectangle : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRectangle(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();

	virtual void redo();
};

