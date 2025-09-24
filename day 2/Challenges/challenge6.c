#include <stdio.h>
int main(void)
{
    int num1;
    int num2;
    int rest;
    printf("Entrez deux entiers :");
    scanf("%d %d", &num1, &num2);


    do
    {
        rest = num1 % num2;
        num1 = num2;
        num2 = rest;
    } while (num2 != 0);

    printf("Le plus grand commun diviseur est : %d", num1);

    return 0;
}