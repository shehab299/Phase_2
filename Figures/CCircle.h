#ifndef CCRCL_H
#define CCRCL_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point RadiusP;
	Point undoc;
	Point redoc;
	Point undor;
	Point redor;

public:
	CCircle(Point, Point, GfxInfo FigGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong( Point p) const;	//check whether point is on fig
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(fstream& InFile);
	virtual void MoveFigure(Point p); //transfer circle to the new position
	virtual void cancelFigure();  //undo the movement
	virtual void Redotransition(); //return the movement
};

#endif
