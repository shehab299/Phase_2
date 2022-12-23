#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\UI_Info.h"
#include "..\GUI\Output.h"
//Base class for all figures
class CFigure
{
protected:
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int ID;		//Each figure has an ID
	/// Add more parameters if needed.

public:

	CFigure(GfxInfo FigureGfxInfo);
	void SetID(int id);
	int GetID();
	void SetSelected(bool s);	//select/unselect the figure
	virtual bool IsBelong(Point p) const = 0;	//check whether point is on fig
	bool IsSelected();
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	//string GetDrawClr();  //gets the the figure's drawing color
	//string GetFillClr();  //gets the the figure's filling color																		
	//The following functions should be supported by the figure class
	//It should be overridden by each inherited figure
	//Decide the parameters that you should pass to each function	
	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut)const = 0;	//print all figure info on the status bar
};

#endif
