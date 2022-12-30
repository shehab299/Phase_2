#include "Select.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pApp) : Action(pApp)
{}

void Select::ReadActionParameters() 
{
	Point Pc;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool flag = true;
	pOut->PrintMessage("Select Action:Please Click at a point on the drawing area");

	do {
		pIn->GetPointClicked(Pc.x, Pc.y);
		if (Pc.y > (UI.AdditionalItemsHeight + UI.ToolBarHeight) && Pc.y < (UI.height - UI.StatusBarHeight))
		{
			p.x = Pc.x;
			p.y = Pc.y;
			flag = false;
		}
		else
			pOut->PrintMessage("Please Click at a point on the drawing area");
	} while (flag);
	pOut->ClearStatusBar();
}

void Select::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure* fig=pManager->GetFigure(p.x,p.y);
	if (fig != NULL)
	{
		if (!(fig->IsSelected()))
		{

			if (pManager->GetSelectedFig() != NULL)
			{
				((pManager->GetSelectedFig())->SetSelected(false));
				pManager->SetSelectedFig(NULL);
			}
			pManager->SetSelectedFig(fig);
			fig->SetSelected(true);
			fig->PrintInfo(pOut);
		}
		else
		{

			fig->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		}
	}
	else
		pOut->PrintMessage("Please click inside or on the borders of any figure");
}

void Select::undo()
{}

void Select::redo()
{}
