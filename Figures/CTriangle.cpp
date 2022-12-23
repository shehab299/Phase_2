#include "CTriangle.h"
float CTriangle::CalcArea(Point p1, Point p2, Point p3)const
{
	return abs(( (p2.x * (p3.y - p1.y)) +( p3.x * (p1.y - p2.y)) + (p1.x * (p2.y - p3.y)) ) / 2.0);
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Triangle   ID : " + to_string(ID) + " Corner 1 (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ ") Corner 2 (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ") Corner 3 (" + to_string(Corner3.x)
		+ "," + to_string(Corner3.y) + ")");
}

bool CTriangle::IsBelong( Point p) const
{	
	float Area = CalcArea(Corner1, Corner2, Corner3);
	float Area1 = CalcArea(p, Corner1, Corner2);
	float Area2 = CalcArea(p, Corner3, Corner2);
	float Area3 = CalcArea(p, Corner1, Corner3);
	return(Area == Area1 + Area2 + Area3);
}
