#include "MyTexture.h"

MyTexture::MyTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

MyTexture::~MyTexture()
{
	free();
}

bool MyTexture::loadFromFile(std::string path)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}


	mTexture = newTexture;
	return mTexture != NULL;
}

void MyTexture::free()
{

	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void MyTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{

	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void MyTexture::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(mTexture, blending);
}

void MyTexture::setAlpha(Uint8 alpha)
{

	SDL_SetTextureAlphaMod(mTexture, alpha);
}


int MyTexture::getWidth()
{
	return mWidth;
}

int MyTexture::getHeight()
{
	return mHeight;
}