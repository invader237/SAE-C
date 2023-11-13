#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <SDL.h>

int randGenerator();
int* sequenceGenerator();
int computeNextTerm();

int* sequenceGenerator() {

  int a = randGenerator(), b = randGenerator(), c = randGenerator();
  int* sequence = (int*)malloc(4 * sizeof(int));
  sequence[0]= c;
  for (int i = 1; i <= 3; i++) {
        //calculation of the following terms of the sequence based on the randomly generated terms
        sequence[i] = computeNextTerm(sequence[i - 1], a, b);
    }
	printf("%d %d %d %d", sequence[0],sequence[1],sequence[2],sequence[3]);
  return sequence;

}

int computeNextTerm(int prevTerm, int a, int b) {

  //calculating the next term of the sequence
  return a * prevTerm + b;

}

int randGenerator() {

  //generates a random number between 1 and 10 with time as seed
	int number = rand() % 10 + 1;
	return number;

}

int main() {
  srand(time(NULL));
	sequenceGenerator();

  /*if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
    return -1;
  }
  SDL_Window* window = SDL_CreateWindow(
    "Ma Fenêtre SDL",             // Titre de la fenêtre
    SDL_WINDOWPOS_UNDEFINED,      // Position X de la fenêtre
    SDL_WINDOWPOS_UNDEFINED,      // Position Y de la fenêtre
    800,                          // Largeur de la fenêtre
    600,                          // Hauteur de la fenêtre
    SDL_WINDOW_SHOWN              // Options de la fenêtre
    );

  if (window == NULL) {
      fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
      return -1;

  }
  int quit = 0;
SDL_Event event;

while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            quit = 1;
        }
    }
}
  SDL_DestroyWindow(window);
  SDL_Quit();*/
	return 0;
}
 
