#include <stdio.h>
#include <string.h>

char lookahead;
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
