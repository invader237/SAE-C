#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../include/gameHeader.h"

int hiddenNumber()
{
    srand(time(NULL));
    int i = 0;
    int nb_hidden = rand() % 1000 + 1;
    int nb;

    printf("Devinez un nombre entre 1 et 1000\n");
    scanf("%d", &nb);

    if (nb > 1000 || nb < 1)
    {
        printf("Le nombre doit être entre 1 et 1000\n");
        return 1; // Quitter le programme en cas d'erreur
    }
    while (nb != nb_hidden && i < 10)
    {
        if (nb > nb_hidden)
        {
            printf("Le nombre choisi est trop grand\n");
        }
        else
        {
            printf("Le nombre choisi est trop petit\n");
        }

        i++; // Utilisez simplement i++ pour augmenter la valeur de i
        printf("Nombre d'essais restants : %d\n", 10 - i);

        if (i < 10) // Ajout de cette condition pour éviter de demander une saisie supplémentaire après 10 essais
        {
            printf("Entrez un nouveau nombre : ");
            scanf("%d", &nb);
        }
    printf("\033[H\033[J");
    }

    if (nb == nb_hidden)
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

int main()
{
    hiddenNumber();
    return 0;
}