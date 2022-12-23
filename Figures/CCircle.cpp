#include "CCircle.h"

CCircle::CCircle(Point cntr, Point p, GfxInfo FigGfxInfo) :CFigure(FigGfxInfo)
{
	Center = cntr;
	RadiusP = p;
}
void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCrcl(Center, RadiusP, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut) const
{
	int radius = sqrt(pow((Center.x - RadiusP.x), 2) + pow((Center.y - RadiusP.y), 2));

	string part1 = "CIRCLE ID " + to_string(ID) + " ";
	string part2 = "Center ( " + to_string(Center.x) + " , " + to_string(Center.y) + " ) ";
	string part3 = "radius : " + to_string(radius);

	string info = part1 + part2 + part3;

	pOut->PrintMessage(info);
}

bool CCircle::IsBelong( Point p) const
{
	//check if the distance between the point and the center less than or equal the radius
	int r = sqrt(pow((Center.x - RadiusP.x), 2) + pow((Center.y - RadiusP.y), 2));
	int d = sqrt(pow((Center.x - p.x), 2) + pow((Center.y - p.y), 2));
	return (d <= r);
}

void CCircle::Save(ofstream& OutFile)
{
	string type = to_string(CIRCLE);
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

