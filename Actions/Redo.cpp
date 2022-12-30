#include "Redo.h"

#include "..\ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"


Redo::Redo(ApplicationManager* pApp) : Action(pApp)
{}

void Redo::ReadActionParameters()
{}

void Redo::Execute()
{
	pManager->RedoLastAction();
}

void Redo::undo()
{}

void Redo::redo()
{}


