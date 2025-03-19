#pragma once
#include "MyTexture.h"

class Timer
{
    //врем€ запуска таймера
    int startTicks;
    //врем€ паузы таймера
    int pausedTicks;
    //статус таймера
    bool paused;
    bool started;
public:
    //конструктор по умолчанию
    Timer();
    ~Timer();
    //методы старта, остановки, паузы и !паузы.. 
    void start();
    void stop();
    void pause();
    void unpause();
    //вернЄт врем€ таймера
    int get_ticks();
    //провер€ют статус таймера
    bool is_started();
    bool is_paused();
    std::string convertion();
};