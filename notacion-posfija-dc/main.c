#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "strutil.h"
#include "notacion_posfija.h"

char *str_crear(char *linea, size_t capacidad){
	char *str = malloc(capacidad * sizeof(char));
	if(!str) return NULL;
	strtok(linea, "\n");
	strcpy(str, linea);
	return str;
}

int main(int argc, const char *argv[]){
	if(argc != 1){
		fprintf(stderr, "%s\n", "Cantidad de parametros erronea");
		return 1;
	}

	char *linea = NULL;
	size_t capacidad;
	ssize_t leidos;
	while((leidos = getline(&linea, &capacidad, stdin )) != -1) {
		char *str = str_crear(linea, capacidad);
    char **strv = split(str, ' ');
    int *resultado = notacion_posfija(strv);
    if(!resultado) {
      fprintf(stderr, "ERROR\n");
    } else {
      fprintf(stdout, "%d\n", *resultado);
    }
    free(resultado);
    free_strv(strv);
		free(str);
	}
	free(linea);
	return 0;
}
