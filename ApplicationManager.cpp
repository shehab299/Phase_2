//STL library
#include <cmath>
#include <fstream>

//Other Files
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

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

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
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

	

	//Shapes Functionality
	case SELECT:
		pAct = new Select(this);
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
	if (pFig)
	{
		if (FigCount < MaxFigCount)
		{
			FigList[FigCount++] = pFig;
			pFig->SetID(FigCount);
		}
	}
}


CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
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

bool ApplicationManager::SaveAll(const string & file_name)
{
	ofstream file(file_name , ios::out);

	if (!file)
	{
		return 0;
	}

	file << FigCount << '\n';
	file << TranslateToInt(pOut->getCrntDrawColor()) << " " << TranslateToInt(pOut->getCrntFillColor()) << '\n';

	for(int i = 0 ; i < FigCount ; i++)
	{
		FigList[i] -> Save(file);
	}

	file.close();

	return 1;

}

bool ApplicationManager::LoadAll(const string & file_name)
{
	ifstream file(file_name, ios::in);

	if (!file)
	{
		return false;
	}

	int shapes_num , draw_color , fill_color;
	char new_line;
	file >> shapes_num >> new_line; 
	file >> draw_color >> fill_color >> new_line;
	pOut->PrintMessage(to_string(shapes_num) + to_string(draw_color) + to_string(fill_color));

}





//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
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


////////////////////////////////////////////////////////////////////////////////////

//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}

