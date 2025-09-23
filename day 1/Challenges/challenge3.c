#include <stdio.h>
#include <math.h>

int main(void)
{
    int r = 0;
    const float PI = 3.14;
    float v = 0;
    printf("Donne le rayon de circle pour calculer le volume :");
    scanf("%d", &r);
    v = (4.0f / 3.0f) * PI * pow(r, 3);
    printf("le volume de sphere est : %.2f", v);

    return 0;
}