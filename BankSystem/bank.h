#ifndef BANK_H
# define BANK_H

# include <stdio.h>
# include <stdlib.h>

typedef struct pass
{
    char    username[20];
    int     date, month, year;
    char    fname[20];
    char    lname[20];
    char    fathname[20];
    char    montname[20];
    char    number[15];
    char    adress[50];
    char    typeacc[20];
}t_pass;

typedef struct money
{
    char        usenameto[50];
    char        userpersonfrom[50];
    long int    money1;
}t_money;

typedef struct userpass
{
    char    password[50];
}t_userpass;

#endif