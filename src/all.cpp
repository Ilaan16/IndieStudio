#include <iostream>
#include <random>

int verif(std::vector <int> tab, int temp)
{
    std::vector<int> number {1, 2, 12, 13, 14, 15, 17, 19, 21, 23, 25, 26, 41, 43, 45, 47, 49, 51, 67, 69, 71, 73, 75, 77, 93, 95, 97, 99, 101, 103, 118, 119, 121, 123, 125, 127, 129, 130, 131, 132, 142, 143};
    int result = 1;

    for (int nb = 0; nb < 143; nb++) {
        if (temp == tab[nb])
            result = 0;
    }

    for (int nb = 0; nb < 42; nb++) {
        if (temp == number[nb])
            result = 0;
    }

    return (result);
}

std::vector <int> aleatoire()
{
    std::vector<int> tab(143, 0);
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(1, 143);

    for (int n = 0, temp = 0; n < 143; n++) {
        temp = (distr(eng));
        if (verif(tab, temp) == 1)
            tab[n] = temp;
    }

    return tab;
}