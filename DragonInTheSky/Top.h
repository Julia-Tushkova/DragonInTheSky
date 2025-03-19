#pragma once
#include "Initialization.h"

//перевод из милисекунд во врем€ string
std::string int_to_time(int a)
{
	std::string path;
	int b;
	a = a / 1000; //перевод в секунды
	b = a / 60;//перевод в минуты
	char str[80];
	sprintf_s(str, "%d%c%d", b, ':', (a - b * 60));
	path = std::string(str);
	return path;
}

//вывод рейтинга
void top(hero_ *a)
{
	bool end = false;
	SDL_Event e;
	SDL_Rect cur;
	int h = 400;
	while (!end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_RETURN:
				{
					end = true;
					break;
				}
				}
			}
		}
		cur = { 0, 0, 1600, 900 };
		Top.render(190, 105, &cur);
		gTextTexture.loadFromRenderedText("Ќажмите Enter дл€ продолжени€...", { 255,255,255 }, gFont);
		gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 800);
		for (int i = 0; i < 10; i++)
		{
			if (a[i].name_hero != "name")
			{
				name = int_to_time(a[i].timer_hero) + "  " + a[i].name_hero;
				gTextTexture.loadFromRenderedText(name, { 126,125,109 }, stone_font);
				gTextTexture.render(920, 350+i*30);
				my_heros.hero[a[i].head_hero * 4 + 3].render(1040, 350 + i * 30, &my_heros.my_hero[a[i].head_hero * 4 + 3]);
			}
		}
		SDL_RenderPresent(gRenderer);
	}
}