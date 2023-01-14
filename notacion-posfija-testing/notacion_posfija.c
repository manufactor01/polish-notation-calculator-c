#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "notacion_posfija.h"
#include "pila.h"
#include "cola.h"

#define SUMA "+"
#define RESTA "-"
#define DIVISION "/"
#define RAIZ "sqrt"
#define OPERADOR_TERNARIO "?"
#define LOGARITMO "log"

bool raiz(int *numero_a, int *resultado) {
  if(*numero_a < 0) return false;
  *resultado = (int) sqrt(*numero_a);
  return true;
}

bool sumar(int *numero_a, int *numero_b, int *resultado) {
  *resultado = *numero_b + *numero_a;
  return true;
}

bool restar(int *numero_a, int *numero_b, int *resultado) {
  *resultado = *numero_b - *numero_a;
  return true;
}

bool dividir(int *numero_a, int *numero_b, int *resultado) {
  if(*numero_a == 0) return false;
  *resultado = *numero_b / *numero_a;
  return true;
}

bool logaritmo(int *numero_a, int *numero_b, int *resultado) {
  if(*numero_a < 2) return false;
  *resultado = (int) (log10((double) *numero_b) / log10((double) *numero_a));
  return true;
}


bool terciarizar(int *numero_a, int *numero_b, int *numero_c, int *resultado) {
  *resultado = *numero_c ? *numero_b : *numero_a;
  return true;
}

bool es_operador(char *str) {
  return !strcmp(str, SUMA) || !strcmp(str, RESTA) || !strcmp(str, DIVISION) || !strcmp(str, OPERADOR_TERNARIO) || !strcmp(str, RAIZ) || !strcmp(str, LOGARITMO);
}

bool operador_unario(pila_t *pila_numeros, bool operacion(int *, int *)) {
  int *a = (int *)pila_desapilar(pila_numeros);
  if(!a) return false;
  int *resultado = calloc(1, sizeof(int));
  if(!operacion(a, resultado)) {
    if(a) free(a);
    free(resultado);
    return false;
  }
  free(a);
  pila_apilar(pila_numeros, resultado);
  return true;
}

bool operador_binario(pila_t *pila_numeros, bool operacion(int *, int *, int *)) {
  int *a = (int *)pila_desapilar(pila_numeros);
  int *b = (int *)pila_desapilar(pila_numeros);
  if(!a || !b) {
    if(a) free(a);
    if(b) free(b);
    return false;
  }
  int *resultado = calloc(1, sizeof(int));
  if(!operacion(a, b, resultado)) {
    free(resultado);
    return false;
  }
  free(a);
  free(b);
  pila_apilar(pila_numeros, resultado);
  return true;
}

bool operador_ternario(pila_t *pila_numeros, bool operacion(int *, int *, int *, int *)) {
  int *a = (int *)pila_desapilar(pila_numeros);
  int *b = (int *)pila_desapilar(pila_numeros);
  int *c = (int *)pila_desapilar(pila_numeros);
  if(!a || !b || !c) {
    if(a) free(a);
    if(b) free(b);
    if(c) free(c);
    return false;
  }
  int *resultado = calloc(1, sizeof(int));
  if(!operacion(a, b, c, resultado)) {
    free(resultado);
    return false;
  }
  free(a);
  free(b);
  free(c);
  pila_apilar(pila_numeros, resultado);
  return true;
}

bool operar(char **strv, pila_t *pila_numeros) {
  for(size_t i = 0; strv[i]; i++) {
    if(!es_operador(strv[i])) {
      int *numero = calloc(1, sizeof(int));
      *numero = atoi(strv[i]);
      pila_apilar(pila_numeros, numero);
    } else {
      if(!strcmp(strv[i], SUMA)) {
        if(!operador_binario(pila_numeros, sumar)) return false;
      }
      if(!strcmp(strv[i], RESTA)) {
        if(!operador_binario(pila_numeros, restar)) return false;
      }
      if(!strcmp(strv[i], DIVISION)) {
        if(!operador_binario(pila_numeros, dividir)) return false;
      }
      if(!strcmp(strv[i], OPERADOR_TERNARIO)) {
        if(!operador_ternario(pila_numeros, terciarizar)) return false;
      }
      if(!strcmp(strv[i], RAIZ)) {
        if(!operador_unario(pila_numeros, raiz)) return false;
      }
      if(!strcmp(strv[i], LOGARITMO)) {
        if(!operador_binario(pila_numeros, logaritmo)) return false;
      }
    }
  }
  return true;
}

int *notacion_posfija(char **strv) {
  pila_t *pila_numeros = pila_crear();
  if(!pila_numeros) return NULL;
  int *resultado = calloc(1, sizeof(int));
  if(!resultado) return NULL;
  bool ok = operar(strv, pila_numeros);
  if(ok) {
    *resultado = *(int *) pila_ver_tope(pila_numeros);
  } else {
    free(resultado);
    resultado = NULL;
  }
  while(!pila_esta_vacia(pila_numeros)) free(pila_desapilar(pila_numeros));
  pila_destruir(pila_numeros);
  return resultado;
}
