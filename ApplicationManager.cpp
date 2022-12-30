//STL library
#include <cmath>
#include <fstream>

//Other Files
#include "ApplicationManager.h"

//Figures
#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
#include "Figures/CCircle.h"
#include "Figures/CHexagon.h"
#include "Figures/CRectangle.h"

//Actions
#include "Actions\AddRectangle.h"
#include "Actions\AddSquare.h"
#include"Actions\AddTriangle.h"
#include "Actions\AddCircle.h"
#include "Actions\AddHexagon.h"
#include "Actions\Select.h"
#include "Actions\ShowShapes.h"
#include "Actions\ShowColors.h"
#include "Actions/Exit.h"
#include "Actions/SwitchToPlay.h"
#include "Actions/PickByColors.h"
#include "Actions/PickByShapesAndColors.h"
#include "Actions/Save.h"
#include "Actions/Load.h"
#include "Actions/Delete.h"
#include "Actions/Undo.h"
#include "Actions/Redo.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	

	FigCount = 0;
	DeletedCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) 
	{
		FigList[i] = NULL;
		DeletedFigs[i] = NULL;
	}
	
	SelectedFig = NULL;
}



//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////


//Creates an Action Object and executes it based on User Input

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object

	switch (ActType)
	{

	//Showing Additional Menu
	case ADD:
		pAct = new ShowShapes(this);
		break;

	case FILL:
		pAct = new ShowColors(this);
		break;

	case DCOLOR:
		pAct = new ShowColors(this);
		break;


	//Adding Shapes Actions

	case rectangle:
		pAct = new AddRectangle(this);
		UndoList.push(pAct);
		break;

	case circle:
		pAct = new AddCircle(this);		
		UndoList.push(pAct);
		break;

	case square:
		pAct = new AddSquare(this);
		UndoList.push(pAct);
		break;

	case hexagon:
		pAct = new AddHexagon(this);
		UndoList.push(pAct);
		break;

	case triangle:
		pAct = new AddTriangle(this);
		UndoList.push(pAct);
		break;
	
	//Shapes Functionality

	case SELECT:
		pAct = new Select(this);
		break;


	case DLTE:
		pAct = new Delete(this);
		UndoList.push(pAct);
		break;


	case UNDO:
		pAct = new Undo(this);
		break;

	case REDO:
		if (LastActionType == UNDO || LastActionType == REDO)
			pAct = new Redo(this);
		else
			FlushRedo();
		break;

	//File Management
		
	case SAVE:
		pAct = new Save(this);
		break;

	case LOAD:
		pAct = new Load(this);
		break;

	case EXIT:
		pAct = new Exit(this);
		break;


	//No Action

	case STATUS:	
		return;

	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); //Execute
		LastAction = pAct;
		LastActionType = ActType;
		pAct = NULL;
	}
}


//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//


//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (pFig)
	{
		if (FigCount < MaxFigCount)
		{
			FigList[FigCount++] = pFig;
			pFig -> SetID(FigCount); // you can't reuse the same id of the deleted figures
		}
	}
}

CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	Point p;
	p.x = x;
	p.y = y;

	for (int i = FigCount - 1; i >= 0; i--)
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
	if(Fig)
	{
		SelectedFig = Fig;
	}
}

CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}

void ApplicationManager::SaveAll(ofstream& file)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(file);
	}
}


//Delete List Functions

void ApplicationManager::DeleteFigure(CFigure* Fig)
{
	for(int i = 0 ; i < FigCount ; i++)
	{
		if(Fig -> GetID() == FigList[i] -> GetID())
		{
			DeletedFigs[DeletedCount++] = FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = nullptr;
			FigCount--;
			break;
		}
	}
}

void ApplicationManager::RestoreDeleted(CFigure* Fig)
{
	for (int i = 0; i < DeletedCount; i++)
	{
		if (Fig->GetID() == DeletedFigs[i]->GetID())
		{
			FigList[FigCount++] = DeletedFigs[i];
			DeletedFigs[i] = DeletedFigs[DeletedCount - 1];
			DeletedFigs[DeletedCount - 1] = nullptr;
			DeletedCount--;
			break;
		}
	}
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}

void ApplicationManager::FlushRedo()
{
	while(!RedoList.is_empty())
	{
		delete RedoList.pop();
	}
}

void ApplicationManager::FlushUndo()
{
	while (!UndoList.is_empty())
	{
		delete UndoList.pop();
	}
}


void ApplicationManager::UndoLastAction()
{
	Action* ActPtr = UndoList.pop();
	if (ActPtr) 
	{
		ActPtr->undo();
		RedoList.push(ActPtr);
	}
}

void ApplicationManager::RedoLastAction()
{
	Action* ActPtr = RedoList.pop();
	if(ActPtr)
	{
		ActPtr->redo();
		UndoList.push(ActPtr);
	}
}



////////////////////////////////////////////////////////////////////////////////////

//Return a pointer to the Input Object
Input* ApplicationManager::GetInput() const
{
	return pIn;
}

//Return a pointer to the Output Object
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}

//Return number of figures
int ApplicationManager::getFigCount() const
{
	return FigCount;
}

////////////////////////////////////////////////////////////////////////////////////

//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];

	for (int i = 0; i < DeletedCount; i++)
		delete DeletedFigs[i];

	delete pIn;
	delete pOut;
}

