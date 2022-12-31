#include "ResizeByDragging.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ResizeByDragging::ResizeByDragging(ApplicationManager* pApp) :Action(pApp)
{}

void ResizeByDragging::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Resize By Dragging Action:Please drag the selected figure from a corner");
		while (pIn->GetPointDragged(p.x, p.y) == BUTTON_UP)
		{
			while (pIn->GetPointDragged(p.x, p.y) == BUTTON_DOWN)
			{
				pManager->GetSelectedFig()->Resize(p);
				pManager->UpdateInterface();
			}
		}
	pOut->ClearStatusBar();
}

void ResizeByDragging::Execute()
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
