#pragma once

#include "../Actions/Action.h"

class ActionStack
{
public:

	ActionStack();
	void push(Action*);
	Action* pop();


	bool is_empty();

private:
	Action** array;
	int current_size;
	int MAX_SIZE;


};