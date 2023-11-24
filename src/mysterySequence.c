#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/windowHeader.h"
#include "../include/gameHeader.h"


int mysterySequence() {

  time_t startTime, currentTime;
  char texte[1000];
  double deltaTime = 0.0;
  srand(time(NULL));
  int* sequence = sequenceGenerator();
  time(&startTime);
  printf("\n ███╗   ███╗██╗   ██╗███████╗████████╗███████╗██████╗ ██╗   ██╗    ███████╗███████╗ ██████╗ ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗\n ████╗ ████║╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗╚██╗ ██╔╝    ██╔════╝██╔════╝██╔═══██╗██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝\n ██╔████╔██║ ╚████╔╝ ███████╗   ██║   █████╗  ██████╔╝ ╚████╔╝     ███████╗█████╗  ██║   ██║██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  \n ██║╚██╔╝██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗  ╚██╔╝      ╚════██║██╔══╝  ██║▄▄ ██║██║   ██║██╔══╝  ██║╚██╗██║██║     ██╔══╝  \n ██║ ╚═╝ ██║   ██║   ███████║   ██║   ███████╗██║  ██║   ██║       ███████║███████╗╚██████╔╝╚██████╔╝███████╗██║ ╚████║╚██████╗███████╗\n ╚═╝     ╚═╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝   ╚═╝       ╚══════╝╚══════╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝\n");
  while (1) {
        time(&currentTime);
        double deltaTime = difftime(currentTime, startTime);
        printf("\nPremier terme: %d \nDeuxième terme: %d \nTroisième terme: %d\n",
            sequence[0],sequence[1],sequence[2]);

        if (deltaTime >= 30.0) {
            printf("Le temps est écoulé ! La reponse était :%d \nFin du jeu.\n", sequence[3]);
            break;  // Sortir de la boucle après 30 secondes
        }

        printf("\nTemps restant : %.0f secondes\n", 30.0 - deltaTime);

        // Permettre aux joueurs d'entrer du texte
        char input[100];
        printf("\nEntrez un entier :");

        scanf("%s", input);
        int isInt = isInteger(input);

        while(!isInt==1) {
          printf("\nEntrez un entier :");
          scanf("%s", input);
          isInt = isInteger(input);
        }

        if (atoi(input) == sequence[3]) {
          printf("\nWin           score:%d\n", 30-deltaTime);
          break;
        }
        else {
          printf("\nReponse fausse\n");
        }
    }
  writeIfGreater(2,30-deltaTime);
  mainMenue();
	return 0;
}

/*int main () {
  mysterySequence();
  return 0;
}*/
