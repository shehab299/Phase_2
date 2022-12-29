#include "MoveByDragging.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Move.h"

MoveByDragging::MoveByDragging(ApplicationManager* pApp):Action(pApp)
{
}

void MoveByDragging::ReadActionParameters()
{
	Point pc;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 
	pOut->PrintMessage("Move By Dragging Action:Please drag the selected figure");
	while (pIn->GetPointDragged(pc.x,pc.y)== BUTTON_UP)
	{
		while (pIn->GetPointDragged(pc.x, pc.y) == BUTTON_DOWN)
		{

			pManager->GetSelectedFig()->Displacment(pc);
			pManager->UpdateInterface();
		}
	}
		//while (buttonstate==BUTTON_DOWN) 
	//{

	//}
	pOut->ClearStatusBar();
}

void MoveByDragging::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig()->IsSelected())
	{
		ReadActionParameters();
		pManager->GetSelectedFig()->Displacment(p);
	}
	else
		pOut->PrintMessage("Please select a figure first");

}