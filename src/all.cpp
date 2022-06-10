#include <iostream>
#include <random>

int intCompare(const void *p1, const void *p2)
{
    int int_a = * ( (int*) p1 );
    int int_b = * ( (int*) p2 );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}

int verif(int *tab, int temp)
{
    int tab_number[42] = {1, 2, 12, 13, 14, 15, 17, 19, 21, 23, 25, 26, 41, 43, 45, 47, 49, 51, 67, 69, 71, 73, 75, 77, 93, 95, 97, 99, 101, 103, 118, 119, 121, 123, 125, 127, 129, 130, 131, 132, 142, 143};
    int result = 1;

    for (int nb = 0; nb < 143; nb++) {
        if (temp == tab[nb])
            result = 0;
    }

    for (int nb = 0; nb < 42; nb++) {
        if (temp == tab_number[nb])
            result = 0;
    }

    return (result);
}

int *aleatoire()
{
    int MIN = 1;
    int MAX = 143;
    int tab[143] {0};

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);

    for (int n = 0, temp = 0; n < 143; ++n) {
        temp = distr(eng);
        if (verif(tab, temp) == 1)
            tab[n] = temp;
    }

    qsort(tab, 143, sizeof(int), intCompare);
    return tab;
}