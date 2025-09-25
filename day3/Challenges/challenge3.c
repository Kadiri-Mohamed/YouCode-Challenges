#include <stdbool.h>
#include <stdio.h>

int main()
{
    int list[10];
    int n;
    int i = 0;
    int size = sizeof(list) / sizeof(list[0]);

    while (i < size)
    {
        printf("Enter nombre: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            break;
        }
        list[i] = n;
        i++;
    }

    for (int x = 0; x < i; x++)
    {
        int counter = 0;
        for (int j = 0; j < i; j++)
        {
            if (list[x] == list[j])
            {
                counter++;
            }
        }
        printf("%d %d \n", list[x], counter);
    }

    return 0;
}