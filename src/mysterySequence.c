#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/windowHeader.h"
#include "../include/gameHeader.h"

int randGenerator();
int* sequenceGenerator();
int computeNextTerm();
int principal();



int* sequenceGenerator() {
  /*
 * This function allows you to create a sequence 
 * of the form Un= axU_(n-1)+b and u_(0)=c with a, b and c generated randomly
 *
 * Parameters:
 * - none
 *
 * Returns:
 * 
 */
  int a = randGenerator(), b = randGenerator(), c = randGenerator();
  int* sequence = (int*)malloc(4 * sizeof(int));
  sequence[0]= c;
  for (int i = 1; i <= 3; i++) {
        //calculation of the following terms of the sequence based on the randomly generated terms
        sequence[i] = computeNextTerm(sequence[i - 1], a, b);
    }
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

int mysterySequence() {

  time_t startTime, currentTime;
  char texte[1000];
  double deltaTime = 0.0;
  srand(time(NULL));
  int* sequence = sequenceGenerator();
  time(&startTime);

  while (1) {
        time(&currentTime);
        double deltaTime = difftime(currentTime, startTime);
        printf("\nPremier terme: %d \nDeuxième terme: %d \nTroisième terme: %d\n %d \n",
            sequence[0],sequence[1],sequence[2], sequence[3]);

        if (deltaTime >= 30.0) {
            printf("Le temps est écoulé ! La reponse était :%d\n Fin du jeu.\n", sequence[3]);
            break;  // Sortir de la boucle après 30 secondes
        }

        printf("Temps restant : %.0f secondes\n", 30.0 - deltaTime);

        // Permettre aux joueurs d'entrer du texte
        char input[100];
        printf("\nEntrez un entier :");

        scanf("%s", input);
        int isInt = verifNumber(input);

        while(!isInt==1) {
          printf("\nEntrez un entier :");
          scanf("%s", input);
          isInt = verifNumber(input);
        }

        if (atoi(input) == sequence[3]) {
          printf("\nWin\n");
          break;
        }
        else {
          printf("\nreponse fausse\n");
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
