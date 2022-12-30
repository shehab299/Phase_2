#include "Exit.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Exit::Exit(ApplicationManager* pApp) : Action(pApp)
{}

void Exit::ReadActionParameters()
{}

void Exit::Execute()
{}

void Exit::undo()
{}

void Exit::redo()
{}