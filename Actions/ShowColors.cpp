#include "ShowColors.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ShowColors::ShowColors(ApplicationManager* pApp) : Action(pApp)
{}

void ShowColors::ReadActionParameters()
{}

void ShowColors::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

		pOut->CreateAdditionalItemsBar(COLORS);
	
}