#include <iostream>
#include "graphics.h"
#include <thread>

using namespace std;
char imagenes[4][20] = {"imagenes\\1.jpg",
                        "imagenes\\2.jpg",
                        "imagenes\\3.jpg",
                        "imagenes\\4.jpg"};

char audio[4][20] = {"Audio\\1.wav",
                    "Audio\\2.wav",
                    "Audio\\3.wav",
                    "Audio\\4.wav"};

int im = 0,  audio2 = 0;

void diapositiva(int *im)
{
    *im+=1;
}

int main()
{
    initwindow(400,400,"SegundaApp",500,150);
    cleardevice();
    while(!kbhit())
    {
        thread diap(diapositiva,&im);
        readimagefile(imagenes[im%4],0,0,getmaxx(),getmaxy());
        PlaySound(audio[audio2%4],NULL,SND_SYNC);
        thread aud(diapositiva,&audio2);
        /*if(audio2 > 3 && im > 3)
            audio2 = im = 0;*/
        diap.join();
        aud.join();
    }
    getch();
}
