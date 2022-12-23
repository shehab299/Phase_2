#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE // Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum COLORS // colors of the colors Menu
{
	RED_,
	BLUE_,
	YELLOW_,
	ORANGE_,
	GREEN_,
	BLACK_,
	COLORS_COUNT,
	UNDEFINED
};

enum SHAPES // shapes in the shapes Menu
{
	RECTANGLE,
	CIRCLE,
	HEXAGON,
	SQUARE,
	TRIANGLE,
	SHAPES_COUNT
};

enum ADDIONAL_MODE // modes for the additional items menu 
{
	NOTHING_MODE,
	COLORS_MODE,
	SHAPES_MODE
};

enum DrawMenuItem // The items of the Draw menu 
{
	ITM_SAVE,
	ITM_LOAD,
	ITM_UNDO,
	ITM_REDO,
	ITM_RECORD,
	ITM_STOP,
	ITM_PLAY,
	ITM_AUDIO,
	ITM_ADD,
	ITM_SELECT,
	ITM_DELETE,
	ITM_CLEARALL,
	ITM_FILL,
	ITM_COLOR,
	ITM_MOVE,
	ITM_DRAG,
	ITM_RESIZE,
	ITM_PLAY_MODE,
	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items 
};

enum PlayMenuItem // The items of the Play menu 
{
	PLAY_COLOR,
	PLAY_SHAPE,
	PLAY_COLORNSHAPE,
	PLAY_DRAW_MODE,
	PLAY_EXIT,
	PLAY_ITM_COUNT		//no. of menu items 
};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth,		//Width of each item in toolbar menu
		Additional_Items_Height,
		MenuItemHeight,
		AdditionalMenuItemHeight,		//Width of each item in toolbar menu
		AdditionalItemsHeight , Yi_icon , Yi_msg;


	ADDIONAL_MODE Additional_Items_Mode;
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif
