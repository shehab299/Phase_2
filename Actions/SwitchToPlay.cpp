#include "SwitchToPlay.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SwitchToPlay::SwitchToPlay(ApplicationManager* pApp): Action(pApp)
{}
void SwitchToPlay::ReadActionParameters()
{}

void SwitchToPlay::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	/// <summary>
	/// save the graph
	/// </summary>
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Welcome to the play mode!!   Please choose a mode from ( by shape/color/shape and color) to start ");

}