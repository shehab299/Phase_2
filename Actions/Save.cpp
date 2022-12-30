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

	ofstream file(file_name, ios::out);

	Output* pOut = pManager->GetOutput();

	if (file)
	{
		//saving the header
		file << pManager->getFigCount() << '\n';
		file << TranslateToInt(pOut->getCrntDrawColor()) << " " << TranslateToInt(pOut->getCrntFillColor()) << '\n';
		
		pManager->SaveAll(file);
		pOut->PrintMessage("Saved Successfully");
	}
	else
		pOut->PrintMessage("Something Wrong Happened");
}

void Save::undo()
{}

void Save::redo()
{}


