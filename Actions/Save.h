#pragma once
#include "Action.h"


class Save : public Action
{
private:
	string file_name;
public:
	Save(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};

