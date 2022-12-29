#pragma once
#include "Action.h"
#include"../Figures/CFigure.h"
class PickByShapes :  public Action
{
private:
	CFigure* Fig;
	Point P;
	int  rand_fig_no, NoPickedFig, flscntr, trucntr;
	void PrintScore(int);
public:
	PickByShapes(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

