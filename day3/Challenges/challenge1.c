#include <stdbool.h>
#include <stdio.h>
int main()
{
    bool digit_seen[10] = {false};
    int list[10];
    int digit;
    long n;
    // int counter = 1;
    int i = 0;

    printf("Entrer un nombre :");
    scanf("%ld", &n);
    while (n > 0)
    {

        digit = n % 10;
        if (digit_seen[digit])
        {
            bool isExit = false;
            for (int w = 0; w < i; w++)
            {
                if (digit == list[w])
                {
                    isExit = true;
                }
            }

            if (!isExit)
            {
                list[i] = digit;
                i++;
            }
        }
        digit_seen[digit] = true;
        n /= 10;
    }
    printf("Chiffre repete :");

    for (int x = 0; x < i; x++)
    {
        printf("%d", list[x]);
    }

    return 0;
}