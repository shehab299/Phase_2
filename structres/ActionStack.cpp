#include "ActionStack.h"



ActionStack::ActionStack() 
{
	MAX_SIZE = 5;
	array = new Action*[MAX_SIZE];
	current_size = 0;
}

void ActionStack::push(Action* pAct)
{
	if (current_size < 5)
		array[current_size++] = pAct;
	else
	{
		for (int i = 0; i < MAX_SIZE - 2; i++)
		{
			array[i] = array[i + 1];
		}
		array[current_size - 1] = pAct;
	}
}

Action* ActionStack::pop()
{
	if (current_size > 0)
	{
		return array[(current_size---1)];
	}
	else
		return nullptr;
}



bool ActionStack::is_empty()
{
	return (current_size == 0);
}



