#ifndef CCRCL_H
#define CCRCL_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point RadiusP;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif