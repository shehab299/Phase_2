#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetID(int id)
{
	ID = id;
}

int CFigure::GetID()
{
	return ID;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsBelong(Output* pOut,Point p) const
{
	return 0; 
}
bool CFigure::IsSelected()
{
	return Selected;
}


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


/*string CFigure::GetDrawClr()
{

	if (FigGfxInfo.FillClr == BLACK)
		return "BLACK";
	else if (FigGfxInfo.FillClr == RED)
		return "RED";
	else if (FigGfxInfo.FillClr == YELLOW)
		return "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE)
		return "ORANGE";
	else if (FigGfxInfo.FillClr == GREEN)
		return "GREEN";
	else
		return "BLUE";
}


string CFigure::GetFillClr()
{
	if (FigGfxInfo.FillClr == BLACK)
		return "BLACK";
	else if (FigGfxInfo.FillClr== RED)
		return "RED";
	else if (FigGfxInfo.FillClr == YELLOW)
		return "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE)
		return "ORANGE";
	else if (FigGfxInfo.FillClr == GREEN)
		return "GREEN";
	else if (FigGfxInfo.FillClr == BLUE)
		return "BLUE";
	else
		return "NO_FILL";
}

*/