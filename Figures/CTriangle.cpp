#include "CTriangle.h"
CTriangle::CTriangle(Point p1,Point p2,Point p3,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TCorner1=p1;	
	TCorner2=p2;	
	TCorner3=p3;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(TCorner1, TCorner2, TCorner3,FigGfxInfo, Selected);
}


CTriangle::~CTriangle(void)
{
}
