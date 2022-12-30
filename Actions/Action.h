#pragma once

#include "..\DefS.h"
#include "../Figures/CFigure.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	CFigure* figPtr;
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() = 0;

	virtual void undo() = 0;

	virtual void redo() = 0;
};




