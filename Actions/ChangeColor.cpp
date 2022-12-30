#pragma once
#include "ChangeColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeColor::ChangeColor(ApplicationManager* pApp) : Action(pApp)
{
}
void ChangeColor::ReadActionParameters()
{
	Input* ffu = pManager->GetInput();// to get the color from the user
	Output* ftu = pManager->GetOutput();
	ftu->CreateAdditionalItemsBar(COLORS_MODE);
	ftu->PrintMessage("Pick up a Color from (black-yellow-red-green-blue-orange)");
	NewColor = ffu->GetUserAction();
	ftu->ClearStatusBar();
}
void ChangeColor::Execute()
{
	ReadActionParameters();
	switch (NewColor)
	{
	case black:
		UI.DrawColor = BLACK;
		UI.FillColor = BLACK;
		break;
	case yellow:
		UI.DrawColor = YELLOW;
		UI.FillColor = YELLOW;
		break;
	case red :
		UI.DrawColor = RED;
		UI.FillColor = RED;
		break;
	case green:
		UI.DrawColor = GREEN;
		UI.FillColor = GREEN;
		break;
	case blue:
		UI.DrawColor = BLUE;
		UI.FillColor = BLUE;
		break;
	case orange:
		UI.DrawColor = ORANGE;
		UI.FillColor = ORANGE;
		break;
	}
	pManager->changingDrawColors();
}

void ChangeColor::undo()
{
}

void ChangeColor::redo()
{
}
