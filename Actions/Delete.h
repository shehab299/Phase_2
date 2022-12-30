#pragma once


#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class Delete : public Action
{
private:
public:
	Delete(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void undo();

	virtual void redo();
};

