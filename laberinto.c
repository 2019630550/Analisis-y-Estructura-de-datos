#include <stdio.h>

#define MAX_M 100
#define MAX_N 100

int maze[MAX_M][MAX_N];
int visited[MAX_M][MAX_N];

int m, n;

int is_valid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0;
}

int solve_maze(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        return 1;
    }

    visited[x][y] = 1;

    if (is_valid(x, y + 1) && solve_maze(x, y + 1)) {
        return 1;
    }

    if (is_valid(x + 1, y) && solve_maze(x + 1, y)) {
        return 1;
    }

    return 0;
}

int main() {
	int i, j;
    printf("Ingrese las dimensiones de la matriz (m y n): ");
    scanf("%d %d", &m, &n);

    printf("Ingrese los elementos de la matriz (0 para camino bloqueado, 1 para camino libre):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;
        }
    }

    if (solve_maze(0, 0)) {
        printf("Se puede llegar a la posición (%d,%d) desde la posición (1,1).\n", m, n);
    } else {
        printf("No se puede llegar a la posición (%d,%d) desde la posición (1,1).\n", m, n);
    }

    return 0;
}

