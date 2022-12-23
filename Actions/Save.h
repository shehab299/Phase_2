#pragma once
#include "Action.h"


class Save : public Action
{
private:
	string file_name;
public:
	Save(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

};

