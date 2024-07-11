#include <iostream>
#include <iostream>
#include "graphics.h"
#include <thread>
#include <chrono>


using namespace std;

void carrera(int);


char imagenes[3][25] = {"Imagenes\\fondo.jpg",
                        "Imagenes\\caballo.gif",
                        "Imagenes\\fondo_c.jpg"
                        };

int paso_1 = 0 , paso_2 = 0 , paso_3 = 0 , paso_4 = 0 , num_ran_1 = 0 , num_ran_2 = 0 , num_ran_3 = 0 , num_ran_4 = 0;

void Carrera(int *num_ran2)
{
    while(true)
    {
        *num_ran2 = rand()%5;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main()
{
    initwindow(1280,500,"Caballos",50,150);
    cleardevice();
    readimagefile(imagenes[0],0,0,getmaxx(),getmaxy());
    thread caballo1(Carrera , &num_ran_1);
    thread caballo2(Carrera , &num_ran_2);
    thread caballo3(Carrera , &num_ran_3);
    thread caballo4(Carrera , &num_ran_4);
    while(!kbhit())
    {

        readimagefile(imagenes[2] , 0 , 430 , paso_4+50 , 480);
        readimagefile(imagenes[1] , paso_4 , 430 , paso_4+50 , 480);

        readimagefile(imagenes[2] , 0 , 350 , paso_3+50 , 400);
        readimagefile(imagenes[1] , paso_3 , 350 , paso_3+50 , 400);

        readimagefile(imagenes[2] , 0 , 260 , paso_2+50 , 310);
        readimagefile(imagenes[1] , paso_2 , 260 , paso_2+50 , 310);

        readimagefile(imagenes[2] , 0 , 180 , paso_1+50 , 220);
        readimagefile(imagenes[1] , paso_1 , 180 , paso_1+50 , 220);


       if(num_ran_1 == 1)
       {
        paso_1+=10;
            if(paso_1 == 1200)
            {  settextstyle(0,0,3);
                outtextxy(getmaxx()/2,250,"El ganador es el caballo 1");
                caballo1.join();
                caballo2.join();
                caballo3.join();
                caballo4.join();
                getch();
            }
       }
       if(num_ran_2 == 2)
       {
        paso_2+=10;
         if(paso_2 == 1200)
            {
                  settextstyle(0,0,3);
                outtextxy(getmaxx()/2,250,"El ganador es el caballo 2");
                caballo1.join();
                caballo2.join();
                caballo3.join();
                caballo4.join();
                getch();
            }
       }
       if(num_ran_3 == 3)
       {
        paso_3+=10;
         if(paso_3 == 1200)
            {
                settextstyle(0,0,3);
                outtextxy(getmaxx()/2,250,"El ganador es el caballo 3");

                caballo1.join();
                caballo2.join();
                caballo3.join();
                caballo4.join();
                getch();
            }
       }
       if(num_ran_4 == 4)
       {
        paso_4+=10;
         if(paso_4 == 1200)
            {
                  settextstyle(0,0,3);
                outtextxy(getmaxx()/2,250,"El ganador es el caballo 4");
                getch();
            }
       }
    }
    caballo1.join();
    caballo2.join();
    caballo3.join();
    caballo4.join();
    return 0;
}
