#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_DIGITOS 5
#define NUM_INTENTOS 10
#define CORRECTO 0
#define NUMERO_CORRECTO_LUGAR_ERRONEO 1
#define INCORRECTO 2

struct Jugador
{
    char nombre[50];
    int intentosMinimos;
    double tiempoMinimo;
};

void generarNumeroAleatorio(int numeroSecreto[NUM_DIGITOS])
{
    srand(time(NULL));
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
        numeroSecreto[i] = rand() % 10;
    }
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
        printf("%d ", numeroSecreto[i]);
    }
}

void mostrarMensajeBienvenida(char nombreJugador[])
{
    printf("¡Bienvenido, %s!\n", nombreJugador);
    printf("Intenta adivinar un número de %d cifras.\n", NUM_DIGITOS);
    printf("Tienes %d intentos.\n", NUM_INTENTOS);
}

void jugar()
{
    int numeroSecreto[NUM_DIGITOS];
    generarNumeroAleatorio(numeroSecreto);

    char nombreJugador[50];
    printf("Ingresa tu nombre: ");
    scanf("%s", nombreJugador);

    mostrarMensajeBienvenida(nombreJugador);

    int intentos = 0;
    int correctos;
    while (intentos < NUM_INTENTOS && correctos < 5)
    {
        int numeroAdivinado[NUM_DIGITOS][2];
        printf("Intento %d: Ingresa un número de %d cifras: ", intentos + 1, NUM_DIGITOS);
        for (int i = 0; i < NUM_DIGITOS; i++)
        {
            scanf("%1d", &numeroAdivinado[i][0]);
        }

        for (int i = 0; i < NUM_DIGITOS; i++)
        {
            printf("%d ", numeroAdivinado[i][0]);
        }
        printf("\n");

        correctos = 0;
        for (int i = 0; i < NUM_DIGITOS; i++)
        {
            numeroAdivinado[i][1] = INCORRECTO;
            if (numeroSecreto[i] == numeroAdivinado[i][0])
            {
                numeroAdivinado[i][1] = CORRECTO;
                correctos++;
            }
            else
            {
                for (int j = 0; j < NUM_DIGITOS && numeroAdivinado[i][1] == INCORRECTO; j++)
                {
                    if (numeroAdivinado[i][1] != NUMERO_CORRECTO_LUGAR_ERRONEO && numeroSecreto[j] == numeroAdivinado[i][0])
                    {
                        numeroAdivinado[i][1] = NUMERO_CORRECTO_LUGAR_ERRONEO;
                    }
                }
            }
        }

        for (int i = 0; i < NUM_DIGITOS; i++)
        {
            printf("Número %d: %s\n", numeroAdivinado[i][0], numeroAdivinado[i][1] == CORRECTO ? "Correcto!" : (numeroAdivinado[i][1] == NUMERO_CORRECTO_LUGAR_ERRONEO ? "Número correcto, lugar erróneo!" : "Número erróneo!"));
        }
        
        intentos++;
    }

    // Muestra los resultados y actualiza el ranking.
    printf(correctos == 5 ? "Felicidades, ganaste!" : "Mala suerte, podés intentar de nuevo.")
    printf("¿Deseas jugar de nuevo? (s/n): ");
    char respuesta;
    scanf(" %c", &respuesta);
    if (respuesta == 's' || respuesta == 'S')
    {
        jugar();
    }
}

int main()
{
    jugar();
    return 0;
}