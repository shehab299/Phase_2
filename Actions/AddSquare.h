#pragma once

#include "Action.h"

//Add Square Action class
class AddSquare : public Action
{
private:
	Point Center; //Square Center
	GfxInfo SqrGfxInfo;
public:
	AddSquare(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};

