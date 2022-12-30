#include "CRectangle.h"
#include <cmath>
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

bool CRectangle::IsBelong(Point p) const
{
	int Xmin = (Corner1.x < Corner2.x) ? Corner1.x : Corner2.x;
	int Xmax = (Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Ymin = (Corner1.y < Corner2.y) ? Corner1.y : Corner2.y;
	int Ymax = (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	return (p.x > Xmin && p.x<Xmax&& p.y>Ymin && p.y < Ymax);
}
void CRectangle::MoveFigure(Point p)
{
	undoCorn1.x = Corner1.x;//Setters for the undo 
	undoCorn1.y = Corner1.y;
	undoCorn2.x = Corner2.x;
	undoCorn2.y = Corner2.y;

	
	int Width = abs(Corner1.x-Corner2.x);
	int Length = abs(Corner1.y-Corner2.y); 

	redoCorn1.x= p.x - (Width / 2); //Setters for the redo
	redoCorn1.y = p.y -(Length/ 2);
	redoCorn2.x = p.x + (Width / 2);
	redoCorn2.y = p.y + (Length / 2);

	Corner1.x = p.x - (Width / 2);
	Corner2.x = p.x + (Width / 2);
	Corner1.y = p.y - (Length / 2);
	Corner2.y = p.y + (Length / 2);
}
void CRectangle::cancelFigure()
{
	Corner1.x = undoCorn1.x;
	Corner2.x = undoCorn2.x;
	Corner1.y = undoCorn1.y;
	Corner2.y = undoCorn2.y;
}
void CRectangle::Redotransition()
{
	Corner1.x = redoCorn1.x;
	Corner2.x = redoCorn2.x;
	Corner1.y = redoCorn1.y;
	Corner2.y = redoCorn2.y;
}

void CRectangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("RECTANGLE ID   " + to_string(ID) + "   " + to_string(Corner1.x) + "   " + to_string(Corner1.y) + "   " + to_string(Corner2.x) + "   " + to_string(Corner2.y));
}



void CRectangle::Save(ofstream& OutFile) const
{
	string type = to_string(RECTANGLE);
	string id = to_string(ID);
	int draw_color = TranslateToInt(FigGfxInfo.DrawClr);
	int fill = (FigGfxInfo.isFilled) ? TranslateToInt(FigGfxInfo.FillClr) : -1;
	if(OutFile.is_open())
	{
		OutFile << setw(1) << type << " ";
		OutFile << setw(3) << id << " ";
		OutFile << setw(3) << Corner1.x << " ";
		OutFile << setw(3) << Corner1.y << " ";
		OutFile << setw(3) << Corner2.x << " ";
		OutFile << setw(3) << Corner2.y << " ";
		OutFile << setw(3) << draw_color << " ";
		OutFile << setw(3) << fill;
		OutFile << "\n";
	}

}

void CRectangle::Load(fstream& InFile)
{
	int draw_color, fill;
	if (InFile.is_open())
	{
		InFile >> ID;
		InFile >> Corner1.x >> Corner1.y;
		InFile >> Corner2.x >> Corner2.y;
		InFile >> draw_color >> fill;
		
		if (fill == -1)
			FigGfxInfo.isFilled = false;
		else
			ChngFillClr(TranslateToColor(fill));

		ChngDrawClr(TranslateToColor(draw_color));
	}
}


