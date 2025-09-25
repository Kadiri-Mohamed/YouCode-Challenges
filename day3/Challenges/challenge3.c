#include <stdbool.h>
#include <stdio.h>

int main()
{
    int list[10];
    int n;
    int count = 0;
    int size = sizeof(list) / sizeof(list[0]);

    while (count < size)
    {
        printf("Enter nombre: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            break;
        }
        list[count] = n;
        count++;
    }

    for (int x = 0; x < count; x++)
    {
        int num = list[x];
        int counter = 0;
        for (int j = 0; j < count; j++)
        {
            if (num == list[j])
            {
                counter++;
            }
        }
        printf("%d %d \n", list[x], counter);
    }

    return 0;
}