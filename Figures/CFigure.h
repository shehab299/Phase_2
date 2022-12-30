#ifndef CFIGURE_H
#define CFIGURE_H


#include <fstream>
#include <iomanip>


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
	bool IsSelected();

	virtual bool IsBelong(Point p) const = 0;	//check whether point is on fig
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	
	
	

	virtual void Save(ofstream &OutFile) const = 0 ;	//Save the figure parameters to the file
	virtual void Load(fstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
};

int TranslateToInt(color);
color TranslateToColor(int);



#endif
