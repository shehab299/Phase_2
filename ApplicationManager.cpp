#include "ApplicationManager.h"
#include "Actions\AddRectangle.h"
#include "Actions\AddSquare.h"
#include"Actions\AddTriangle.h"
#include "Actions\AddCircle.h"
#include "Actions\AddHexagon.h"
#include "Figures\CFigure.h"
#include "Actions/Delete.h"
#include "Actions\Select.h"
#include "Actions\ShowShapes.h"
#include "Actions\ShowColors.h"
#include "Actions/Exit.h"
#include "Actions/SwitchToPlay.h"
#include "Actions/PickByShapes.h"
#include "Actions/PickByColors.h"
#include "Actions/PickByShapesAndColors.h"


#include <cmath>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	SelectedFig = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case rectangle:
			pAct = new AddRectangle(this);
			break;

		case circle:
			pAct = new AddCircle(this);
			break;

		case square:
			pAct = new AddSquare(this);
			break;

		case hexagon:
			pAct = new AddHexagon(this);
			break;

		case triangle:
			pAct = new AddTriangle(this);
			break;

		case ADD:
			pAct = new ShowShapes(this);
			break;
		
		case FILL:
			pAct = new ShowColors(this);
			break;

		case DCOLOR:
			pAct = new ShowColors(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlay(this);
			break;
		case DLTE:
			pAct = new Delete(this);
			break;

		case PCOLOR:
			pAct = new PickByColors(this);
			break;

		case PSHAPE:
			pAct = new PickByShapes(this);
			break;

		case PCOLORNSHAPE:
			pAct = new PickByShapesAndColors(this);
			break;

		case EXIT:
			pAct = new Exit(this);
			break;

		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		pFig->SetID(FigCount);
	}
}
/*void ApplicationManager::DeleteFigure(int ID)
{
	for (int i = ID; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
		FigList[i]->SetID(i);
	}
	//Reduce FigCount by 1 and nullify the extra pointer (used to point at the deleted figure)
	FigCount--;
	FigList[FigCount] = NULL;

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]==pFig)
		{
			delete FigList[i];
			FigCount--;
			FigList[i] = FigList[FigCount - 1];
			FigList[--FigCount] = NULL;
		}
	}
	}*/

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	Point p;
	p.x = x;
	p.y = y;
	for (int i = FigCount - 1; i >=0; i--)
	{
		if (FigList[i]->IsBelong(p))
		{
			return FigList[i];
		}
	}
	return NULL;
}
void ApplicationManager::SetSelectedFig(CFigure* Fig)
{
	SelectedFig = Fig;
}
CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}
