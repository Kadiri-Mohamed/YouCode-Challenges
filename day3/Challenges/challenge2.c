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

    for (int x = 0; x < 10; x++)
    {
        counter = 0;
        printf("%d ", x);
        for (int j = 0; j < i; j++)
        {
            if (x == list[j])
            {
                counter++;
            }
        }
        printf("%d \n", counter);
    }

    return 0;
}