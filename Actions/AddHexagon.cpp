#include "AddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexagon::AddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexagon::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");

	//Read center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);

	HxgGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HxgGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HxgGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexagon::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	figPtr = new CHexagon(Center,HxgGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(figPtr);
}


void AddHexagon::undo()
{
	pManager->DeleteFigure(figPtr);
}

void AddHexagon::redo()
{
	if (pManager->GetSelectedFig() == figPtr)
		pManager->SetSelectedFig(NULL);
	pManager->RestoreDeleted(figPtr);
}


