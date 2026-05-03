/* Multiplying 2-D matrices */

#include <stdio.h>

void print_matrice(int arr[][99], int rows, int cols);

int main() {
    int n, m; //store the size of a
    printf("Enter the number of rows and columns for matrix a: ");
    /* TODO: read the size of a */
    
    scanf("%i %i", &n, &m);

    int p, q; //store the size of b
    printf("Enter the number of rows and columns for matrix b: ");
    /* TODO: read the size of b */
    
    scanf("%i %i",&p, &q);

    int a[n][m], b[p][q], c[n][q]; //declaring 3 matrices, automatically declares size a n by q, appropriately.

    /* TODO: if the sizes are compatible, read a and b from the user, multiply them and store the result in c, and print all three matrices.
             if the sizes are not compatible, print an error and exit the program. Return -1. 
             your output format must match the sample output shown in the pdf. */

    // sizes are compatible if m == p

    if (m != p) {
        printf("The given matrix sizes are not compatible!");
        return 0;
    }

    // implict else via return 0 earlier in if conditional.

    // get matrix input

    printf("Enter %d values for matrix a: ",n*m);
    
    
    int input, j = 0; // input is uninitialized, j = 0;
    while (scanf("%i", &input) == 1 &&  j < (n*m - 1)) {
        a[j/m][j%m] = input;
         //printf("a[%d][%d] = %d",j/m,j%m,input);
        j++;
    }
    
    a[j/m][j%m] = input;
    

    printf("Enter %d values for matrix b: ",p*q);
    
    
    int input2, j2 = 0; // input2 is uninitialized, j2 = 0;
    while (scanf("%i", &input2) == 1 && j2 < (p * q - 1)) {
        b[j2/q][j2%q] = input2;
        j2++;
    }


    b[j2/q][j2%q] = input2;


    // display matrices

    printf("Matrix a:\n");


    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            printf("%d ",a[r][c]);
        }
        printf("\n");
    }


    printf("Matrix b:\n");


    for (int r = 0; r < p; r++) {
        for (int c = 0; c < q; c++) {
            printf("%d ",b[r][c]);
        }
        printf("\n");
    }





    // now actually mutliply them
    
    for (int rows1 = 0; rows1 < n; rows1++) {
        // multiply matrice: 1x3 3x1 (conceptual example (not in code) from Organic Chemistry Tutor),
        // then replace [0] with index [rows1] for each row.
        for (int cols2= 0; cols2 < q; cols2++) {
            c[rows1][cols2] = 0;
            for (int cols1 = 0; cols1 < m; cols1++) {
                c[rows1][cols2] += a[rows1][cols1] * b[cols1][cols2];
            }
        }
    }
    // display them

        printf("Matrix c:\n");


    for (int r = 0; r < n; r++) {
        for (int z = 0; z < q; z++) {
            printf("%d ",c[r][z]);
        }
        printf("\n");
    }



    return 0;
}
