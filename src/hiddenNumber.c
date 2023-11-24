#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/gameHeader.h"

int hiddenNumber()
{
    srand(time(NULL));
    int i = 0;
    int nb_hidden = rand() % 1000 + 1;
    char input[10]; // Utiliser une chaîne de caractères pour stocker l'entrée de l'utilisateur
    printf("\n ██╗  ██╗██╗██████╗ ██████╗ ███████╗███╗   ██╗    ███╗   ██╗██╗   ██╗███╗   ███╗██████╗ ███████╗██████╗\n ██║  ██║██║██╔══██╗██╔══██╗██╔════╝████╗  ██║    ████╗  ██║██║   ██║████╗ ████║██╔══██╗██╔════╝██╔══██╗\n ███████║██║██║  ██║██║  ██║█████╗  ██╔██╗ ██║    ██╔██╗ ██║██║   ██║██╔████╔██║██████╔╝█████╗  ██████╔╝\n ██╔══██║██║██║  ██║██║  ██║██╔══╝  ██║╚██╗██║    ██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██╗██╔══╝  ██╔══██╗\n ██║  ██║██║██████╔╝██████╔╝███████╗██║ ╚████║    ██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██████╔╝███████╗██║  ██║\n ╚═╝  ╚═╝╚═╝╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝    ╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝\n");
    printf("Devinez un nombre entre 1 et 1000\n");

    do
    {
        printf("Entrez un nombre : ");
        scanf("%s", input);

        if (!isInteger(input))
        {
            printf("Veuillez entrer un nombre entier.\n");
        }
        else
        {
            int nb = atoi(input);

            if (nb > 1000 || nb < 1)
            {
                printf("Le nombre doit être entre 1 et 1000\n");
                return 1; // Quitter le programme en cas d'erreur
            }

            if (nb > nb_hidden)
            {
                printf("Le nombre choisi est trop grand\n");
            }
            else if (nb < nb_hidden)
            {
                printf("Le nombre choisi est trop petit\n");
            }

            i++;
            printf("Nombre d'essais restants : %d\n", 10 - i);
        }
    } while (i < 10 && atoi(input) != nb_hidden);

    printf("\033[H\033[J");

    if (atoi(input) == nb_hidden)
    {
        printf("Bravo, vous avez trouvé le nombre caché : %d\n", nb_hidden);
        printf("Votre score est de %d essais\n", i);
    }
    else
    {
        printf("Désolé, vous n'avez pas trouvé le nombre caché. Le nombre était : %d\n", nb_hidden);
        printf("Votre score est de 11\n");
    }

    return 0;
}
