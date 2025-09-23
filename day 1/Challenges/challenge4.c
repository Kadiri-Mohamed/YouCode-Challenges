#include <stdio.h>
int main(void)
{
    float montant = 0;
    printf("Donner un montant :");
    scanf("%f", &montant);

    float tax = montant * 0.05;
    float montant_avec_tax = montant + tax;

    printf("montant avec taxe ajoute : $%.2f", montant_avec_tax);

    return 0;
}