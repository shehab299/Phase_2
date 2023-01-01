#include "MoveByDragging.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Move.h"

MoveByDragging::MoveByDragging(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveByDragging::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move By Dragging Action:Please drag the selected figure from a point inside it");
	while (pIn->GetPointDragged(p.x, p.y) == BUTTON_UP)
	{
		if ((pManager->GetFigure(p.x, p.y)) == (pManager->GetSelectedFig()))
		while (pIn->GetPointDragged(p.x, p.y) == BUTTON_DOWN)
		{
			pManager->GetSelectedFig()->Displacment(p);
			Sleep(10);
			pManager->UpdateInterface();
		}
	}
	pOut->ClearStatusBar();
}

void MoveByDragging::Execute()
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
