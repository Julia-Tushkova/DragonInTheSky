#pragma once
#include "Image.h"
#include "Text.h"
#include "Timer.h"
#include "Heart.h"
#include <fstream>
#include <sstream>
#include <windows.h>


//размер окна
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

bool init();

bool loadMedia();

void close();

struct hero_
{
	std::string name_hero;
	int timer_hero;
	int head_hero;
};

struct array_hero
{
	Image hero[16];
	SDL_Rect my_hero[16];
};

Text gTextTexture;
Image picture, background, vilage, vilage_dark, dragon, fire_ball, gameOver, youWin, Top, begin, sel;
SDL_Rect image_heart_dragon[3], image_heart_town[3];
Heart hearts_dragon, hearts_town;
std::ofstream out;
std::ifstream in("top.txt");
char symbol[3];
std::string name;

SDL_Renderer* gRenderer = NULL;
TTF_Font* gFont = NULL, * stone_font = NULL, * sel_per = NULL;
SDL_Window* gWindow = NULL;

array_hero my_heros = {};


bool init()
{
	bool success = true;

	if (!in.is_open())
	{
		success = false;
		std::cout << "Файл не открыт" << std::endl;
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	gFont = TTF_OpenFont("Pixel.ttf", 28);//название файла и размер текста
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else 
	{
		stone_font = TTF_OpenFont("Pixel.ttf", 25);//название файла и размер текста
		if (stone_font == NULL)
		{
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
			success = false;
		}
		sel_per = TTF_OpenFont("Pixel.ttf", 20);//название файла и размер текста
		if (sel_per == NULL)
		{
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
			success = false;
		}
		else
		{
			//рендеринг текста
			SDL_Color textColor = { 255, 255, 0 };
			if (!gTextTexture.loadFromRenderedText(" ", textColor, gFont))
			{
				printf("Failed to render text texture!\n");
				success = false;
			}
		}
	}
	//загрузка картинок
	if (!picture.loadFromFile("town.jpg"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!background.loadFromFile("puc.jpg"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!vilage.loadFromFile("vilage.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!vilage_dark.loadFromFile("vilage_dark.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	
	if (!dragon.loadFromFile("dragon.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!fire_ball.loadFromFile("fire_ball.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!hearts_dragon.loadFromFile("hearts_dragon.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		image_heart_dragon[0].x = 314;
		image_heart_dragon[0].y = 0;
		image_heart_dragon[0].w = 156;
		image_heart_dragon[0].h = 47;

		image_heart_dragon[1].x = 157;
		image_heart_dragon[1].y = 0;
		image_heart_dragon[1].w = 156;
		image_heart_dragon[1].h = 47;

		image_heart_dragon[2].x = 0;
		image_heart_dragon[2].y = 0;
		image_heart_dragon[2].w = 156;
		image_heart_dragon[2].h = 47;
	}
	if (!hearts_town.loadFromFile("hearts_town.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		image_heart_town[0].x = 314;
		image_heart_town[0].y = 0;
		image_heart_town[0].w = 156;
		image_heart_town[0].h = 47;

		image_heart_town[1].x = 157;
		image_heart_town[1].y = 0;
		image_heart_town[1].w = 156;
		image_heart_town[1].h = 47;

		image_heart_town[2].x = 0;
		image_heart_town[2].y = 0;
		image_heart_town[2].w = 156;
		image_heart_town[2].h = 47;
	}
	if (!gameOver.loadFromFile("game_over.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!youWin.loadFromFile("you_win.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!Top.loadFromFile("top.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!begin.loadFromFile("dits.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!my_heros.hero[0].loadFromFile("1.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[0] = { 0,0,65*3,120*3 };
	}
	if (!my_heros.hero[1].loadFromFile("2.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[1] = { 0,0,100,150 };
	}
	if (!my_heros.hero[2].loadFromFile("3.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[2] = { 0,0,100,150 };
	}
	if (!my_heros.hero[3].loadFromFile("4.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[3] = { 0,0,33,28 };
	}
	if (!my_heros.hero[4].loadFromFile("5.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[4] = { 0,0,75*3,120*3 };
	}
	if (!my_heros.hero[5].loadFromFile("6.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[5] = { 0,0,100,150 };
	}
	if (!my_heros.hero[6].loadFromFile("7.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[6] = { 0,0,100,150 };
	}
	if (!my_heros.hero[7].loadFromFile("8.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[7] = { 0,0,35,28 };
	}
	if (!my_heros.hero[8].loadFromFile("9.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[8] = { 0,0,75*3,115*3 };
	}
	if (!my_heros.hero[9].loadFromFile("10.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[9] = { 0,0,100,150 };
	}
	if (!my_heros.hero[10].loadFromFile("11.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[10] = { 0,0,100,150 };
	}
	if (!my_heros.hero[11].loadFromFile("12.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[11] = { 0,0,30,25 };
	}
	if (!my_heros.hero[12].loadFromFile("13.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[12] = { 0,0,75*3,125*3 };
	}
	if (!my_heros.hero[13].loadFromFile("14.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[13] = { 0,0,100,150 };
	}
	if (!my_heros.hero[14].loadFromFile("15.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[14] = { 0,0,100,150 };
	}
	if (!my_heros.hero[15].loadFromFile("16.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		my_heros.my_hero[15] = { 0,0,38,30 };
	}
	if (!sel.loadFromFile("selector_player.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}

	return success;
}

void close()
{
	gTextTexture.free();

	TTF_CloseFont(gFont);
	gFont = NULL;
	TTF_CloseFont(stone_font);
	stone_font = NULL;
	TTF_CloseFont(sel_per);
	sel_per = NULL;
	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}