#pragma once

#include "Action.h"

//Add triangle Action class
class AddTriangle : public Action
{
private:
	Point P1, P2,P3,Pc; //Triangle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriangle(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};

