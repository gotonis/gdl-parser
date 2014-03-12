#include <stdio.h>
#include <string.h>
#include "token.h"

char lookahead;
char * lahead;
const int maxRSize = 32;
int main(int argc, char* argv[]);
void GetChar();
//void GetWord();
void Error(char * s);
void Expected(char * s);
void Match(char x);
char uncapitalize(char c);
int IsAlpha(char c);
int IsNum(char c);
void Emit(char * s);
void EmitLn(char * s);
void Init();
void Comment();

//added on github
lobj* parseRel();
