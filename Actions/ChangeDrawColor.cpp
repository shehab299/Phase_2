#include "ChangeDrawColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager* pApp) :Action(pApp)
{
}

void ChangeDrawColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
		Point* Pc = new Point;
		pOut->PrintMessage("Change Draw Color Action: Please Choose a color from the colors list.");
		color = pIn->GetUserAction();
		pOut->ClearStatusBar();
		delete Pc;
		Pc = NULL;
}

void ChangeDrawColor::Execute()
{

	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	switch (color)
	{
		pOut->setIsfilled(true);
		pOut->setCrntFillColor(color);

		case yellow:
		{
			(pManager->GetSelectedFig())->ChngDrawClr(YELLOW);
			UI.DrawColor = YELLOW;
			break;
		}

		case red:
		{
			(pManager->GetSelectedFig())->ChngDrawClr(RED);
			UI.DrawColor = RED;
			break;
		}

		case blue:
		{
			(pManager->GetSelectedFig())->ChngDrawClr(BLUE);
			UI.DrawColor = BLUE;
			break;
		}

		case green:
		{
			(pManager->GetSelectedFig())->ChngDrawClr(GREEN);
			UI.DrawColor = GREEN;
			break;
		}

		case black:
		{
			(pManager->GetSelectedFig())->ChngDrawClr(BLACK);
			UI.DrawColor = BLACK;
			break;
		}

		case orange:
		{
			(pManager->GetSelectedFig())->ChngDrawClr(ORANGE);
			UI.DrawColor = ORANGE;
			break;
		}
	}


}
