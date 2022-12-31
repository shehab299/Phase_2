#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
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
	void AddFigure(CFigure* pFig); 	//Adds a new figure to the FigList
	void DeleteFigure(int ID);//Delete a figure from the FigList
	CFigure *GetFigure(int x1, int y1) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure* Fig);
	CFigure* GetSelectedFig();
	int GetFigCount(); // get the number of the figlist
	int GetFilledFigCout(); // get the number of filled figs in the figlist 
	int GetColorsCount(color c);  // get the filled figs in the figlist with a specific color
	int GetSearchedFigCount(CFigure* Fig); // // get the number of a specific fig the figlist
	int GetColoredFigCount(CFigure* Fig); //// get the number of a specific fig filled with a specific color in the figlist
	CFigure* RetFig(int idx); // return a fig from the figlist with the passed index 
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	 
	void ShowAllFigure();
};

#endif
