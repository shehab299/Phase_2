#ifndef CHXGN_H
#define CHXGN_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	int length;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong( Point p) const;	//check whether point is on fig
	virtual void Displacment(Point p); //dicplace the coordinates of the figure
	virtual void Resize(Point p); //resize the figure
	virtual string GetFigureType() const;
};

#endif
