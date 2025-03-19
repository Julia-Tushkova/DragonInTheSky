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
    started = true;  // ���� � ������ ������
    paused = false;  /// ��������� �����
    startTicks = SDL_GetTicks();  // ����� ������
}

void Timer::stop() 
{
    started = false;
    paused = false;
}

void Timer::pause()
{
    if ((started == true) && (paused == false)) 
    {  // ���� ������ �������
        paused = true;  /// ������������� ���� �����
        pausedTicks = SDL_GetTicks() - startTicks;   // ���������� ����� ������ �� �����
    }
}

void Timer::unpause() 
{
    if (paused == true) 
    {  // ���� ������ �� �����
        paused = false; // ������ ����
        startTicks = SDL_GetTicks() - pausedTicks; // ������������� ����� ����� ������ ������
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
    a = this->get_ticks() / 1000; //������� � �������
    b = a / 60;//������� � ������
    char str[80];
    sprintf_s(str, "%d%c%d", b,':', (a-b*60));
    path = std::string(str);
    return path;
}