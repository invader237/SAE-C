#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define NB_VOYELLES (sizeof(vowel) / sizeof(char) - 1)

int verifNumber(double d)
{
    if (d == floor(d))
        puts("Entier");
    else
        puts("Flottant");

    return 0;
}

char generateOneRandomVowel() {
    char vowel[] ="AEIOUY";
    int index = rand() % NB_VOYELLES;
    return vowel[index];
}

char* generateVowelList() {
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
    char vowel[] = "AEIOUY";
    for (int i = 0; i < NB_VOYELLES; i++) {
        if (caracter == vowel[i]) {
            return 0;
        }
    }
    return 1;
}

int checkPosCorrect(char *user,char *vowelListe) {
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