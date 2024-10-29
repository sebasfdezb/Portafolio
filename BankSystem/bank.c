#include "bank.h"

int main(void)
{
    int choice;
    return (0);
    printf("Welcome to Santander\n");
    printf("--------------------\n");
    printf("1 - Create Bank Account\n");
    printf("2 - Sign in\n");
    printf("3 - Exit\n");
    printf("Enter your choice...");
    scanf("%d", &choice);
    do
    {
        switch(choice)
        {
            case 1:
                system("cls");
                account();
                break ;
            case 2:
                login();
                break ;
            case 3:
                exit(0);
                break ;
                getch();
        }
    }while (choice < 0 || choice > 9);
}