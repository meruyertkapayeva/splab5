// your code goes here
// your code goes here
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int n; 
int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int a[n][n];
    int b[n][n];
    int c[n][n];

    srand(time(0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }

    printf("A:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("B:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int result=0;
            for(int k=0; k<n; k++) {
                result = result + a[i][k] * b[k][j];
            }
            c[i][j] = result;
        }
    }

    printf("C:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n;j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
