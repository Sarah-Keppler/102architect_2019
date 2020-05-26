/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** Do you want to do an architect software ? Yes you want !
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

typedef struct {
    float matrice[3][3];
} matrice_t;

void Multiplication_matrice33(matrice_t *m, float matrice2[3][3])
{
    float res = 0;
    matrice_t current;

    for (int l = 0; 3 > l; ++l) {
        for (int c = 0; 3 > c; ++c) {
            for (int p = 0; 3 > p; ++p)
                res += m->matrice[l][p] * matrice2[p][c];
            current.matrice[l][c] = res;
            res = 0;
        }
    }
    for (int l = 0; l < 3; ++l)
        for (int c = 0; c < 3; ++c)
            m->matrice[l][c] = current.matrice[l][c];
}

void Multiplication_matrice31(float matrice1[3][3], float matrice2[3], matrice_t *m)
{
    float res = 0;

    for (int l = 0; 3 > l; ++l) {
        for (int c = 0; 3 > c; ++c) {
            for (int p = 0; 3 > p; ++p) {
                res += matrice1[l][p] * matrice2[p];
            }
            m->matrice[l][c] = res;
            res = 0;
        }
    }
    m->matrice[0][0] = matrice1[0][0];
    m->matrice[0][1] = matrice1[0][1];
    m->matrice[1][0] = matrice1[1][0];
    m->matrice[1][1] = matrice1[1][1];
    m->matrice[2][0] = matrice1[2][0];
    m->matrice[2][1] = matrice1[2][1];
}

void reflection(float x, float y, int angle)
{
    float in_degree = M_PI / 180;
    float reflect_m1[3][3] = {{cos(cos(-(angle * (M_PI / 180)))),
                               -sin(-sin(-(angle * (M_PI / 180)))) ,
                               0},
                              {sin(sin(-(angle * (M_PI / 180)))),
                               cos(cos(-(angle * (M_PI / 180)))),
                               0},
                              {0, 0, 1}};
    float reflect_m2[3] = {x, y, 1};
    matrice_t current;

    Multiplication_matrice31(reflect_m1, reflect_m2, &current);
    printf("Reflection over an axis with an inclinaison angle of  %d degrees\n", angle);
    printf("%.2f   %.2f   0.00\n%.2f   %.2f   0.00\n0.00   0.00   1.00\n",
           reflect_m1[0][0], reflect_m1[0][1], reflect_m1[1][0], reflect_m1[1][1]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, current.matrice[0][0], current.matrice[1][1]);
}

int check_if_flags(char *src)
{
    char *flags = "tzrs";
    int nb_flag = 0;

    if (2 != my_strlen(src))
        return (0);
    else if ('-' != src[0])
        return (0);
    for (int i = 0; my_strlen(flags) > i; ++i)
        if (flags[i] == src[1])
            ++nb_flag;
    if (0 == nb_flag)
        return (0);
    return (1);
}

void disp_one_flag(matrice_t *m, char **av, float m1[3][3])
{
    printf("%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f\n",
           m1[0][0], m1[0][1], m1[0][2],
           m1[1][0], m1[1][1], m1[1][2],
           m1[2][0], m1[2][1], m1[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(av[1]), atof(av[2]),
           m->matrice[0][2], m->matrice[1][2]);
}

void display_mflags(char **av, int ac)
{
    for (int d = 0; ac > d; ++d) {
        if (1 == check_if_flags(av[d])) {
            if ('t' == av[d][1])
                printf("Translation along vector (%d, %d)\n", atoi(av[d + 1]), atoi(av[d + 2]));
            if ('z' == av[d][1])
                printf("Scaling by factors %d and %d\n", atoi(av[d + 1]), atoi(av[d + 2]));
            if ('r' == av[d][1])
                printf("Rotation by a %d degree angle\n", atoi(av[d + 1]));
            if ('s' == av[d][1])
                printf("Reflection over an axis with an inclinaison angle of %d degrees\n", atoi(av[d + 1]));
        }
    }
}

void multiple_flags(char **av, int ac, matrice_t *m, int i)
{
    float m1[3][3] = {{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 1}};

    for (; 0 < i; --i) {
        if (1 == check_if_flags(av[i])) {
            if ('t' == av[i][1]) {
                m1[0][0] = 1.0;
                m1[1][1] = 1.0;
                m1[0][2] = atof(av[i + 1]);
                m1[1][2] = atof(av[i + 2]);
            }
            if ('z' == av[i][1]) {
                m1[0][0] = atof(av[i + 1]);
                m1[1][1] = atof(av[i + 2]);
            }
            if ('r' == av[i][1]) {
                m1[0][0] = cos(atof(av[i + 1]) * (M_PI / 180));
                m1[0][1] = -sin(atof(av[i + 1]) * (M_PI / 180));
                m1[1][0] = sin(atof(av[i + 1]) * (M_PI / 180));
                m1[1][1] = m1[0][0];
            }
            Multiplication_matrice33(m, m1);
            m1[0][0] = 0;
            m1[0][1] = 0;
            m1[0][2] = 0;
            m1[1][0] = 0;
            m1[1][1] = 0;
            m1[1][2] = 0;
            m1[2][0] = 0;
            m1[2][1] = 0;
            m1[2][2] = 1;
        }
    }
    printf("%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f\n",
           m->matrice[0][0], m->matrice[0][1], m->matrice[0][2],
           m->matrice[1][0], m->matrice[1][1], m->matrice[1][2],
           m->matrice[2][0], m->matrice[2][1], m->matrice[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(av[1]), atof(av[2]),
           m->matrice[0][2], m->matrice[1][2]);
}

int check_if_nb(char **av, int i, int nb_time)                                
{                                                                             
    for (int i = 1; nb_time + 1 > i; ++i)                                         
        if (0 == my_str_isint_float(av[i])) {                                         
            return (84);                                                                  
        }                                                                             
    return (1);                                                                   
}   

int error(int ac, char **av)
{
    if (ac < 4) {
        printf("Too less arguments ! (e0)");
        return (84);
    }
    for (int i = 1; 3 > i; ++i)
        if (0 == my_str_isint_float(av[i])) {
            printf("No float or int (e1)");
            return (84);
        }
    return (0);
}

int main(int ac, char **av)
{
    int flags = 0;
    matrice_t current;
    float m1[3][3] = {{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 1}};
    float m2[3] = {atof(av[1]), atof(av[2]), 1};
    if (84 == error(ac, av))
        return (84);
    for (int i = ac - 1; 0 < i; --i)
        if (1 == check_if_flags(av[i]))
            ++flags;
    for (int i = ac - 1; 0 < i; --i)
        if (1 == check_if_flags(av[i])) {
            if ('t' == av[i][1]) {
                m1[0][0] = 1.0;
                m1[1][1] = 1.0;
                m1[0][2] = atof(av[i + 1]);
                m1[1][2] = atof(av[i + 2]);

            }
            if ('z' == av[i][1]) {
                m1[0][0] = atof(av[i + 1]);
                m1[1][1] = atof(av[i + 2]);
            }
            if ('r' == av[i][1]) {
                m1[0][0] = cos(atof(av[i + 1]) * (M_PI / 180));
                m1[0][1] = -sin(atof(av[i + 1]) * (M_PI / 180));
                m1[1][0] = sin(atof(av[i + 1]) * (M_PI / 180));
                m1[1][1] = m1[0][0];
            }
            Multiplication_matrice31(m1, m2, &current);
            if (1 == flags) {
                display_mflags(av, ac);
                disp_one_flag(&current, av, m1);
            } else {
                display_mflags(av, ac);
                multiple_flags(av, ac, &current, i - 1);
                return (0);
            }
        }
    return (84);
}
