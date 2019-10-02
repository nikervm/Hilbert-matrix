#include "header.h"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        printf("Отсутствуют аргументы.\n");
        return 0;
    }
    for (int i = 1; i < ac; i++)
        create_and_calc(av[i]);
    return 0;
}