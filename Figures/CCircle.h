#ifndef CCRCL_H
#define CCRCL_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point RadiusP;
	int r;
public:
	CCircle(Point, Point, GfxInfo FigGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong( Point p) const;	//ch+eck whether point is on fig
	virtual void Displacment(Point p) ; //dicplace the coordinates of the figure
	virtual void Resize(Point p); //resize the figure
	virtual string GetFigureType() const;
};

#endif
