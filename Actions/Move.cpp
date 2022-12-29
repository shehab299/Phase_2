#include "Move.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Move::Move(ApplicationManager* pApp) : Action(pApp)
{}

void Move::ReadActionParameters()
{

	Point Pc;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool flag = true;
	pOut->PrintMessage("Move Action:Please Click at a point on the drawing area");

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

void Move::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig()->IsSelected())
	{
		ReadActionParameters();
		pManager->GetSelectedFig()->Displacment(p);
	}
	else
		pOut->PrintMessage("Please select a figure first");
}

