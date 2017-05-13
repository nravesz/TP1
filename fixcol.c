#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if (argc != 3){
		fprintf(stderr, "ERROR: Numero de parametros incorrecto\n");
		return 0;
	}
	FILE* archivo = fopen(argv[1], "r");
	int cant_caracter = atoi(argv[2]);
	if (!archivo){
		fprintf(stderr, "ERROR: Ha habido un problema con el archivo \"%s\"!\n", argv[1]);
		return 0;
	}
	char* linea = NULL;
	size_t capacidad = 0;
	ssize_t longitud = getline(&linea, &capacidad, archivo);
	int restantes = (int)longitud;
	int j = 0;
	while (longitud != -1){
		if (restantes > cant_caracter){ // Si la longitud es mayor que la cantidad de caracteres a imprimir
			char cadena[cant_caracter];
			for (int i = 0; i < cant_caracter; i++){
				cadena[i] = linea[j];
				j++;
				restantes--;
			}
			cadena[cant_caracter] = '\0';
			char buffer[cant_caracter];
			sprintf(buffer, "%s", cadena);
			fputs(buffer, stdout);
			fputs("\n", stdout);
		}
		else{
			char cadena[restantes];
			for (int i = 0; i < restantes; i++){
				cadena[i] = linea[j];
				j++;
			}
			cadena[restantes] = '\0';
			char buffer[restantes];
			sprintf(buffer, "%s", cadena);
			fputs(buffer, stdout);
			free(linea);
			linea = NULL;
			longitud = getline(&linea, &capacidad, archivo);
			restantes = (int)longitud;
			j = 0;
		}
	}
	free(linea);
}
