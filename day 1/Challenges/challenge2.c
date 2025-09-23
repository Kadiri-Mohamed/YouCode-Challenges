#include <stdio.h>
#include <math.h>

int main(void)
{
    int r = 10;
    const float PI = 3.14;
    float v = 0;
    v = (4.0f / 3.0f) * PI * pow(r, 3);
    printf("%.2f", v);

    return 0;
}