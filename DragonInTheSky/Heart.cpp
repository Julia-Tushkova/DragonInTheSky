#include "Heart.h"
int Heart::break_heart()
{
	counter_heart--;
	return counter_heart;
}

int Heart::get_counter()
{
	return counter_heart;
}

Heart::Heart() : Image()
{
	counter_heart = 3;
}
void Heart::heart_repear()
{
	counter_heart = 3;
}