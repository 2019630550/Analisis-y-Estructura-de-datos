#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define NUM_POINTS 50
#define POINT_RADIUS 5

// Estructura para un punto
typedef struct {
    int x;
    int y;
} Point;

// Función para generar un punto aleatorio
Point generate_random_point() {
    Point p;
    p.x = POINT_RADIUS + rand() % (WINDOW_WIDTH - 2 * POINT_RADIUS);
    p.y = POINT_RADIUS + rand() % (WINDOW_HEIGHT - 2 * POINT_RADIUS);
    return p;
}

// Función para verificar si dos puntos se solapan
int points_overlap(Point p1, Point p2) {
    double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return distance < 2 * POINT_RADIUS;
}

// Algoritmo de Las Vegas para generar puntos sin solapamientos
void generate_points(Point *points, int num_points) {
    int count = 0;
    while (count < num_points) {
        Point point = generate_random_point();
        int overlap = 0;
        for (int i = 0; i < count; i++) {
            if (points_overlap(point, points[i])) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            points[count] = point;
            count++;
        }
    }
}

int main() {
    srand(time(NULL));  // Inicializar la semilla para números aleatorios

    Point points[NUM_POINTS];
    generate_points(points, NUM_POINTS);

    // Imprimir los puntos generados
    printf("Puntos generados:\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("Punto %d: (%d, %d)\n", i + 1, points[i].x, points[i].y);
    }

    return 0;
}
