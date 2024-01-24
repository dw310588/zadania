#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int **mat, int n) {
    for(int i = 0; i < n; i++) {
        mat[i] = (int *) malloc(sizeof(int *) * n);
        for(int j = 0; j < n; j++) {
            mat[i][j] = 5;
        }
    }
}

void print_matrix(int **mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%i ",mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **p;
    int n;
    scanf("%i",&n);
    p = (int **) malloc(sizeof(int *) * n);
    fill_matrix(p,n);
    print_matrix(p,n);
    return 0;
}
