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
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong(Point p)const;
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(fstream& InFile);
};

#endif