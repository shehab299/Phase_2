#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window

	string MenuItemImages[DRAW_ITM_COUNT];
	string ColorsItems[COLORS_COUNT];
	string ShapesItems[SHAPES_COUNT];
	string PlayMenuItems[PLAY_ITM_COUNT];

	//path for draw icons
	const string PATH_ICONS_DRAW = "images\\DrawMenuItems\\1\\";
	//paths for colors and shapes
	const string COLORS_PATH = "images\\Colors\\";
	const string SHAPES_PATH = "images\\Shapes\\";
	//path for play icons
	const string PATH_ICONS_PLAY = "images\\PlayMenuItems\\";
	//status bar icon
	const string notify_path = "images//notifications//message2.jpg";



public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreateAdditionalItemsBar(ADDIONAL_MODE) const; // creates Additonal Items  menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawTriangle(Point p1, Point p2, Point p3, GfxInfo triGfxInfo, bool selected = false) const;//Draw triangle
	void DrawSqr(Point P1, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a square with a default side =80
	void DrawCrcl(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a circle
	void DrawHxg(Point P1, GfxInfo RectGfxInfo, bool selected = false) const;	//Draw a hexagon with a default side =120
	void CalcHxgVer(Point Pc, int XVer[], int YVer[], int NumVer, int side) const; // calcuate the X & Y coordinates of hexagon vertices 

	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setCrntFillColor(color c) const;	//set current filling color
	void setCrntDrawColor(color c) const;	//set current drawing color
	void setIsfilled(bool b);
	
	~Output();
};

#endif
