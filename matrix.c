#include <stdio.h>

#define SIZE 5


void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int addResult[SIZE][SIZE]) {
    // going through two for loops to extract elements in rows and columns
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // adding elements
            addResult[i][j] = m1[i][j] + m2[i][j];
        }
    }
    
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // output matrix
            result[i][j] = 0;

            for (int k = 0; k < SIZE; k++) {
                // multiply row m1, column m2
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // swapping rows and columns for transpose
            result[j][i] = matrix[i][j];
        }
    }
}


void printMatrix(int matrix[SIZE][SIZE]) {
    // going through two for loops for i and j - iterating throught the rows and columns
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // displaying matrix with width 4, for better alignment and display
            printf("%4d ", matrix[i][j]);
        }
        // creating new line after each row
        printf("\n");
    }
}




int main() {

    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // matrix to store addition matrix
    int addResult[SIZE][SIZE];
    // matrix to store multiplication matrix
    int multResult[SIZE][SIZE];
    // matrix to store transpose matrix
    int tranResult[SIZE][SIZE];


    // adding matrices m1 and m2
    addMatrices(m1, m2, addResult);
    printf("Matrices m1 and m2 added together\n");
    printMatrix(addResult);
    printf("\n");
    printf("\n");

    // mulitplying matrices m1 and m2
    multiplyMatrices(m1, m2, multResult);
    printf("Matrices m1 and m2 multiplied together\n");
    printMatrix(multResult);
    printf("\n");
    printf("\n");

    // transpose of matrix 1
    transposeMatrix(m1, tranResult);
    printf("Displaying the transpose of Matrix m1\n");
    printMatrix(tranResult);
    printf("\n");
    printf("\n");

    // simply printing matrix 1
    printf("Displaying Matrix m1 with no changes\n");
    printMatrix(m1);
    printf("\n");

    return 0;
}