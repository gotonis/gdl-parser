#pragma once
#include <stdio.h>
#include <string.h>
#include "parser.h"
//#include <Judy.h>

//TODO: Import and test Judy arrays

//STRUCTS AND UNIONS

struct lobject {
  token * ID;
  lobject * dependencies[];
} lobj;
  
struct token{
  uint8_t* tag;
  int numDeps;
} ;
    
union utok{
  token* tok;
  Word_t * rvl;
};

//FUNCTIONS

uint8_t* getTag(token * t);
token newToken(uint8_t * t, int deps);
token * getToken(char * t, int deps, Pvoid_t ary);
lobj makeLobj(char* rel, int deps, Pvoid_t ary);
void freeLobj(lobj l, Pvoid_t ary);
  
