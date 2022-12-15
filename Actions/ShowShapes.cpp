#include "ShowShapes.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ShowShapes::ShowShapes(ApplicationManager* pApp) : Action(pApp)
{}

void ShowShapes::ReadActionParameters()
{}

void ShowShapes::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->CreateAdditionalItemsBar(SHAPES);

}
