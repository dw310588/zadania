#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define FIRST_EL 5
#define SECOND_EL 7

typedef struct Result {
    double min;
    int min_idx;
    double avg;
} Result;

Result calc_n_elements(double *src, int n) {
    double a1,a2;
    double result;
    double sum = 0;
    int min = INT_MAX;
    int min_idx = 0;
    int i;
    for(i = 0; i < n; i++) {
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
        sum += result;
        if(min > result) {
            min = result;
            min_idx = i;
        }
    }
    double avg = sum / i;
    Result res = { .min = min, .min_idx = min_idx, .avg = avg };
    return res;
}

void save(Result *res, const char *filename) {
    FILE *fptr = fopen(filename, "w");
    fprintf(fptr,"Min -> %f\n",res->min);
    fprintf(fptr,"Min index -> %i\n",res->min_idx);
    fprintf(fptr,"Avg -> %f\n",res->avg);
    fclose(fptr);
}

int main() {
    double *elements;
    int n;
    scanf("%i",&n);
    elements = (double *) malloc(sizeof(double)*n);
    Result res = calc_n_elements(elements,n);
    save(&res,"dane.txt");

    return 0;
}
