#pragma once
#include "c:\users\dell\downloads\phase2 - code f22\phase2 - code f22\figures\cfigure.h"
class CTriangle :
	public CFigure
{
private:
	Point TCorner1; //the three corners needed for truangle shape
	Point TCorner2;
	Point TCorner3;
public:

	CTriangle(Point p1,Point p2,Point p3,GfxInfo FigureGfxInfo ); //Triangle Non_Default Constructor
	virtual void Draw(Output* pOut) const;

	~CTriangle(void);
};

