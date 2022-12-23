#include "CCircle.h"

CCircle::CCircle(Point cntr, Point p, GfxInfo FigGfxInfo) :CFigure(FigGfxInfo)
{
	Center = cntr;
	RadiusP = p;
}
void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCrcl(Center, RadiusP, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("CIRCLE ID   " + to_string(ID) + "Center(" + to_string(Center.x) + "  ,  " + to_string(Center.y) + ")   raduis" + to_string(int(sqrt(pow((Center.x - RadiusP.x), 2) + pow((Center.y - RadiusP.y), 2)))));

}

bool CCircle::IsBelong( Point p) const
{
	//check if the distance between the point and the center less than or equal the radius
	int r = sqrt(pow((Center.x - RadiusP.x), 2) + pow((Center.y - RadiusP.y), 2));
	int d = sqrt(pow((Center.x - p.x), 2) + pow((Center.y - p.y), 2));
	return (d <= r);
}

