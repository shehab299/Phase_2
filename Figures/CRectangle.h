#ifndef CRECT_H
#define CRECT_H


#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point undoCorn1;
	Point redoCorn1;
	Point undoCorn2;
	Point redoCorn2;
public:

	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual bool IsBelong( Point p) const;	//check whether point is on fig
	virtual void Save(ofstream& OutFile) const;
	virtual void MoveFigure(Point p);
	virtual void Load(fstream& InFile);
	virtual void cancelFigure();
	virtual void Redotransition();
	
};

#endif
