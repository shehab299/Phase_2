#include "Load.h"

#include "..\ApplicationManager.h"

#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"


#include <fstream>

#include "../GUI/Input.h"
#include "../GUI/Output.h"

Load::Load(ApplicationManager* pApp) : Action(pApp)
{}

void Load::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("input the file name ");
	file_name = pIn->GetSrting(pOut) + ".txt";
}


void Load::Execute()
{
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	
	fstream file(file_name , ios::in);

	if (!file) {
		pOut->PrintMessage("Something Wrong Happened! Please try again");
		return;
	}

	int draw_color, fill_color, n_figures;
	
	Point p; 
	p.x = 0;
	p.y = 0;

	GfxInfo gfx;
	gfx.BorderWdth = 0;
	gfx.isFilled = false;
	gfx.DrawClr = BLUE;
	gfx.FillClr = BLUE;


	file >> n_figures;
	file >> draw_color >> fill_color;
	int type;

	for (int i = 0; i < n_figures; i++)
	{
		file >> type;

		CFigure* figptr;

		switch (type)
		{
		case RECTANGLE: figptr = new CRectangle(p, p, gfx); break;
		case TRIANGLE: figptr = new CTriangle(p, p, p, gfx); break;
		case SQUARE: figptr = new CSquare(p, gfx); break;
		case HEXAGON:	figptr = new CHexagon(p, gfx); break;
		case CIRCLE: figptr = new CCircle(p, p, gfx); break;
		default:
			char* text = "";
			file.getline(text, INT_MAX, '\n');
		}

		if (figptr) 
		{
			figptr-> Load(file);
			pManager -> AddFigure(figptr);
		}

	}
	file.close();

		
}


void Load::undo()
{}

void Load::redo()
{}
