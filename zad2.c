#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FIRST_EL 5
#define SECOND_EL 7

void calc_n_elements(double *src, int n) {
    double a1,a2;
    double result;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            a1 = FIRST_EL;
            a2 = SECOND_EL;
        } else if(i == 1) {
            a1 = SECOND_EL;
            a2 = src[0];
        } else {
            a1 = src[i - 2];
            a2 = src[i - 1];
        }
        result = sin(a2) + pow(a1,1./5) - 2;
        src[i] = result;
    }
}

void print_elements(double *src, int n) {
    printf("%i %i ",FIRST_EL,SECOND_EL);
    for(int i = 0; i < n; i++) {
        printf("%f ",src[i]);
    }
    printf("\n");
}

int main() {
    double *elements;
    int n;
    scanf("%i",&n);
    elements = (double *) malloc(sizeof(double)*n);
    calc_n_elements(elements,n);
    print_elements(elements,n);

    return 0;
}
