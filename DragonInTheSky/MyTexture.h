#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <locale>
#include <iostream>

extern TTF_Font* gFont;
extern SDL_Renderer* gRenderer;
extern SDL_Window* gWindow;

class MyTexture
{
public:
	MyTexture();

	~MyTexture();

	bool loadFromFile(std::string path);

	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setBlendMode(SDL_BlendMode blending);

	void setAlpha(Uint8 alpha);

	int getWidth();
	int getHeight();

protected:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;

};