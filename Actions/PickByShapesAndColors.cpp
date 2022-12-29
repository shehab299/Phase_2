#include "PickByShapesAndColors.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CHexagon.h"
#include"../Figures/CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PickByShapesAndColors::PickByShapesAndColors(ApplicationManager* pApp) : Action(pApp)
{
	flscntr = 0;
	trucntr = 0;
}
void PickByShapesAndColors::PrntScore(int Score) {

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

void PickByShapesAndColors::ReadActionParameters()
{
	for (int i = 0; i < pManager->GetFigCount(); i++) {
		Fig = pManager->RetFig(i);
		if ((Fig->GetGfxInfo().isFilled)) //counts combinations occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[0]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[1]++;
				else
					combinations[2]++;
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[3]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[4]++;
				else
					combinations[5]++;
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[6]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[7]++;
				else
					combinations[8]++;
			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[9]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[10]++;
				else
					combinations[11]++;
			}
			else
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[12]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[13]++;
				else
					combinations[14]++;
			}
		}
		else {
			if (dynamic_cast<CRectangle*>(Fig))
				combinations[15]++;
			else if (dynamic_cast<CTriangle*>(Fig))
				combinations[16]++;
			else if (dynamic_cast<CCircle*>(Fig))
				combinations[17]++;
			else
			{

				if (Fig->GetGfxInfo().DrawClr == BLACK)
					combinations[18]++;

				else if (Fig->GetGfxInfo().DrawClr == WHITE)
					combinations[19]++;

				else if (Fig->GetGfxInfo().DrawClr == BLUE)
					combinations[20]++;

				else if (Fig->GetGfxInfo().DrawClr == GREEN)
					combinations[21]++;

				else
					combinations[22]++;

			}
		}
	}

	for (int i = 0; i < 23; i++)
		if (combinations[i] != 0)
			no_combs++;


}

void PickByShapesAndColors::Execute()
{
}
