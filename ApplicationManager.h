#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include <climits>

#include "Figures\CFigure.h"

#include "GUI\input.h"
#include "GUI\output.h"

#include "structres/ActionStack.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200  , MaxRecordCount = 20};	//Max no of figures

private:
	int FigCount; //Actual number of figures
	int DeletedCount; //Actual number of deleted items

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* DeletedFigs[MaxFigCount];
	Action* ActionList[MaxRecordCount];


	CFigure* SelectedFig; //Pointer to the selected figure
	Action* LastAction;
	ActionType LastActionType;


	ActionStack UndoList;
	ActionStack RedoList;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions

	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void DeleteFigure(CFigure* Fig); //Delete a figure from the FigList
	void RestoreDeleted(CFigure* Fig); //Remove a figure from the DeletedList

	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point 
	
	void SetSelectedFig(CFigure* Fig);
	CFigure* GetSelectedFig();
	void SaveAll(ofstream& file);

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//Getters
	int getFigCount() const;

	//undo & redo
	void FlushRedo();
	void FlushUndo();
	void UndoLastAction();
	void RedoLastAction();

};

#endif