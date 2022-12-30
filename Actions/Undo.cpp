#include "Undo.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Undo::Undo(ApplicationManager* pApp) : Action(pApp)
{}

void Undo::ReadActionParameters()
{}

void Undo::Execute()
{
	pManager->UndoLastAction();
}

void Undo::undo()
{}

void Undo::redo()
{}


