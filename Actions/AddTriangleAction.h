#include "Action.h"

//Add Rectangle Action class
class AddTriangleAction: public Action
{
private:
	Point P1,P2,P3; //Triangle Corners
	GfxInfo TrianglefGfxInfo;
public:
	AddTriangleAction(ApplicationManager *pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();
	
	//Add Triangle to the ApplicationManager
	virtual void Execute() ;
	
};