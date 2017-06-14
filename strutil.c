#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* *****************************************************************
 *                    			SPLIT
 * *****************************************************************/

#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(const char* str, char sep, int pos){
	int tamanio = 0;
	for (int i = 0; str[i] != '\0' && str[i] != sep; i++){
		tamanio++;
	}
	return tamanio;
}

char** split(const char* str, char sep){
	if (!sep){
		return NULL;
	}

	// Cuento la cantidad de separadores
	int cant = 0;
	for (int k = 0; str[k] != '\0'; k++){
		if (str[k] == sep){
			cant++;
		}
	}

	// Pido memoria para el array
	char** strv = malloc(sizeof(char*) * (cant + 2));
	int i = 0;
	int pos = 0;
	int total = 0;

	// Separo las palabras
	while (total != cant + 1){
		int tamanio = len(str, sep, i);
		i += tamanio + 1;
		char* cadena = malloc(sizeof(char) * tamanio + 1);
		if (!cadena){
			for (int j = 0; j != total; j++){
				free(strv[j]);
			}
			free(strv);
		}
		memcpy(cadena, str, tamanio);
		cadena[tamanio] = '\0';
		strv[pos] = cadena;
		pos++;
		total++;
		str += tamanio + 1;
	}
	
	strv[pos] = NULL;
	return strv;
}


/* *****************************************************************
 *                    			JOIN
 * *****************************************************************/
 
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
		if (j< i - 1){
			memcpy(cadena + bytes, &sep, 1);
			bytes += 1;
		}
		j++;
	}
	cadena[strlen(cadena)] = '\0';
	return cadena;
}

/* *****************************************************************
 *                    		 FREE STRV
 * *****************************************************************/

void free_strv(char *strv[]){
	int i = 0;
	while(strv[i] != NULL){
		free(strv[i]);
		i++;
	}
	free(strv);
}
