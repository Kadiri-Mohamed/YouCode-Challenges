#include <stdbool.h>
#include <stdio.h>
int main()
{
    bool digit_seen[10] = {false};
    int list[10];
    int digit;
    long n;
    int counter = 1;
    int i = 0;

    printf("Entrer un nombre :");
    scanf("%ld", &n);
    while (n > 0)
    {

        digit = n % 10;

        list[i] = digit;
        i++;

        n /= 10;
    }
    for (int b = 0; b < 10; b++)
    {
        printf("%d ", b);
    }
    printf("\n");
    for (int x = 0; x < 10; x++)
    {
        counter = 0;
        for (int j = 0; j < i; j++)
        {
            if (x == list[j])
            {
                counter++;
            }
        }
        printf("%d ", counter);
    }

    return 0;
}