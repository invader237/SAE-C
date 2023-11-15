#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../bin/verif"
int main(int nb)
{
    srand(time(NULL));
    int i=0;
    int nb_hidden = rand();
    printf("donnez un nombre entre 1 et 1000\n");
    scanf("%d",&nb);
    scanf()
    if (nb>=1000 || nb<=1)
        printf("Donnez un nombre entre 1 et 1000\n");
    while (nb!=nb_hidden && i<=10);
    {   
        printf("blabla");
        if (nb>nb_hidden)
        {
            printf("le nombre choisit est plus petit");
        }
        else
        {   
            printf("le nombre choisit est plus grand");
        }
        i=i++;
    printf("Nombre d'essais restants : %d\n", 10 - i);
    scanf("%d",&nb);
    }
}

int randGenerator() {

    // generates a random number between 1 and 10 with time as seed //
	int number = rand() % 1000 + 1;
	return number;
}