#include <stdio.h>
int main(void)
{
    int note;

    printf("Entrez une note numerique :");
    scanf("%d", &note);

    switch (note)
    {
    case 0 ... 59:
        printf("Note litterale : F");
        break;
    case 60 ... 69:
        printf("Note litterale : D");
        break;

    case 70 ... 79:
        printf("Note litterale : C");
        break;

    case 80 ... 89:
        printf("Note litterale : B");
        break;

    case 90 ... 100:
        printf("Note litterale : A");
        break;

    default:
        printf("note invalide");
        break;
    }
    return 0;
}