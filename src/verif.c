#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define NB_VOYELLES (sizeof(vowel) / sizeof(char) - 1)

int verifNumber(const char *nb){
    /**
     * checks whether the input character is an integer
     * parameter:
     *      - 
     * 
     * Local variables:
     *      - 
     * 
     * return:
     */
  int test;
  char extra;

    // Tente de convertir la chaîne en un entier et vérifie si la conversion est réussie
  if (sscanf(nb, "%d%c", &test, &extra) == 1 && extra == '\0') {
      return 1;  // La chaîne est un entier
  } else {
        return 0;  // La chaîne n'est pas un entier ou contient un point flottant
  }
}


char generateOneRandomVowel() {
    /**
     * Generates one vowel wich will be reused in generateVowelList
     * parameter:
     *      - none
     * 
     * Local variables:
     *      - vowel[](char): list of the six vowels
     *      - index (int): generates a random vowel
     * 
     * return:vowel[index]
     */
    char vowel[] ="AEIOUY";
    int index = rand() % NB_VOYELLES;
    return vowel[index];
}

char* generateVowelList() {
    /**
     * Generates four vowels
     * parameter:
     *      - none
     * 
     * Local variables:
     *      - vowelListe[4](char): The caracters that were generated randomly
     * 
     * return: vowelList
     */
    srand(time(NULL));
    char* vowelListe = (char*)malloc(4 * sizeof(char)); // Ajout de l'espace pour le caractère nul
    if (vowelListe == NULL) {
        return NULL;
    }

    for (int i = 0; i <= 4; i++) {
        vowelListe[i] = generateOneRandomVowel();
    }

    // Ajout du caractère nul à la fin de la liste
    vowelListe[4] = '\0';

    return vowelListe;
}

int verifVowel(char caracter) {
    /**
     * Verify if the entry caracter is a vowel
     * parameter:
     *       -caracter (char): The caracters the player entered
     *
     * Local variables:
     *       -vowel[] (char): Count correct vowels that are well-placed
     * return: 0 if the caracter is a vowel or 1 if the caracter isn't
     */
    char vowel[] = "AEIOUY";
    for (int i = 0; i < NB_VOYELLES; i++) {
        if (caracter == vowel[i]) {
            return 0;
        }
    }
    return 1;
}

int checkPosCorrect(char *user,char *vowelListe) {

    /**
     * Checks whether the vowel is correct and well-positioned
     * parameter:
     *       -user (char): The caracters the player entered
     *       -vowelList (char): The caracters that were generated randomly
     * Local variables:
     *       -correctPos (int): Count correct vowels that are well-placed
     *
     * return: correctPos
     */

    // Compteur de voyelles correctement placées
    int correctPos = 0;

    // Comparaison des voyelles correctement placées
    for (int i = 0; i < 4; i++) {
        if (vowelListe[i] == user[i]) {
            correctPos++;
        }
    }
    return correctPos;
}

int checkPosIncorrect(char *user,char *vowelListe) {
    /**
     * Checks whether the vowel is correct but misplaced
     *
     * parameter:
     *       -user (char): The caracters the player entered
     *       -vowelList (char): The caracters that were generated randomly
     *
     * Local variables:
     *       -incorrectPos (int): Count correct vowels but misplaced
     *       -checkedIndices[4](int): Table to keep track of vowels already checked to avoid duplicates
     * 
     * return: incorrectPos
     */

    // Compteur de voyelles présentes mais mal placées
    int incorrectPos = 4;

    // Comparaison des voyelles présentes mais mal placées
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (vowelListe[i] == user[j] && i != j) {
                incorrectPos-=1;
                break; // Sortir de la boucle interne dès qu'une correspondance est trouvée
            }
        }
    }
    return incorrectPos;
}


/*int main()
{
    // Vérification de la voyelle 'E'
    verifVoyelles('E');

    // Vérification du nombre 67
    verifNumber('a');

    // Génération de 4 voyelles
    char* liste=generateVowelList();


    // Vérification de la combinaison "AEOU"
    printf("\n%d",checkPosCorrect("AEOU", liste));
    printf("\n%d",checkPosIncorrect("AEOU", liste));

}*/
