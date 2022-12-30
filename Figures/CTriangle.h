#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point Center;
	Point undoCr1;
	Point undoCr2;
	Point undoCr3;
	Point undoCen;
	Point redoCr1;
	Point redoCr2;
	Point redoCr3;
	Point redoCen;



	float CalcArea(Point p1, Point p2, Point p3) const;


public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong(Point p) const;
	virtual void MoveFigure(Point p);
	virtual void cancelFigure();
	//void SetCenter();
	virtual void Redotransition();
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(fstream& InFile);
};

#endif
