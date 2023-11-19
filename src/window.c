#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "/mnt/c/Users/diego/SAE-C/include/SDL2/SDL.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

#define BUTTON_WIDTH 240
#define BUTTON_HEIGHT 55
#define BUTTON_SPACING 80
#define BUTTON_MARGIN 40

int main(int argc, char* args[]) {

    // Initialization of the sdl window and renderer
    SDL_Window* mainWindow;
    SDL_Renderer* renderer;
    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Creating the window
    mainWindow = SDL_CreateWindow("Super Epic Mini Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (mainWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    renderer = SDL_CreateRenderer(mainWindow,-1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(renderer);

    // Initializing the background image
    SDL_Surface* bgImage = SDL_LoadBMP("../datafile/image.bmp");
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgImage);
    SDL_FreeSurface(bgImage);
    SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
    // Initializing the texture of the game access buttons
    SDL_Texture* gameButtonTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 240, 55);
    SDL_SetRenderTarget(renderer, gameButtonTexture);

    // Creating the button rectangle
    SDL_SetRenderDrawColor(renderer, 99, 121, 194,250);
    SDL_Rect buttonRecPos = {0, 0, BUTTON_WIDTH, BUTTON_HEIGHT};
    SDL_RenderFillRect(renderer, &buttonRecPos);
    SDL_SetRenderDrawColor(renderer, 0,0,255,250);
    SDL_Rect buttonRecPos2 = {3,3,BUTTON_WIDTH-6,BUTTON_HEIGHT-6};
    SDL_RenderDrawRect(renderer, &buttonRecPos2);

    // Positioning the button texture on the renderer
    SDL_SetRenderTarget(renderer, NULL);
    SDL_Rect buttonPosition;
    buttonPosition.y = SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 5;

    // Drawing multiple copies of the texture with spacing of 80 pixels
    for (int i = 0; i<3; i++) {
        buttonPosition.x = BUTTON_MARGIN + i * (BUTTON_WIDTH + BUTTON_SPACING);
        SDL_QueryTexture(gameButtonTexture, NULL, NULL, &buttonPosition.w, &buttonPosition.h);
        SDL_RenderCopy(renderer, gameButtonTexture, NULL, &buttonPosition);
    }

    // Loading and positioning the three illustration images
    SDL_Surface* picture1 = SDL_LoadBMP("../datafile/tf1.bmp");
    SDL_Texture* picture1Texture = SDL_CreateTextureFromSurface(renderer, picture1);
    SDL_FreeSurface(picture1);
    SDL_Rect src = { BUTTON_MARGIN, SCREEN_HEIGHT / 2, 240, 240 };
    SDL_RenderCopy(renderer, picture1Texture, NULL, &src);  
    
    SDL_Surface* picture2 = SDL_LoadBMP("../datafile/tf2.bmp");
    SDL_Texture* picture2Texture = SDL_CreateTextureFromSurface(renderer, picture2);
    SDL_FreeSurface(picture2);
    SDL_Rect src2 = { BUTTON_MARGIN*3+240, SCREEN_HEIGHT / 2, 240, 240 };
    SDL_RenderCopy(renderer, picture2Texture, NULL, &src2);  
      
    
    SDL_Surface* picture3 = SDL_LoadBMP("../datafile/tf3.bmp");
    SDL_Texture* picture3Texture = SDL_CreateTextureFromSurface(renderer, picture3);
    SDL_FreeSurface(picture3);
    SDL_Rect src3 = { BUTTON_MARGIN*5+240*2, SCREEN_HEIGHT / 2, 240, 240} ;
    SDL_RenderCopy(renderer, picture3Texture, NULL, &src3);  

    // Display the scene
    SDL_RenderPresent(renderer);
    

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        // Gérer les événements de la file d'attente
        while (SDL_PollEvent(&e) != 0) {
            // L'utilisateur ferme la fenêtre
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            // Gérer les événements de la souris
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
              if (e.button.y <= buttonPosition.y + 55 && e.button.y>= buttonPosition.y){
                if(e.button.x<=BUTTON_MARGIN + 240 && e.button.x>= BUTTON_MARGIN){
                  printf("b1\n");                  
                }
                else if(e.button.x<=BUTTON_MARGIN + 1 * (BUTTON_WIDTH + BUTTON_SPACING) + 240 && e.button.x>= BUTTON_MARGIN + 1 * (BUTTON_WIDTH + BUTTON_SPACING)){
                  printf("b2\n");                  
                }
                else if(e.button.x<=BUTTON_MARGIN + 2 * (BUTTON_WIDTH + BUTTON_SPACING) + 240 && e.button.x>= BUTTON_MARGIN + 2 * (BUTTON_WIDTH + BUTTON_SPACING)){
                  printf("b3\n");                  
                } 
              } 
            }
            // Gérer les événements du clavier
            else if (e.type == SDL_KEYDOWN) {
                printf("Touche pressée (code SDL): %d\n", e.key.keysym.sym);
                quit = 1;
            }
        }

        // Mettre à jour le rendu ou effectuer d'autres actions en fonction des événements

        // Attendre un court laps de temps pour ne pas monopoliser le processeur
        SDL_Delay(10);
    }

    // Détruire la fenêtre et quitter SDL

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();

    return 0;
}


