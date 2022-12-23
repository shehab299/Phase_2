#include "Load.h"

#include "..\ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

Load::Load(ApplicationManager* pApp) : Action(pApp)
{}

void Load::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("input the file name ");
	file_name = pIn->GetSrting(pOut) + ".txt";
}


void Load::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	bool is_loaded = pManager->LoadAll(file_name);
	/*if (is_loaded)
		pOut->PrintMessage("Loaded Successfully");
	else
		pOut->PrintMessage("Something wrong happened , try again");
		*/
}
