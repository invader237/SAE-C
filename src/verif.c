#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
  char chaine[100]; // tableau pouvant contenir 100 caractères //
  int nombre;

  printf("Entrez une chaîne de caractères : ");
  fgets(chaine, 100, stdin); // lis la chaine de caractère dans chaine //

  nombre = strtol(chaine, NULL, 10); // permet de convertir une chaîne de caractères en un nombre entier //

  printf("Le nombre est %d.\n", nombre);

  return 0;
}