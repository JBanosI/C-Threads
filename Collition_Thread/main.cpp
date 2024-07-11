#include <iostream>
#include "graphics.h"
#include <thread>
#include <chrono>

using namespace std;

char Ovni[1][40] = { "Imagenes\\Ovni.gif" };
char Asteroid[1][40] = { "Imagenes\\Asteroide.gif" };

bool DetectarColision(int X1, int Y1, int X2, int Y2, int Ancho1, int Alto1, int Ancho2, int Alto2)
{
    // Comprueba si las imágenes se superponen en términos de coordenadas
    if (X1 < X2 + Ancho2 && X1 + Ancho1 > X2 &&
        Y1 < Y2 + Alto2 && Y1 + Alto1 > Y2)
    {
        return true; // Hay colisión
    }
    return false; // No hay colisión
}

void Coordenadas(int *X, int *Y, int *DireccionX, int *DireccionY)
{
    while (true)
    {
        if (*DireccionX == 1) // Si la dirección horizontal es 1, mueve a la derecha
        {
            *X = *X + rand() % 11;
        }
        else // Si la dirección horizontal es -1, mueve a la izquierda
        {
            *X = *X - rand() % 11;
        }

        if (*DireccionY == 1) // Si la dirección vertical es 1, mueve hacia abajo
        {
            *Y = *Y + rand() % 11;
        }
        else // Si la dirección vertical es -1, mueve hacia arriba
        {
            *Y = *Y - rand() % 11;
        }

        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main()
{
    initwindow(900, 600, "Practica 8: Colisiones", 150, 0);
    setbkcolor(15);
    cleardevice();

    int XM1 = 0, XM2 = 850, YM1 = 0, YM2 = 500;
    int XA1 = 0, XA2 = 800, YA1 = 0, YA2 = 500; // Cambiamos las coordenadas iniciales del asteroide
    int DireccionX1 = 1, DireccionX2 = -1; // Inicialmente, mueve horizontalmente a la derecha y a la izquierda respectivamente
    int DireccionY1 = 1, DireccionY2 = -1; // Inicialmente, mueve verticalmente hacia abajo y hacia arriba respectivamente

    int DireccionXA1 = 1, DireccionXA2 = -1; // Inicialmente, mueve horizontalmente a la derecha y a la izquierda respectivamente
    int DireccionYA1 = 1, DireccionYA2 = -1; // Inicialmente, mueve verticalmente hacia abajo y hacia arriba respectivamente

    thread MarcianoUno(Coordenadas, &XM1, &YM1, &DireccionX1, &DireccionY1);
    thread Asteroide(Coordenadas, &XA2, &YA2, &DireccionXA1, &DireccionYA1); // Cambiamos las direcciones iniciales

    while (!kbhit())
    {
        if (XM1 <= 0 || XM1 >= getmaxx() - 100)
        {
            DireccionX1 *= -1; // Cambia la dirección horizontal si llega al límite izquierdo o derecho
        }
        if (XM2 <= 0 || XM2 >= getmaxx() - 100)
        {
            DireccionX2 *= -1; // Cambia la dirección horizontal si llega al límite izquierdo o derecho
        }
        if (YM1 <= 0 || YM1 >= getmaxy() - 50)
        {
            DireccionY1 *= -1; // Cambia la dirección vertical si llega al límite superior o inferior
        }
        if (YA2 <= 0 || YA2 >= getmaxy() - 60)
        {
            DireccionYA1 *= -1;
        }
        if (DetectarColision(XM1, YM1, XA1, YA2, 100, 50, 90, 60))
        {
            return 0;
        }
        //rectangle()
        readimagefile(Ovni[0], 0 + XM1, 0 + YM1, 100 + XM1, 50 + YM1);
        readimagefile(Asteroid[0], 0 + XA1, 0 + YA2, 90 + XA1, 60 + YA2);
    }


    MarcianoUno.join();
    Asteroide.join();

}
