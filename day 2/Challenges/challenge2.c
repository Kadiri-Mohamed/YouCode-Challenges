#include <stdio.h>
int main(void)
{
    int x;
    int y;
    int z;

    printf("donner un nombre : ");
    scanf("%d", &x);
    y = x / 10;
    z = x % 10;

    printf("inverted number is : %d%d", z, y);
    return 0;
}