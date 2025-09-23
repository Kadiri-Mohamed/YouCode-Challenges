#include <stdio.h>
int main(void)
{
    int montant = 0;
    int mod1, mod2, mod3;
    int out1, out2, out3 ,out4;

    printf("Donner un montant :");
    scanf("%d", &montant);

    out1 = montant / 20;
    mod1 = montant % 20;

    out2 = mod1 /10;
    mod2 = montant % 10;

    out3 = mod2 / 5;
    mod3 = mod2 % 5;

    out4 = mod3 /1;

    printf("Billets de 20$ : %d\n", out1);

    printf("Billets de 10$ : %d\n", out2);

    printf("Billets de 5$ : %d\n", out3);

    printf("Billets de 1$ : %d\n", out4);

    return 0 ;

}