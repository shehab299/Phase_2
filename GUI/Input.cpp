#include "Input.h"
#include "Output.h"
#include <iostream>

Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind-> WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind-> WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage("You entered " + Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		
		
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			int ClickedItemOrder = (x / (UI.MenuItemWidth+5));

			//int boundary_item = (ClickedItemOrder+1) * UI.MenuItemWidth;
			//int boundary_empty = boundary_item + 5;

			//if(x >= boundary_item && x <= boundary_empty)
			//	return EMPTY;	
			//else
			//{
				switch (ClickedItemOrder)
				{
					case ITM_SAVE : return SAVE;
					case ITM_LOAD : return LOAD;
					case ITM_UNDO: return UNDO;
					case ITM_REDO : return REDO;
					case ITM_RECORD: return RECORD;
					case ITM_STOP: return STOP;
					case ITM_PLAY:  return  PLAY;
					case ITM_AUDIO: return AUDIO;
					case ITM_ADD:   return ADD;
					case ITM_SELECT :  return SELECT;
					case ITM_DELETE: return DLTE;
					case ITM_CLEARALL: return CLR;
					case ITM_FILL:   return FILL;
					case ITM_COLOR:  return DCOLOR;
					case ITM_MOVE:   return MOVE; 
					case ITM_DRAG: return DRAG;
					case ITM_RESIZE: return RESIZE;
					case ITM_PLAY_MODE: return TO_PLAY; 
					case ITM_EXIT: return EXIT;						 					//A click on empty place in desgin toolbar
				}
		//	}
		}


		//If USER clickes on additional items menu
		int UpperBound = UI.ToolBarHeight + UI.AdditionalItemsHeight + 2;
		int LowerBound = UI.ToolBarHeight + 1;
		if(y >= LowerBound && y <= UpperBound)
		{
			if(UI.Additional_Items_Mode==NOTHING_MODE)
				return DRAWING_AREA;
			else
			{
				int ClickedItemOrder = (x / (UI.MenuItemWidth + 5));

				//int boundary_item = (ClickedItemOrder + 1) * UI.MenuItemWidth;
				//int boundary_empty = boundary_item + 5;

				//if (x > boundary_item && x < boundary_empty)
				//	return EMPTY;


				if (UI.Additional_Items_Mode == COLORS_MODE)
				{
					switch (ClickedItemOrder)
					{
					case BLACK_: return black;
					case YELLOW_:return yellow;
					case ORANGE_:return orange;
					case RED_: return red;
					case GREEN_: return green;
					case BLUE_: return blue;
					default: return EMPTY;
					}

				}
				else
				{
					switch (ClickedItemOrder)
					{
						case RECTANGLE: return rectangle;
						case CIRCLE :return circle;
						case HEXAGON : return hexagon;
						case SQUARE  : return square;
						case TRIANGLE: return triangle;   
						default: return EMPTY;
					}		
			
				}	
			
			}		
		
		
		}

		//User Clicks on Drawing Area
		else if ( y >= UI.ToolBarHeight + UI.AdditionalItemsHeight + 4 && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//Status Menu
		else if(y >= UI.height - UI.StatusBarHeight && y <= UI.height)
			return STATUS;
	}
	
	else if(UI.InterfaceMode == MODE_PLAY)
	{

		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
				case PLAY_COLOR:return PCOLOR;
				case PLAY_SHAPE: return PSHAPE;
				case PLAY_COLORNSHAPE : return PCOLORNSHAPE;
				case PLAY_DRAW_MODE: return TO_DRAW;
				case PLAY_EXIT: return EXT_PLAY;

			}		
		}			//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}		

		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
