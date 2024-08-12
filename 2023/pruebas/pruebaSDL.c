#include <SDL2/SDL.h>

// Dimensiones de la ventana
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// renderer parameters
const int       REN_INDEX = -1;
const Uint32    REN_FLAGS = 0;


int main() {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_EVERYTHING ) < 0) {
        printf("SDL no se pudo inicializar. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Crear una ventana
    SDL_Window* window = SDL_CreateWindow("SDL Shapes Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("La ventana no se pudo crear. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Crear un renderizador para la ventana
    SDL_Renderer*   renderer = SDL_CreateRenderer(window, REN_INDEX, REN_FLAGS);
    if (renderer == NULL) {
        printf("El renderizador no se pudo crear. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    printf("Iniciar prueba...");
    // Color de dibujo: rojo
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Dibujar una línea
    SDL_RenderDrawLine(renderer, 100, 100, 500, 100);

    // Color de dibujo: verde
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    // Dibujar un rectángulo
    SDL_Rect rect = {20, 20, 20, 100};
    SDL_RenderDrawRect(renderer, &rect);

    // Color de dibujo: azul
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Dibujar un círculo
    int radius = 50;
    int x = 400;
    int y = 400;
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }

    // Actualizar la pantalla
    SDL_RenderPresent(renderer);

    // Esperar un tiempo antes de salir
    getchar();

    // Limpiar y cerrar SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}