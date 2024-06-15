#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Número de muestras
#define NUM_SAMPLES 1000000

// Función para generar un número aleatorio entre -1 y 1
double random_double() {
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

// Función para calcular pi usando el método de Monte Carlo
double monte_carlo_pi(int num_samples) {
    int inside_circle = 0;

    for (int i = 0; i < num_samples; i++) {
        double x = random_double();
        double y = random_double();

        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }

    double pi_estimate = (double)inside_circle / num_samples * 4;
    return pi_estimate;
}

int main() {
    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    // Calcular π
    double pi_estimate = monte_carlo_pi(NUM_SAMPLES);

    // Imprimir el resultado
    printf("Estimación de π usando %d muestras: %f\n", NUM_SAMPLES, pi_estimate);

    return 0;
}
