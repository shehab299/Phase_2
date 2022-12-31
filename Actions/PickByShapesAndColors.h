#pragma once
#include "Action.h"
#include"../Figures/CFigure.h"
class PickByShapesAndColors : public Action
{

private:
	CFigure* Fig;
	int  rand_fig_no, NoPickedFig, flscntr, trucntr;
	Point P;
public:
	PickByShapesAndColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};


