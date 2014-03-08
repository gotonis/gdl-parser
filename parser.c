#include <stdio.h>
#include "parser.h"
#include <string.h>

FILE * inFile;
FILE * outFile;
const char TAB = 9;
char lookahead;
char * lahead;
int nParens = 0;

/*int main(int argc, char* argv[]){
  if(argc < 2)
    Error("Needs input and output files\n");
  printf("file 1 = %s\n", argv[1]);
  printf("file 2 = %s\n", argv[2]);
  inFile = fopen(argv[1],"r");
  outFile = fopen(argv[2],"w");
  GetChar();
  Expression();
  fclose(inFile);
  fclose(outFile);
  return 0;
}
*/
void GetChar(){
  lookahead = getc(inFile);
}

/*
void GetWord(){
  lahead = (char*)calloc(32,sizeof(char));
  while(lookahead != ' ' &&
	lookahead != '\n' &&
	lookahead != ')' &&
	lookahead != '('){
    char temp[];
    temp[0] = lookahead;
    strcat(lahead,temp);
    GetChar();
  }
  while(lookahead == ' ' || lookahead == '\n')
    GetChar();
}
*/

void Error(char * s){
  printf("\n Error:%s.\n", s);
  abort();
}

void Expected(char * s){
  char ermsg[128] = "expected ";
  Error(strcat(ermsg,s));
}

void Match(char x){
  if(lookahead==x)
    GetChar();
  else
    Expected(&x);
}
char uncapitalize(char c){
  char ch2 = c;
  if(c >= 'A' && c <= 'Z')
    ch2 -= ('A' -'a');
  
  return ch2;
}

int IsAlpha(char c){
  c = uncapitalize(c);
  return (('a' <= c)&&('z' >= c));
}

int IsNum(char c){
  return (('0' <= c)&&('9' >= c));
}

void Emit(char * s){
  fprintf(outFile,s);
}

void EmitLn(char * s){
  fprintf(outFile,"%s\n",s);
}

void Init(){
  GetChar();
}

void Comment(){
  while(lookahead != '\n')
    GetChar();
}
