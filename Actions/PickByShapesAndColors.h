#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByShapesAndColors : public Action
{
private:
	CFigure* Fig;
	Point P;
	int  no_combs, rand_fig_no, picked_comb_no, trucntr, flscntr;
	int combinations[23];
	//void PrntScore(int);
public:
	PickByShapesAndColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void PrntScore(int fd);

};


