#include <iostream>
#include "graphics.h"
#include <thread>
#include <chrono>
#include <pthread.h>


using namespace std;

int rojo = 0 , amarillo = 0, verde = 0;
pthread_mutex_t llave , llave2 , llave3;

char imagenes[1][25] = {"Imagenes\\Fondo.jpg"};

char semaforo_rojo[2][25] = {"Imagenes\\Apagado.jpg",
                            "Imagenes\\Rojo.jpg"};

char semaforo_amarillo[2][25] = {"Imagenes\\Apagado.jpg",
                                "Imagenes\\Amarillo.jpg"};

char semaforo_verde[2][25] = {"Imagenes\\Apagado.jpg",
                            "Imagenes\\Verde.jpg",};

void* Parpadeo_Rojo(void *red)
{
    pthread_mutex_lock(&llave);
    *(int*)red = 1;
    this_thread::sleep_for(chrono::milliseconds(3000));
    *(int*)red = 0;
    pthread_mutex_unlock(&llave);
}

void* Parpadeo_Amarillo(void *yellow)
{
    pthread_mutex_lock(&llave);
    pthread_mutex_lock(&llave2);
    *(int*)yellow = 1;
    this_thread::sleep_for(chrono::milliseconds(1000));
    *(int*)yellow = 0;
    pthread_mutex_unlock(&llave);
    pthread_mutex_unlock(&llave2);
}

void* Parpadeo_Verde(void *green)
{
    pthread_mutex_lock(&llave);
    pthread_mutex_lock(&llave2);
    *(int*)green = 1;
    this_thread::sleep_for(chrono::milliseconds(3000));
    *(int*)green = 0;
    pthread_mutex_unlock(&llave);
    pthread_mutex_unlock(&llave2);
}

int main()
{
    initwindow(500,600,"Semaforo",450,80);
    cleardevice();
    readimagefile(imagenes[0],0,0,getmaxx(),getmaxy());


    pthread_mutex_init( &llave , NULL );
    pthread_mutex_init( &llave2 , NULL );
    pthread_mutex_init( &llave3 , NULL );
    pthread_t Hilo_rojo;
    pthread_t Hilo_amarillo;
    pthread_t Hilo_verde;

    while(!kbhit())
    {
        pthread_create(&Hilo_rojo , NULL , Parpadeo_Rojo , (void *)&rojo );
        pthread_create(&Hilo_amarillo , NULL , Parpadeo_Amarillo , (void *)&amarillo );
        pthread_create(&Hilo_verde , NULL , Parpadeo_Verde , (void *)&verde );
        readimagefile(semaforo_rojo[rojo%2],135,20,355,190);
        readimagefile(semaforo_amarillo[amarillo%2],135,215,355,385);
        readimagefile(semaforo_verde[verde%2],135,395,355,565);
    }
    pthread_join(Hilo_rojo , NULL);
    pthread_join(Hilo_amarillo , NULL);
    pthread_join(Hilo_verde , NULL);
}
