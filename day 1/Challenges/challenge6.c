#include <stdio.h>
#include <math.h>
int main(void)
{
    int x = 0;

    printf("Donner un nombre pour calculer ((((3x+2)x-5)x-1)x+7)x-6:");
    scanf("%d", &x);
    int y = ((((3*x+2)*x-5)*x-1)*x+7)*x-6;
    printf("%d", y);

    return 0;
}