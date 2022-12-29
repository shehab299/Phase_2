#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("RECTANGLE ID   " + to_string(ID) + "   " + to_string(Corner1.x) + "   " + to_string(Corner1.y) + "   " + to_string(Corner2.x) + "   " + to_string(Corner2.y));
}

bool CRectangle::IsBelong(Point p) const
{
	int Xmin = (Corner1.x < Corner2.x) ? Corner1.x : Corner2.x;
	int Xmax = (Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Ymin = (Corner1.y < Corner2.y) ? Corner1.y : Corner2.y;
	int Ymax = (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	return (p.x > Xmin && p.x<Xmax&& p.y>Ymin && p.y < Ymax);
}

void CRectangle::Displacment(Point p)
{
	int DeltaX = abs(Corner1.x - Corner2.x)/2;
	int DeltaY = abs(Corner1.y - Corner2.y)/2;
	Corner2.x = p.x + DeltaX;
	Corner2.y = p.y + DeltaY;
	Corner1.x = p.x - DeltaX;
	Corner1.y = p.y - DeltaY;
}
