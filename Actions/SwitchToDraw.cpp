#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) : Action(pApp)
{}
void SwitchToDraw::ReadActionParameters()
{}

void SwitchToDraw::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	/// <summary>
	/// save the graph
	/// </summary>
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Welcome to the Draw mode!!   Please choose an icon  to start ");

}

void SwitchToDraw::undo()
{}


void SwitchToDraw::redo()
{}