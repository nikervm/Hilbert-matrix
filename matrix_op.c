#include "header.h"

static void fill_matrix(double *arr, int n)
{
    for (int i = 0; i < n * n; i++)
        *(arr + i) = (double)1 / ((i / n + 1) + (i % n + 1) - 1);
}

static void print_matrix(double *arr, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        printf("%f", *(arr + i));
        if (!((i + 1) % n))
            printf("\n");
        else
            printf("\t");
    }
    for (int i = 0; i < (2 * n - 1) * 8; i++)
        printf("=");
    printf("\n");
}

void create_and_calc(char *s)
{
    double *matrix;
    int rank;
    
    if (!(rank = atoi(s)))
    {
        printf("Невалидный аргумент.\n");
        return;
    }
    if (!(matrix = (double *)malloc(sizeof(double) * rank * rank)))
    {
        printf("Ошибка аллоцирования памяти.\n");
        return;
    }
    if (rank == 1)
    {
        printf("Детерминант = %f.20\n", 1.0);
        free(matrix);
        return;
    }
    else
    {
        fill_matrix(matrix, rank);
        print_matrix(matrix, rank);
    }
    printf("Детерминант = %.20f\n", determinant(matrix, rank));
    free(matrix);
}
