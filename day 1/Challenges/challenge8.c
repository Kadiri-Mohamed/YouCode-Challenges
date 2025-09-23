#include <stdio.h>
int main(void)
{
    float montant_pret;
    float taux_interet = 0.06 / 12;
    float paiment_mensuel = 386.66;

    printf("donner le montant : ");
    scanf("%f", &montant_pret);

    montant_pret = (montant_pret * taux_interet) + montant_pret - paiment_mensuel;
    printf("Solde restant après le premier paiement : %.2f \n", montant_pret);

    montant_pret = montant_pret + taux_interet - paiment_mensuel;
    printf("Solde restant après le deuxième paiement : %.2f \n", montant_pret);

    montant_pret = montant_pret + taux_interet - paiment_mensuel;
    printf("Solde restant après le troisième paiement : %.2f \n", montant_pret);

    return 0;
}