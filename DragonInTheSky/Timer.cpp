#include "Timer.h"
#include <cstring>
#include <cstdio>

Timer::Timer() 
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

Timer::~Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    started = true;  // флаг о начале работы
    paused = false;  /// выключаем паузу
    startTicks = SDL_GetTicks();  // время начала
}

void Timer::stop() 
{
    started = false;
    paused = false;
}

void Timer::pause()
{
    if ((started == true) && (paused == false)) 
    {  // если таймер работал
        paused = true;  /// устанавливаем флаг паузы
        pausedTicks = SDL_GetTicks() - startTicks;   // запоминаем время работы до паузы
    }
}

void Timer::unpause() 
{
    if (paused == true) 
    {  // если таймер на паузе
        paused = false; // меняем флаг
        startTicks = SDL_GetTicks() - pausedTicks; // устанавливаем новое время начала работы
        pausedTicks = 0;
    }
}

int Timer::get_ticks() 
{
    if (started == true) 
    {
        if (paused == true) 
        {
            return pausedTicks;
        }
        else 
        {
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}

bool Timer::is_started() 
{
    return started;
}

bool Timer::is_paused() 
{
    return paused;
}

std::string Timer::convertion()
{
    std::string path;
    int a, b;
    a = this->get_ticks() / 1000; //перевод в секунды
    b = a / 60;//перевод в минуты
    char str[80];
    sprintf_s(str, "%d%c%d", b,':', (a-b*60));
    path = std::string(str);
    return path;
}