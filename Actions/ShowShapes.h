#include "Action.h"


class ShowShapes : public Action
{
private:
public:
	ShowShapes(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};