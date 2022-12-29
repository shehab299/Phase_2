#include "ChangeFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) : Action(pApp)
{
}
void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


		Point* Pc = new Point;
		pOut->PrintMessage("Change Fill Color Action: Please Choose a color from the colors list.");
		color = pIn->GetUserAction();
		pOut->ClearStatusBar();
		delete Pc;
		Pc = NULL;
	
	
}

void ChangeFillColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	switch (color) {
		case yellow:
		{
			pOut->setCrntFillColor(YELLOW);
			(pManager->GetSelectedFig())->ChngFillClr(YELLOW);
			break;
		}

		case red:
		{
			(pManager->GetSelectedFig())->ChngFillClr(RED);
			pOut->setCrntFillColor(RED);
			break;
		}

		case blue:
		{
			(pManager->GetSelectedFig())->ChngFillClr(BLUE);
			pOut->setCrntFillColor(BLUE);
			break;
		}

		case green:
		{
			(pManager->GetSelectedFig())->ChngFillClr(GREEN);
			pOut->setCrntFillColor(GREEN);
			break;
		}

		case black:
		{
			(pManager->GetSelectedFig())->ChngFillClr(BLACK);
			pOut->setCrntFillColor(BLACK);
			break;
		}

		case orange:
		{
			(pManager->GetSelectedFig())->ChngFillClr(ORANGE);
			pOut->setCrntFillColor(ORANGE);
			break;
		}
	}


}
