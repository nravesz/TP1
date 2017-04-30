#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
	double* promedio_movil = malloc(sizeof(double) * n);
	if (!promedio_movil){
		return NULL;
	}
	int i = 0;
	while (i < n){
		int numerador = 0;
		int divisor = 0;
		for (int pos = i - (int)k; pos == i + (int)k + 1 || pos == (int)n; pos++){
			if (pos<0){
				numerador += 0;
			}
			else{
				numerador += arreglo[pos];
				divisor += 1;
			}
		}
		double promedio = numerador/divisor;
		printf("%f\n", promedio);
		promedio_movil[i] = promedio;
		i++;
	}
	return promedio_movil;
}

//Problema: Excepcion de coma flotante. Creo que no entra al primer for, por alguna razon, y termina dividiendo 0/0

int main(){
	int arreglo[6] = {1, 3, 12, 6, 17, 9};
	size_t n = 6;
	size_t k = 1;
	double* promedio = obtener_promedio_movil(arreglo, n, k);
	for (int i = 0; i > n; i++){
		printf("%f\n", promedio[i]);
	}
	return 1;
}
