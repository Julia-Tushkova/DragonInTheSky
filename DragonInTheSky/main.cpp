#include "Initialization.h"
#include "Play.h"
#include "Top.h"
#include <Windows.h>

//������� ���������� ���������
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
	hero_ result[10] = {};//��������� �� ����� ����
	for (int i = 0; i < 10; i++)
	{
		in >> result[i].timer_hero;
		in >> result[i].name_hero;
		in >> result[i].head_hero;
	}
	//�������� ����
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//�������� �����
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//���� ������
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
			//������� ����
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
								//������ ����
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
								//�������
								sort(result);
								top(result);
								break;
							}
							case 3:
							{
								//�������
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
										gTextTexture.loadFromRenderedText("� ���! �� ��� ������� ����� ����������� ����� ����������� ������!", {0,0,0}, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 300);
										gTextTexture.loadFromRenderedText("�������� �� �����(���������� � ����������� ��������� �����) ���������", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 350);
										gTextTexture.loadFromRenderedText("�������� ��� �� ��������� ������� �������?", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 400);
										gTextTexture.loadFromRenderedText("��� ������ ������� ��������:", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 450);
										gTextTexture.loadFromRenderedText("		�����!", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 500);
										gTextTexture.loadFromRenderedText("		�������� � ������� ���������", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 550);
										gTextTexture.loadFromRenderedText("		������ ����� ��������� ������ ���� �������� ��� �� ���", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 600);
										gTextTexture.loadFromRenderedText("		���� ���, ������������ ��� ����� �������� �������� ���", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 650);
										gTextTexture.loadFromRenderedText("		�� ��� �������� ����� ��������� ������, ������� ��, ����� �������� �������", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 700);
										gTextTexture.loadFromRenderedText("		� ����� �������, ����� ���� �������� ���������: <<�����, ��� ������, ��� ����� �����>>", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 750);
										gTextTexture.loadFromRenderedText(		"�����!", { 0,0,0 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 800);
										gTextTexture.loadFromRenderedText("������� Enter ��� �����������...", { 255,255,255 }, gFont);
										gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 850);
										SDL_RenderPresent(gRenderer);
									}
								break;
							}
							case 4:
							{
								//�����
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
					gTextTexture.loadFromRenderedText("������ �����", brown, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("����� ������", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("��� ��������", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("�������?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("�������", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				case 2:
				{
					gTextTexture.loadFromRenderedText("������ �����", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("����� ������", brown, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("��� ��������", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("�������?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("�������", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				case 3:
				{
					gTextTexture.loadFromRenderedText("������ �����", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("����� ������", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("��� ��������", brown, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("�������?", brown, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("�������", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				case 4:
				{
					gTextTexture.loadFromRenderedText("������ �����", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("����� ������", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("��� ��������", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("�������?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("�������", brown, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				default:
				{
					gTextTexture.loadFromRenderedText("������ �����", blue, gFont);
					gTextTexture.render(400, 400);
					gTextTexture.loadFromRenderedText("����� ������", blue, gFont);
					gTextTexture.render(400, 450);
					gTextTexture.loadFromRenderedText("��� ��������", blue, gFont);
					gTextTexture.render(400, 500);
					gTextTexture.loadFromRenderedText("�������?", blue, gFont);
					gTextTexture.render(440, 530);
					gTextTexture.loadFromRenderedText("�������", blue, gFont);
					gTextTexture.render(440, 580);
					break;
				}
				}
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//�������� � ������� ������
	close();

	return 0;
}