#include <stdio.h>
#include <string.h>

int main(void)
{
    char ISBN[100];
    int counter = 1;
    char temp[100];
    int j = 0;

    printf("Entrez ISBN : ");
    scanf("%[^\n]", ISBN);


    for (int i = 0; ISBN[i] != '\0'; i++)
    {
        if ((ISBN[i] == '-' || ISBN[i] == ' ' || ISBN[i] + 1 == '\0'))
        {
            temp[j] = '\0';
            switch (counter)
            {
            case 1:
                printf("Prefixe GS1: %s\n", temp);
                break;
            case 2:
                printf("Identifiant de groupe: %s\n", temp);
                break;
            case 3:
                printf("Code de l'editeur: %s\n", temp);
                break;
            case 4:
                printf("Numero d'article %s\n", temp);
                break;
            case 5:
                printf("Chiffre de controle %s\n", temp);
                break;
            default:
                break;
            }
            j = 0;
        counter++;
        }
        else
        {
            temp[j] = ISBN[i];
            j++;
        }
    }

    return 0;
}
