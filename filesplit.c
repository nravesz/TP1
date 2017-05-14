#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generar_nombre(char *argv[], int contador);

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
	int contador  = 0;
	int n_archivo = 1;
	while (!feof(archivo)){
		char* nombre = generar_nombre(argv, n_archivo);
		FILE* nuevo = fopen(nombre,"w");
		free(nombre);
		int c;
		while ((c = fgetc(archivo)) != EOF){
			if (c == '\n'){
				fputs(" ", nuevo);
			}
			else{
				char buffer[1];
				sprintf(buffer, "%c", c);
				fputs(buffer, nuevo);
			}
			contador++;
			if (contador > cant_caracter){
				fputs("\0", nuevo);
				contador = 0;
				break;
			}
		}
		fclose(nuevo);
		n_archivo++;
	}
	fclose(archivo);
	return 1;
}

char* generar_nombre(char *argv[], int contador){
	char* nombre = malloc(sizeof(char));
	if (contador >= 1000){
		sprintf(nombre, "%s_%i.txt", argv[1], contador);
	}
	else if (contador >= 100){
		sprintf(nombre, "%s_0%i.txt", argv[1], contador);
	}
	else if (contador >= 10){
		sprintf(nombre, "%s_00%i.txt", argv[1], contador);
	}
	else{
		sprintf(nombre, "%s_000%i.txt", argv[1], contador);
	}
	return nombre;
}
