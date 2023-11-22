#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../include/gameHeader.h"

#define NB_VOYELLES (sizeof(vowel) / sizeof(char) - 1)
#define NB_ESSAIS 10
#define TEMPS_LIMITE 30

int checkPosCorrect(char *user, char *vowelListe);
int checkPosIncorrect(char *user, char *vowelListe);
char generateOneRandomVowel();
char* generateVowelList();
int verifVowel(char caracter);

int mastermind() {
    char* vowelListe = generateVowelList();
    printf("%c%c%c%c",vowelListe[0],vowelListe[1],vowelListe[2],vowelListe[3]);

    if (vowelListe == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    char essai[4];
    time_t debut = time(NULL);
    int tempsEcoule;
    int score = 0;

    // Affichage de l'instruction pour le joueur
    printf("Essayez de deviner la séquence de voyelles en majuscules!\n");

    for (int essaiCount = 1; essaiCount <= NB_ESSAIS; essaiCount++) {
        printf("\nEssai %d: Saisissez 4 voyelles en majuscules:\n", essaiCount);

        // Saisie des voyelles pour l'essai en cours
        for (int i = 0; i < 4; i++) {
            scanf(" %c", &essai[i]);

            // Vérification si la saisie est une voyelle
            while (verifVowel(essai[i]) != 0) {
                printf("Veuillez entrer une voyelle valide en majuscules.\n");
                scanf(" %c", &essai[i]);
            }
        }

        // Appel aux fonctions de vérification des positions
        int correctPos = checkPosCorrect(essai, vowelListe);
        int incorrectPos = checkPosIncorrect(essai, vowelListe);

        // Affichage du résultat de l'essai
        printf("Résultat de l'essai %d:\n%d bien placé(s),\n%d mal placé(s).\n", essaiCount, correctPos, incorrectPos);

        // Vérification si toutes les voyelles sont correctes
        if (correctPos == 4) {
            printf("Félicitations, vous avez trouvé la séquence!\n");
            // Calcul du score en fonction du temps écoulé
            tempsEcoule = difftime(time(NULL), debut);
            score = (TEMPS_LIMITE - tempsEcoule) * 10;
            if (score < 0) {
                score = 0;  // Le score ne peut pas être négatif
            }
            printf("Votre score est: %d\n", score);
            break;
        }

        // Si tous les essais sont épuisés
        if (essaiCount == NB_ESSAIS) {
            printf("Désolé, vous n'avez pas trouvé la séquence en %d essais. La séquence était: %s\n", NB_ESSAIS, vowelListe);
            // Le score est 0 car le joueur n'a pas réussi à trouver la séquence
            printf("Votre score est: 0\n");
        }

        // Vérification du temps écoulé
        tempsEcoule = difftime(time(NULL), debut);
        if (tempsEcoule >= TEMPS_LIMITE) {
            printf("Temps écoulé! Vous n'avez pas trouvé la séquence à temps. Votre score est 0.\n");
            break;
        }
    }

    // Libération de la mémoire allouée pour la liste de voyelles
    free(vowelListe);

    return 0;
}

int main()
{
    mastermind();
    return 0;
}
