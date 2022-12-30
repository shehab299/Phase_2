#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	Point undoc;
	Point redoc;
	int length ;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong(Point p)const;
	virtual void MoveFigure(Point p);
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(fstream& InFile);
	virtual void cancelFigure();
	virtual void Redotransition();
};

#endif
