#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define NB_VOYELLES (sizeof(vowel) / sizeof(char) - 1)

int isInteger(char input[]){
    /**
     * checks whether the input character is an integer
     * parameter:
     *      - input(char): list of caracters
     * 
     * Local variables:
     *      - none
     * 
     * return:
     *      - 0 if the input character list is not a number
     *      - 1 if the imput character list is a integer
     */
     // Vérifie si la chaîne de caractères est un entier
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return 0; // The character string is not an integer
        }
    }
    return 1; // The character string is an integer
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
     *
     * parameter:
     *       -caracter (char): The caracters the player entered
     *
     * Local variables:
     *       -vowel[] (char): Count correct vowels that are well-placed
     *
     * return:
     *      - 0 if the caracter is a vowel or 1 if the caracter isn't
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

int checkPosIncorrect(char *user, char *vowelListe) {
    /**
     * Vérifie si la voyelle est correcte mais mal placée
     *
     * Paramètres :
     *       -user (char) : Les caractères que le joueur a entrés
     *       -vowelList (char) : Les caractères qui ont été générés aléatoirement
     *
     * Variables locales :
     *       -incorrectPos (int) : Compteur de voyelles correctes mais mal placées
     *       -checkedIndices[4](int) : Tableau pour garder une trace des voyelles déjà vérifiées afin d'éviter les doublons
     *
     * Retour : 
     *      -incorrectPos
     */

    // Compteur de voyelles présentes mais mal placées
    int incorrectPos = 0;

    // Initialisation du tableau de vérification des indices
    int checkedIndices[4] = {0, 0, 0, 0};

    // Comparaison des voyelles présentes mais mal placées
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && vowelListe[i] == user[j] && checkedIndices[j] == 0) {
                incorrectPos++;
                checkedIndices[j] = 1;
                break; // Sortir de la boucle interne dès qu'une correspondance est trouvée
            }
        }
    }
    return incorrectPos;
}

//========================//
//mysterySequence Function//
//========================//

int* sequenceGenerator() {
/*
 * This function allows you to create a sequence 
 * of the form Un= axU_(n-1)+b and u_(0)=c with a, b and c generated randomly.
 *
 * Parameters:
 *      - none
 *
 * Local variables:
 *      - a,b,c (int): 3 randomly generated coefficient
 *      - sequence (int*): the table which contains the terms of the sequence
 *
 * Returns:
 *      - sequence(int*):A list of 4 numbers corresponding to the first 4 terms of the sequence.
 * 
 */
  int a = randGenerator(), b = randGenerator(), c = randGenerator();
  int* sequence = (int*)malloc(4 * sizeof(int));
  sequence[0]= c;
  for (int i = 1; i <= 3; i++) {
        //calculation of the following terms of the sequence based on the randomly generated coefficient
        sequence[i] = computeNextTerm(sequence[i - 1], a, b);
    }
  return sequence;

}

int computeNextTerm(int prevTerm, int a, int b) {
/*
 * calculating the next term of the sequence
 *
 * Parameters:
 *      - prevTerm (int): the previous term of the sequence
 *      - a,b(int): the two coefficients of the sequence
 *
 * return:
 *      - the next term in the sequence
 */
  return a * prevTerm + b;

}

int randGenerator() {
/*
 * Generates a random number between 1 and 10 with time as seed
 *
 * Parameters:
 *      - none
 *
 * Local variables:
 *      - none
 *
 * Returns:
 *      - number(int): a randomly generated number between 1 and 10
 */
	int number = rand() % 10 + 1;
	return number;

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
