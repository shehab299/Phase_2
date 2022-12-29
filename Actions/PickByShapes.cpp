#include "PickByShapes.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

void PickByShapes::PrintScore(int Score)
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

PickByShapes::PickByShapes(ApplicationManager* pApp) : Action(pApp)
{
	flscntr = 0;
	trucntr = 0;
}

void PickByShapes::ReadActionParameters()
{
}

void PickByShapes::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	NoPickedFig = pManager->GetFigCount();
	CFigure* ClickedFig;
	rand_fig_no = rand() % NoPickedFig;
	Fig = pManager->RetFig(rand_fig_no);
	if (dynamic_cast<CRectangle*>(Fig))
		pOut->PrintMessage("Pick up all the rectangles!");
	else if (dynamic_cast<CTriangle*>(Fig))
		pOut->PrintMessage("Pick up all the triangles!");
	else if (dynamic_cast<CCircle*>(Fig))
		pOut->PrintMessage("Pick up all the circles!");
	else if (dynamic_cast<CSquare*>(Fig))
		pOut->PrintMessage("Pick up all the squares!");
	else
		pOut->PrintMessage("Pick up all the hexagons!");

	while (NoPickedFig > 0)
	{
		{

			pIn->GetPointClicked(P.x, P.y);
			ClickedFig = pManager->GetFigure(P.x, P.y);
			if (ClickedFig != NULL)
			{

				if ((dynamic_cast<CHexagon*>(ClickedFig)) && (dynamic_cast<CHexagon*>(Fig)))
				{
					PrintScore(1);
					pManager->UpdateInterface();
					NoPickedFig--;
				}
				else if ((dynamic_cast<CTriangle*>(ClickedFig)) && (dynamic_cast<CTriangle*>(Fig)))
				{
					PrintScore(1);
					pManager->UpdateInterface();
					NoPickedFig--;
				}
				else if ((dynamic_cast<CCircle*>(ClickedFig)) && (dynamic_cast<CCircle*>(Fig)))
				{
					PrintScore(1);
					pManager->UpdateInterface();
					NoPickedFig--;
				}
				else if ((dynamic_cast<CRectangle*>(ClickedFig)) && (dynamic_cast<CRectangle*>(Fig)))
				{
					PrintScore(1);
					pManager->UpdateInterface();
					NoPickedFig--;
				}
				else if ((dynamic_cast<CSquare*>(ClickedFig)) && (dynamic_cast<CSquare*>(Fig)))
				{
					PrintScore(1);
					pManager->UpdateInterface();
					NoPickedFig--;
				}
				else
				{
					PrintScore(2);
					pManager->UpdateInterface();
				}
			}
		}
	}
	if (!NoPickedFig)
		PrintScore(3);
	pManager->UpdateInterface();
}
	
