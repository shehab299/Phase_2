#include "PickByShapes.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
PickByShapes::PickByShapes(ApplicationManager* pApp) : Action(pApp)
{
	flscntr = 0;
	trucntr = 0;
}

void PickByShapes::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
		rand_fig_no = rand() % pManager->GetFigCount();
		Fig = pManager->RetFig(rand_fig_no);
		NoPickedFig = pManager->GetSearchedFigCount(Fig);
	pOut->PrintMessage("pick all " + Fig->GetFigureType() + "s.");
}

void PickByShapes::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (!pManager->GetFigCount())
		pOut->PrintMessage("You must draw at least a  figure first!!!!");
	else
	{
		ReadActionParameters();
		CFigure* ClickedFig;
		while (NoPickedFig > 0)
		{
			pIn->GetPointClicked(P.x, P.y);
			ClickedFig = pManager->GetFigure(P.x, P.y);
			if (ClickedFig != NULL)
			{
				if (Fig->GetFigureType() == ClickedFig->GetFigureType())
				{
					trucntr++;
					pOut->PrintMessage("True :)");
					NoPickedFig--;
				}
				else
				{
					flscntr++;
					pOut->PrintMessage("False T-T");
				}
			}
		}
		if (NoPickedFig == 0)
			pOut->PrintMessage("Congratulations!!! you won <3");

		pManager->UpdateInterface();
		Sleep(1000);
		pOut->PrintMessage("Your score is : " + to_string(trucntr) + " True, and " + to_string(flscntr) + " False.");
	}
}
