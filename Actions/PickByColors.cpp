#include "PickByColors.h"
#include "..\CMUgraphicsLib\colors.cpp" 
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

color PickByColors::AssignColor(CFigure* Fig )
{
	if (Fig->GetGfxInfo().isFilled)
	{
		if (Fig->GetGfxInfo().FillClr == BLACK)
			return BLACK;
		else if (Fig->GetGfxInfo().FillClr == YELLOW)
			return WHITE;
		else if (Fig->GetGfxInfo().FillClr == BLUE)
			return BLUE;
		else if (Fig->GetGfxInfo().FillClr == GREEN)
			return GREEN;
		else if (Fig->GetGfxInfo().FillClr == RED)
			return RED;
		else if (Fig->GetGfxInfo().FillClr == ORANGE)
			return ORANGE;
	}
	return TURQUOISE;
}

void PickByColors::PrntScore(int Score)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (Score == 1)
	{
		trucntr++;
		message = "True!!! (:";
	}
	else 	if (Score == 2)
	{
		flscntr++;
		message = "False!!! T-T";
	}
	else
		message = "Congratulations,YOU WIN!!! :> ";
	pOut->PrintMessage(message);
	Sleep(1000);

	pOut->PrintMessage("Your score is : " + to_string(trucntr) + " True, and " + to_string(flscntr) + " False.");

}

PickByColors::PickByColors(ApplicationManager* pApp) : Action(pApp)
{
	flscntr = 0;
	trucntr = 0;
}

void PickByColors::ReadActionParameters()
{
}

void PickByColors::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

		CFigure* ClickedFig;
		NoPickedFig = pManager->GetFigCount();
		rand_fig_no = rand() % NoPickedFig;
		Fig = pManager->RetFig(rand_fig_no);
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				pOut->PrintMessage("Pick up figures colored black!");
			}
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
			{
				pOut->PrintMessage("Pick up figures colored yellow!");
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				pOut->PrintMessage("Pick up figures colored blue!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				pOut->PrintMessage("Pick up figures colored green!");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				pOut->PrintMessage("Pick up figures colored red!");

			}
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
			{
				pOut->PrintMessage("Pick up figures colored orange!");
			}
		}
		

		while (NoPickedFig > 0)
		{

			pIn->GetPointClicked(P.x, P.y);
		
				ClickedFig = pManager->GetFigure(P.x, P.y);
				if (ClickedFig != NULL)
				{

					if ((!(Fig->GetGfxInfo().isFilled) &&  (!(ClickedFig->GetGfxInfo().isFilled))))
					{
						PrntScore(1);
						pManager->UpdateInterface();
						NoPickedFig--;
					}
					else
					{
						PrntScore(2);
						pManager->UpdateInterface();
					}
				}

		}
		if (NoPickedFig == 0)
			PrntScore(3);
	
	pManager->UpdateInterface();

}
