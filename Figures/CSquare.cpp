#include "CSquare.h"

CSquare::CSquare(Point Cntr, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = Cntr;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}