#include "CSquare.h"

CSquare::CSquare(Point Cntr, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = Cntr;
	length = 120;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}

void CSquare::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("SQUARE  ID   " + to_string(ID) + "    Center (" + to_string(Center.x) + "  ,  " + to_string(Center.y) + ")   side length" + to_string(length));
}

void CSquare::Displacment(Point p) 
{
	Center.x = p.x;
	Center.y = p.y;
}


bool CSquare::IsBelong( Point p)const
{
	return((p.x > Center.x - (length / 2.0)) && (p.x < Center.x + (length / 2.0)) && (p.y > Center.y - (length / 2.0)) && (p.y < Center.y + (length / 2.0)));
}

