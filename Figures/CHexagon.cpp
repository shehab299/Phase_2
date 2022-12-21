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


bool CHexagon::IsBelong(Output* pOut, Point p) const
{
	int xMirror = abs(p.x - Center.x);
	int yMirror = abs(p.y - Center.y);
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


