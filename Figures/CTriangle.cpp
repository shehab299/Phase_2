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
	return Area == Area1 + Area2 + Area3;
}


void CTriangle::Save(ofstream& OutFile) const
{
	string type = to_string(TRIANGLE);
	string id = to_string(ID);
	int draw_color = TranslateToInt(FigGfxInfo.DrawClr);
	int fill = (FigGfxInfo.isFilled) ? TranslateToInt(FigGfxInfo.FillClr) : -1;

	if (OutFile.is_open()) {
		OutFile << setw(1) << type << " ";
		OutFile << setw(3) << id << " ";
		OutFile << setw(3) << Corner1.x << " ";
		OutFile << setw(3) << Corner1.y << " ";
		OutFile << setw(3) << Corner2.x << " ";
		OutFile << setw(3) << Corner2.y << " ";
		OutFile << setw(3) << Corner3.x << " ";
		OutFile << setw(3) << Corner3.y << " ";
		OutFile << setw(3) << draw_color << " ";
		OutFile << setw(3) << fill << " ";
		OutFile << '\n';
	}
}

void CTriangle::Load(fstream& InFile) 
{
	int draw_color, fill;
	if (InFile.is_open())
	{
		InFile >> ID;
		InFile >> Corner1.x >> Corner1.y;
		InFile >> Corner2.x >> Corner2.y;
		InFile >> Corner3.x >> Corner3.y;
		InFile >> draw_color >> fill;
		if (fill == -1)
			FigGfxInfo.isFilled = false;
		else
			ChngFillClr(TranslateToColor(fill));
		ChngDrawClr(TranslateToColor(draw_color));
	}
}
void CTriangle::MoveFigure(Point p)
{

	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;//setters for Center
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	undoCen.x = (Corner1.x + Corner2.x + Corner3.x) / 3; //setters for undoCenter
	undoCen.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	undoCr1.x = Corner1.x;  //setters for corners
	undoCr1.y = Corner1.y;
	undoCr2.x = Corner2.x;
	undoCr2.y = Corner2.y;
	undoCr3.x = Corner3.x;
	undoCr3.y = Corner3.y;



	int DeltaxMovement = (p.x - Center.x);
	int DeltayMovement = (p.y - Center.y);

	Center.x = p.x; //new Center
	Center.y = p.y;

	redoCen.x = p.x;
	redoCen.y = p.y; //setters for redocenter

	Corner1.x += DeltaxMovement; 
	Corner1.y += DeltayMovement;
	Corner2.x += DeltaxMovement;
	Corner2.y += DeltayMovement;
	Corner3.x += DeltaxMovement;
	Corner3.y += DeltayMovement;

	redoCr1.x = Corner1.x; //settersfor redocorners
	redoCr1.y = Corner1.y;
	redoCr2.x = Corner2.x;
	redoCr2.y = Corner2.y;
	redoCr3.x = Corner3.x;
	redoCr3.y = Corner3.y;
}

void CTriangle::cancelFigure()
{
	Center.x = undoCen.x;
	Center.y = undoCen.y;
	Corner1.x = undoCr1.x;
	Corner1.y = undoCr1.y;
	Corner2.x = undoCr2.x;
	Corner2.y = undoCr2.y;
	Corner3.x = undoCr3.x;
	Corner3.y = undoCr3.y;

}

void CTriangle::Redotransition()
{
	Center.x = redoCen.x;
	Center.y = redoCen.y;
	Corner1.x = redoCr1.x;
	Corner1.y = redoCr1.y;
	Corner2.x = redoCr2.x;
	Corner2.y = redoCr2.y;
	Corner3.x = redoCr3.x;
	Corner3.y = redoCr3.y;
}
