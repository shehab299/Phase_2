#include "CHexagon.h"
#include "CTriangle.h"
CHexagon::CHexagon(Point cntr, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = cntr;
	length=120;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHxg(Center, FigGfxInfo, Selected);
}

void CHexagon::PrintInfo(Output* pOut) const
{
	string part1 = "HEXAGON ID " + to_string(ID) + " ";
	string part2 = "Center ( " + to_string(Center.x) + " , " + to_string(Center.y) + " )";
	string part3 = "side length " + to_string(length);
	pOut->PrintMessage(part1 + part2 + part3);
}


bool CHexagon::IsBelong( Point p) const
{
	int xMirror = abs(p.x - Center.x), yMirror ( abs(p.y - Center.y));
	bool condition = (yMirror >= 0 && yMirror <= ((sqrt(3) / 2.0) * (length)));
	condition = condition && (xMirror >= 0) && (xMirror < ((1.5 * length) - 2 * yMirror / sqrt(3)));
	return condition;
		
}

void CHexagon::Save(ofstream& OutFile) const
{
	string type = to_string(HEXAGON);
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


void CHexagon::Load(fstream& InFile)
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



