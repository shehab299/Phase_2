#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SAVE,
	LOAD,
	UNDO,
	REDO,
	RECORD,
	STOP,
	PLAY,
	AUDIO,
	ADD,
	SELECT,
	DLTE,
	CLR,
	FILL,
	DCOLOR,
	MOVE,
	DRAG,
	RESIZE,
	COUNT,
	EXIT,	
	PCOLOR,
	PSHAPE,
	PCOLORNSHAPE,
	black,
	yellow,
	red,
	green,
	blue,
	orange,
	rectangle,
	circle,
	hexagon,
	square,
	triangle,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	EXT_PLAY,
	STATUS	//A click on the status bar
	
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif
