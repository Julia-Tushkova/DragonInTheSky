#pragma once
#include "Image.h"
class Heart :public Image
{
	int counter_heart;
public:
	Heart();
	int get_counter();
	int break_heart();
	void heart_repear();
};