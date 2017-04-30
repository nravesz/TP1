#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, char sep){
	/* Cuento la cantidad de separadores */
	int cant = 0;
	for (int k = 0; str[k] != '\0'; k++){
		if (str[k] == sep){
			cant++;
		}
	}
	
	/* Pido memoria para el array */
	char** strv = malloc(sizeof(char*) * (cant + 2));
	int i = 0;
	int pos = 0;
	
	/* Separo las palabras */
	while (str[i] != '\0'){
		printf("[hola]\n");
		char* cadena;
		for (int j = 0; str[i] != sep || str[i] == '\0'; j++, i++){
			cadena[j] = str[i];
		}
		strv[pos] = strdup(cadena);
		printf("[%s]\n", cadena);
		cadena = "";
		pos++;
	}
	strv[pos] = NULL;
	return strv;
}

int main(){
	char cadena[30] = "abc,def,ghi\0";
	char* str = strdup(cadena);
	char** arreglo = split(str, ',');
	if (arreglo){
		for (int i = 0; arreglo[i] != NULL; i++){
			printf("[%s]\n", arreglo[i]);
		}
	}
	free(arreglo);
}
