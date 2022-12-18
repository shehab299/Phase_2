#include "Output.h"


Output::Output()
{

	UI.InterfaceMode = MODE_DRAW;
	UI.Additional_Items_Mode = NOTHING;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.Yi_icon = UI.height - UI.StatusBarHeight;
	UI.Yi_msg = UI.height - UI.StatusBarHeight + 10;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 40;
	UI.MenuItemHeight = UI.ToolBarHeight - 15;
	UI.AdditionalMenuItemHeight = 30;
	UI.AdditionalItemsHeight = 32;

	
	UI.ToolBarColor = WHITE;
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = CORNFLOWERBLUE;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = ANTIQUEWHITE;	//Background color
	UI.HighlightColor = DARKBLUE;
	UI.StatusBarColor = BRIGHTPURPLE;
	UI.PenWidth = 4;	//width of the figures frames

	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	pWind->ChangeTitle("Paint for Kids");

	//DrawIcons
	MenuItemImages[ITM_SAVE] = PATH_ICONS_DRAW + "saved.jpg";
	MenuItemImages[ITM_LOAD] = PATH_ICONS_DRAW + "load.jpg";
	MenuItemImages[ITM_UNDO] = PATH_ICONS_DRAW + "undo.jpg";
	MenuItemImages[ITM_REDO] = PATH_ICONS_DRAW + "redo.jpg";
	MenuItemImages[ITM_RECORD] = PATH_ICONS_DRAW + "record.jpg";
	MenuItemImages[ITM_STOP] = PATH_ICONS_DRAW + "stop.jpg";
	MenuItemImages[ITM_PLAY] = PATH_ICONS_DRAW + "play.jpg";
	MenuItemImages[ITM_AUDIO] = PATH_ICONS_DRAW + "audio.jpg";
	MenuItemImages[ITM_ADD] = PATH_ICONS_DRAW + "shapes.jpg";
	MenuItemImages[ITM_SELECT] = PATH_ICONS_DRAW + "select.jpg";
	MenuItemImages[ITM_DELETE] = PATH_ICONS_DRAW + "delete.jpg";
	MenuItemImages[ITM_CLEARALL] = PATH_ICONS_DRAW + "clearall.jpg";
	MenuItemImages[ITM_FILL] = PATH_ICONS_DRAW + "fill.jpg";
	MenuItemImages[ITM_COLOR] = PATH_ICONS_DRAW + "color.jpg";
	MenuItemImages[ITM_MOVE] = PATH_ICONS_DRAW + "move.jpg";
	MenuItemImages[ITM_DRAG] = PATH_ICONS_DRAW + "drag.jpg";
	MenuItemImages[ITM_RESIZE] = PATH_ICONS_DRAW + "enlarge.jpg";
	MenuItemImages[ITM_PLAY_MODE] = PATH_ICONS_DRAW + "playMode.jpg";
	MenuItemImages[ITM_EXIT] = PATH_ICONS_DRAW + "exit.jpg";

	//colors
	ColorsItems[RED_] = COLORS_PATH + "red.jpg";
	ColorsItems[BLACK_] = COLORS_PATH + "black.jpg";
	ColorsItems[YELLOW_] = COLORS_PATH + "yellow.jpg";
	ColorsItems[BLUE_] = COLORS_PATH + "blue.jpg";
	ColorsItems[ORANGE_] = COLORS_PATH + "orange.jpg";
	ColorsItems[GREEN_] = COLORS_PATH + "green.jpg";

	//shapes
	ShapesItems[RECTANGLE] = SHAPES_PATH + "rectangle.jpg";
	ShapesItems[CIRCLE] = SHAPES_PATH + "circle.jpg";
	ShapesItems[HEXAGON] = SHAPES_PATH + "hexagon.jpg";
	ShapesItems[SQUARE] = SHAPES_PATH + "square.jpg";
	ShapesItems[TRIANGLE] = SHAPES_PATH + "triangle.jpg";

	//play icons
	PlayMenuItems[PLAY_COLOR] = PATH_ICONS_PLAY + "bycolor.jpg";
	PlayMenuItems[PLAY_SHAPE] = PATH_ICONS_PLAY + "byshape.jpg";
	PlayMenuItems[PLAY_COLORNSHAPE] = PATH_ICONS_PLAY + "bycolornshape.jpg";
	PlayMenuItems[PLAY_DRAW_MODE] = PATH_ICONS_PLAY + "draw.jpg";
	PlayMenuItems[PLAY_EXIT] = PATH_ICONS_DRAW + "exit.jpg";


	CreateDrawToolBar();
	CreateAdditionalItemsBar(UI.Additional_Items_Mode);
	CreateStatusBar();
}

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}


window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}


void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	pWind->DrawImage(notify_path, 5, UI.Yi_icon, 35, 35);
}

void Output::ClearStatusBar() const
{
	CreateStatusBar();
}


void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	for (int i = 0; i < DRAW_ITM_COUNT; i++) 
	{
		pWind->DrawImage(MenuItemImages[i], i * (UI.MenuItemWidth + 5), 10, UI.MenuItemWidth, UI.MenuItemHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}


void Output::CreateAdditionalItemsBar(ADDIONAL_MODE mode) const
{
	UI.Additional_Items_Mode = mode;
	//draw the Bar
	color fill_color = UI.ToolBarColor;
	color draw_color = UI.DrawColor;

	pWind->SetPen(draw_color, 1);
	pWind->SetBrush(fill_color);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 1, UI.width, UI.ToolBarHeight + 1 + UI.AdditionalItemsHeight);

	//check the mode and show the suitable icons
	if (mode == COLORS)
	{
		for (int i = 0; i < COLORS_COUNT; i++)
		{
			pWind->DrawImage(ColorsItems[i], i * (UI.MenuItemWidth + 5), UI.ToolBarHeight + 2, UI.MenuItemWidth, UI.AdditionalMenuItemHeight);
		}
	}
	else if (mode == SHAPES)
	{
		for (int i = 0; i < SHAPES_COUNT; i++)
		{
			pWind->DrawImage(ShapesItems[i], i * (UI.MenuItemWidth + 5), UI.ToolBarHeight + 2, UI.MenuItemWidth, UI.AdditionalMenuItemHeight);
		}
	}
}


void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;
	CreateAdditionalItemsBar(NOTHING);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.Additional_Items_Mode = NOTHING;

	//Draw menu item one image at a time

	for (int j = 0; j < PLAY_ITM_COUNT; j++)
	{
		pWind->DrawImage(PlayMenuItems[j], j * (UI.MenuItemWidth + 5), 10, UI.MenuItemWidth, UI.MenuItemHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(UI.DrawColor, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}


void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.AdditionalItemsHeight, UI.width, UI.height - UI.StatusBarHeight);

}


void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(50, UI.Yi_msg, msg);
}


color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}



//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTriangle(Point P1, Point P2,Point p3, GfxInfo triGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = triGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (triGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(triGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,p3.x,p3.y, style);

}

void Output::DrawSqr(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int side = 120;
	Point P2;
	Point P3;
	P2.x = P1.x - (side / 2);
	P2.y = P1.y + (side / 2);
	P3.x = P1.x + (side / 2);
	P3.y = P1.y - (side / 2);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCrcl(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	int deltX = pow((P1.x - P2.x), 2);
	int deltY = pow((P1.y - P2.y), 2);
	int r = sqrt(deltX + deltY);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, r, style);
}



void Output::CalcHxgVer(Point Pc, int XVer[], int YVer[], int NumVer, int side) const
{
	for (int i = 0; i < NumVer; i++)
	{
		//calculate the x coordinates of the vertices
		if (i == 0 || i == 2)
			XVer[i] = Pc.x + (0.5 * side);
		else if (i == 3 || i == 5)
			XVer[i] = Pc.x - (0.5 * side);
		else if (i == 1)
			XVer[i] = Pc.x + side;
		else
			XVer[i] = Pc.x - side;


		//calculate the y coordinates of the vertices
		if (i == 0 || i == 5)
			YVer[i] = Pc.y - (0.866025 * side);
		else if (i == 3 || i == 2)
			YVer[i] = Pc.y + (0.866025 * side);
		else
			YVer[i] = Pc.y;

	}

}


void Output::DrawHxg(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int side = 120;
	const int VerNum = 6;
	int VerX[VerNum];
	int VerY[VerNum];
	CalcHxgVer(P1, VerX, VerY, VerNum, side); //calculate the vertices of hexagon
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(VerX, VerY, VerNum, style);
}



Output::~Output()
{
	delete pWind;
}

