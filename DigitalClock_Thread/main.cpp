#include <iostream>
#include "graphics.h"
#include <thread>
#include <chrono>
#include <string.h>


using namespace std;
int seg0 = 0, seg1 = 0 , min0 = 0, min1 = 0, hrs1 = 0, hrs0 = 0;

void incremento(int *suma)
{
    *suma+=1;
}


int main()
{
    char segundos[2] = {'0','0'};
    char minutos[2] = {'0','0'};
    char horas[2] = {'0','0'};
    char s_num_1[11] = {'0','1','2','3','4','5','6','7','8','9'};
    initwindow(212,400,"Reloj",450,80);
    cleardevice();
    settextstyle(3,0,10);
    outtextxy(0,50,"H");
    outtextxy(0,150,"M");
    outtextxy(0,250,"S");
    while(!kbhit())
    {
        outtextxy(100,50,horas);
        outtextxy(100,150,minutos);
        outtextxy(100,250,segundos);
        segundos[1] = s_num_1[seg1%10];
        this_thread::sleep_for(chrono::milliseconds(300));
        thread ss1(incremento,&seg1);
        //seg1++;
        if(seg1%10 == 0)
        {
            //seg0++;
            thread ss0(incremento,&seg0);
            segundos[0] = s_num_1[seg0%6];
            if(seg0%6 == 0)
            {
                //min1++;
                thread mm1(incremento,&min1);
                minutos[1] = s_num_1[min1%10];
                if(min1%10 == 0)
                {
                    //min0++;
                    thread mm0(incremento,&min0);
                    minutos[0] = s_num_1[min0%6];
                    if(min0%6 == 0)
                    {
                        //hrs1++;
                        thread hr1(incremento,&hrs1);
                        horas[1] = s_num_1[hrs1%10];
                        if(hrs1%10 == 0)
                        {
                            //hrs0++;
                            thread hr0(incremento,&hrs0);
                            horas[0] = s_num_1[hrs0%3];
                            if(horas[1] == '2' && horas[0] == '4')
                            {
                                segundos[0] = 0;
                                segundos[1] = 0;
                                minutos[0] = 0;
                                minutos[1] = 0;
                                horas[0] = 0;
                                horas[1] = 0;
                            }hr0.join();
                        }hr1.join();
                    }mm0.join();
                }mm1.join();
            }ss0.join();
        }ss1.join();
    }
}


