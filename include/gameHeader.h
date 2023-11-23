#ifndef wind_H
#define wind_H


//======================//
//=hidden Number header=//
//======================//

int hiddenNumber();
int verifNumber(const char *nb);

//----------------------//

//======================//
//===Mystery Sequence===//
//======================//
int principal();
//----------------------//

//======================//
//==Master Mind Header==//
//======================//

int mastermind();
int checkPosCorrect(char *user, char *vowelListe);
int checkPosIncorrect(char *user, char *vowelListe);
char generateOneRandomVowel();
char* generateVowelList();
int verifVowel(char caracter);

//----------------------//

#endif
