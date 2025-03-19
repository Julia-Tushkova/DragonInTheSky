#include "Initialization.h"

//функция паузы
bool pause()
{
	bool end = false, menu;
	SDL_Rect cur;
	SDL_Event e;
	int c = 0;
	while (!end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
				{
					c--;
					if (c == 0||c==-1) c = 2;
					break;
				}
				case SDLK_DOWN:
				{
					c++;
					if (c == 3 || c == 0) c = 1;
					break;
				}
				case SDLK_RETURN:
				{
					switch (c)
					{
					case 1:
					{
						menu = false;
						end = true;
						break;
					}
					case 2:
					{
						menu = true;
						end = true;
						break;
					}
					}
				}
				}
			}
			SDL_RenderClear(gRenderer);
			cur = { 0, 0, 1600, 900 };
			vilage_dark.render(190, 105, &cur);
			switch (c)
			{
			case 1:
			{
				gTextTexture.loadFromRenderedText("Продолжить битву", { 255,0,0 }, gFont);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT /2-25);
				gTextTexture.loadFromRenderedText("Сбежать", { 255,255,255 }, gFont);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT /2+25);
				break;
			}
			case 2:
			{
				gTextTexture.loadFromRenderedText("Продолжить битву", { 255,255,255 }, gFont);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT /2-25);
				gTextTexture.loadFromRenderedText("Сбежать", { 255,0,0 }, gFont);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT /2+25);
				break;
			}
			default:
			{
				gTextTexture.loadFromRenderedText("Продолжить битву", { 255,255,255 }, gFont);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT/2-25);
				gTextTexture.loadFromRenderedText("Сбежать", { 255,255,255 }, gFont);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT/2+25);
				break;
			}
			}
			SDL_RenderPresent(gRenderer);
		}
	}
	return menu;
}

//функция выбора персонажа
int player_selection()
{
	int number_player;
	bool end = false, n=true;
	SDL_Rect cur, *hero_rect;
	SDL_Event e;
	int c = 0;
	while (!end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
				{
					c--;
					if (c == -1) c = 3;
					break;
				}
				case SDLK_RIGHT:
				{
					c++;
					if (c == 4) c = 0;
					break;
				}
				case SDLK_RETURN:
				{
					number_player = c * 4;
					end = true;
					break;
				}
				}
			}
			
		}
		SDL_RenderClear(gRenderer);
		cur = { 0, 0, 1920, 1080 };
		sel.render(0, 0, &cur);
		gTextTexture.loadFromRenderedText("Выбор персонажа", { 255,255,255 }, gFont);
		gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 200);
		hero_rect = &my_heros.my_hero[c * 4];
		if (n)
		{
			my_heros.hero[c * 4].render(935, 350, hero_rect);
			SDL_Delay(500);
			hero_rect->h = hero_rect->h - 15;
			n = false;
		}
		else
		{
			my_heros.hero[c * 4].render(935, 365, hero_rect);
			SDL_Delay(500);
			hero_rect->h = hero_rect->h + 15;
			n = true;
		}
		switch (c)
		{
		case 0:
		{
			gTextTexture.loadFromRenderedText("Ульям", { 0,0,0 }, gFont);
			gTextTexture.render(650 - gTextTexture.getWidth(), 410);
			gTextTexture.loadFromRenderedText("Ужасно не везучий.", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410+40);
			gTextTexture.loadFromRenderedText("Как только он решил", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 70);
			gTextTexture.loadFromRenderedText("заказать волшебную", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 100);
			gTextTexture.loadFromRenderedText("дверь, чтобы", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 130);
			gTextTexture.loadFromRenderedText("обезопасить свой дом,", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 160);
			gTextTexture.loadFromRenderedText("так его спалил дракон", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 190);
			break;
		}
		case 1:
		{
			gTextTexture.loadFromRenderedText("Джейн", { 0,0,0 }, gFont);
			gTextTexture.render(650 - gTextTexture.getWidth(), 410);
			gTextTexture.loadFromRenderedText("Говорят драконы любят", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 40);
			gTextTexture.loadFromRenderedText("красавиц. Хоть она и", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 70);
			gTextTexture.loadFromRenderedText("неотразима, но", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 100);
			gTextTexture.loadFromRenderedText("нападения нужно", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 130);
			gTextTexture.loadFromRenderedText("как-то отражать. Как", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 160);
			gTextTexture.loadFromRenderedText("нападение отразится", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 190);
			gTextTexture.loadFromRenderedText("на судьбе города?", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 220);
			break;
		}
		case 2:
		{
			gTextTexture.loadFromRenderedText("Рыцарь", { 0,0,0 }, gFont);
			gTextTexture.render(650 - gTextTexture.getWidth(), 410);
			gTextTexture.loadFromRenderedText("Рыцарь святого полена.", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 40);
			gTextTexture.loadFromRenderedText("Волшебный", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 70);
			gTextTexture.loadFromRenderedText("огнеупорный щит,", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 100);
			gTextTexture.loadFromRenderedText("сверкающие доспехи.", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 130);
			gTextTexture.loadFromRenderedText("Просто рыцарь...", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 160);
			break;
		}
		case 3:
		{
			gTextTexture.loadFromRenderedText("Катара", { 0,0,0 }, gFont);
			gTextTexture.render(650 - gTextTexture.getWidth(), 410);
			gTextTexture.loadFromRenderedText("Верховный архимаг", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 40);
			gTextTexture.loadFromRenderedText("гильдии магов", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 70);
			gTextTexture.loadFromRenderedText("Быдлограда. Кому,", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 100);
			gTextTexture.loadFromRenderedText("как не ей защищать", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 130);
			gTextTexture.loadFromRenderedText("свой родной город от ", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 160);
			gTextTexture.loadFromRenderedText("злого дракона", { 0,0,0 }, sel_per);
			gTextTexture.render(495, 410 + 190);
			break;
		}
		}
		SDL_RenderPresent(gRenderer);
	}
	return number_player;
}

//столкновения между героем и огненым шаром
int check_collision(SDL_Rect* a, SDL_Rect* b, int y, int speed, int a1)
{
		int height_hero, height_ball;
		int hero_left, hero_right;
		int ball_left, ball_right;
		int b_x, c_x;

		height_hero = 750+35; height_ball = b->h+y;
		hero_left = speed; hero_right = speed + a->w;
		ball_left = a1; ball_right = a1 + b->w;
		b_x = speed + 40; c_x = speed + 60;
		if (hero_left < ball_right)
		{
			if (hero_left < ball_left)
				if (b_x > ball_left)
					if (height_ball >= height_hero && height_ball <= height_hero + 20)
						return 0;
			if (b_x < ball_left)
				if (c_x > ball_left)
					if (height_ball >= height_hero && height_ball <= height_hero + 20)
						return 1;
			if (c_x < ball_left)
				if (hero_right > ball_left)
					if (height_ball >= height_hero && height_ball <= height_hero + 20)
						return 2;
		}
		if (ball_left < hero_right)
			if (hero_left < ball_right)
					if (height_ball >= height_hero && height_ball <= height_hero + 20)
						return 0;
	return 3;
}

//столкновения между огненым шаром и драконом
int collision_dragon(SDL_Rect* a, SDL_Rect* b, int f, int a1, int y)
{
	int dragon_left, dragon_mid, dragon_right, head;
	int ball_left, ball_right;
	int height_ball;

	dragon_left = f + 20; dragon_mid = f + 180; dragon_right = f + a->h; head = f + 260;
	ball_left = a1; ball_right = a1 + b->w;
	height_ball = b->h/2 + y;

	if (ball_left <= dragon_mid)
		if (dragon_left < ball_right)
			if (180>=height_ball)
				return 1;
	if (ball_left <= head)
		if (dragon_mid < ball_right)
			if (250 >= height_ball)
				return 2;
	if (ball_left <= dragon_right)
		if (head < ball_right)
			if (100 >= height_ball)
				return 3;

	if (dragon_left <= ball_right)
		if (ball_left < dragon_mid)
			if (180 >= height_ball)
				return 1;
	if (head <= ball_right)
		if (ball_left < dragon_right)
			if (250 >= height_ball)
				return 2;
	if (dragon_mid <= ball_right)
		if (ball_left < head)
			if (100 >= height_ball)
				return 3;

	return 0;
}

//рендеринг шара в зависимости от условий
void fire_ball_renderer(bool* fly, int* x, int a, int b, SDL_Rect ball, int* y, int check)
{
	switch (check)
	{
	case 3:
	{
		*y += 10;
		if (*fly)
		{
			if (a > 0) *x = 200 + a;
			else *x = 200 + b;
			*fly = false;

		}
		if (*x)
			fire_ball.render(*x, *y, &ball);
		break;
	}
	case 2:
	{
		*x += 10;
		*y -= 10;
		int i = 2 * SCREEN_WIDTH - *x;
		if (*x + 260 > SCREEN_WIDTH) 
		{ 
			fire_ball.render(2 * SCREEN_WIDTH - 2*260 - *x, *y, &ball);  
		}
		else fire_ball.render(*x, *y, &ball);
		break;
	}
	case 1:
	{
		*y -= 10;
		fire_ball.render(*x, *y, &ball);
		break;
	}
	case 0:
	{
		*x -= 10;
		*y -= 10;
		if (*x < 200) fire_ball.render(400-*x, *y, &ball);
		else fire_ball.render(*x, *y, &ball);
		break;
	}
	}
}

//когда игрок проиграл
void game_over()
{
	bool end=false;
	SDL_Event e;
	SDL_Rect cur;
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
		gameOver.render(190, 105, &cur);
		gTextTexture.loadFromRenderedText("Нажмите Enter для продолжения...", { 255,255,255 }, gFont);
		gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 800);
		SDL_RenderPresent(gRenderer);
	}
}

//когда игрок победил
void you_win()
{
	bool end = false;
	int j = 0;
	SDL_Event e;
	SDL_Rect cur;
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
				if (j < 2 && symbol[j]!='_')
					j++;
			}
		}
		cur = { 0, 0, 1600, 900 };
		youWin.render(170, 105, &cur);
		const Uint8* Keys = NULL;
		Keys = SDL_GetKeyboardState(NULL);
		for (int i = 0; i < 26; i++)
		{
			if (Keys[4 + i])
			{
				symbol[j] = i + 65;
				break;
			}
		}
		name = std::string(symbol);
		gTextTexture.loadFromRenderedText("Введите имя героя: ", { 255,255,255 }, gFont);
		gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth())/2, 800);
		gTextTexture.loadFromRenderedText(name, { 255,255,255 }, gFont);
		gTextTexture.render(1110, 800);
		SDL_RenderPresent(gRenderer);
	}
}

//основная функция игры
int play(int number_player)
{
	Timer tim;
	tim.start();
	int left_hero = number_player + 1, right_hero = number_player + 2;
	bool end = false, menu, fly=true;
	int d = left_hero, speed = SCREEN_WIDTH / 2 - 70, y = 340, a1 = 0, timer;
	int check_flag = 0, flag_fly = 0, flag_colision_dragon = 0, flag = 3;
	SDL_Rect cur,* h, drag, ball;
	SDL_Event e;
	int a = (SCREEN_WIDTH / 2 - 201), b; 
	while (!end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
				{
					tim.pause();
					menu = pause();
					if (menu)
					{	
						end = true;
					}
					else
					{
						tim.unpause();
					}
					break;
				}
				case SDLK_LEFT:
				{
					if (speed > 190) speed -= 15;
					d = right_hero;
					break;
				}
				case SDLK_RIGHT:
				{
					if (speed + 100 < SCREEN_WIDTH-200) speed += 15;
					d = left_hero;
					break;
				}
				}
			}
		}
		SDL_RenderClear(gRenderer);
		cur = { 0, 0, 1600, 900 };
		vilage.render(190, 105, &cur);
		h = &my_heros.my_hero[d];
		my_heros.hero[d].render(speed, 750, h);
		ball = { 0,0,60,91 };
		drag = { 0,0,402,402 };
		if ((a + 400 < SCREEN_WIDTH) && (a != -1))
		{
			dragon.render(a, -100, &drag);
			flag_colision_dragon = collision_dragon(&drag, &ball, a, a1, y);
			a += 10;
			b = SCREEN_WIDTH - 400;
		}
		else
		{
			dragon.render(b, -100, &drag);
			flag_colision_dragon = collision_dragon(&drag, &ball, b, a1, y);
			a = -1;
			if (b > 0)
				b -= 10;
			else a = 0;
		}
		check_flag = check_collision(h, &ball, y, speed, a1);
		switch (check_flag)
		{
		case 2:
		{
			flag = 2;
			break;
		}
		case 1:
		{
			flag = 1;
			break;
		}
		case 0:
		{
			flag = 0;
			break;
		}
		}
		if ((tim.get_ticks() % 30) == 0) flag_fly = 1;
		if (flag_fly == 1) fire_ball_renderer(&fly, &a1, a, b, ball, &y, flag);
		if (y >= 800) 
		{
				y = 340;
				fly = true;
				flag_fly = 0;
				a1 = 0;
				if (flag == 3)
					hearts_town.break_heart();
		}
		if (y+91<100)
		{
			y = 340;
			fly = true;
			flag_fly = 0;
			flag = 3;
			a1 = 0;
		}
		gTextTexture.loadFromRenderedText(tim.convertion(), { 0,255,0 }, gFont);
		gTextTexture.render(1050, 910);
		gTextTexture.loadFromRenderedText("Время битвы:", { 0,255,0 }, gFont);
		gTextTexture.render(845, 910);
		h = &image_heart_dragon[hearts_dragon.get_counter()-1];
		hearts_dragon.render(300, 910, h);
		h = &image_heart_town[hearts_town.get_counter() - 1];
		hearts_town.render(1450, 910, h);
		if (flag_colision_dragon)
		{
			hearts_dragon.break_heart();
			y = 340;
			fly = true;
			flag_fly = 0;
			flag = 3;
			a1 = 0;
		}
		if (hearts_dragon.get_counter()==0)
		{
			tim.pause();
			timer = tim.get_ticks();
			you_win();
			tim.stop();
			return timer;
		}
		if (hearts_town.get_counter()==0)
		{
			tim.stop();
			game_over();
			return 0;
		}
		SDL_Delay(100);
		SDL_RenderPresent(gRenderer);
	}
	tim.stop();
	return 0;
}