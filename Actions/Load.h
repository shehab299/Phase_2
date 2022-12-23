#pragma once
#include "Action.h"

class Load : public Action
{
private:
	string file_name;
public:
	Load(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
