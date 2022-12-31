#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	hide = false;
}

void CFigure::SetID(int id)
{
	ID = id;
}

int CFigure::GetID()
{
	return ID;
}

bool CFigure::ishidden()
{
	return hide;
}

void CFigure::SetHidden(bool h)
{
	hide = h;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsBelong(Point p) const
{
	return 0; 
}
bool CFigure::IsSelected()
{
	return Selected;
}

GfxInfo CFigure::GetGfxInfo()
{
	return FigGfxInfo;
}

int CFigure::dist(Point p1, Point p2) const
{
	return sqrt(pow((p1.x-p2.x), 2) + pow((p1.y-p2.y), 2));
}


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::GetDrawClr()
{

	if (FigGfxInfo.DrawClr == BLACK)
		return "black";
	else if (FigGfxInfo.DrawClr == RED)
		return "red";
	else if (FigGfxInfo.DrawClr == YELLOW)
		return "yellow";
	else if (FigGfxInfo.DrawClr == ORANGE)
		return "orange";
	else if (FigGfxInfo.DrawClr == GREEN)
		return "green";
	else
		return "blue";
}

string CFigure::GetFillClr()
{
	if (FigGfxInfo.isFilled)
	{
		if (FigGfxInfo.FillClr == BLACK)
			return "black";
		else if (FigGfxInfo.FillClr == RED)
			return "red";
		else if (FigGfxInfo.FillClr == YELLOW)
			return "yellow";
		else if (FigGfxInfo.FillClr == ORANGE)
			return "orange";
		else if (FigGfxInfo.FillClr == GREEN)
			return "green";
		else if (FigGfxInfo.FillClr == BLUE)
			return "blue";
	}
}

