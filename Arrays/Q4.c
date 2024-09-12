#include <stdio.h>
#include <stdlib.h>

void input_matrix(int **matrix, int n)
{
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int **matrix, int n)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void solve(int **arr, int n)
{
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[i][n - 1 - j];
            arr[i][n - 1 - j] = temp;
        }
    }
}

int main()
{
    int n = 3;
    int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    input_matrix(matrix, n);
    print_matrix(matrix, n);
    solve(matrix, n);
    print_matrix(matrix, n);
}