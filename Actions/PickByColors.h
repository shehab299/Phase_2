#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class PickByColors :public Action
{
private:
	CFigure* Fig;
	int  rand_fig_no, NoPickedFig, flscntr, trucntr;
	Point P;
public:
	PickByColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
