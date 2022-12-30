#pragma once
#include "MoveFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigure::MoveFigure(ApplicationManager* pApp) : Action(pApp)
{}

void MoveFigure::ReadActionParameters()
{
	Point Pc;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool flag = true;
	pOut->PrintMessage("Select Action:Please Click at a point on the drawing area");

	do {
		pIn->GetPointClicked(Pc.x, Pc.y);
		if (Pc.y > (UI.AdditionalItemsHeight + UI.ToolBarHeight) && Pc.y < (UI.height - UI.StatusBarHeight))
		{
			p.x = Pc.x;
			p.y = Pc.y;
			flag = false;
		}
		else
			pOut->PrintMessage("Please Click at a point on the drawing area");
	} while (flag);
	pOut->ClearStatusBar();
}

void MoveFigure::Execute()
{

	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	mfigptr = pManager->GetSelectedFig();
	if(mfigptr)
	mfigptr->MoveFigure(p);
	else
	{
		
		pOut->PrintMessage("Select a Figure first to Move ");
	}

}
void MoveFigure::undo()
{
	mfigptr->cancelFigure();
}
void MoveFigure::redo()
{
	mfigptr->Redotransition();
}
