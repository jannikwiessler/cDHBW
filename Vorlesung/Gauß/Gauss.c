#include <stdio.h>
#include <stdlib.h>

double readFile(char filename[]) {
    FILE *fPtr = fopen(filename, "r");
    double zahl;

    if(fPtr == NULL) {
        printf("Could not open file");
        return -1;
    }

    fscanf(fPtr, "%lf", &zahl);
    fclose(fPtr);

    return zahl;
}

void print_matrix(double **matrix, double *rhs, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("| %f\n", rhs[i]);
    }
}

// obere dreiecksform machen
void gaussian_elimination(double **matrix, double *rhs, int dim) {
    // i forschleife von 0 bis dim-1 wegen nur < nicht <=
    for (int i = 0; i < dim; i++) {
        // j forschleife i+1 für nächste Zeile
        for (int j = i+1; j < dim; j++) {
            /*
                1 2 3 | 6
                4 5 6 | 9
                7 8 9 | 10
                Factor im Bsp: 4/1 = 4  5/0 kaputt
            */
            double factor = matrix[j][i] / matrix[i][i];

            // hier die ganzen Spalten 0 setzten
            for (int k = i; k < dim; k++) {
                // 4         -= 4      * 1            --> 0
                matrix[j][k] -= factor * matrix[i][k];
            }

            // 9   -= 4      * 6      --> -15
            rhs[j] -= factor * rhs[i];
        }
    }
}

// nach x umstellen
void back_substitution(double **matrix, double *rhs, double *solution, int dim) {
    // i=3-1
    for (int i = dim-1; i >= 0; i--) {
        double sum = 0;

        // j=3 

            /*
                1 2 3 | 6
                0 5 6 | 9
                0 0 9 | 10
                 
            */

        for (int j = i+1; j < dim; j++) {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (rhs[i] - sum) / matrix[i][i];
    }
}

void readMatrix(int dim, double **matrix) {
    FILE *fPtr = fopen("matrix_large.txt", "r");

    for (int i = 0; i < dim; i++) {
        matrix[i] = (double *) malloc(dim * sizeof(double));
        for (int j = 0; j < dim; j++) {
            fscanf(fPtr, "%lf\n", &matrix[i][j]);
        }
    }

    fclose(fPtr);
}

void readRHS(int dim, double *rhs) {
    FILE *fPtr = fopen("rhs_large.txt", "r");

    for (int i = 0; i < dim; i++) {
        fscanf(fPtr, "%lf\n", &rhs[i]);
    }

    fclose(fPtr);
}

int main() {
    double **matrix, *rhs, *solution;
    int dim = readFile("dim_large.txt");

    matrix = (double **) malloc(dim * sizeof(double *));
    rhs = (double *) malloc(dim * sizeof(double));
    solution = (double *) malloc(dim * sizeof(double));

    readMatrix(dim, matrix);
    readRHS(dim, rhs);

    //printf("\nOriginal system:\n");
    //print_matrix(matrix, rhs, dim);
    gaussian_elimination(matrix, rhs, dim);

    //printf("\nUpper triangular system:\n");
    //print_matrix(matrix, rhs, dim);

    back_substitution(matrix, rhs, solution, dim);


    printf("\nSolution:\n");
    for (int i = 0; i < dim; i++) {
        printf("%f\n", solution[i]);
    }
    
    return 0;
}