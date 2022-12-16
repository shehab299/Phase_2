#include "CCircle.h"

CCircle::CCircle(Point cntr, Point p, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = cntr;
	RadiusP = p;
}
void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCrcl(Center, RadiusP, FigGfxInfo, Selected);
}
