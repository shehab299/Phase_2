#include "Delete.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{}

void Delete::ReadActionParameters()
{}

void Delete::Execute()
{
	figPtr = pManager->GetSelectedFig();

	if(figPtr)
		pManager->DeleteFigure(figPtr);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Select a Figure first");
	}

}


void Delete::undo()
{
	pManager->RestoreDeleted(figPtr);
}

void Delete::redo()
{
	if (pManager->GetSelectedFig() == figPtr)
		pManager->SetSelectedFig(NULL);
	pManager->DeleteFigure(figPtr);
}




