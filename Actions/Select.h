#include "Action.h"
#include "..\Figures\CFigure.h"
class Select : public Action
{

private:
	Point p;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};