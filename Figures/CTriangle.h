#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;

	float CalcArea(Point p1, Point p2, Point p3) const;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong(Point p) const;
	virtual void Save(ofstream& OutFile);
};

#endif