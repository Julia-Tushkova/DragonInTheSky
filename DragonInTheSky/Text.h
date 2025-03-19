#pragma once
#include "MyTexture.h"

class Text : public MyTexture
{
public:
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* gFont);
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};