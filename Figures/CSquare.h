#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	int length ;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	int Setlength(int l);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong(Point p)const;
	virtual void Displacment(Point p); //dicplace the coordinates of the figure

};

#endif