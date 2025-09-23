#include <stdio.h>
#include <math.h>
int main(void)
{
    int x = 0;

    printf("Donner un nombre pour calculer 3x5+2x4-5x3-x2+7x-6 :");
    scanf("%d", &x);
    int y = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    printf("%d", y);

    return 0;
}