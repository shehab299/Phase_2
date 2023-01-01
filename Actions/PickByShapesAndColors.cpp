#include "PickByShapesAndColors.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
PickByShapesAndColors::PickByShapesAndColors(ApplicationManager* pApp) : Action(pApp)
{
	flscntr = 0;
	trucntr = 0;
}

void PickByShapesAndColors::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	do
	{
		rand_fig_no = rand() % pManager->GetFigCount();
		Fig = pManager->RetFig(rand_fig_no);
	} while (!(Fig->GetGfxInfo().isFilled));
	NoPickedFig = pManager->GetColoredFigCount(Fig);
	pOut->PrintMessage("pick all " + Fig->GetFillClr() + " "+ Fig->GetFigureType()+"s.");
}

void PickByShapesAndColors::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (!pManager->GetFilledFigCout())
		pOut->PrintMessage("You must draw a filled figure at least !!!");
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
				if ((Fig->GetFillClr() == ClickedFig->GetFillClr()) && (ClickedFig->GetGfxInfo().isFilled) && ( Fig->GetFigureType() == ClickedFig->GetFigureType() ) )
				{
					ClickedFig->SetHidden(1);
					trucntr++;
					pOut->PrintMessage("True :)");
					NoPickedFig--;
				}
				else
				{
					ClickedFig->SetHidden(1);
					flscntr++;
					pOut->PrintMessage("False T-T");
				}
			}
			Sleep(500);
			pManager->UpdateInterface();
			pOut->PrintMessage("Your score is : " + to_string(trucntr) + " True, and " + to_string(flscntr) + " False.");
		}
		if (NoPickedFig == 0)
		{
			pManager->ShowAllFigure();
			pOut->PrintMessage("Congratulations!!! you won <3");
		}
		pManager->UpdateInterface();
		Sleep(1000);
		pOut->PrintMessage("Your score is : " + to_string(trucntr) + " True, and " + to_string(flscntr) + " False.");
	}
}
