#pragma once
#include "MyTexture.h"

class Image:public MyTexture
{
public:
	void render(int x, int y, SDL_Rect* clip = NULL);
};