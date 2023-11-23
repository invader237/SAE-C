#include <stdio.h>

void writeIfGreater(int gameNumber, int newScore) {
    FILE *file = fopen("score.txt", "r");
    
    if (file == NULL) {
        // Le fichier n'existe pas, créer le fichier et écrire la nouvelle valeur
        file = fopen("score.txt", "w");
        if (file != NULL) {
            fprintf(file, "%d\n", newScore);
            fclose(file);
            printf("Nouveau score pour le jeu %d écrit dans le fichier.\n", gameNumber);
        } else {
            printf("Erreur lors de l'ouverture du fichier en mode écriture.\n");
        }
    } else {
        // Le fichier existe, lire les scores actuels
        int currentScores[3];  // Supposons que nous ayons trois jeux
        for (int i = 0; i < 3; i++) {
            fscanf(file, "%d", &currentScores[i]);
        }
        fclose(file);

        // Comparer avec la nouvelle valeur
        if (newScore > currentScores[gameNumber - 1]) {
            // La nouvelle valeur est meilleure, ouvrir le fichier en mode écriture et écrire la nouvelle valeur
            file = fopen("score.txt", "w");
            if (file != NULL) {
                currentScores[gameNumber - 1] = newScore;
                for (int i = 0; i < 3; i++) {
                    fprintf(file, "%d\n", currentScores[i]);
                }
                fclose(file);
                printf("Nouveau score plus élevé pour le jeu %d écrit dans le fichier.\n", gameNumber);
            } else {
                printf("Erreur lors de l'ouverture du fichier en mode écriture.\n");
            }
        } else {
            printf("Le nouveau score pour le jeu %d n'est pas plus élevé que le score actuel dans le fichier.\n", gameNumber);
        }
    }
}



