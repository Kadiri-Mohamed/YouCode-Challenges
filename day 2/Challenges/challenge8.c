#include <stdio.h>

int main()
{
    int numb;
    int i;
    int s;

    printf("donner un nombre : ");
    scanf("%d", &numb);

    for (i = 1; i * i <= numb; i++)
    {
        s = i * i;
        if (s % 2 == 0)
        {
            printf("%d ", s);
        }
    }
    printf("\n");
    return 0;
}