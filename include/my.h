/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Header for ping pong ! Ping.. Pong.. ping .. pong
*/

#ifndef MY_H_
#define MY_H_

//Display
void my_putchar(char);
int my_putstr(char const *);
int my_put_nbr(int);
int display_digits(int);

//String
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int match(char *, char const *, int);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

//Calculation
int my_compute_power_rec(int, int);

//Others functions
int my_getnbr(char const *);
int my_str_character(char const *);
int my_strlen_per(char const *, char);
int my_isneg(int);
void my_swap(int *, int *);
void my_swap_char(char *, char *);

//101Pong
int check_errors(int, char **);
int how_many_negative_signs(char *);
int my_str_isnum_with_neg(char const *);
int nb_of_the_char_given(char *, char);

#endif /* MY_H_ */
