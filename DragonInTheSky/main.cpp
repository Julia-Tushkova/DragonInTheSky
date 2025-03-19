#include "Initialization.h"
#include "Play.h"
#include "Top.h"
#include <Windows.h>

//функция сортировки рейтингов
void sort(hero_* a)
{
	hero_ temp;
	for (int i = 9; i >=0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j].timer_hero < a[j + 1].timer_hero)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j].timer_hero > a[j + 1].timer_hero && a[j].name_hero != "name" && a[j + 1].name_hero != "name")
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main(int argc, char* args[])
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	hero_ result[10] = {};//считывать из файла сюда
	for (int i = 0; i < 10; i++)
	{
		in >> result[i].timer_hero;
		in >> result[i].name_hero;
		in >> result[i].head_hero;
	}
	//создание окна
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//загрузка медиа
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//флаг выхода
			bool quit = false;

			SDL_Event e;
			SDL_Color brown = { 0,0,255 }, blue = { 65,25,0 } ;
			int c=0, timer, number;
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);
			SDL_Rect cur = { 0, 0, 1580, 870 };
			begin.render(190, 105, &cur);
			SDL_RenderPresent(gRenderer);
			SDL_Delay(5000);
			//главный цикл
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
						{
							c--;
							if (c == 0) c = 4;
							break;
						}
						case SDLK_DOWN:
						{
							c++;
							if (c == 5||c==0) c = 1;
							break;
						}
						case SDLK_RETURN:
						{
							switch (c)
							{
							case 1:
							{
								//начало игры
								symbol[0] = symbol[1] = symbol[2] = '_';
								number = player_selection();
								timer = play(number);
								if (result[9].timer_hero < timer)
								{
									result[9].timer_hero = timer;
									result[9].name_hero = name;
									result[9].head_hero = number/4;
								}
								hearts_dragon.heart_repear();
								hearts_town.heart_repear();
								break;
							}
							case 2:
							{
								//рейтинг
								sort(result);
								top(result);
								break;
							}
							case 3:
							{
								//правила
									SDL_Rect cur;
									bool quit = false;
									SDL_Event e;
									while (!quit)
									{
										while (SDL_PollEvent(&e) != 0)
										{
											if (e.type == SDL_KEYDOWN)
											{
												switch (e.key.keysym.sym)
												{
												case SDLK_RETURN:
												{
													quit = true;
													break;
												}
												}
											}
										}
										SDL_RenderClear(gRenderer);
										cur = { 0, 0, 1580, 870 };
										background.render(190, 105, &cur);
										gTextTexture.loadFromRenderedText("О нет! На наш славный город Былинноград напал огнедышащий дракон!", {0,0,0}, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 300);
										gTextTexture.loadFromRenderedText("Найдется ли герой(желательно с огнеупорным волшебным щитом) способный", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 350);
										gTextTexture.loadFromRenderedText("защитить нас от огненного дыхания дракона?", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 400);
										gTextTexture.loadFromRenderedText("Как гласит древнее придание:", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 450);
										gTextTexture.loadFromRenderedText("		Герой!", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 500);
										gTextTexture.loadFromRenderedText("		Двигайся с помощью стрелочек", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 550);
										gTextTexture.loadFromRenderedText("		Дракон может выплюнуть только один огненный шар за раз", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 600);
										gTextTexture.loadFromRenderedText("		Твой щит, единственное что может отразить огненный шар", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 650);
										gTextTexture.loadFromRenderedText("		Не дай огненным шарам консуться города, отражай их, чтобы поразить дракона", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 700);
										gTextTexture.loadFromRenderedText("		И самое главное, помни нашу народную пословицу: <<Город, аки дракон, три жизни имеет>>", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 750);
										gTextTexture.loadFromRenderedText(		"Удачи!", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 800);
										gTextTexture.loadFromRenderedText("Нажмите Enter для продолжения...", { 255,255,255 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 850);
										SDL_RenderPresent(gRenderer);
									}
								break;
							}
							case 4:
							{
								//выход
								quit = true;
								in.close();
								out.open("top.txt");
								for (int i = 0; i < 10; i++)
									out << result[i].timer_hero << " " << result[i].name_hero << " " << result[i].head_hero << "\n";
								out.close();
								break;
							}
							default:
								break;
							}
							break;
						}
						}
					}
				}
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				SDL_Rect cur = { 0, 0, 1580, 870 };
				picture.render(190, 105, &cur);
				switch (c)
				{
				case 1:
				{
					gTextTexture.loadFromRenderedText("Начать битву", brown, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("Герои города", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("Как победить", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("дракона?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("Сбежать", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				case 2:
				{
					gTextTexture.loadFromRenderedText("Начать битву", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("Герои города", brown, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("Как победить", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("дракона?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("Сбежать", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				case 3:
				{
					gTextTexture.loadFromRenderedText("Начать битву", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("Герои города", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("Как победить", brown, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("дракона?", brown, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("Сбежать", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				case 4:
				{
					gTextTexture.loadFromRenderedText("Начать битву", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("Герои города", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("Как победить", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("дракона?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("Сбежать", brown, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				default:
				{
					gTextTexture.loadFromRenderedText("Начать битву", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("Герои города", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("Как победить", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("дракона?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("Сбежать", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				}
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//закрытие и отчиска памяти
	close();

	return 0;
}