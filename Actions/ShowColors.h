#include "Action.h"


class ShowColors : public Action
{
private:
public:
	ShowColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};


