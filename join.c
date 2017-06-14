#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* join(char** strv, char sep){
	if (!sep){
		return NULL;
	}
	// Cuento la cantidad de caracteres
	int cant = 0;
	int i = 0;
	while (strv[i] != NULL){
		cant += (int)strlen(strv[i]) + 1;
		i++;
	}
	// Pido memoria para la cadena
	char* cadena = malloc(sizeof(char) * (cant + i + 1));
	
	//Agrupo las palabras
	int j = 0;
	int bytes = 0;
	while (strv[j]){
		memcpy(cadena + bytes, strv[j], strlen(strv[j]) + 1);
		bytes += (int)strlen(strv[j]);
		if (j < i - 1){
			memcpy(cadena + bytes, &sep, 1);
			bytes += 1;
		}
		j++;
	}
	cadena[strlen(cadena)] = '\0';
	return cadena;
}
