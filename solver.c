#include "header.h"

static double *create_minor(int n, int i, double *arr)
{
    double *new_arr;
    int j_n = 0;
    
    if (!(new_arr = (double *)malloc(sizeof(double) * (n - 1) * (n - 1))))
    {
        printf("Ошибка аллоцирования памяти.\n");
        exit(0);
    }
    for (int j = 0; j < n * n; j++)
    {
        if (j % n == i || j / n == 0)
            continue;
        *(new_arr + j_n) = *(arr + j);
        j_n++;
    }
    return new_arr;
    
}

static void print_minor(double *arr, int n)
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

double determinant(double *arr, int n)
{
    double *minor, det = 0;
    
    if (n == 1)
    {
        printf("%f\n", *arr);
        for (int i = 0; i < (2 * n - 1) * 8; i++)
            printf("=");
        printf("\n");
        return (*arr);
    }
    for (int i = 0; i < n; i++)
    {
        minor = create_minor(n, i, arr);
        if (n > 2)
            print_minor(minor, n - 1);
        det += ((i % 2) ? -1 : 1) * *(arr + i) * determinant(minor, n - 1);
        free(minor);
    }
    return (det);
}