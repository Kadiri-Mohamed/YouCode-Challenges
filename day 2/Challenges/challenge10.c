#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char alpha[100];
    int somme = 0;
    char maj_alpha;

    printf("donner le numero de telephone: ");

    scanf(" %[^\n]", alpha);

    for (int i = 0; alpha[i] != '\0'; i++)
    {
        maj_alpha = toupper(alpha[i]);

        if (maj_alpha == 'A' || maj_alpha == 'E' || maj_alpha == 'I' || maj_alpha == 'L' || maj_alpha == 'N' || maj_alpha == 'O' || maj_alpha == 'R' || maj_alpha == 'S' || maj_alpha == 'T' || maj_alpha == 'U')
        {
            somme += 1;
        }
        else if (maj_alpha == 'D' || maj_alpha == 'G')
        {
            somme += 2;
        }
        else if (maj_alpha == 'B' || maj_alpha == 'C' || maj_alpha == 'M' || maj_alpha == 'P')
        {
            somme += 3;
        }
        else if (maj_alpha == 'F' || maj_alpha == 'H' || maj_alpha == 'V' || maj_alpha == 'W' || maj_alpha == 'Y')
        {
            somme += 4;
        }
        else if (maj_alpha == 'K')
        {
            somme += 5;
        }
        else if (maj_alpha == 'J' || maj_alpha == 'X')
        {
            somme += 8;
        }
        else if (maj_alpha == 'Q' || maj_alpha == 'Z')
        {
            somme += 10;
        }
        else
        {
            somme += 0;
        }
    }
    printf("%d", somme);

    return 0;
}