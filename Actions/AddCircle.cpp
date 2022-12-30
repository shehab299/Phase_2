#include "AddCircle.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircle::AddCircle(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at a point on the circle");

	//Read a point on the circle and store in point Rad
	pIn->GetPointClicked(Rad.x, Rad.y);

	CrclGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CrclGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CrclGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircle::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	figPtr = new CCircle(Center, Rad, CrclGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(figPtr);
}

void AddCircle::undo()
{
	if (pManager->GetSelectedFig() == figPtr)
		pManager->SetSelectedFig(NULL);
	pManager->DeleteFigure(figPtr);
}

void AddCircle::redo()
{
	pManager->RestoreDeleted(figPtr);
}



