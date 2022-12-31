#include "CCircle.h"

CCircle::CCircle(Point cntr, Point p, GfxInfo FigGfxInfo) :CFigure(FigGfxInfo)
{
	Center = cntr;
	RadiusP = p;
 r = dist(Center, RadiusP);
}
void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCrcl(Center, RadiusP, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("CIRCLE ID   " + to_string(ID) + "    Center(" + to_string(Center.x) + "  ,  " + to_string(Center.y) + ")   raduis  " + to_string(r));
}

bool CCircle::IsBelong( Point p) const
{
	//check if the distance between the point and the center less than or equal the radius
	int d = dist(Center,p);
	return (d <= r);
}

void CCircle::Displacment(Point p) 
{
	RadiusP.x = p.x + r;
	RadiusP.y = p.y;
	Center.x = p.x;
	Center.y = p.y;
}

void CCircle::Resize(Point p)
{
	RadiusP = p;
}

string CCircle::GetFigureType() const
{
	return "Circle";
}

