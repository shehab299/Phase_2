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
	pOut->PrintMessage("HEXAGON ID   " + to_string(ID) + "Center(" + to_string(Center.x) + "  ,  " + to_string(Center.y) + ")   side length" + to_string(length));

}


bool CHexagon::IsBelong( Point p) const
{
	int xMirror = abs(p.x - Center.x), yMirror ( abs(p.y - Center.y));
	return (yMirror >= 0 && yMirror <= ((sqrt(3) / 2.0) * (length))) && (xMirror >= 0) && (xMirror < ((1.5 * length) - 2 * yMirror / sqrt(3)));
	/*  
	* Non optimized soluation
	 	int xMirror = abs(p.x - Center.x);
		int yMirror = abs(p.y - Center.y);
		bool xbndrect = ((xMirror <=  0.5 * (length)) && (xMirror >= 0));
		bool ybndrect = ((yMirror <=  (length * sqrt(3) / 2.0)) && (yMirror >= 0));
		bool xbndtri = ((xMirror > (0.5 * length)) && (xMirror <= length));
		bool ybndtri = ((yMirror > 0) && (yMirror <= ((sqrt(3) / 2.0) * (length))));
		if (xbndrect && ybndrect)
		{
			return true;
		}
		if (xbndtri && ybndtri)
		{
			return true;
		}
	return false;
	*/
		
}

void CHexagon::Save(ofstream& OutFile)
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


