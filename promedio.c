#include <stdio.h>
#include "cola.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
	double* promedio_movil = malloc(sizeof(double) * n);
	if (!promedio_movil){
		return NULL;
	}
	cola_t* cola_arreglo = cola_crear();
	cola_t* cola1 = cola_crear();
	cola_t* cola2 = cola_crear();
	
	// Lleno la cola con los elementos del arreglo
	int i = 0;
	while (i < n){
		cola_encolar(cola_arreglo, &arreglo[i]);
		i++;
	}
	
	// Desencolo k elementos de la cola_arreglo y los encolo en la cola1
	int cant_cola1 = 0;
	while (cant_cola1 < k){
		int elem = *((int *)cola_desencolar(cola_arreglo));
		cola_encolar(cola1, &elem);
		cant_cola1++;
	}
	
	// Comienzo a guardar el promedio en promedio_movil
	int max = ((int)k * 2) + 1; // Capacidad maxima que tiene permitido tener cola1
	int pos = 0;
	while (pos < n){
		// Casos en los cuales se debe encolar/desencolar
		if (!cola_esta_vacia(cola_arreglo) && cant_cola1 < max){
			int elem = *((int *)cola_desencolar(cola_arreglo));
			cola_encolar(cola1, &elem);
			cant_cola1++;
		}
		else if (!cola_esta_vacia(cola_arreglo) && cant_cola1 == max){
			int elem = *((int *)cola_desencolar(cola_arreglo));
			cola_encolar(cola1, &elem);
			cola_desencolar(cola1);
		}
		else{
			cola_desencolar(cola1);
		}
		// Calculo del promedio
		int numerador = 0;
		int divisor = 0;
		while (!cola_esta_vacia(cola1)){
			int n = *((int *)cola_desencolar(cola1));
			printf("%i", n);
			numerador += n;
			divisor += 1;
			cola_encolar(cola2, &n);
		}
		while (!cola_esta_vacia(cola2)){
			int n = *((int *)cola_desencolar(cola2));
			cola_encolar(cola1, &n);
		}
		double promedio = (double)numerador/(double)divisor;
		promedio_movil[pos] = promedio;
		printf("Numerador = %i\nDenominador = %i", numerador, divisor);
		printf("Promedio: %f\n", promedio);
		printf("\n");
		pos++;
	}
	return promedio_movil;
}

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
