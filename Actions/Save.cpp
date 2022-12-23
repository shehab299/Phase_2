#include "Save.h"

#include "..\ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

Save::Save(ApplicationManager* pApp) : Action(pApp)
{}

void Save::ReadActionParameters()
{
	Output* pOut = pManager -> GetOutput();
	Input* pIn = pManager -> GetInput();

	pOut->PrintMessage("input the file name ");
	file_name = pIn->GetSrting(pOut) + ".txt";
}

void Save::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	bool is_saved = pManager->SaveAll(file_name);
	if (is_saved)
		pOut->PrintMessage("Saved Successfully");
	else
		pOut->PrintMessage("Something wrong happened , try again");

}

