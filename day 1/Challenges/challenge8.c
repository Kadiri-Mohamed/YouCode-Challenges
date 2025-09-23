#include <stdio.h>
int main(void)
{
    float montant_pret;
    float x;
    float taux_interet;
    float paiment_mensuel;

    printf("donner le montant : ");
    scanf("%f", &montant_pret);
    printf("donner le taux : ");
    scanf("%f", &x);
    printf("donner le paiment mensuel : ");
    scanf("%f", &paiment_mensuel);

    // montant_pret = (montant_pret * taux_interet) + montant_pret - paiment_mensuel;
    // printf("Solde restant apres le premier paiement : %.2f \n", montant_pret);

    // montant_pret = montant_pret + taux_interet - paiment_mensuel;
    // printf("Solde restant apres le deuxieme paiement : %.2f \n", montant_pret);

    // montant_pret = montant_pret + taux_interet - paiment_mensuel;
    // printf("Solde restant apres le troisieme paiement : %.2f \n", montant_pret);

    for (int i = 0; i < 4; i++)
    {
        taux_interet = (x / 100) / 12;
        montant_pret = (montant_pret * taux_interet) + montant_pret - paiment_mensuel;
        printf("Solde restant apres le %d paiement : %.2f \n", i, montant_pret);
    }

    return 0;
}