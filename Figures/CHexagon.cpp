#include "CHexagon.h"

CHexagon::CHexagon(Point cntr, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = cntr;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHxg(Center, FigGfxInfo, Selected);
}
