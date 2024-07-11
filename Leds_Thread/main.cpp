#include <iostream>
#include "graphics.h"
#include <thread>
#include <chrono>

using namespace std;

void place(int,int,int,int,int,int,int);

char fondo[4][30] = {"Imagenes\\fondo.jpg",
                    "Imagenes\\f_led_rojo.jpg",
                    "Imagenes\\f_led_verde.jpg",
                    "Imagenes\\f_led_azul.jpg"
                    };
char destellos[3][30] = {"Imagenes\\destello_rojo.gif",
                        "Imagenes\\destello_verde.gif",
                        "Imagenes\\destello_azul.gif"
                        };
int main()
{
    initwindow(800,337,"SegundaApp",500,150);
    readimagefile(fondo[0],0,0,getmaxx(),getmaxy());
    thread destello_rojo(place,100,0,1,300,50,350,100);
    thread destello_verde(place,500,1,2,485,54,536,105);
    thread destello_azul(place,1000,2,3,675,50,725,100);
    destello_azul.join();
    destello_rojo.join();
    destello_verde.join();
    return(0);
}

void place(int tiempo , int imagen , int im_fondo , int pos_x1 , int pos_y1 , int pos_x2 , int pos_y2)
{
    while(!kbhit())
    {
        readimagefile(destellos[imagen],pos_x1,pos_y1,pos_x2,pos_y2); //para azul 675,50,725,100, verde 485,50,535,100 , rojo 300,50,350,100
        this_thread::sleep_for(chrono::milliseconds(tiempo));
        readimagefile(fondo[im_fondo],pos_x1,pos_y1,pos_x2,pos_y2);
        this_thread::sleep_for(chrono::milliseconds(tiempo));
     }
}
