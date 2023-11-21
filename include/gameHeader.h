#ifndef wind_H
#define wind_H


//======================//
//=hidden Number header=//
//======================//

int hiddenNumber();
int verifNumber(double d);

//----------------------//

//======================//
//===Mystery Sequence===//
//======================//

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
