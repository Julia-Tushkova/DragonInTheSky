#pragma once
#include "MyTexture.h"

class Timer
{
    //����� ������� �������
    int startTicks;
    //����� ����� �������
    int pausedTicks;
    //������ �������
    bool paused;
    bool started;
public:
    //����������� �� ���������
    Timer();
    ~Timer();
    //������ ������, ���������, ����� � !�����.. 
    void start();
    void stop();
    void pause();
    void unpause();
    //����� ����� �������
    int get_ticks();
    //��������� ������ �������
    bool is_started();
    bool is_paused();
    std::string convertion();
};