#include "CHexagon.h"
#include "CTriangle.h"
CHexagon::CHexagon(Point cntr, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = cntr;
	length=90;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHxg(Center,length, FigGfxInfo, Selected);
}

void CHexagon::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("HEXAGON ID   " + to_string(ID) + "    Center(" + to_string(Center.x) + "  ,  " + to_string(Center.y) + ")   side length   " + to_string(length));

}


bool CHexagon::IsBelong( Point p) const
{
	int xMirror = abs(p.x - Center.x), yMirror ( abs(p.y - Center.y));
	bool yBnd((yMirror >= 0) && yMirror <= ((sqrt(3) / 2.0) * (length))),
		XBnd((xMirror >= 0) && (xMirror < ((1.5 * length) - 2 * yMirror / sqrt(3))));
	return ( yBnd && XBnd );	
}

void CHexagon::Displacment(Point p)
{
	Center.x = p.x;
	Center.y = p.y;
}

void CHexagon::Resize(Point p)
{
	length = dist(p, Center);
}

string CHexagon::GetFigureType() const
{
	return "Hexagon";
}


