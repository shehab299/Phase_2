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

bool CFigure::IsBelong(Point p) const
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

int TranslateToInt(color Color) 
{
	if (Color == RED)
		return RED_;
	else if (Color == GREEN)
		return GREEN_;
	else if (Color == BLUE)
		return BLUE_;
	else if (Color == YELLOW)
		return YELLOW_;
	else if (Color == ORANGE)
		return ORANGE_;
	else if (Color == BLACK)
		return BLACK_;
	else
		return UNDEFINED;
}

color TranslateToColor(int color_num)
{
	switch (color_num)
	{
	case BLACK_: return BLACK;
	case YELLOW_: return YELLOW;
	case BLUE_: return BLUE;
	case ORANGE_: return ORANGE;
	case RED_: return RED;
	case GREEN_: return GREEN;
	default:
		return UI.BkGrndColor;
	}
}



