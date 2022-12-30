#include "CSquare.h"

CSquare::CSquare(Point Cntr, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = Cntr;
	length=120;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}




void CSquare::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("SQUARE  ID   " + to_string(ID) + "Center(" + to_string(Center.x) + "  ,  " + to_string(Center.y) + ")   side length" + to_string(length));
}

bool CSquare::IsBelong( Point p)const
{
	return((p.x > Center.x - (length / 2.0)) && (p.x < Center.x + (length / 2.0)) && (p.y > Center.y - (length / 2.0)) && (p.y < Center.y + (length / 2.0)));
}
void CSquare::MoveFigure(Point p)
{
	undoc.x = Center.x;
	undoc.y = Center.y;
	redoc.x = p.x;
	redoc.y = p.y;
	Center.x = p.x;
	Center.y = p.y;
}

void CSquare::Save(ofstream& OutFile) const
{
	string type = to_string(SQUARE);
	string id = to_string(ID);
	int draw_color = TranslateToInt(FigGfxInfo.DrawClr);
	int fill = (FigGfxInfo.isFilled) ? TranslateToInt(FigGfxInfo.FillClr) : -1;

	if (OutFile.is_open()) {
		OutFile << setw(1) << type << " ";
		OutFile << setw(3) << id << " ";
		OutFile << setw(3) << Center.x << " ";
		OutFile << setw(3) << Center.y << " ";
		OutFile << setw(3) << draw_color << " ";
		OutFile << setw(3) << fill << " ";
		OutFile << '\n';
	}
}


void CSquare::Load(fstream& InFile)
{
	int draw_color, fill;
	if (InFile.is_open())
	{
		InFile >> ID;
		InFile >> Center.x >> Center.y;
		InFile >> draw_color >> fill;
		if (fill == -1)
			FigGfxInfo.isFilled = false;
		else
			ChngFillClr(TranslateToColor(fill));
		ChngDrawClr(TranslateToColor(draw_color));
	}
}
void CSquare::cancelFigure()
{
	Center.x = undoc.x;
	Center.y = undoc.y;
}
void CSquare::Redotransition()
{
	Center.x = redoc.x;
	Center.y = redoc.y;
}
