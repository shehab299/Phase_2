#pragma once

#include "Action.h"

//Add Hexagon Action class
class AddHexagon : public Action
{
private:
	Point Center; //Hexagon center
	GfxInfo HxgGfxInfo;
public:
	AddHexagon(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();

};

