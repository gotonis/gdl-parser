#pragma once
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "token.h"
//#include <Judy.h>

string getTag(token * t){
  return t->tag;
}

token newToken(uint8_t* t, int deps){
  token retval;
  retval.ID = t;
  retval.numDeps = deps;
  return retval;
}


token * getToken(char * t, int deps, Pvoid_t ary){
  uint8_t * index = (uint8_t)t;
  utok pv;
  JSLG(pv.rvl, ary, index);
  if(utok.rvl == NULL){
    pv.tok = newToken(index, deps);
    JSLI(pv.rvl, ary, index);
  }
  return pv.tok;
}

lobj makeLobj(char* rel, int deps, Pvoid_t ary){
  token * id = getToken(rel, deps, ary);
  lobj retval;
  retval.ID = id;
  dependencies = calloc(deps, sizeof(lobject*));
  return retval;
}

void freeLobj(lobj l, Pvoid_t ary){
  uint8_t * index = l.ID->tag;
  JLSD(1,ary, index);
  free(l.dependencies);
}
